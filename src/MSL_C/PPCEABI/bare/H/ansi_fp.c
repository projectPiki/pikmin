#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_fp.h"
#include "types.h"

#define isnormal(x) (fpclassify(x) == 4)
#define isnan(x)    (fpclassify(x) == 1)

const f64 bit_values[] = {
	1e1, 1e2, 1e4, 1e8, 1e16, 1e32, 1e64, 1e128, 1e256,
};

const f64 digit_values[] = {
	1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8,
};

/*
 * --INFO--
 * Address:	802158EC
 * Size:	0003B4
 */
void __num2dec(const decform* f, f64 x, decimal* d)
{
	int sp30;
	int exp;
	u8* p;
	int digits;
	int var_r4;
	f64 var_f1;
	int var_r11;
	int var_r12;
	int temp_r5;
	int var_r6;
	int var_r6_2;
	const f64* var_r5;

	// fixes float ordering issue
	(void)0.0;
	(void)1.0;
	(void)4503601774854144.0;

	digits = f->digits;
	if (digits > 16) {
		digits = 16;
	}

	d->sign       = 0;
	d->exp        = 0;
	d->sig.length = 1;

	if (x == 0.0) {
		d->sig.text[0] = '0';
		return;
	}

	if (!isfinite(x)) {
		d->sig.text[0] = isnan(x) ? 'N' : 'I';
		return;
	}

	d->sig.length = 0;
	if (x < 0.0) {
		x       = -x;
		d->sign = 1;
	}

	frexp(x, &sp30);
	var_r4 = (sp30 * 301029) / 1000000; // log_10(2)
	exp    = var_r4;
	var_r5 = bit_values;
	if (var_r4 < 0) {
		var_r4 = -var_r4;
		while (var_r4 != 0) {
			if (var_r4 & 1) {
				x *= *var_r5;
			}
			var_r4 >>= 1;
			var_r5++;
		}
	} else if (var_r4 > 0) {
		var_f1 = 1.0f;
		while (var_r4 != 0) {
			if (var_r4 & 1) {
				var_f1 *= *var_r5;
			}
			var_r4 >>= 1;
			var_r5++;
		}
		x /= var_f1;
	}

	while (x >= 1.0) {
		x *= 0.1;
		exp += 1;
	}

	while (x < 0.1) {
		x *= 10.0;
		exp -= 1;
	}

	p = d->sig.text;
	while (digits != 0) {
		var_r12 = digits;
		if (digits > 8) {
			var_r12 = 8;
		}
		d->sig.length += var_r12;
		digits -= var_r12;
		exp -= var_r12;
		p += var_r12;
		x *= digit_values[var_r12 - 1];
		var_r6 = (int)x;
		x      = x - var_r6;

		var_r11 = var_r12 + 1;
		while (--var_r11 != 0) {
			*--p = '0' + (var_r6 % 10);
			var_r6 /= 10;
		}
		p += var_r12;
	}

	digits = f->digits;
	if (f->digits > 36) {
		digits = 36;
	}

	temp_r5 = digits - d->sig.length;
	if (temp_r5 > 0) {
		var_r6_2 = temp_r5 + 1;
		while (--var_r6_2 != 0) {
			*p++ = '0';
		}
		exp -= temp_r5;
		d->sig.length += temp_r5;
	}

	d->exp = exp;
}

/*
 * --INFO--
 * Address:	80215648
 * Size:	0002A4
 */
f64 __dec2num(const decimal* d)
{
	if (d->sig.length <= 0) {
		return copysign(0.0, d->sign == 0 ? 1.0 : -1.0);
	}

	switch (d->sig.text[0]) {
	case '0':
		return copysign(0.0, d->sign == 0 ? 1.0 : -1.0);
	case 'I':
		return copysign((f64)INFINITY, d->sign == 0 ? 1.0 : -1.0);
	case 'N': {
		f64 result;
		u64* ll = (u64*)&result;

		*ll = 0x7FF0000000000000;
		if (d->sign)
			*ll |= 0x8000000000000000;

		if (d->sig.length == 1)
			*ll |= 0x8000000000000;
		else {
			u8* p               = (u8*)&result + 1;
			int placed_non_zero = 0;
			int low             = 1;
			int i;
			int e = d->sig.length;
			if (e > 14)
				e = 14;

			for (i = 1; i < e; ++i) {
				u8 c = d->sig.text[i];

				if (isdigit(c)) {
					c -= '0';
				} else {
					c = (u8)(_tolower(c) - 'a' + 10);
				}

				if (c != 0) {
					placed_non_zero = 1;
				}

				if (low) {
					*p++ |= c;
				} else {
					*p = (u8)(c << 4);
				}

				low = !low;
			}

			if (!placed_non_zero) {
				*ll |= 0x0008000000000000;
			}
		}

		return result;
	}
	}

	{
		f64 pow_10[8] = { 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8 };

		decimal dec = *d;
		u8* i       = dec.sig.text;
		u8* e       = i + dec.sig.length;
		f64 first_guess;
		int exponent;

		for (; i < e; ++i)
			*i -= '0';
		dec.exp += dec.sig.length - 1;
		exponent = dec.exp;

		i           = dec.sig.text;
		first_guess = *i++;

		while (i < e) {
			u32 ival = 0;
			int j;
			f64 temp1, temp2;
			int ndig = (int)(e - i) % 8;

			if (ndig == 0)
				ndig = 8;

			for (j = 0; j < ndig; ++j, ++i) {
				ival = ival * 10 + *i;
			}

			temp1 = first_guess * pow_10[ndig - 1];
			temp2 = temp1 + ival;

			if (ival != 0 && temp1 == temp2)
				break;

			first_guess = temp2;
			exponent -= ndig;
		}

		if (exponent < 0) {
			first_guess /= pow(5.0, -exponent);
		} else {
			first_guess *= pow(5.0, exponent);
		}

		first_guess = ldexp(first_guess, exponent);

		if (isinf(first_guess)) {
			decimal max;
			__str2dec(&max, "179769313486231580793729011405303420", 308);
			if (__less_dec(&max, &dec))
				goto done;
			first_guess = DBL_MAX;
		}

		{
			decimal feedback1;

			__num2dec_internal(&feedback1, first_guess);

			if (__equals_dec(&feedback1, &dec)) {
				goto done;
			}

			if (__less_dec(&feedback1, &dec)) {

				decimal feedback2, difflow, diffhigh;
				f64 next_guess = first_guess;
				u64* ull       = (u64*)&next_guess;
				++*ull;

				if (isinf(next_guess)) {
					first_guess = next_guess;
					goto done;
				}

				__num2dec_internal(&feedback2, next_guess);

				while (__less_dec(&feedback2, &dec)) {
					feedback1   = feedback2;
					first_guess = next_guess;
					++*ull;
					if (isinf(next_guess)) {
						first_guess = next_guess;
						goto done;
					}
					__num2dec_internal(&feedback2, next_guess);
				}

				__minus_dec(&difflow, &dec, &feedback1);
				__minus_dec(&diffhigh, &feedback2, &dec);

				if (__equals_dec(&difflow, &diffhigh)) {
					if (*(u64*)&first_guess & 1) {
						first_guess = next_guess;
					}
				} else if (!__less_dec(&difflow, &diffhigh)) {
					first_guess = next_guess;
				}
			} else {
				decimal feedback2, difflow, diffhigh;
				f64 next_guess = first_guess;
				u64* ull       = (u64*)&next_guess;
				--*ull;

				__num2dec_internal(&feedback2, next_guess);

				while (__less_dec(&dec, &feedback2)) {
					feedback1   = feedback2;
					first_guess = next_guess;
					--*ull;
					__num2dec_internal(&feedback2, next_guess);
				}

				__minus_dec(&difflow, &dec, &feedback2);
				__minus_dec(&diffhigh, &feedback1, &dec);

				if (__equals_dec(&difflow, &diffhigh)) {
					if (*(u64*)&first_guess & 1) {
						first_guess = next_guess;
					}
				} else if (__less_dec(&difflow, &diffhigh)) {
					first_guess = next_guess;
				}
			}
		}
	done:
		if (dec.sign) {
			first_guess = -first_guess;
		}
		return first_guess;
	}
}
