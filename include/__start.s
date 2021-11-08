Analyzing: C:\Users\jupit\AppData\Local\Temp\__start.o
Header idenfication: 0x7f, ELF, 32 bit MSB v1
    type:           1, machine:         20
    version: 00000001, entry:     00000000, phoff:  00000000
    shoff:   000006b0, flags:     80000000, ehsize:       52, phentsize:  0
    phnum:          0, shentsize:       40, shnum:         9, shstrndx:  7


==> .shstrtab
    [  1]	.init
    [  7]	.mwcats.init
    [ 20]	.rela.init
    [ 31]	.rela.mwcats.init
    [ 49]	.symtab
    [ 57]	.strtab
    [ 65]	.shstrtab
    [ 75]	.comment

==> .init [1]: Section Header
    type:    00000001, flags:  00000006
    address: 00000000, offset: 00000034, size: 000001cc
    link:    00000000, info:   00000000, alignment: 4, entry size: 0


==> .mwcats.init [2]: Section Header
    type:    ca2a82c2, flags:  00000000
    address: 00000000, offset: 00000200, size: 00000008
    link:    00000001, info:   00000000, alignment: 4, entry size: 1


==> .rela.init [3]: Section Header
    type:    00000004, flags:  00000000
    address: 00000000, offset: 00000208, size: 00000114
    link:    00000005, info:   00000001, alignment: 4, entry size: 12


==> .rela.mwcats.init [4]: Section Header
    type:    00000004, flags:  00000000
    address: 00000000, offset: 0000031c, size: 0000000c
    link:    00000005, info:   00000002, alignment: 4, entry size: 12


==> .symtab [5]: Section Header
    type:    00000002, flags:  00000000
    address: 00000000, offset: 00000328, size: 00000170
    link:    00000006, info:   00000005, alignment: 4, entry size: 16


==> .strtab [6]: Section Header
    type:    00000003, flags:  00000000
    address: 00000000, offset: 00000498, size: 000000df
    link:    00000000, info:   00000000, alignment: 1, entry size: 1


==> .shstrtab [7]: Section Header
    type:    00000003, flags:  00000000
    address: 00000000, offset: 00000577, size: 00000054
    link:    00000000, info:   00000000, alignment: 1, entry size: 1


==> .comment [8]: Section Header
    type:    00000001, flags:  00000000
    address: 00000000, offset: 000005cb, size: 000000e4
    link:    00000000, info:   00000000, alignment: 1, entry size: 1


==> .strtab
    [  1]	__start.c
    [ 11]	__init_registers
    [ 28]	__start
    [ 36]	__init_registers
    [ 53]	__init_data
    [ 65]	_stack_addr
    [ 77]	_SDA_BASE_
    [ 88]	_SDA2_BASE_
    [ 100]	_rom_copy_info
    [ 115]	_bss_init_info
    [ 130]	__init_hardware
    [ 146]	InitMetroTRK
    [ 159]	DBInit
    [ 166]	OSInit
    [ 173]	__init_user
    [ 185]	main
    [ 190]	exit
    [ 195]	memcpy
    [ 202]	__flush_cache
    [ 216]	memset

==> .symtab
    entry  spndx   value      size   bind   type  other    shndx         name
    [   0]     0   00000000      0   LOC    NULL      0    UND           
    [   1]     1   00000000      0   LOC    FILE      0    ABS           __start.c
    [   2]     0   00000000      0   LOC    SECT      0    .init         .init
    [   3]     0   00000000      0   LOC    SECT      0    .mwcats.init  .mwcats.init
    [   4]    11   000000f0     28   LOC    FUNC      0    .init         __init_registers
    [   5]    28   00000000    240   WEAK   FUNC      0    .init         __start
    [   6]    36   00000000      0   GLOB   NULL      0    UND           __init_registers
    [   7]    53   0000010c    192   GLOB   FUNC      0    .init         __init_data
    [   8]    65   00000000      0   GLOB   NULL      0    UND           _stack_addr
    [   9]    77   00000000      0   GLOB   NULL      0    UND           _SDA_BASE_
    [  10]    88   00000000      0   GLOB   NULL      0    UND           _SDA2_BASE_
    [  11]   100   00000000      0   GLOB   NULL      0    UND           _rom_copy_info
    [  12]   115   00000000      0   GLOB   NULL      0    UND           _bss_init_info
    [  13]   130   00000000      0   GLOB   NULL      0    UND           __init_hardware
    [  14]   146   00000000      0   GLOB   NULL      0    UND           InitMetroTRK
    [  15]   159   00000000      0   GLOB   NULL      0    UND           DBInit
    [  16]   166   00000000      0   GLOB   NULL      0    UND           OSInit
    [  17]   173   00000000      0   GLOB   NULL      0    UND           __init_user
    [  18]   185   00000000      0   GLOB   NULL      0    UND           main
    [  19]   190   00000000      0   GLOB   NULL      0    UND           exit
    [  20]   195   00000000      0   GLOB   NULL      0    UND           memcpy
    [  21]   202   00000000      0   GLOB   NULL      0    UND           __flush_cache
    [  22]   216   00000000      0   GLOB   NULL      0    UND           memset

==> .rela.init
    entry  offset   addend   type name(symbol id)
    [   0] 00000000 00000000   10 __init_registers(6)
    [   1] 00000004 00000000   10 __init_hardware(13)
    [   2] 00000018 00000000   10 __init_data(7)
    [   3] 0000005e 00000000    6 InitMetroTRK(14)
    [   4] 00000062 00000000    4 InitMetroTRK(14)
    [   5] 000000d4 00000000   10 DBInit(15)
    [   6] 000000d8 00000000   10 OSInit(16)
    [   7] 000000dc 00000000   10 __init_user(17)
    [   8] 000000e8 00000000   10 main(18)
    [   9] 000000ec 00000000   10 exit(19)
    [  10] 000000f2 00000000    5 _stack_addr(8)
    [  11] 000000f6 00000000    4 _stack_addr(8)
    [  12] 000000fa 00000000    5 _SDA2_BASE_(10)
    [  13] 000000fe 00000000    4 _SDA2_BASE_(10)
    [  14] 00000102 00000000    5 _SDA_BASE_(9)
    [  15] 00000106 00000000    4 _SDA_BASE_(9)
    [  16] 00000126 00000000    6 _rom_copy_info(11)
    [  17] 0000012a 00000000    4 _rom_copy_info(11)
    [  18] 00000160 00000000   10 memcpy(20)
    [  19] 0000016c 00000000   10 __flush_cache(21)
    [  20] 0000017a 00000000    6 _bss_init_info(12)
    [  21] 0000017e 00000000    4 _bss_init_info(12)
    [  22] 000001a4 00000000   10 memset(22)

==> .init

Hunk:	Kind=HUNK_GLOBAL_CODE     Name="__start"  Size=240
00000000: 48000001  bl       __init_registers
00000004: 48000001  bl       __init_hardware
00000008: 3800FFFF  li       r0,-1
0000000C: 9421FFF8  stwu     rsp,-8(rsp)
00000010: 90010004  stw      r0,4(rsp)
00000014: 90010000  stw      r0,0(rsp)
00000018: 48000001  bl       __init_data
0000001C: 38000000  li       r0,0
00000020: 3CC08000  lis      r6,-32768
00000024: 38C60044  addi     r6,r6,68
00000028: 90060000  stw      r0,0(r6)
0000002C: 3CC08000  lis      r6,-32768
00000030: 38C600F4  addi     r6,r6,244
00000034: 80C60000  lwz      r6,0(r6)
00000038: 28060000  cmplwi   r6,0x0000
0000003C: 41820030  beq      *+48                    ; 0x0000006C
00000040: 80E6000C  lwz      r7,12(r6)
00000044: 38A00000  li       r5,0
00000048: 28070002  cmplwi   r7,0x0002
0000004C: 41820010  beq      *+16                    ; 0x0000005C
00000050: 28070003  cmplwi   r7,0x0003
00000054: 40820018  bne      *+24                    ; 0x0000006C
00000058: 38A00001  li       r5,1
0000005C: 3CC00000  lis      r6,InitMetroTRK@ha
00000060: 38C60000  addi     r6,r6,InitMetroTRK@l
00000064: 7CC803A6  mtlr     r6
00000068: 4E800021  blrl
0000006C: 3CC08000  lis      r6,-32768
00000070: 38C600F4  addi     r6,r6,244
00000074: 80A60000  lwz      r5,0(r6)
00000078: 28050000  cmplwi   r5,0x0000
0000007C: 41A20050  beq+     *+80                    ; 0x000000CC
00000080: 80C50008  lwz      r6,8(r5)
00000084: 28060000  cmplwi   r6,0x0000
00000088: 41A20044  beq+     *+68                    ; 0x000000CC
0000008C: 7CC53214  add      r6,r5,r6
00000090: 81C60000  lwz      r14,0(r6)
00000094: 280E0000  cmplwi   r14,0x0000
00000098: 41820034  beq      *+52                    ; 0x000000CC
0000009C: 39E60004  addi     r15,r6,4
000000A0: 7DC903A6  mtctr    r14
000000A4: 38C60004  addi     r6,r6,4
000000A8: 80E60000  lwz      r7,0(r6)
000000AC: 7CE72A14  add      r7,r7,r5
000000B0: 90E60000  stw      r7,0(r6)
000000B4: 4200FFF0  bdnz     *-16                    ; 0x000000A4
000000B8: 3CA08000  lis      r5,-32768
000000BC: 38A50034  addi     r5,r5,52
000000C0: 55E70034  clrrwi   r7,r15,5
000000C4: 90E50000  stw      r7,0(r5)
000000C8: 4800000C  b        *+12                    ; 0x000000D4
000000CC: 39C00000  li       r14,0
000000D0: 39E00000  li       r15,0
000000D4: 48000001  bl       DBInit
000000D8: 48000001  bl       OSInit
000000DC: 48000001  bl       __init_user
000000E0: 7DC37378  mr       r3,r14
000000E4: 7DE47B78  mr       r4,r15
000000E8: 48000001  bl       main
000000EC: 48000000  b        exit

Hunk:	Kind=HUNK_LOCAL_CODE     Name="__init_registers"  Size=28
000000F0: 3C200000  lis      rsp,_stack_addr@h
000000F4: 60210000  ori      rsp,rsp,_stack_addr@l
000000F8: 3C400000  lis      r2,_SDA2_BASE_@h
000000FC: 60420000  ori      r2,r2,_SDA2_BASE_@l
00000100: 3DA00000  lis      r13,_SDA_BASE_@h
00000104: 61AD0000  ori      r13,r13,_SDA_BASE_@l
00000108: 4E800020  blr

Hunk:	Kind=HUNK_GLOBAL_CODE     Name="__init_data"  Size=192
0000010C: 7C0802A6  mflr     r0
00000110: 90010004  stw      r0,4(rsp)
00000114: 9421FFE8  stwu     rsp,-24(rsp)
00000118: 93E10014  stw      r31,20(rsp)
0000011C: 93C10010  stw      r30,16(rsp)
00000120: 93A1000C  stw      r29,12(rsp)
00000124: 3C600000  lis      r3,_rom_copy_info@ha
00000128: 38030000  addi     r0,r3,_rom_copy_info@l
0000012C: 7C1D0378  mr       r29,r0
00000130: 48000004  b        *+4                     ; 0x00000134
00000134: 48000004  b        *+4                     ; 0x00000138
00000138: 83DD0008  lwz      r30,8(r29)
0000013C: 281E0000  cmplwi   r30,0x0000
00000140: 41820038  beq      *+56                    ; 0x00000178
00000144: 809D0000  lwz      r4,0(r29)
00000148: 83FD0004  lwz      r31,4(r29)
0000014C: 41820024  beq      *+36                    ; 0x00000170
00000150: 7C1F2040  cmplw    r31,r4
00000154: 4182001C  beq      *+28                    ; 0x00000170
00000158: 7FE3FB78  mr       r3,r31
0000015C: 7FC5F378  mr       r5,r30
00000160: 48000001  bl       memcpy
00000164: 7FE3FB78  mr       r3,r31
00000168: 7FC4F378  mr       r4,r30
0000016C: 48000001  bl       __flush_cache
00000170: 3BBD000C  addi     r29,r29,12
00000174: 4BFFFFC4  b        *-60                    ; 0x00000138
00000178: 3C600000  lis      r3,_bss_init_info@ha
0000017C: 38030000  addi     r0,r3,_bss_init_info@l
00000180: 7C1D0378  mr       r29,r0
00000184: 48000004  b        *+4                     ; 0x00000188
00000188: 48000004  b        *+4                     ; 0x0000018C
0000018C: 80BD0004  lwz      r5,4(r29)
00000190: 28050000  cmplwi   r5,0x0000
00000194: 4182001C  beq      *+28                    ; 0x000001B0
00000198: 807D0000  lwz      r3,0(r29)
0000019C: 4182000C  beq      *+12                    ; 0x000001A8
000001A0: 38800000  li       r4,0
000001A4: 48000001  bl       memset
000001A8: 3BBD0008  addi     r29,r29,8
000001AC: 4BFFFFE0  b        *-32                    ; 0x0000018C
000001B0: 8001001C  lwz      r0,28(rsp)
000001B4: 83E10014  lwz      r31,20(rsp)
000001B8: 83C10010  lwz      r30,16(rsp)
000001BC: 7C0803A6  mtlr     r0
000001C0: 83A1000C  lwz      r29,12(rsp)
000001C4: 38210018  addi     rsp,rsp,24
000001C8: 4E800020  blr

==> .rela.mwcats.init
    entry  offset   addend   type name(symbol id)
    [   0] 00000004 00000000    1 __init_data(7)

==> .mwcats.init
    type size     addr     procexits
       2 00c0     00000000         0

==> .comment
MagicWord: CodeWarrior
Comment section version: 8
Compiler version: 2.3.0
CW Compiler generated
Pooled data: true
PPC EABI compliant
FP Support: Hardware
Processor: Unknown CPU
