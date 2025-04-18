#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_fp.h"
#include "types.h"

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
		static f64 pow_10[8] = { 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8 };

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

/*
 * --INFO--
 * Address:	802158EC
 * Size:	0003B4
 */
void __num2dec(const decform* form, f64 x, decimal* d)
{
	s16 digits = form->digits;
	int i;
	__num2dec_internal(d, x);

	if (d->sig.text[0] > 9) {
		return;
	}

	if (digits > SIGDIGLEN) {
		digits = SIGDIGLEN;
	}

	__rounddec(d, digits);

	while (d->sig.length < digits) {
		d->sig.text[d->sig.length++] = 0;
	}

	d->exp -= d->sig.length - 1;

	for (i = 0; i < d->sig.length; i++) {
		d->sig.text[i] += '0';
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  fmr       f31, f1
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x54(r1)
	  mr        r29, r3
	  lha       r0, 0x2(r3)
	  cmpwi     r0, 0x10
	  mr        r31, r0
	  ble-      .loc_0x3C
	  li        r31, 0x10

	.loc_0x3C:
	  li        r3, 0
	  stb       r3, 0x0(r30)
	  li        r0, 0x1
	  sth       r3, 0x2(r30)
	  stb       r0, 0x4(r30)
	  lfd       f0, -0x3C18(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x68
	  li        r0, 0x30
	  stb       r0, 0x5(r30)
	  b         .loc_0x394

	.loc_0x68:
	  stfd      f31, 0x28(r1)
	  lis       r0, 0x7FF0
	  lwz       r4, 0x28(r1)
	  rlwinm    r3,r4,0,1,11
	  cmpw      r3, r0
	  beq-      .loc_0x90
	  bge-      .loc_0xD8
	  cmpwi     r3, 0
	  beq-      .loc_0xB4
	  b         .loc_0xD8

	.loc_0x90:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0xA4
	  lwz       r0, 0x2C(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0xAC

	.loc_0xA4:
	  li        r0, 0x1
	  b         .loc_0xDC

	.loc_0xAC:
	  li        r0, 0x2
	  b         .loc_0xDC

	.loc_0xB4:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0xC8
	  lwz       r0, 0x2C(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0xD0

	.loc_0xC8:
	  li        r0, 0x5
	  b         .loc_0xDC

	.loc_0xD0:
	  li        r0, 0x3
	  b         .loc_0xDC

	.loc_0xD8:
	  li        r0, 0x4

	.loc_0xDC:
	  cmpwi     r0, 0x2
	  bgt-      .loc_0x174
	  stfd      f31, 0x20(r1)
	  lis       r0, 0x7FF0
	  lwz       r4, 0x20(r1)
	  rlwinm    r3,r4,0,1,11
	  cmpw      r3, r0
	  beq-      .loc_0x10C
	  bge-      .loc_0x154
	  cmpwi     r3, 0
	  beq-      .loc_0x130
	  b         .loc_0x154

	.loc_0x10C:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0x120
	  lwz       r0, 0x24(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x128

	.loc_0x120:
	  li        r0, 0x1
	  b         .loc_0x158

	.loc_0x128:
	  li        r0, 0x2
	  b         .loc_0x158

	.loc_0x130:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0x144
	  lwz       r0, 0x24(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x14C

	.loc_0x144:
	  li        r0, 0x5
	  b         .loc_0x158

	.loc_0x14C:
	  li        r0, 0x3
	  b         .loc_0x158

	.loc_0x154:
	  li        r0, 0x4

	.loc_0x158:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x168
	  li        r0, 0x4E
	  b         .loc_0x16C

	.loc_0x168:
	  li        r0, 0x49

	.loc_0x16C:
	  stb       r0, 0x5(r30)
	  b         .loc_0x394

	.loc_0x174:
	  li        r0, 0
	  stb       r0, 0x4(r30)
	  lfd       f0, -0x3C18(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x194
	  li        r0, 0x1
	  fneg      f31, f31
	  stb       r0, 0x0(r30)

	.loc_0x194:
	  fmr       f1, f31
	  addi      r3, r1, 0x30
	  bl        0x5A4C
	  lis       r3, 0x5
	  lwz       r4, 0x30(r1)
	  subi      r0, r3, 0x681B
	  mullw     r0, r4, r0
	  lis       r3, 0x431C
	  subi      r3, r3, 0x217D
	  mulhw     r0, r3, r0
	  srawi     r0, r0, 0x12
	  rlwinm    r3,r0,1,31,31
	  add.      r4, r0, r3
	  lis       r3, 0x8022
	  addi      r0, r3, 0x2780
	  addi      r3, r4, 0
	  mr        r5, r0
	  bge-      .loc_0x208
	  neg       r4, r4
	  b         .loc_0x1FC

	.loc_0x1E4:
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0x1F4
	  lfd       f0, 0x0(r5)
	  fmul      f31, f31, f0

	.loc_0x1F4:
	  srawi     r4, r4, 0x1
	  addi      r5, r5, 0x8

	.loc_0x1FC:
	  cmpwi     r4, 0
	  bne+      .loc_0x1E4
	  b         .loc_0x238

	.loc_0x208:
	  ble-      .loc_0x238
	  lfd       f1, -0x3C08(r2)
	  b         .loc_0x22C

	.loc_0x214:
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0x224
	  lfd       f0, 0x0(r5)
	  fmul      f1, f1, f0

	.loc_0x224:
	  srawi     r4, r4, 0x1
	  addi      r5, r5, 0x8

	.loc_0x22C:
	  cmpwi     r4, 0
	  bne+      .loc_0x214
	  fdiv      f31, f31, f1

	.loc_0x238:
	  lfd       f1, -0x3BF8(r2)
	  lfd       f0, -0x3C08(r2)
	  b         .loc_0x24C

	.loc_0x244:
	  fmul      f31, f31, f1
	  addi      r3, r3, 0x1

	.loc_0x24C:
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  beq+      .loc_0x244
	  lfd       f1, -0x3BF0(r2)
	  lfd       f0, -0x3BF8(r2)
	  b         .loc_0x26C

	.loc_0x264:
	  fmul      f31, f31, f1
	  subi      r3, r3, 0x1

	.loc_0x26C:
	  fcmpo     cr0, f31, f0
	  blt+      .loc_0x264
	  lis       r5, 0x6666
	  lfd       f1, -0x3C00(r2)
	  lis       r6, 0x8022
	  addi      r4, r30, 0x5
	  addi      r7, r5, 0x6667
	  addi      r10, r6, 0x27C8
	  lis       r9, 0x4330
	  b         .loc_0x33C

	.loc_0x294:
	  cmpwi     r31, 0x8
	  addi      r12, r31, 0
	  ble-      .loc_0x2A4
	  li        r12, 0x8

	.loc_0x2A4:
	  lbz       r6, 0x4(r30)
	  rlwinm    r0,r12,3,0,28
	  add       r5, r10, r0
	  add       r0, r6, r12
	  stb       r0, 0x4(r30)
	  sub       r31, r31, r12
	  sub       r3, r3, r12
	  lfd       f0, -0x8(r5)
	  add       r4, r4, r12
	  addi      r11, r12, 0x1
	  fmul      f31, f31, f0
	  fctiwz    f0, f31
	  stfd      f0, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stfd      f0, 0x48(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x3C(r1)
	  lwz       r6, 0x4C(r1)
	  stw       r9, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsub      f0, f0, f1
	  fsub      f31, f31, f0
	  b         .loc_0x330

	.loc_0x300:
	  mulhw     r8, r7, r6
	  srawi     r0, r8, 0x2
	  rlwinm    r5,r0,1,31,31
	  add       r0, r0, r5
	  mulli     r0, r0, 0xA
	  sub       r6, r6, r0
	  srawi     r0, r8, 0x2
	  addi      r6, r6, 0x30
	  stb       r6, -0x1(r4)
	  rlwinm    r5,r0,1,31,31
	  add       r6, r0, r5
	  subi      r4, r4, 0x1

	.loc_0x330:
	  subic.    r11, r11, 0x1
	  bne+      .loc_0x300
	  add       r4, r4, r12

	.loc_0x33C:
	  cmpwi     r31, 0
	  bne+      .loc_0x294
	  lha       r5, 0x2(r29)
	  cmpwi     r5, 0x24
	  ble-      .loc_0x354
	  li        r5, 0x24

	.loc_0x354:
	  lbz       r0, 0x4(r30)
	  sub.      r5, r5, r0
	  ble-      .loc_0x38C
	  addi      r6, r5, 0x1
	  li        r0, 0x30
	  b         .loc_0x374

	.loc_0x36C:
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1

	.loc_0x374:
	  subic.    r6, r6, 0x1
	  bne+      .loc_0x36C
	  lbz       r0, 0x4(r30)
	  sub       r3, r3, r5
	  add       r0, r0, r5
	  stb       r0, 0x4(r30)

	.loc_0x38C:
	  extsh     r0, r3
	  sth       r0, 0x2(r30)

	.loc_0x394:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  mtlr      r0
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x68
	  blr
	*/
}
