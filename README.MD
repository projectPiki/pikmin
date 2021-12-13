# Pikmin 1
Pikmin 1 (USA Revision 1) disassembly/decompilation

## Building
This edited compiler modifies the epilogue in such a way as to approximate older scheduling models.

In this case, the epilogue should remain unscheduled.

tool/frank.py cleans up the output.

### Required Tools
* [devkitPro](https://devkitpro.org/wiki/Getting_Started)
* gcc

### Instructions

* WINDOWS ONLY STEP:
	- Launch msys2(Provided by devkitPro) and run the command `pacman -S gcc`.

* OPTIONAL:
	- Obtain a clean DOL of Pikmin 1 USA 1.01 and place it in the base working directory and rename it to `baserom.dol`.
	
1. Download GC_WII_COMPILERS.zip from (https://cdn.discordapp.com/attachments/727918646525165659/917185027656286218/GC_WII_COMPILERS.zip) and extract it to tools/mwcc_compiler/.
2. Run the `make` command.

## Project Organisation
- For each namespace that types and functions are contained within, create a folder. E.g. the structure `Game::GameSystem` will go in include/Game/GameSystem.h.
- The exception is only when adding extra folders becomes useless, for example having to add multiple folders that are empty, you can instead opt for creating a header file with the namespace's definitions inside.
