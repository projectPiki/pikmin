#include "jaudio/jamosc.h"
#include "jaudio/jammain_2.h"

s16 VIB_TABLE[] = { 0, 0, 0, 0, 20, 0x7fff, 0, 20, 0, 0, 0x14, 0xc000, 0, 20, 0, 13, 0, 1 };
s16 TRE_TABLE[] = { 0, 0, 0x7fff, 0, 20, 0, 0, 20, 0x8001, 0, 0x14, 0, 0, 0x14, 0x7fff, 13, 0, 1 };
s16 REL_TABLE[] = { 0, 10, 0, 15, 1, 0 };

Osc_definition VIBRATO_DEF  = { 1, 0.8f, VIB_TABLE, VIB_TABLE, 0.0f, 1.0f };
Osc_definition TREMOLO_DEF  = { 0, 1.0f, TRE_TABLE, TRE_TABLE, 0.0f, 1.0f };
Osc_definition ENVELOPE_DEF = { 0, 1.0f, nullptr, REL_TABLE, 1.0f, 0.0f };

s16 ADS_TABLE[]         = { 0, 0, 0x7fff, 0, 0, 0x7fff, 0, 0, 0, 14, 0, 0 };
Osc_definition ADSR_DEF = { 0, 1.0f, nullptr, nullptr, 1.0f, 0.0f };
Osc_definition OSC_DEF  = { 0, 1.0f, nullptr, REL_TABLE, 1.0f, 0.0f };

/*
 * --INFO--
 * Address:	80014CA0
 * Size:	000090
 */
void Osc_Update_Param(seqp_* track, u8 id, f32 val)
{
	u8* REF_param_1 = &id;
	f32* REF_val    = &val;

	switch (id) {
	case 6:
		track->_340[0]._10 = val;
		break;
	case 7:
		track->_340[0]._04 = val;
		break;
	case 8:
		track->_340[0]._14 = val;
		break;
	case 9:
		track->_340[1]._10 = val;
		break;
	case 10:
		track->_340[1]._04 = val;
		break;
	case 11:
		track->_340[1]._14 = val;
		break;
	}
}

/*
 * --INFO--
 * Address:	80014D40
 * Size:	00003C
 */
void Osc_Setup_Vibrato(seqp_* track, u8 id)
{
	track->_340[id] = VIBRATO_DEF;
}

/*
 * --INFO--
 * Address:	80014D80
 * Size:	00003C
 */
void Osc_Setup_Tremolo(seqp_* track, u8 id)
{
	track->_340[id] = TREMOLO_DEF;
}

/*
 * --INFO--
 * Address:	80014DC0
 * Size:	000064
 */
void Osc_Setup_Simple(seqp_* track, u8 id)
{
	switch (id) {
	case 0:
		Osc_Setup_Vibrato(track, 1);
		break;
	case 1:
		Osc_Setup_Tremolo(track, 0);
		break;
	case 2:
		Osc_Setup_Tremolo(track, 1);
		break;
	}
}

/*
 * --INFO--
 * Address:	80014E40
 * Size:	000010
 */
void Osc_Clear_Overwrite(seqp_* track)
{
	track->_370[0] = 15;
	track->_370[1] = 15;
}

/*
 * --INFO--
 * Address:	80014E60
 * Size:	00004C
 */
void Osc_Init_Env(seqp_* track)
{
	track->_340[0] = ENVELOPE_DEF;

	Osc_Clear_Overwrite(track);
}

/*
 * --INFO--
 * Address:	80014EC0
 * Size:	000094
 */
void Osc_Setup_SimpleEnv(seqp_* track, u8 id, u32 val)
{
	u32 badCompiler[2];
	switch (id) {
	case 0:
		track->_340[0]     = ENVELOPE_DEF;
		track->_340[0]._08 = (s16*)Jam_OfsToAddr(track, val);
		break;

	case 1:
		track->_340[0]._0C = (s16*)Jam_OfsToAddr(track, val);
		break;
	}
}

/*
 * --INFO--
 * Address:	80014F60
 * Size:	0000B0
 */
void Osc_Setup_ADSR(seqp_* track, s16* addr)
{
	track->_340[0] = ADSR_DEF;

	track->_340[0]._08 = track->_372;
	track->_340[0]._0C = track->_38A;

	for (int i = 0; i < 12; i++) {
		track->_372[i] = ADS_TABLE[i];
	}

	for (int i = 0; i < 6; i++) {
		track->_38A[i] = REL_TABLE[i];
	}

	track->_372[1] = addr[0];
	track->_372[4] = addr[1];
	track->_372[7] = addr[2];
	track->_372[8] = addr[3];
	track->_38A[1] = addr[4];
}

/*
 * --INFO--
 * Address:	80015020
 * Size:	00010C
 */
void Osc_Setup_Full(seqp_* track, u8 flag, u32 offs1, u32 offs2)
{
	u32 a   = flag & 0xF;
	u32 b   = flag & 0x40;
	u32 idx = (flag >> 4) & 0x1;
	u32 c   = flag & 0x20;
	u32 d   = flag & 0x80;
	if (d) {
		track->_340[idx] = ENVELOPE_DEF;

		track->_340[idx]._00 = a;
		switch (a) {
		case 1:
			track->_340[idx]._14 = 1.0f;
			break;
		}
	}

	if (b) {
		if (offs1 == 0) {
			track->_340[idx]._08 = nullptr;
		}
		track->_340[idx]._08 = (s16*)Jam_OfsToAddr(track, offs1);
	}

	if (c) {
		if (offs2 == 0) {
			track->_340[idx]._0C = REL_TABLE;
		}
		track->_340[idx]._0C = (s16*)Jam_OfsToAddr(track, offs2);
	}
}
