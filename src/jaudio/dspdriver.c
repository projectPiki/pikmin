#include "jaudio/dspdriver.h"

#include "jaudio/audiothread.h"
#include "jaudio/driverinterface.h"
#include "jaudio/dspinterface.h"
#include "jaudio/rate.h"

#define DSPCH_LENGTH (64)
static dspch_ DSPCH[DSPCH_LENGTH] ATTRIBUTE_ALIGN(32);

static int old_time;
static u32 history[10] = { 0xF4240 };

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
dspch_* GetDSPchannelHandle(u32 idx)
{
	return &DSPCH[idx];
	// UNUSED FUNCTION
}

void InitDSPchannel()
{
	dspch_* chan;
	int i;

	for (i = 0; i < DSPCH_LENGTH; ++i) {
		chan = &DSPCH[i];

		chan->buffer_idx    = i;
		chan->allocState    = DSPCHAN_Free;
		chan->logicalChan   = 0;
		chan->callbackTimer = 0;
		chan->logicalChanCb = NULL;
		chan->prio          = 0;
		chan->releaseTime   = 0;
	}
}

dspch_* AllocDSPchannel(u32 param_1, u32 param_2)
{

	s32 i;
	STACK_PAD_VAR(1);
	u32* p2 = &param_2;
	s32* ip = &i;
	if (param_1 == 0) {

		for (i = 0; i < DSPCH_LENGTH; ++i) {
			if (DSPCH[i].allocState == DSPCHAN_Free) {
				DSPCH[i].allocState  = DSPCHAN_MonoAllocated;
				DSPCH[i].logicalChan = (jc_*)param_2;
				DSPCH[i].prio        = 1;
				DSP_AllocInit(i);
				return &DSPCH[i];
			}
		}
		return NULL;
	}

	for (i = 1; i < DSPCH_LENGTH; i += 2) {

		if (DSPCH[i].allocState != DSPCHAN_Free || DSPCH[i - 1].allocState != DSPCHAN_Free)
			continue;

		DSPCH[i].allocState      = DSPCHAN_StereoRight;
		DSPCH[i - 1].allocState  = DSPCHAN_StereoLeft;
		DSPCH[i].logicalChan     = (jc_*)param_2;
		DSPCH[i - 1].logicalChan = (jc_*)param_2;
		DSP_AllocInit(i);
		DSP_AllocInit(i - 1);
		return &DSPCH[i - 1];
	}
	return NULL;
}

int DeAllocDSPchannel(dspch_* chan, u32 id)
{
	if (chan == NULL) {
		return -1;
	}
	if (chan->logicalChan != (jc_*)id) {
		return -2;
	}

	switch (chan->allocState) {
	case DSPCHAN_MonoAllocated:
	case DSPCHAN_Stopping:
		chan->allocState = DSPCHAN_Free;
		break;
	case DSPCHAN_StereoLeft:
		chan->allocState = DSPCHAN_Free;
		DeAllocDSPchannel(&DSPCH[chan->buffer_idx + 1], id);
		break;
	case DSPCHAN_StereoRight:
		chan->allocState = DSPCHAN_Free;
		DeAllocDSPchannel(&DSPCH[chan->buffer_idx - 1], id);
		break;
	}
	chan->prio          = 0;
	chan->logicalChanCb = NULL;
	chan->logicalChan   = NULL;
	return 0;

	STACK_PAD_VAR(2);
}

dspch_* GetLowerDSPchannel()
{
	u8 max      = 255;
	u32 id      = 0;
	u32 x       = 0;
	u32 i       = 0;
	u8* REF_max = &max;
	u32* REF_id = &id;
	u32* REF_x  = &x;
	u32* REF_i  = &i;

	STACK_PAD_VAR(2);

	for (i; i < DSPCH_LENGTH; i++) {
		if (DSPCH[i].allocState != DSPCHAN_Stopping) {
			if (DSPCH[i].allocState == DSPCHAN_Free) {
				DSPCH[i].prio = 0;
				id            = i;
				break;
			}

			if (DSPCH[i].logicalChanCb) {
				GetDspHandle(DSPCH[i].buffer_idx);
				if (DSPCH[i].prio <= max) {
					DSPchannel_* buf = GetDspHandle(DSPCH[i].buffer_idx);
					if (max != DSPCH[i].prio || (x && (buf->ageCounter >= x || buf->ageCounter == 0))) {
						x   = buf->ageCounter;
						id  = i;
						max = DSPCH[i].prio;
					}
				}
			}
		}
	}

	return &DSPCH[id];
}

dspch_* GetLowerActiveDSPchannel()
{
	u8 a      = 0xFF;
	u32 index = 0;
	u32 c     = 0;
	u32 i;
	DSPchannel_* buf;

	u8* REF_a      = &a;
	u32* REF_index = &index;
	u32* REF_c     = &c;

	for (i = 0; i < DSPCH_LENGTH; ++i) {
		if (DSPCH[i].allocState == DSPCHAN_Stopping || DSPCH[i].allocState == DSPCHAN_Free)
			continue;

		if (DSPCH[i].prio > a)
			continue;

		buf = GetDspHandle(DSPCH[i].buffer_idx);
		if (a == DSPCH[i].prio) {

			if (c == 0)
				continue;
			if (buf->ageCounter < c && buf->ageCounter != 0)
				continue;
		}
		c     = buf->ageCounter;
		index = i;
		a     = DSPCH[i].prio;
	}

	return &DSPCH[index];
}

BOOL ForceStopDSPchannel(dspch_* chan)
{
	dspch_** REF_chan;

	DSPchannel_* buf;

	REF_chan = &chan;
	if (chan->allocState == DSPCHAN_Stopping)
		return FALSE;
	buf = GetDspHandle(chan->buffer_idx);
	if (!buf->enabled)
		return FALSE;
	buf->endRequested = DSP_TRUE;
	chan->allocState  = DSPCHAN_Stopping;
	DSP_FlushChannel(chan->buffer_idx);
	return TRUE;
}

BOOL BreakLowerDSPchannel(u8 param_1)
{
	u8* REF_param_1;

	dspch_* chan;
	DSPchannel_* buf;

	chan        = GetLowerDSPchannel();
	REF_param_1 = &param_1;
	if (chan->prio > param_1)
		return FALSE;
	if (chan->prio == param_1) {
		buf = GetDspHandle(chan->buffer_idx); // UNUSED??
	}
	if (chan->allocState != DSPCHAN_Free) {
		if (chan->logicalChanCb) {
			chan->callbackTimer = chan->logicalChanCb(chan, DSPCHCB_StateChange);
			ForceStopDSPchannel(chan);
			chan->allocState = DSPCHAN_Stopping;
		}
		ForceStopDSPchannel(chan);
	} else {
		return FALSE;
	}
	return TRUE;
}

BOOL BreakLowerActiveDSPchannel(u8 id)
{
	u8* id_ptr   = &id;
	dspch_* chan = GetLowerActiveDSPchannel();

	if (chan->prio > id) {
		return FALSE;
	}

	if (chan->prio == id) {
		GetDspHandle(chan->buffer_idx);
	}

	if (chan->allocState != DSPCHAN_Free) {
		if (chan->logicalChanCb) {
			chan->callbackTimer = chan->logicalChanCb(chan, DSPCHCB_StateChange);
			ForceStopDSPchannel(chan);
			chan->allocState = DSPCHAN_Stopping;
		}
		ForceStopDSPchannel(chan);
	} else {
		return FALSE;
	}

	return TRUE;

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void UpdateDSPchannel(dspch_* chan)
{
	// UNUSED FUNCTION
}

void UpdateDSPchannelAll()
{
	// Calculate delta time since last update
	int tick = OSGetTick();
	u32 old  = tick - old_time;
	old_time = tick;

	// Get subframe index based on DSP sync status and store timing history
	int subframeIdx      = JAC_SUBFRAMES - DspSyncCountCheck();
	history[subframeIdx] = old;

	// Break lower priority DSP channels if timing variance is within tolerance
	if (subframeIdx != 0 && (f32)history[0] / (f32)old < 1.1f) {
		BreakLowerActiveDSPchannel(DSPCHAN_MAX_PRIO - 1);
	}

	// Update all DSP channels
	for (u32 i = 0; i < DSPCH_LENGTH; i++) {
		dspch_* chan     = &DSPCH[i];
		dspch_** chanptr = &chan;

		// Skip free channels
		if (chan->allocState == DSPCHAN_Free) {
			continue;
		}

		DSPchannel_* buf = GetDspHandle(chan->buffer_idx);

		if (buf->done) {
			// Call logical channel for completion notification
			if (chan->logicalChanCb) {
				chan->callbackTimer = chan->logicalChanCb(chan, DSPCHCB_Completion);
			}

			// Reset buffer state and flush the channel
			buf->done    = FALSE;
			buf->enabled = FALSE;
			DSP_FlushChannel(chan->buffer_idx);
			if (chan->allocState == DSPCHAN_Free) {
				continue;
			}
		}

		// Handle aging and release timing
		if (!buf->endRequested) {
			buf->ageCounter++;
			if (buf->ageCounter == chan->releaseTime && chan->logicalChanCb) {
				chan->callbackTimer = chan->logicalChanCb(chan, DSPCHCB_PriorityUpdate);
			}
		}

		if (chan->logicalChanCb) {
			// This is a bit weird, but below is a timer that decrements
			u16* frameDelay  = &chan->callbackTimer;
			u16 currentDelay = *frameDelay;
			if (currentDelay) {
				*frameDelay = currentDelay - 1;
			}

			// Once the timer hits 0, call them back!
			if (*frameDelay == 0) {
				*frameDelay = chan->logicalChanCb(chan, DSPCHCB_NormalUpdate);

				// If the callback returns 0, (STOP) the channel immediately
				if (*frameDelay == 0) {
					buf->done    = FALSE;
					buf->enabled = FALSE;
					__Entry_WaitChannel(1);
					DSP_FlushChannel(chan->buffer_idx);
				}
			}
		}
	}
	EntryCheck_WaitDSPChannel();
	PPCSync();

	STACK_PAD_VAR(9);
}
