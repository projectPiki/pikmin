# Pikmin 1
Pikmin 1 (USA Revision 1) disassembly/decompilation to C++/C

```diff
- INFORMATION! -

The ROM this repository builds can be shifted! Meaning you are able to now
add and remove code as you see fit, for modding or research purposes.

- DISCLAIMER -

Shiftability is tentative and not fully verified. Use at your own discretion.
```

It builds the following DOL:
pikmin.usa.1.dol: `sha1: 02204260B7EFE8742D34572E58BA3DFECD92E4E9`

## Building

### Required Tools
* [devkitPro](https://devkitpro.org/wiki/Getting_Started)
* python

### Instructions

* WINDOWS ONLY STEP:
	- Launch msys2 (provided by devkitPro) and run the following commands: 
	
	```
	pacman -S msys2-keyring
	pacman -S git python
	```

* OPTIONAL:
	- Obtain a clean DOL of Pikmin 1 USA 1.01 and place it in the base working directory and rename it to `baserom.dol`.
	
1. Download GC_WII_COMPILERS.zip from (https://files.decomp.dev/compilers_20230715.zip) and extract it to tools/mwcc_compiler/.
2. Run the `make` command.

## Project Organisation
- For each namespace that types and functions are contained within, create a folder. E.g. the structure `Game::GameSystem` will go in include/Game/GameSystem.h.
- The exception is only when adding extra folders becomes useless, for example having to add multiple folders that are empty, you can instead opt for creating a header file with the namespace's definitions inside.
