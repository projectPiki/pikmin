

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005560
 * Size:	000088
 *
 *
 * -schedule off needs to be there so the "lwz r3" in the prologue is positioned correctly, but
 * if scheduling is off, the "crclr" later on is in the wrong position in the body. -schedule
 * on fixes that, but breaks the prologue. Why does this prove an earlier compiler is used?
 *
 * In the file called "CW Embedded PPC 2.3.1.txt" which can be found in early Codewarriors for
 * Dolphin, there is a changelog for earlier versions. Particularly, in "Changes from 2.2",
 * you can find this line:
 * 
 * "* Function Epilogues and Prologues are now scheduled."
 *
 * This means -schedule off applied to prologues/epilogues which exactly fits our problem.
 * This means that Pikmin 1 (USA) uses this elusive earlier compiler.
 */
void myNewTest() {
    gsys.Initialise();

    nodeMgr = new NodeMgr;
    gsys.run(new PlugPikiApp);
    OSPanic("sysBootup.cpp", 0x1d, "End of demo");
}