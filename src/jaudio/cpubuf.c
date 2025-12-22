#include "jaudio/cpubuf.h"
#include "Dolphin/os.h"
#include "jaudio/aictrl.h"
#include "jaudio/rate.h"

static u8 write_buffer = 0;
static u8 read_buffer  = 0;
static u8 dspstatus    = 0;

static s16* dsp_buf[DSPBUF_NUM];

s16* CpubufProcess(DSPBUF_EVENTS event)
{
	u32 i, j;

	switch (event) {
	case DSPBUF_EVENT_INIT:
		write_buffer = 2;
		read_buffer  = 0;
		for (i = 0; i < DSPBUF_NUM; i++) {
			dsp_buf[i] = (s16*)OSAlloc2(JAC_FRAMESAMPLES << 2);
			for (j = 0; j < (JAC_FRAMESAMPLES << 1); j++) {
				dsp_buf[i][j] = 0;
			}

			DCStoreRange(dsp_buf[i], JAC_FRAMESAMPLES << 2);
		}

		dspstatus = 0;
		break;
	case DSPBUF_EVENT_FRAME_END:
		u8 write = write_buffer + 1;

		if (write == DSPBUF_NUM) {
			write = 0;
		}

		if (write == read_buffer) {
			dspstatus = 0;
		} else {
			write_buffer = write;
			dspstatus    = 1;
		}
		break;
	case DSPBUF_EVENT_MIX:
		u8 read = read_buffer + 1;
		if (read == DSPBUF_NUM) {
			read = 0;
		}

		if (read == write_buffer) {
			s16 left  = dsp_buf[read_buffer][(JAC_FRAMESAMPLES / 2) - 1];
			s16 right = dsp_buf[read_buffer][JAC_FRAMESAMPLES - 1];

			for (i = 0; i < JAC_FRAMESAMPLES; i++) {
				dsp_buf[read_buffer][i] = right;
			}

			for (i = JAC_FRAMESAMPLES; i < (JAC_FRAMESAMPLES << 1); i++) {
				dsp_buf[read_buffer][i] = left;
			}

			if (dspstatus == 0) {
				CpubufProcess(DSPBUF_EVENT_FRAME_END);
			}
		} else {
			read_buffer = read;
			if (dspstatus == 0) {
				CpubufProcess(DSPBUF_EVENT_FRAME_END);
			}
		}

		return dsp_buf[read_buffer];
	}

	return NULL;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void MixCpu(s32)
{
	// UNUSED FUNCTION
}

void CpuFrameEnd()
{
	CpubufProcess(DSPBUF_EVENT_FRAME_END);
}
