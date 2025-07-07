#include "PowerPC_EABI_Support/MSL_C/MSL_Common/strtold.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_fp.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/stdio_api.h"
#include "stl/ctype.h"
#include "stl/errno.h"
#include "stl/limits.h"
#include "stl/locale.h"

enum scan_states {
	start              = 0x0001,
	sig_start          = 0x0002,
	leading_sig_zeroes = 0x0004,
	int_digit_loop     = 0x0008,
	frac_start         = 0x0010,
	frac_digit_loop    = 0x0020,
	sig_end            = 0x0040,
	exp_start          = 0x0080,
	leading_exp_digit  = 0x0100,
	leading_exp_zeroes = 0x0200,
	exp_digit_loop     = 0x0400,
	finished           = 0x0800,
	failure            = 0x1000,
};

#define final_state(scan_state) (scan_state & (finished | failure))
#define success(scan_state) \
	(scan_state & (leading_sig_zeroes | int_digit_loop | frac_digit_loop | leading_exp_zeroes | exp_digit_loop | finished))

#define fetch()    (count++, (*ReadProc)(ReadProcArg, 0, __GetAChar))
#define unfetch(c) (*ReadProc)(ReadProcArg, c, __UngetAChar)

/*
 * --INFO--
 * Address:	802194B8
 * Size:	0006E4
 */
f128 __strtold(int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned, int* overflow)
{
	long double result;
	int c;
	int scan_state   = start;
	int count        = 0;
	int spaces       = 0;
	int sig_negative = 0;
	int exp_negative = 0;
	long exp_value   = 0;
	int exp_adjust   = 0;
	int dot          = *(unsigned char*)__lconv.decimal_point;
	decimal d        = { 0, 0, 0, { 0, "" } };

	*overflow = 0;
	c         = fetch();

	while (count <= max_width && c != -1 && !final_state(scan_state)) {
		switch (scan_state) {
		case start:
			if (isspace(c)) {
				c = fetch();
				count--;
				spaces++;
				break;
			}

			if (c == '+') {
				c = fetch();
			} else if (c == '-') {
				c            = fetch();
				sig_negative = 1;
			}
			scan_state = sig_start;
			break;

		case sig_start:
			if (c == dot) {
				scan_state = frac_start;
				c          = fetch();
				break;
			}
			if (!isdigit(c)) {
				scan_state = failure;
				break;
			}

			if (c == '0') {
				scan_state = leading_sig_zeroes;
				c          = fetch();
				break;
			}

			scan_state = int_digit_loop;
			break;

		case leading_sig_zeroes:
			if (c == '0') {
				c = fetch();

				break;
			}
			scan_state = int_digit_loop;
			break;

		case int_digit_loop:
			if (!isdigit(c)) {
				if (c == dot) {
					scan_state = frac_digit_loop;
					c          = fetch();
				} else {
					scan_state = sig_end;
				}
				break;
			}
			if (d.sig.length < 20) {
				d.sig.text[d.sig.length++] = c;
			} else {
				exp_adjust++;
			}

			c = fetch();
			break;

		case frac_start:
			if (!isdigit(c)) {
				scan_state = failure;
				break;
			}

			scan_state = frac_digit_loop;
			break;

		case frac_digit_loop:
			if (!isdigit(c)) {
				scan_state = sig_end;
				break;
			}

			if (d.sig.length < 20) {
				if (c != '0' || d.sig.length) {
					d.sig.text[d.sig.length++] = c;
				}

				exp_adjust--;
			}
			c = fetch();
			break;

		case sig_end:
			if (c == 'E' || c == 'e') {
				scan_state = exp_start;
				c          = fetch();
				break;
			}
			scan_state = finished;
			break;

		case exp_start:
			if (c == '+') {
				c = fetch();
			} else if (c == '-') {
				c            = fetch();
				exp_negative = 1;
			}

			scan_state = leading_exp_digit;
			break;

		case leading_exp_digit:
			if (!isdigit(c)) {
				scan_state = failure;
				break;
			}

			if (c == '0') {
				scan_state = leading_exp_zeroes;
				c          = fetch();
				break;
			}

			scan_state = exp_digit_loop;
			break;

		case leading_exp_zeroes:
			if (c == '0') {
				c = fetch();
				break;
			}

			scan_state = exp_digit_loop;
			break;

		case exp_digit_loop:
			if (!isdigit(c)) {
				scan_state = finished;
				break;
			}

			exp_value = exp_value * 10 + (c - '0');
			if (exp_value > SHRT_MAX) {
				*overflow = 1;
			}

			c = fetch();
			break;
		}
	}

	if (!success(scan_state)) {
		count          = 0;
		*chars_scanned = 0;
	} else {
		count--;
		*chars_scanned = count + spaces;
	}

	unfetch(c);

	if (exp_negative) {
		exp_value = -exp_value;
	}

	{
		int n            = d.sig.length;
		unsigned char* p = &d.sig.text[n];

		while (n-- && *--p == '0') {
			exp_adjust++;
		}

		d.sig.length = n + 1;

		if (d.sig.length == 0) {
			d.sig.text[d.sig.length++] = '0';
		}
	}

	exp_value += exp_adjust;

	if (exp_value < SHRT_MIN || exp_value > SHRT_MAX) {
		*overflow = 1;
	}

	if (*overflow) {
		if (exp_negative) {
			return 0.0;
		} else {
			return sig_negative ? -HUGE_VAL : HUGE_VAL;
		}
	}

	d.exp = exp_value;

	result = __dec2num(&d);

	if (result != 0.0 && result < LDBL_MIN) {
		*overflow = 1;
		result    = 0.0;
	} else if (result > LDBL_MAX) {
		*overflow = 1;
		result    = HUGE_VAL;
	}

	if (sig_negative) {
		result = -result;
	}

	return result;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void strtod(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021942C
 * Size:	00008C
 */
f64 atof(const char* str)
{
	__InStrCtrl isc;
	int overflow;
	int chars_scanned;
	f128 result;
	f128 abs_result;
	s32 pad[5];

	isc.NextChar         = str;
	isc.NullCharDetected = 0;
	result               = __strtold(INT_MAX, __StringRead, &isc, &chars_scanned, &overflow);

	abs_result = fabs(result);
	if (overflow || (result != 0.0 && (abs_result < DBL_MIN || abs_result > DBL_MAX))) {
		errno = ERANGE;
	}

	return result;
}
