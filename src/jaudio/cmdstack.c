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
	cmd->_0C  = NULL;
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL Add_Portcmd(JPorthead_* port, Portcmd_* cmd)
{
	BOOL interrupt = OSDisableInterrupts();

	if (cmd->_0C) {
		OSRestoreInterrupts(interrupt);
		return FALSE;
	}

	if (port->_04) {
		port->_04->_10 = cmd;
	} else {
		port->_00 = cmd;
	}

	port->_04 = cmd;
	cmd->_10  = NULL;
	cmd->_0C  = port;
	OSRestoreInterrupts(interrupt);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
static Portcmd_* Get_Portcmd(JPorthead_* port)
{
	Portcmd_* a = port->_00;
	if (a) {
		port->_00 = port->_00->_10;
		if (port->_00 == NULL) {
			port->_04 = NULL;
		}
		a->_0C = NULL;
	} else {
		a = NULL;
	}

	return a;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
void Cancel_Portcmd(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void Cancel_PortcmdStay(void)
{
	// UNUSED FUNCTION
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
	Portcmd_* p = port->_00;
	while (1) {
		if (!p) {
			break;
		}
		p->func(p->args);

		p = p->_10;
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
	port->_00 = NULL;
	port->_04 = NULL;
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
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void JP_Start1Shot(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
void JP_Stop1Shot(void)
{
	// UNUSED FUNCTION
}
