Pikmin 1 (USA Revision 1) disassembly/decompilation

Copy the 1.2.5 Gamecube compiler folder and name the copy "1.2.5e".
Place the copy in a new folder as the original.

Hex edit the 1.2.5e mwcceppc.exe as follows:
change offset 0x35092 to 0x01 (normally 0x00)

This edit modifies the compiler in such a way as to approximate older scheduling models.
In this case, the epilogue should remain unscheduled.

tool/frank.py cleans up the output.
