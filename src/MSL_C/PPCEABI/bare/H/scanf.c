#include "types.h"
#include "stdarg.h"
#include "ctype.h"
#include "stdio.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/stdio_api.h"

typedef s64 intmax_t;

enum argument_options {
	normal_argument,
	char_argument,
	short_argument,
	long_argument,
	long_long_argument,
	double_argument,
	long_double_argument,
	wchar_argument
};

typedef u8 char_map[32];

typedef struct {
	u8 suppress_assignment;
	u8 field_width_specified;
	u8 argument_options;
	u8 conversion_char;
	int field_width;
	char_map char_set;
} scan_format;

#define set_char_map(map, ch) map[(u8)ch >> 3] |= (1 << (ch & 7))
#define tst_char_map(map, ch) (map[(u8)ch >> 3] & (1 << (ch & 7)))

/*
 * --INFO--
 * Address:	80218B84
 * Size:	000564
 */
static const char* parse_format(const char* format_string, scan_format* format)
{
	const char* s = format_string;
	int c;
	int flag_found, invert;
	scan_format f = { 0, 0, normal_argument, 0, 2147483647, { 0 } };

	if (((c = *++s) == '%')) {
		f.conversion_char = c;
		*format           = f;
		return ((const char*)s + 1);
	}

	if (c == '*') {
		f.suppress_assignment = 1;
		c                     = *++s;
	}

	if (isdigit(c)) {
		f.field_width = 0;

		do {
			f.field_width = (f.field_width * 10) + (c - '0');
			c             = *++s;
		} while (isdigit(c));

		if (f.field_width == 0) {
			f.conversion_char = 0xFF;
			*format           = f;
			return ((const char*)s + 1);
		}

		f.field_width_specified = 1;
	}

	flag_found = 1;

	switch (c) {
	case 'h':
		f.argument_options = short_argument;

		if (s[1] == 'h') {
			f.argument_options = char_argument;
			c                  = *++s;
		}

		break;
	case 'l':
		f.argument_options = long_argument;

		if (s[1] == 'l') {
			f.argument_options = long_long_argument;
			c                  = *++s;
		}
		break;
	case 'L':
		f.argument_options = long_double_argument;
		break;
	default:
		flag_found = 0;
	}

	if (flag_found) {
		c = *++s;
	}

	f.conversion_char = c;

	switch (c) {
	case 'd':
	case 'i':
	case 'u':
	case 'o':
	case 'x':
	case 'X':
		if (f.argument_options == long_double_argument) {
			f.conversion_char = 0xFF;
			break;
		}

		break;

	case 'a':
	case 'f':
	case 'e':
	case 'E':
	case 'g':
	case 'G':
		if (f.argument_options == char_argument || f.argument_options == short_argument || f.argument_options == long_long_argument) {
			f.conversion_char = 0xFF;
			break;
		}

		if (f.argument_options == long_argument) {
			f.argument_options = double_argument;
		}

		break;

	case 'p':
		f.argument_options = long_argument;
		f.conversion_char  = 'x';
		break;

	case 'c':
		if (f.argument_options == long_argument) {
			f.argument_options = wchar_argument;
		} else {
			if (f.argument_options != normal_argument) {
				f.conversion_char = 0xFF;
			}
		}

		break;

	case 's':
		if (f.argument_options == long_argument) {
			f.argument_options = wchar_argument;
		} else {
			if (f.argument_options != normal_argument) {
				f.conversion_char = 0xFF;
			}
		}

		{
			int i;
			u8* p;

			for (i = sizeof(f.char_set), p = f.char_set; i; --i) {
				*p++ = 0xFF;
			}

			f.char_set[1] = 0xC1;
			f.char_set[4] = 0xFE;
		}

		break;

	case 'n':
		break;

	case '[':
		if (f.argument_options == long_argument) {
			f.argument_options = wchar_argument;
		} else {
			if (f.argument_options != normal_argument) {
				f.conversion_char = 0xFF;
			}
		}

		c      = *++s;
		invert = 0;

		if (c == '^') {
			invert = 1;
			c      = *++s;
		}

		if (c == ']') {
			set_char_map(f.char_set, ']');
			c = *++s;
		}

		while (c && c != ']') {
			int d;
			set_char_map(f.char_set, c);

			if (*(s + 1) == '-' && (d = *(s + 2)) != 0 && d != ']') {
				while (++c <= d) {
					set_char_map(f.char_set, c);
				}

				c = *(s += 3);
			} else {
				c = *++s;
			}
		}

		if (!c) {
			f.conversion_char = 0xFF;
			break;
		}

		if (invert) {
			int i;
			u8* p;

			for (i = sizeof(f.char_set), p = f.char_set; i; --i, ++p) {
				*p = ~*p;
			}

			break;
		}

		break;
	default:
		f.conversion_char = 0xFF;
		break;
	}

	*format = f;
	return ((const char*)s + 1);
}

/*
 * --INFO--
 * Address:	802181E0
 * Size:	0009A4
 */
static int __sformatter(int (*ReadProc)(void*, int, int), void* ReadProcArg, const char* format_str, va_list arg)
{
	int num_chars, chars_read, items_assigned, conversions;
	int base, negative, overflow;
	const char* format_ptr;
	char format_char;
	char c;
	scan_format format;
	s32 long_num;
	u32 u_long_num;
	s64 long_long_num;
	u64 u_long_long_num;
	f128 long_double_num;
	char* arg_ptr;
	int terminate = 0;

	format_ptr     = format_str;
	chars_read     = 0;
	items_assigned = 0;
	conversions    = 0;

	while (!terminate && (format_char = *format_ptr) != 0) {
		if (isspace(format_char)) {
			do {
				format_char = *++format_ptr;
			} while (isspace(format_char));

			while (isspace(c = (*ReadProc)(ReadProcArg, 0, __GetAChar)))
				++chars_read;

			(*ReadProc)(ReadProcArg, c, __UngetAChar);

			continue;
		}

		if (format_char != '%') {
			if ((c = (*ReadProc)(ReadProcArg, 0, __GetAChar)) != (u8)format_char) {
				(*ReadProc)(ReadProcArg, c, __UngetAChar);
				goto exit;
			}

			chars_read++;
			format_ptr++;

			continue;
		}

		format_ptr = parse_format(format_ptr, &format);

		if (!format.suppress_assignment && format.conversion_char != '%') {
			arg_ptr = va_arg(arg, char*);
		} else {
			arg_ptr = 0;
		}

		if ((format.conversion_char != 'n') && (*ReadProc)(ReadProcArg, 0, __TestForError)) {
			terminate = 1;
			goto exit;
		}

		switch (format.conversion_char) {
		case 'd':
			base = 10;
			goto signed_int;
		case 'i':
			base = 0;
		signed_int:
			if ((format.argument_options == long_long_argument))
				u_long_long_num = __strtoull(base, format.field_width, ReadProc, ReadProcArg, &num_chars, &negative, &overflow);
			else
				u_long_num = __strtoul(base, format.field_width, ReadProc, ReadProcArg, &num_chars, &negative, &overflow);

			if (!num_chars) {
				goto exit;
			}

			chars_read += num_chars;

			if ((format.argument_options == long_long_argument))
				long_long_num = (negative ? -u_long_long_num : u_long_long_num);
			else
				long_num = (negative ? -u_long_num : u_long_num);

		signed_int_assign:

			if (arg_ptr) {
				switch (format.argument_options) {
				case normal_argument:
					*(int*)arg_ptr = long_num;
					break;
				case char_argument:
					*(s8*)arg_ptr = long_num;
					break;
				case short_argument:
					*(s16*)arg_ptr = long_num;
					break;
				case long_argument:
					*(s32*)arg_ptr = long_num;
					break;
				case long_long_argument:
					*(s64*)arg_ptr = long_long_num;
					break;
				}

				items_assigned++;
			}

			conversions++;
			break;
		case 'o':
			base = 8;
			goto unsigned_int;
		case 'u':
			base = 10;
			goto unsigned_int;
		case 'x':
		case 'X':
			base = 16;
		unsigned_int:
			if ((format.argument_options == long_long_argument))
				u_long_long_num = __strtoull(base, format.field_width, ReadProc, ReadProcArg, &num_chars, &negative, &overflow);
			else
				u_long_num = __strtoul(base, format.field_width, ReadProc, ReadProcArg, &num_chars, &negative, &overflow);

			if (!num_chars) {
				goto exit;
			}

			chars_read += num_chars;

			if (negative) {
				if (format.argument_options == long_long_argument)
					u_long_long_num = -u_long_long_num;
				else
					u_long_num = -u_long_num;
			}

		unsigned_int_assign:

			if (arg_ptr) {
				switch (format.argument_options) {
				case normal_argument:
					*(uint*)arg_ptr = u_long_num;
					break;
				case char_argument:
					*(u8*)arg_ptr = u_long_num;
					break;
				case short_argument:
					*(u16*)arg_ptr = u_long_num;
					break;
				case long_argument:
					*(u32*)arg_ptr = u_long_num;
					break;
				case long_long_argument:
					*(u64*)arg_ptr = u_long_long_num;
					break;
				}

				items_assigned++;
			}

			conversions++;
			break;
		case 'a':
		case 'f':
		case 'e':
		case 'E':
		case 'g':
		case 'G':
		flt:
			long_double_num = __strtold(format.field_width, ReadProc, ReadProcArg, &num_chars, &overflow);

			if (!num_chars) {
				goto exit;
			}

			chars_read += num_chars;

		assign_float:

			if (arg_ptr) {
				switch (format.argument_options) {
				case normal_argument:
					*(f32*)arg_ptr = long_double_num;
					break;
				case double_argument:
					*(f64*)arg_ptr = long_double_num;
					break;
				case long_double_argument:
					*(f128*)arg_ptr = long_double_num;
					break;
				}

				items_assigned++;
			}

			conversions++;
			break;

		case 'c':

			if (!format.field_width_specified)
				format.field_width = 1;

			if (arg_ptr) {
				int rval;
				num_chars = 0;

				while (format.field_width-- && ((rval = ((*ReadProc)(ReadProcArg, 0, __GetAChar))) != -1)) {
					c = rval;

					if (format.argument_options == wchar_argument) {
						mbtowc(((wchar_t*)arg_ptr), (char*)(&c), 1);
						(wchar_t*)arg_ptr++;
					} else {
						*arg_ptr++ = c;
					}
					num_chars++;
				}

				if (!num_chars) {
					goto exit;
				}

				chars_read += num_chars;

				items_assigned++;
			} else {
				num_chars = 0;

				while (format.field_width-- && ((c = ((*ReadProc)(ReadProcArg, 0, __GetAChar))) != -1)) {
					num_chars++;
				}
				if (!num_chars)
					goto exit;
			}

			conversions++;
			break;
		case '%':
			while (isspace(c = (*ReadProc)(ReadProcArg, 0, __GetAChar)))
				chars_read++;

			if (c != '%') {
				(*ReadProc)(ReadProcArg, c, __UngetAChar);
				goto exit;
			}

			chars_read++;
			break;
		case 's':
			c = (*ReadProc)(ReadProcArg, 0, __GetAChar);
			while (isspace(c)) {
				chars_read++;
				c = (*ReadProc)(ReadProcArg, 0, __GetAChar);
			}

			(*ReadProc)(ReadProcArg, c, __UngetAChar);
		case '[':
			if (arg_ptr) {
				num_chars = 0;

				while (format.field_width-- && ((c = ((*ReadProc)(ReadProcArg, 0, __GetAChar))) != -1)
				       && tst_char_map(format.char_set, c)) {
					if (format.argument_options == wchar_argument) {
						mbtowc(((wchar_t*)arg_ptr), (char*)&c, 1);
						arg_ptr = (char*)((wchar_t*)arg_ptr + 1);
					} else {
						*arg_ptr++ = c;
					}
					num_chars++;
				}

				if (!num_chars) {
					(*ReadProc)(ReadProcArg, c, __UngetAChar);
					goto exit;
				}

				chars_read += num_chars;

				if (format.argument_options == wchar_argument)
					*(wchar_t*)arg_ptr = L'\0';
				else
					*arg_ptr = 0;

				items_assigned++;
			} else {
				num_chars = 0;

				while (format.field_width-- && ((c = ((*ReadProc)(ReadProcArg, 0, __GetAChar))) != -1)
				       && tst_char_map(format.char_set, c)) {

					num_chars++;
				}

				if (!num_chars) {
					(*ReadProc)(ReadProcArg, c, __UngetAChar);
					break;
				}
				chars_read += num_chars;
			}

			if (format.field_width >= 0)
				(*ReadProc)(ReadProcArg, c, __UngetAChar);

			conversions++;
			break;
		case 'n':
			if (arg_ptr)
				switch (format.argument_options) {
				case normal_argument:
					*(int*)arg_ptr = chars_read;
					break;
				case short_argument:
					*(s16*)arg_ptr = chars_read;
					break;
				case long_argument:
					*(s32*)arg_ptr = chars_read;
					break;
				case char_argument:
					*(char*)arg_ptr = chars_read;
					break;
				case long_long_argument:
					*(s64*)arg_ptr = chars_read;
					break;
				}
			continue;
		case 0xFF:
		default:
			goto exit;
		}
	}

exit:

	if ((*ReadProc)(ReadProcArg, 0, __TestForError) && conversions == 0)
		return -1;

	return items_assigned;
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r7, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stmw      r16, 0x58(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  addi      r16, r6, 0
	  addi      r25, r5, 0
	  addi      r29, r1, 0x1C
	  addi      r28, r7, 0x2808
	  li        r27, 0
	  li        r22, 0
	  li        r26, 0
	  b         .loc_0x950

	.loc_0x3C:
	  add       r3, r28, r23
	  lbz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,29,30
	  beq-      .loc_0xBC

	.loc_0x4C:
	  lbzu      r0, 0x1(r25)
	  add       r3, r28, r0
	  lbz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,29,30
	  bne+      .loc_0x4C
	  b         .loc_0x68

	.loc_0x64:
	  addi      r27, r27, 0x1

	.loc_0x68:
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  blrl
	  extsb     r3, r3
	  rlwinm    r0,r3,0,24,31
	  stb       r3, 0x44(r1)
	  add       r3, r28, r0
	  lbz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,29,30
	  bne+      .loc_0x64
	  mr        r12, r30
	  lbz       r4, 0x44(r1)
	  mtlr      r12
	  addi      r3, r31, 0
	  extsb     r4, r4
	  li        r5, 0x1
	  blrl
	  b         .loc_0x950

	.loc_0xBC:
	  extsb     r0, r23
	  cmpwi     r0, 0x25
	  beq-      .loc_0x11C
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  blrl
	  extsb     r0, r3
	  cmpw      r23, r0
	  stb       r0, 0x44(r1)
	  beq-      .loc_0x110
	  mr        r12, r30
	  lbz       r4, 0x44(r1)
	  mtlr      r12
	  addi      r3, r31, 0
	  extsb     r4, r4
	  li        r5, 0x1
	  blrl
	  b         .loc_0x95C

	.loc_0x110:
	  addi      r27, r27, 0x1
	  addi      r25, r25, 0x1
	  b         .loc_0x950

	.loc_0x11C:
	  addi      r3, r25, 0
	  addi      r4, r1, 0x1C
	  bl        .loc_0x9A4
	  lbz       r0, 0x1C(r1)
	  addi      r25, r3, 0
	  cmplwi    r0, 0
	  bne-      .loc_0x158
	  lbz       r0, 0x1F(r1)
	  cmplwi    r0, 0x25
	  beq-      .loc_0x158
	  addi      r3, r16, 0
	  li        r4, 0x1
	  bl        -0x3ABC
	  lwz       r23, 0x0(r3)
	  b         .loc_0x15C

	.loc_0x158:
	  li        r23, 0

	.loc_0x15C:
	  lbz       r0, 0x1F(r1)
	  cmplwi    r0, 0x6E
	  beq-      .loc_0x188
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0x2
	  blrl
	  cmpwi     r3, 0
	  bne-      .loc_0x95C

	.loc_0x188:
	  lbz       r0, 0x1F(r1)
	  cmpwi     r0, 0x64
	  beq-      .loc_0x24C
	  bge-      .loc_0x1EC
	  cmpwi     r0, 0x58
	  beq-      .loc_0x390
	  bge-      .loc_0x1C8
	  cmpwi     r0, 0x45
	  beq-      .loc_0x48C
	  bge-      .loc_0x1BC
	  cmpwi     r0, 0x25
	  beq-      .loc_0x630
	  b         .loc_0x95C

	.loc_0x1BC:
	  cmpwi     r0, 0x47
	  beq-      .loc_0x48C
	  b         .loc_0x95C

	.loc_0x1C8:
	  cmpwi     r0, 0x61
	  beq-      .loc_0x48C
	  bge-      .loc_0x1E0
	  cmpwi     r0, 0x5B
	  beq-      .loc_0x708
	  b         .loc_0x95C

	.loc_0x1E0:
	  cmpwi     r0, 0x63
	  bge-      .loc_0x508
	  b         .loc_0x95C

	.loc_0x1EC:
	  cmpwi     r0, 0x73
	  beq-      .loc_0x694
	  bge-      .loc_0x228
	  cmpwi     r0, 0x6E
	  beq-      .loc_0x8E4
	  bge-      .loc_0x21C
	  cmpwi     r0, 0x69
	  beq-      .loc_0x254
	  bge-      .loc_0x95C
	  cmpwi     r0, 0x68
	  bge-      .loc_0x95C
	  b         .loc_0x48C

	.loc_0x21C:
	  cmpwi     r0, 0x70
	  bge-      .loc_0x95C
	  b         .loc_0x380

	.loc_0x228:
	  cmpwi     r0, 0x78
	  beq-      .loc_0x390
	  bge-      .loc_0x240
	  cmpwi     r0, 0x75
	  beq-      .loc_0x388
	  b         .loc_0x95C

	.loc_0x240:
	  cmpwi     r0, 0xFF
	  beq-      .loc_0x95C
	  b         .loc_0x95C

	.loc_0x24C:
	  li        r3, 0xA
	  b         .loc_0x258

	.loc_0x254:
	  li        r3, 0

	.loc_0x258:
	  lbz       r0, 0x1E(r1)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x28C
	  lwz       r4, 0x20(r1)
	  addi      r5, r30, 0
	  addi      r6, r31, 0
	  addi      r7, r1, 0x50
	  addi      r8, r1, 0x4C
	  addi      r9, r1, 0x48
	  bl        0x19A0
	  addi      r20, r4, 0
	  addi      r21, r3, 0
	  b         .loc_0x2AC

	.loc_0x28C:
	  lwz       r4, 0x20(r1)
	  addi      r5, r30, 0
	  addi      r6, r31, 0
	  addi      r7, r1, 0x50
	  addi      r8, r1, 0x4C
	  addi      r9, r1, 0x48
	  bl        0x1D44
	  mr        r24, r3

	.loc_0x2AC:
	  lwz       r0, 0x50(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x95C
	  lbz       r4, 0x1E(r1)
	  add       r27, r27, r0
	  cmplwi    r4, 0x4
	  bne-      .loc_0x2F4
	  lwz       r0, 0x4C(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x2E0
	  subfic    r3, r20, 0
	  subfze    r0, r21
	  b         .loc_0x2E8

	.loc_0x2E0:
	  addi      r3, r20, 0
	  addi      r0, r21, 0

	.loc_0x2E8:
	  addi      r18, r3, 0
	  mr        r17, r0
	  b         .loc_0x310

	.loc_0x2F4:
	  lwz       r0, 0x4C(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x308
	  neg       r0, r24
	  b         .loc_0x30C

	.loc_0x308:
	  mr        r0, r24

	.loc_0x30C:
	  mr        r19, r0

	.loc_0x310:
	  cmplwi    r23, 0
	  beq-      .loc_0x378
	  cmpwi     r4, 0x2
	  beq-      .loc_0x358
	  bge-      .loc_0x334
	  cmpwi     r4, 0
	  beq-      .loc_0x344
	  bge-      .loc_0x34C
	  b         .loc_0x374

	.loc_0x334:
	  cmpwi     r4, 0x4
	  beq-      .loc_0x36C
	  bge-      .loc_0x374
	  b         .loc_0x364

	.loc_0x344:
	  stw       r19, 0x0(r23)
	  b         .loc_0x374

	.loc_0x34C:
	  extsb     r0, r19
	  stb       r0, 0x0(r23)
	  b         .loc_0x374

	.loc_0x358:
	  extsh     r0, r19
	  sth       r0, 0x0(r23)
	  b         .loc_0x374

	.loc_0x364:
	  stw       r19, 0x0(r23)
	  b         .loc_0x374

	.loc_0x36C:
	  stw       r18, 0x4(r23)
	  stw       r17, 0x0(r23)

	.loc_0x374:
	  addi      r22, r22, 0x1

	.loc_0x378:
	  addi      r26, r26, 0x1
	  b         .loc_0x950

	.loc_0x380:
	  li        r3, 0x8
	  b         .loc_0x394

	.loc_0x388:
	  li        r3, 0xA
	  b         .loc_0x394

	.loc_0x390:
	  li        r3, 0x10

	.loc_0x394:
	  lbz       r0, 0x1E(r1)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x3C8
	  lwz       r4, 0x20(r1)
	  addi      r5, r30, 0
	  addi      r6, r31, 0
	  addi      r7, r1, 0x50
	  addi      r8, r1, 0x4C
	  addi      r9, r1, 0x48
	  bl        0x1864
	  addi      r20, r4, 0
	  addi      r21, r3, 0
	  b         .loc_0x3E8

	.loc_0x3C8:
	  lwz       r4, 0x20(r1)
	  addi      r5, r30, 0
	  addi      r6, r31, 0
	  addi      r7, r1, 0x50
	  addi      r8, r1, 0x4C
	  addi      r9, r1, 0x48
	  bl        0x1C08
	  mr        r24, r3

	.loc_0x3E8:
	  lwz       r3, 0x50(r1)
	  cmpwi     r3, 0
	  beq-      .loc_0x95C
	  lwz       r0, 0x4C(r1)
	  add       r27, r27, r3
	  cmpwi     r0, 0
	  beq-      .loc_0x420
	  lbz       r0, 0x1E(r1)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x41C
	  subfic    r20, r20, 0
	  subfze    r21, r21
	  b         .loc_0x420

	.loc_0x41C:
	  neg       r24, r24

	.loc_0x420:
	  cmplwi    r23, 0
	  beq-      .loc_0x484
	  lbz       r0, 0x1E(r1)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x468
	  bge-      .loc_0x448
	  cmpwi     r0, 0
	  beq-      .loc_0x458
	  bge-      .loc_0x460
	  b         .loc_0x480

	.loc_0x448:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x478
	  bge-      .loc_0x480
	  b         .loc_0x470

	.loc_0x458:
	  stw       r24, 0x0(r23)
	  b         .loc_0x480

	.loc_0x460:
	  stb       r24, 0x0(r23)
	  b         .loc_0x480

	.loc_0x468:
	  sth       r24, 0x0(r23)
	  b         .loc_0x480

	.loc_0x470:
	  stw       r24, 0x0(r23)
	  b         .loc_0x480

	.loc_0x478:
	  stw       r20, 0x4(r23)
	  stw       r21, 0x0(r23)

	.loc_0x480:
	  addi      r22, r22, 0x1

	.loc_0x484:
	  addi      r26, r26, 0x1
	  b         .loc_0x950

	.loc_0x48C:
	  lwz       r3, 0x20(r1)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  addi      r6, r1, 0x50
	  addi      r7, r1, 0x48
	  bl        0xE38
	  lwz       r0, 0x50(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x95C
	  cmplwi    r23, 0
	  add       r27, r27, r0
	  beq-      .loc_0x500
	  lbz       r0, 0x1E(r1)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x4F0
	  bge-      .loc_0x4D8
	  cmpwi     r0, 0
	  beq-      .loc_0x4E4
	  b         .loc_0x4FC

	.loc_0x4D8:
	  cmpwi     r0, 0x7
	  bge-      .loc_0x4FC
	  b         .loc_0x4F8

	.loc_0x4E4:
	  frsp      f0, f1
	  stfs      f0, 0x0(r23)
	  b         .loc_0x4FC

	.loc_0x4F0:
	  stfd      f1, 0x0(r23)
	  b         .loc_0x4FC

	.loc_0x4F8:
	  stfd      f1, 0x0(r23)

	.loc_0x4FC:
	  addi      r22, r22, 0x1

	.loc_0x500:
	  addi      r26, r26, 0x1
	  b         .loc_0x950

	.loc_0x508:
	  lbz       r0, 0x1D(r1)
	  cmplwi    r0, 0
	  bne-      .loc_0x51C
	  li        r0, 0x1
	  stw       r0, 0x20(r1)

	.loc_0x51C:
	  cmplwi    r23, 0
	  beq-      .loc_0x5C0
	  li        r0, 0
	  stw       r0, 0x50(r1)
	  b         .loc_0x56C

	.loc_0x530:
	  lbz       r0, 0x1E(r1)
	  cmplwi    r0, 0x7
	  bne-      .loc_0x554
	  addi      r3, r23, 0
	  addi      r4, r1, 0x44
	  li        r5, 0x1
	  bl        -0x260C
	  addi      r23, r23, 0x1
	  b         .loc_0x560

	.loc_0x554:
	  lbz       r0, 0x44(r1)
	  stb       r0, 0x0(r23)
	  addi      r23, r23, 0x1

	.loc_0x560:
	  lwz       r3, 0x50(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x50(r1)

	.loc_0x56C:
	  lwz       r3, 0x20(r1)
	  subi      r0, r3, 0x1
	  cmpwi     r3, 0
	  stw       r0, 0x20(r1)
	  beq-      .loc_0x5A8
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  blrl
	  extsb     r0, r3
	  cmpwi     r0, -0x1
	  stb       r0, 0x44(r1)
	  bne+      .loc_0x530

	.loc_0x5A8:
	  lwz       r0, 0x50(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x95C
	  add       r27, r27, r0
	  addi      r22, r22, 0x1
	  b         .loc_0x620

	.loc_0x5C0:
	  li        r0, 0
	  stw       r0, 0x50(r1)
	  b         .loc_0x5D8

	.loc_0x5CC:
	  lwz       r3, 0x50(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x50(r1)

	.loc_0x5D8:
	  lwz       r3, 0x20(r1)
	  subi      r0, r3, 0x1
	  cmpwi     r3, 0
	  stw       r0, 0x20(r1)
	  beq-      .loc_0x614
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  blrl
	  extsb     r0, r3
	  cmpwi     r0, -0x1
	  stb       r0, 0x44(r1)
	  bne+      .loc_0x5CC

	.loc_0x614:
	  lwz       r0, 0x50(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x95C

	.loc_0x620:
	  addi      r26, r26, 0x1
	  b         .loc_0x950
	  b         .loc_0x630

	.loc_0x62C:
	  addi      r27, r27, 0x1

	.loc_0x630:
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  blrl
	  extsb     r3, r3
	  rlwinm    r0,r3,0,24,31
	  stb       r3, 0x44(r1)
	  add       r3, r28, r0
	  lbz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,29,30
	  bne+      .loc_0x62C
	  lbz       r0, 0x44(r1)
	  extsb     r4, r0
	  cmpwi     r4, 0x25
	  beq-      .loc_0x68C
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r5, 0x1
	  blrl
	  b         .loc_0x95C

	.loc_0x68C:
	  addi      r27, r27, 0x1
	  b         .loc_0x950

	.loc_0x694:
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  blrl
	  extsb     r0, r3
	  stb       r0, 0x44(r1)
	  b         .loc_0x6DC

	.loc_0x6B8:
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  addi      r27, r27, 0x1
	  blrl
	  extsb     r0, r3
	  stb       r0, 0x44(r1)

	.loc_0x6DC:
	  lbz       r4, 0x44(r1)
	  add       r3, r28, r4
	  lbz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,29,30
	  bne+      .loc_0x6B8
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  extsb     r4, r4
	  li        r5, 0x1
	  blrl

	.loc_0x708:
	  cmplwi    r23, 0
	  beq-      .loc_0x80C
	  li        r0, 0
	  stw       r0, 0x50(r1)
	  b         .loc_0x754

	.loc_0x71C:
	  lbz       r0, 0x1E(r1)
	  cmplwi    r0, 0x7
	  bne-      .loc_0x740
	  addi      r3, r23, 0
	  addi      r4, r1, 0x44
	  li        r5, 0x1
	  bl        -0x27F8
	  addi      r23, r23, 0x2
	  b         .loc_0x748

	.loc_0x740:
	  stb       r5, 0x0(r23)
	  addi      r23, r23, 0x1

	.loc_0x748:
	  lwz       r3, 0x50(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x50(r1)

	.loc_0x754:
	  lwz       r3, 0x20(r1)
	  subi      r0, r3, 0x1
	  cmpwi     r3, 0
	  stw       r0, 0x20(r1)
	  beq-      .loc_0x7B4
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  blrl
	  extsb     r0, r3
	  cmpwi     r0, -0x1
	  stb       r0, 0x44(r1)
	  beq-      .loc_0x7B4
	  lbz       r5, 0x44(r1)
	  li        r3, 0x1
	  srawi     r4, r5, 0x3
	  addi      r4, r4, 0x8
	  rlwinm    r0,r5,0,29,31
	  lbzx      r4, r29, r4
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  bne+      .loc_0x71C

	.loc_0x7B4:
	  lwz       r3, 0x50(r1)
	  cmpwi     r3, 0
	  bne-      .loc_0x7E0
	  mr        r12, r30
	  lbz       r4, 0x44(r1)
	  mtlr      r12
	  addi      r3, r31, 0
	  extsb     r4, r4
	  li        r5, 0x1
	  blrl
	  b         .loc_0x95C

	.loc_0x7E0:
	  lbz       r0, 0x1E(r1)
	  add       r27, r27, r3
	  cmplwi    r0, 0x7
	  bne-      .loc_0x7FC
	  li        r0, 0
	  sth       r0, 0x0(r23)
	  b         .loc_0x804

	.loc_0x7FC:
	  li        r0, 0
	  stb       r0, 0x0(r23)

	.loc_0x804:
	  addi      r22, r22, 0x1
	  b         .loc_0x8B4

	.loc_0x80C:
	  li        r0, 0
	  stw       r0, 0x50(r1)
	  b         .loc_0x824

	.loc_0x818:
	  lwz       r3, 0x50(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x50(r1)

	.loc_0x824:
	  lwz       r3, 0x20(r1)
	  subi      r0, r3, 0x1
	  cmpwi     r3, 0
	  stw       r0, 0x20(r1)
	  beq-      .loc_0x884
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  blrl
	  extsb     r0, r3
	  cmpwi     r0, -0x1
	  stb       r0, 0x44(r1)
	  beq-      .loc_0x884
	  lbz       r0, 0x44(r1)
	  li        r3, 0x1
	  srawi     r4, r0, 0x3
	  addi      r4, r4, 0x8
	  rlwinm    r0,r0,0,29,31
	  lbzx      r4, r29, r4
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  bne+      .loc_0x818

	.loc_0x884:
	  lwz       r0, 0x50(r1)
	  cmpwi     r0, 0
	  bne-      .loc_0x8B0
	  mr        r12, r30
	  lbz       r4, 0x44(r1)
	  mtlr      r12
	  addi      r3, r31, 0
	  extsb     r4, r4
	  li        r5, 0x1
	  blrl
	  b         .loc_0x95C

	.loc_0x8B0:
	  add       r27, r27, r0

	.loc_0x8B4:
	  lwz       r0, 0x20(r1)
	  cmpwi     r0, 0
	  blt-      .loc_0x8DC
	  mr        r12, r30
	  lbz       r4, 0x44(r1)
	  mtlr      r12
	  addi      r3, r31, 0
	  extsb     r4, r4
	  li        r5, 0x1
	  blrl

	.loc_0x8DC:
	  addi      r26, r26, 0x1
	  b         .loc_0x950

	.loc_0x8E4:
	  cmplwi    r23, 0
	  beq-      .loc_0x950
	  lbz       r0, 0x1E(r1)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x924
	  bge-      .loc_0x90C
	  cmpwi     r0, 0
	  beq-      .loc_0x91C
	  bge-      .loc_0x938
	  b         .loc_0x950

	.loc_0x90C:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x944
	  bge-      .loc_0x950
	  b         .loc_0x930

	.loc_0x91C:
	  stw       r27, 0x0(r23)
	  b         .loc_0x950

	.loc_0x924:
	  extsh     r0, r27
	  sth       r0, 0x0(r23)
	  b         .loc_0x950

	.loc_0x930:
	  stw       r27, 0x0(r23)
	  b         .loc_0x950

	.loc_0x938:
	  extsb     r0, r27
	  stb       r0, 0x0(r23)
	  b         .loc_0x950

	.loc_0x944:
	  stw       r27, 0x4(r23)
	  srawi     r0, r27, 0x1F
	  stw       r0, 0x0(r23)

	.loc_0x950:
	  lbz       r23, 0x0(r25)
	  extsb.    r0, r23
	  bne+      .loc_0x3C

	.loc_0x95C:
	  addi      r12, r30, 0
	  mtlr      r12
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0x2
	  blrl
	  cmpwi     r3, 0
	  beq-      .loc_0x98C
	  cmpwi     r26, 0
	  bne-      .loc_0x98C
	  li        r3, -0x1
	  b         .loc_0x990

	.loc_0x98C:
	  mr        r3, r22

	.loc_0x990:
	  lmw       r16, 0x58(r1)
	  lwz       r0, 0x9C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr

	.loc_0x9A4:
	*/
}

/*
 * --INFO--
 * Address:	80218150
 * Size:	000090
 */
int __StringRead(void* pPtr, int ch, int act)
{
	char ret;
	__InStrCtrl* Iscp = (__InStrCtrl*)pPtr;

	switch (act) {
	case __GetAChar:
		ret = *(Iscp->NextChar);

		if (ret == '\0') {
			Iscp->NullCharDetected = 1;
			return -1;
		} else {
			Iscp->NextChar++;
			return (s8)ret;
		}

	case __UngetAChar:
		if (Iscp->NullCharDetected == 0) {
			Iscp->NextChar--;
		} else {
			Iscp->NullCharDetected = 0;
		}

		return ch;

	case __TestForError:
		return Iscp->NullCharDetected;
	}

	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void fscanf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void scanf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
int __vsscanf(const char* s, const char* format, va_list arg)
{
	__InStrCtrl isc;
	isc.NextChar = (char*)s;

	if ((s == 0) || (*isc.NextChar == '\0')) {
		return -1;
	}

	isc.NullCharDetected = 0;
	return __sformatter(&__StringRead, (void*)&isc, format, arg);
}

/*
 * --INFO--
 * Address:	80218094
 * Size:	0000BC
 */
int sscanf(const char* s, const char* pFormat, ...)
{
	va_list args;
	va_start(args, pFormat);
	return __vsscanf(s, pFormat, args);
}
