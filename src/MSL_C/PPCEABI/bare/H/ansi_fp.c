#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_fp.h"

#define isnormal(x) (fpclassify(x) == 4)
#define isnan(x)    (fpclassify(x) == 1)

const f64 bit_values[] = {
	1e1, 1e2, 1e4, 1e8, 1e16, 1e32, 1e64, 1e128, 1e256,
};

const f64 digit_values[] = {
	1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8,
};

static f64 ten = 10.0;

/**
 * @brief Converts floating-point value to decimal digit/exponent form.
 *
 * Normalizes magnitude and emits fixed-count significand digits into output buffer.
 */
void __num2dec(const decform* form, f64 value, decimal* out)
{
	int binaryExp;
	int exp;
	u8* sigWritePtr;
	int digits;
	int exp10Estimate;
	f64 scaleFactor;
	int writeCount;
	int chunkDigits;
	int padDigits;
	int chunkValue;
	int padCount;
	const f64* bitScalePtr;

	digits = form->digits;
	if (digits > 16) {
		digits = 16;
	}

	out->sign       = 0;
	out->exp        = 0;
	out->sig.length = 1;

	if (value == 0.0) {
		out->sig.text[0] = '0';
		return;
	}

	if (!isfinite(value)) {
		out->sig.text[0] = isnan(value) ? 'N' : 'I';
		return;
	}

	out->sig.length = 0;
	if (value < 0.0) {
		value     = -value;
		out->sign = 1;
	}

	// Approximate base-10 exponent from base-2 exponent, then scale magnitude.
	frexp(value, &binaryExp);
	exp10Estimate = (binaryExp * 301029) / 1000000; // log_10(2)
	exp           = exp10Estimate;
	bitScalePtr   = bit_values;
	if (exp10Estimate < 0) {
		exp10Estimate = -exp10Estimate;
		while (exp10Estimate != 0) {
			if (exp10Estimate & 1) {
				value *= *bitScalePtr;
			}
			exp10Estimate >>= 1;
			bitScalePtr++;
		}
	} else if (exp10Estimate > 0) {
		scaleFactor = 1.0f;
		while (exp10Estimate != 0) {
			if (exp10Estimate & 1) {
				scaleFactor *= *bitScalePtr;
			}
			exp10Estimate >>= 1;
			bitScalePtr++;
		}
		value /= scaleFactor;
	}

	while (value >= 1.0) {
		value *= 0.1;
		exp += 1;
	}

	while (value < 0.1) {
		value *= 10.0;
		exp -= 1;
	}

	// Emit significand digits in groups of up to 8 decimal digits.
	sigWritePtr = out->sig.text;
	while (digits != 0) {
		chunkDigits = digits;
		if (digits > 8) {
			chunkDigits = 8;
		}
		out->sig.length += chunkDigits;
		digits -= chunkDigits;
		exp -= chunkDigits;
		sigWritePtr += chunkDigits;
		value *= digit_values[chunkDigits - 1];
		chunkValue = (int)value;
		value      = value - chunkValue;

		writeCount = chunkDigits + 1;
		while (--writeCount != 0) {
			*--sigWritePtr = '0' + (chunkValue % 10);
			chunkValue /= 10;
		}
		sigWritePtr += chunkDigits;
	}

	digits = form->digits;
	if (form->digits > 36) {
		digits = 36;
	}

	padDigits = digits - out->sig.length;
	if (padDigits > 0) {
		padCount = padDigits + 1;
		while (--padCount != 0) {
			*sigWritePtr++ = '0';
		}
		exp -= padDigits;
		out->sig.length += padDigits;
	}

	out->exp = exp;
}

/**
 * @brief Converts decimal digit/exponent form into a floating-point value.
 *
 * Rebuilds significand from decimal chunks, then applies decimal exponent scaling.
 */
f64 __dec2num(const decimal* dec)
{
	f64 num          = 0.0;
	int sign         = dec->sign;
	int exp          = dec->exp;
	int length       = dec->sig.length;
	char firstDigit  = dec->sig.text[0];
	f64 firstDigitScale;
	f64 expScale;
	const f64* bitScalePtr;
	int chunkDigits;
	int chunkValue;
	int parseCount;
	int absExp;
	const u8* sigReadPtr;
	s32 pad[4];

	if (length < 1 || firstDigit == '0') {
		return 0.0;
	} else if (firstDigit == 'I') {
		return sign ? -HUGE_VAL : HUGE_VAL;
	} else if (firstDigit == 'N') {
		return DBL_NAN;
	}

	if (length > 16) {
		exp    = length + exp;
		length = 16;
		exp -= 16;
	}

	chunkDigits = length % 8;
	sigReadPtr  = dec->sig.text;
	if (chunkDigits == 0) {
		chunkDigits = 8;
	}
	exp += length - 1;
	firstDigitScale = pow(ten, length - 1);

	// Parse decimal text in 8-digit chunks to limit intermediate overflow.
	while (chunkDigits != 0) {
		chunkValue = 0;
		parseCount = chunkDigits + 1;
		while (--parseCount) {
			chunkValue = chunkValue * 10 + (*sigReadPtr++ - '0');
		}

		length -= chunkDigits;
		num = num * 100000000.0 + chunkValue;
		if (length == 0) {
			break;
		}
		chunkDigits = 8;
	}

	num    = num / firstDigitScale;
	absExp = __labs(exp);
	bitScalePtr = bit_values;
	if (absExp > 0x1FF) {
		if (exp < 0) {
			return 0.0;
		} else {
			return sign ? -HUGE_VAL : HUGE_VAL;
		}
	}

	expScale = 1.0;
	while (absExp != 0) {
		if (absExp & 1) {
			if (expScale > DBL_MAX / *bitScalePtr) {
				return sign ? -HUGE_VAL : HUGE_VAL;
			}
			expScale *= *bitScalePtr;
		}
		absExp >>= 1;
		bitScalePtr++;
	}

	if (exp < 0) {
		if (num < DBL_MIN * expScale) {
			return 0.0;
		}
		num /= expScale;
	} else if (exp > 0) {
		if (num > DBL_MAX / expScale) {
			return sign ? -HUGE_VAL : HUGE_VAL;
		}
		num *= expScale;
	}

	return sign ? -num : num;
}
