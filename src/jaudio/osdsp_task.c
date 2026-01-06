#include "Dolphin/dsp.h"
#include "Dolphin/os.h"
#include "jaudio/dspproc.h"

#if defined(VERSION_GPIP01_00)

static vu8 DSP_prior_yield;
static int AUDIO_UPDATE_REQUEST;
static u32 sync_stack[3];

static void Dsp_Update_Request();

#ifdef __cplusplus
extern "C" {
void Console_printf(char*, ...);
#endif // ifdef __cplusplus

/**
 * @TODO: Documentation
 */
void __DSPHandler(__OSInterrupt interrupt, OSContext* context)
{
	OSContext funcContext;
	int stack[3];

	__DSPRegs[5] = ((u16)(__DSPRegs[5]) & ~0x28) | 0x80;

	if (DSP_prior_yield == 1 || DSP_prior_yield == 0) {
		__DSP_curr_task = DSP_prior_task;
	}

	while (DSPCheckMailFromDSP() == 0)
		;
	u32 mail = DSPReadMailFromDSP();

	if ((__DSP_curr_task->flags & 2) && mail == 0xDCD10002) {
		mail = 0xDCD10003;
	}

	switch (mail) {
	case 0xDCD10000:
	{
		__DSP_curr_task->state = 1;
		if (__DSP_curr_task == DSP_prior_task) {
			DSP_prior_yield = 1;
		}
		if (__DSP_curr_task->init_cb != nullptr) {
			__DSP_curr_task->init_cb(__DSP_curr_task);
		}
		break;
	}
	case 0xDCD10001:
	{
		__DSP_curr_task->state = 1;
		if (__DSP_curr_task == DSP_prior_task) {
			DSP_prior_yield = 1;
			Dsp_Update_Request();
		}
		if (__DSP_curr_task->res_cb != nullptr) {
			__DSP_curr_task->res_cb(__DSP_curr_task);
		}
		Console_printf("Audio Resumed\n");
		break;
	}
	case 0xDCD10002:
	{
		Console_printf("Yield Handler\n");
		DSPSendMailToDSP(0xCDD10001);
		while (DSPCheckMailToDSP() != 0)
			;
		__DSP_curr_task->state = 2;
		if (__DSP_curr_task->next == nullptr && AUDIO_UPDATE_REQUEST) {
			__DSP_exec_task(__DSP_curr_task, DSP_prior_task);
			AUDIO_UPDATE_REQUEST = 0;
			__DSP_curr_task      = DSP_prior_task;
		} else {
			__DSP_exec_task(__DSP_curr_task, __DSP_curr_task->next);
			__DSP_curr_task = __DSP_curr_task->next;
		}
		break;
	}
	case 0xDCD10003:
	{
		Console_printf("Done DSP Task  %x \n"); // doesnt actually have another param, very cool
		if (__DSP_curr_task->done_cb) {
			__DSP_curr_task->done_cb(__DSP_curr_task);
		}
		DSPSendMailToDSP(0xCDD10001);
		while (DSPCheckMailToDSP() != 0)
			;
		__DSP_curr_task->state = 3;
		if (__DSP_curr_task->next == nullptr) {
			__DSP_exec_task(nullptr, DSP_prior_task);
			__DSP_remove_task(__DSP_curr_task);
			__DSP_curr_task = DSP_prior_task;
		} else {
			__DSP_exec_task(nullptr, __DSP_curr_task->next);
			__DSP_curr_task = __DSP_curr_task->next;
			__DSP_remove_task(__DSP_curr_task->prev);
		}
		break;
	}
	case 0xDCD10004:
	{
		if (__DSP_curr_task->req_cb != nullptr) {
			__DSP_curr_task->req_cb(__DSP_curr_task);
		}
		break;
	}
	case 0xDCD10005:
	{
		if (__DSP_first_task == nullptr || AUDIO_UPDATE_REQUEST) {
			DSPSendMailToDSP(0xCDD10003);
			while (DSPCheckMailToDSP() != 0)
				;
			AUDIO_UPDATE_REQUEST = 0;
			__DSP_curr_task      = DSP_prior_task;
			Dsp_Update_Request();
		} else {
			Console_printf("Audio Yield Start\n");
			DSP_prior_yield = 3;
			DSPSendMailToDSP(0xCDD10001);
			while (DSPCheckMailToDSP() != 0)
				;
			__DSP_exec_task(DSP_prior_task, __DSP_first_task);
			__DSP_curr_task = __DSP_first_task;
			Console_printf("Audio Yield Finish\n");
		}
		break;
	}
	default:
	{
		OSErrorLine(0x10b, "__DSPHandler(): Unknown msg from DSP 0x%08X - task sync failed!\n", mail);
	}
	}
}
END_SCOPE_EXTERN_C

/**
 * @TODO: Documentation
 */
void DsyncFrame2(u32 subframes, u32 dspbufStart, u32 dspbufEnd)
{
	if (DSP_prior_yield != TRUE) {
		Console_printf("Yield中です\n");
		sync_stack[0]        = subframes;
		sync_stack[1]        = dspbufStart;
		sync_stack[2]        = dspbufEnd;
		AUDIO_UPDATE_REQUEST = TRUE;
	} else {
		DsyncFrame(subframes, dspbufStart, dspbufEnd);
		AUDIO_UPDATE_REQUEST = FALSE;
	}
}

/**
 * @TODO: Documentation
 */
static void Dsp_Update_Request()
{
	if (AUDIO_UPDATE_REQUEST != 0) {
		DsyncFrame2(sync_stack[0], sync_stack[1], sync_stack[2]);
	}
}

/**
 * @TODO: Documentation
 */
BOOL Dsp_Running_Check()
{
	return (DSP_prior_yield != TRUE) ? FALSE : TRUE;
}

/**
 * @TODO: Documentation
 */
void Dsp_Running_Start()
{
	DSP_prior_yield = 1;
}

#endif
