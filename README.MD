Pikmin 1 (USA Revision 1) disassembly/decompilation

Copy the 1.0 Gamecube compiler folder's mwcceppc.exe and name the copy "mwcceppc_profile.exe".
Place the copy in the same folder as the original.

Hex edit mwcceppc_profile.exe as follows:

set offset 0x333E2 to 0x01 (normally 0x00)

This edit modifies the compiler in such a way as to approximate older scheduling models.
In this case, the epilogue should remain unscheduled.

tool/frank.py cleans up the output.
