Pikmin 1 (USA Revision 1) disassembly/decompilation

Copy the 1.0 Gamecube compiler folder and name the new folder 1.0e.

Hex edit the copied mwcceppc.exe as follows:

set byte at offset 0xA6941 to 0x0 (normally 0x1)

set 0xA6CFF to 0xA6D03 as 0x90 (normally 0x25 0x10 0x00 0x00 0x00)

These edits modify the compiler in such a way as to approximate older scheduling models.
In this case, the epilogue should remain unscheduled.
