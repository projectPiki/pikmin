#include "jaudio/cmdstack.h"
#include "Dolphin/os.h"
#include "jaudio/playercall.h"

JPorthead_ cmd_once;
JPorthead_ cmd_stay;

/**
 * @TODO: Documentation
 */
void Add_PortcmdOnce(Portcmd_* cmd)
{
	Add_Portcmd(&cmd_once, cmd);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028 (Matching by size)
 */
void Add_PortcmdStay(Portcmd_* cmd)
{
	Add_Portcmd(&cmd_stay, cmd);
}

/**
 * @TODO: Documentation
 */
BOOL Set_Portcmd(Portcmd_* cmd, Portfunc func, Portargs_* args)
{
	cmd->func = func;
	cmd->args = args;
	cmd->mOwnerPort = NULL;
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL Add_Portcmd(JPorthead_* port, Portcmd_* cmd)
{
	BOOL interrupt = OSDisableInterrupts();

	if (cmd->mOwnerPort) {
		OSRestoreInterrupts(interrupt);
		return FALSE;
	}

	if (port->mTailCmd) {
		port->mTailCmd->mNextCmd = cmd;
	} else {
		port->mHeadCmd = cmd;
	}

	port->mTailCmd = cmd;
	cmd->mNextCmd  = NULL;
	cmd->mOwnerPort = port;
	OSRestoreInterrupts(interrupt);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
static Portcmd_* Get_Portcmd(JPorthead_* port)
{
	Portcmd_* cmd = port->mHeadCmd;
	if (cmd) {
		port->mHeadCmd = port->mHeadCmd->mNextCmd;
		if (port->mHeadCmd == NULL) {
			port->mTailCmd = NULL;
		}
		cmd->mOwnerPort = NULL;
	} else {
		cmd = NULL;
	}

	return cmd;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
void Cancel_Portcmd(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void Cancel_PortcmdStay(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
int Jac_Portcmd_Proc_Once(JPorthead_* port)
{
	Portcmd_* p;
	while (1) {
		p = Get_Portcmd(port);
		if (!p) {
			break;
		}
		p->func(p->args);
	}
	return 0;
}

/**
 * @TODO: Documentation
 */
int Jac_Portcmd_Proc_Stay(JPorthead_* port)
{
	Portcmd_* p = port->mHeadCmd;
	while (1) {
		if (!p) {
			break;
		}
		p->func(p->args);

		p = p->mNextCmd;
	}
	return 0;
}

/**
 * @TODO: Documentation
 */
static s32 Portcmd_Main(void* a)
{
	Jac_Portcmd_Proc_Once(&cmd_once);
	Jac_Portcmd_Proc_Stay(&cmd_stay);
	return 0;
}

/**
 * @TODO: Documentation
 */
void Jac_Porthead_Init(JPorthead_* port)
{
	port->mHeadCmd = NULL;
	port->mTailCmd = NULL;
}

/**
 * @TODO: Documentation
 */
void Jac_Portcmd_Init(void)
{
	Jac_Porthead_Init(&cmd_once);
	Jac_Porthead_Init(&cmd_stay);
	Jac_RegisterPlayerCallback(Portcmd_Main, 0);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
void JP_Pitch1Shot(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void JP_Start1Shot(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
void JP_Stop1Shot(void)
{
	TRAP_UNIMPLEMENTED;
}
