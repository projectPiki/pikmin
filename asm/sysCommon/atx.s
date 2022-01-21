.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global close__9AtxStreamFv
close__9AtxStreamFv:
/* 800438EC 0004084C  7C 08 02 A6 */	mflr r0
/* 800438F0 00040850  7C 64 1B 78 */	mr r4, r3
/* 800438F4 00040854  90 01 00 04 */	stw r0, 4(r1)
/* 800438F8 00040858  94 21 FF F8 */	stwu r1, -8(r1)
/* 800438FC 0004085C  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 80043900 00040860  80 65 02 78 */	lwz r3, 0x278(r5)
/* 80043904 00040864  81 83 00 00 */	lwz r12, 0(r3)
/* 80043908 00040868  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8004390C 0004086C  7D 88 03 A6 */	mtlr r12
/* 80043910 00040870  4E 80 00 21 */	blrl 
/* 80043914 00040874  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80043918 00040878  38 21 00 08 */	addi r1, r1, 8
/* 8004391C 0004087C  7C 08 03 A6 */	mtlr r0
/* 80043920 00040880  4E 80 00 20 */	blr 

.global open__9AtxStreamFPci
open__9AtxStreamFPci:
/* 80043924 00040884  7C 08 02 A6 */	mflr r0
/* 80043928 00040888  90 01 00 04 */	stw r0, 4(r1)
/* 8004392C 0004088C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80043930 00040890  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80043934 00040894  3B E4 00 00 */	addi r31, r4, 0
/* 80043938 00040898  93 C1 00 20 */	stw r30, 0x20(r1)
/* 8004393C 0004089C  3B C3 00 00 */	addi r30, r3, 0
/* 80043940 000408A0  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 80043944 000408A4  80 06 02 78 */	lwz r0, 0x278(r6)
/* 80043948 000408A8  28 00 00 00 */	cmplwi r0, 0
/* 8004394C 000408AC  7C 03 03 78 */	mr r3, r0
/* 80043950 000408B0  40 82 00 0C */	bne lbl_8004395C
/* 80043954 000408B4  38 60 00 00 */	li r3, 0
/* 80043958 000408B8  48 00 00 8C */	b lbl_800439E4
lbl_8004395C:
/* 8004395C 000408BC  81 83 00 00 */	lwz r12, 0(r3)
/* 80043960 000408C0  7F C4 F3 78 */	mr r4, r30
/* 80043964 000408C4  81 8C 00 08 */	lwz r12, 8(r12)
/* 80043968 000408C8  7D 88 03 A6 */	mtlr r12
/* 8004396C 000408CC  4E 80 00 21 */	blrl 
/* 80043970 000408D0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80043974 000408D4  40 82 00 18 */	bne lbl_8004398C
/* 80043978 000408D8  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8004397C 000408DC  38 00 00 00 */	li r0, 0
/* 80043980 000408E0  38 60 00 00 */	li r3, 0
/* 80043984 000408E4  90 04 02 78 */	stw r0, 0x278(r4)
/* 80043988 000408E8  48 00 00 5C */	b lbl_800439E4
lbl_8004398C:
/* 8004398C 000408EC  7F C3 F3 78 */	mr r3, r30
/* 80043990 000408F0  81 9E 00 04 */	lwz r12, 4(r30)
/* 80043994 000408F4  38 9F 00 00 */	addi r4, r31, 0
/* 80043998 000408F8  38 A0 00 04 */	li r5, 4
/* 8004399C 000408FC  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 800439A0 00040900  7D 88 03 A6 */	mtlr r12
/* 800439A4 00040904  4E 80 00 21 */	blrl 
/* 800439A8 00040908  80 7E 00 08 */	lwz r3, 8(r30)
/* 800439AC 0004090C  81 83 00 04 */	lwz r12, 4(r3)
/* 800439B0 00040910  81 8C 00 08 */	lwz r12, 8(r12)
/* 800439B4 00040914  7D 88 03 A6 */	mtlr r12
/* 800439B8 00040918  4E 80 00 21 */	blrl 
/* 800439BC 0004091C  28 03 FF FF */	cmplwi r3, 0xffff
/* 800439C0 00040920  40 82 00 0C */	bne lbl_800439CC
/* 800439C4 00040924  38 60 00 00 */	li r3, 0
/* 800439C8 00040928  48 00 00 1C */	b lbl_800439E4
lbl_800439CC:
/* 800439CC 0004092C  7F C3 F3 78 */	mr r3, r30
/* 800439D0 00040930  81 9E 00 04 */	lwz r12, 4(r30)
/* 800439D4 00040934  81 8C 00 54 */	lwz r12, 0x54(r12)
/* 800439D8 00040938  7D 88 03 A6 */	mtlr r12
/* 800439DC 0004093C  4E 80 00 21 */	blrl 
/* 800439E0 00040940  38 60 00 01 */	li r3, 1
lbl_800439E4:
/* 800439E4 00040944  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800439E8 00040948  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800439EC 0004094C  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800439F0 00040950  38 21 00 28 */	addi r1, r1, 0x28
/* 800439F4 00040954  7C 08 03 A6 */	mtlr r0
/* 800439F8 00040958  4E 80 00 20 */	blr 

.global write__9AtxStreamFPvi
write__9AtxStreamFPvi:
/* 800439FC 0004095C  7C 08 02 A6 */	mflr r0
/* 80043A00 00040960  90 01 00 04 */	stw r0, 4(r1)
/* 80043A04 00040964  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80043A08 00040968  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80043A0C 0004096C  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80043A10 00040970  3B C5 00 00 */	addi r30, r5, 0
/* 80043A14 00040974  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80043A18 00040978  3B A4 00 00 */	addi r29, r4, 0
/* 80043A1C 0004097C  93 81 00 20 */	stw r28, 0x20(r1)
/* 80043A20 00040980  3B 83 00 00 */	addi r28, r3, 0
/* 80043A24 00040984  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 80043A28 00040988  83 E6 02 78 */	lwz r31, 0x278(r6)
/* 80043A2C 0004098C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80043A30 00040990  38 7F 00 00 */	addi r3, r31, 0
/* 80043A34 00040994  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80043A38 00040998  7D 88 03 A6 */	mtlr r12
/* 80043A3C 0004099C  4E 80 00 21 */	blrl 
/* 80043A40 000409A0  80 7C 00 08 */	lwz r3, 8(r28)
/* 80043A44 000409A4  38 9D 00 00 */	addi r4, r29, 0
/* 80043A48 000409A8  38 BE 00 00 */	addi r5, r30, 0
/* 80043A4C 000409AC  81 83 00 04 */	lwz r12, 4(r3)
/* 80043A50 000409B0  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80043A54 000409B4  7D 88 03 A6 */	mtlr r12
/* 80043A58 000409B8  4E 80 00 21 */	blrl 
/* 80043A5C 000409BC  7F E3 FB 78 */	mr r3, r31
/* 80043A60 000409C0  81 9F 00 00 */	lwz r12, 0(r31)
/* 80043A64 000409C4  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80043A68 000409C8  7D 88 03 A6 */	mtlr r12
/* 80043A6C 000409CC  4E 80 00 21 */	blrl 
/* 80043A70 000409D0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80043A74 000409D4  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80043A78 000409D8  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80043A7C 000409DC  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 80043A80 000409E0  83 81 00 20 */	lwz r28, 0x20(r1)
/* 80043A84 000409E4  38 21 00 30 */	addi r1, r1, 0x30
/* 80043A88 000409E8  7C 08 03 A6 */	mtlr r0
/* 80043A8C 000409EC  4E 80 00 20 */	blr 

.global read__9AtxStreamFPvi
read__9AtxStreamFPvi:
/* 80043A90 000409F0  7C 08 02 A6 */	mflr r0
/* 80043A94 000409F4  90 01 00 04 */	stw r0, 4(r1)
/* 80043A98 000409F8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80043A9C 000409FC  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80043AA0 00040A00  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80043AA4 00040A04  3B C5 00 00 */	addi r30, r5, 0
/* 80043AA8 00040A08  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80043AAC 00040A0C  3B A4 00 00 */	addi r29, r4, 0
/* 80043AB0 00040A10  93 81 00 20 */	stw r28, 0x20(r1)
/* 80043AB4 00040A14  3B 83 00 00 */	addi r28, r3, 0
/* 80043AB8 00040A18  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 80043ABC 00040A1C  83 E6 02 78 */	lwz r31, 0x278(r6)
/* 80043AC0 00040A20  81 9F 00 00 */	lwz r12, 0(r31)
/* 80043AC4 00040A24  38 7F 00 00 */	addi r3, r31, 0
/* 80043AC8 00040A28  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80043ACC 00040A2C  7D 88 03 A6 */	mtlr r12
/* 80043AD0 00040A30  4E 80 00 21 */	blrl 
/* 80043AD4 00040A34  80 7C 00 08 */	lwz r3, 8(r28)
/* 80043AD8 00040A38  38 9D 00 00 */	addi r4, r29, 0
/* 80043ADC 00040A3C  38 BE 00 00 */	addi r5, r30, 0
/* 80043AE0 00040A40  81 83 00 04 */	lwz r12, 4(r3)
/* 80043AE4 00040A44  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 80043AE8 00040A48  7D 88 03 A6 */	mtlr r12
/* 80043AEC 00040A4C  4E 80 00 21 */	blrl 
/* 80043AF0 00040A50  7F E3 FB 78 */	mr r3, r31
/* 80043AF4 00040A54  81 9F 00 00 */	lwz r12, 0(r31)
/* 80043AF8 00040A58  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80043AFC 00040A5C  7D 88 03 A6 */	mtlr r12
/* 80043B00 00040A60  4E 80 00 21 */	blrl 
/* 80043B04 00040A64  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80043B08 00040A68  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80043B0C 00040A6C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80043B10 00040A70  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 80043B14 00040A74  83 81 00 20 */	lwz r28, 0x20(r1)
/* 80043B18 00040A78  38 21 00 30 */	addi r1, r1, 0x30
/* 80043B1C 00040A7C  7C 08 03 A6 */	mtlr r0
/* 80043B20 00040A80  4E 80 00 20 */	blr 

.global getPending__9AtxStreamFv
getPending__9AtxStreamFv:
/* 80043B24 00040A84  7C 08 02 A6 */	mflr r0
/* 80043B28 00040A88  90 01 00 04 */	stw r0, 4(r1)
/* 80043B2C 00040A8C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80043B30 00040A90  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80043B34 00040A94  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80043B38 00040A98  7C 7E 1B 78 */	mr r30, r3
/* 80043B3C 00040A9C  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80043B40 00040AA0  83 E4 02 78 */	lwz r31, 0x278(r4)
/* 80043B44 00040AA4  81 9F 00 00 */	lwz r12, 0(r31)
/* 80043B48 00040AA8  7F E3 FB 78 */	mr r3, r31
/* 80043B4C 00040AAC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80043B50 00040AB0  7D 88 03 A6 */	mtlr r12
/* 80043B54 00040AB4  4E 80 00 21 */	blrl 
/* 80043B58 00040AB8  80 7E 00 08 */	lwz r3, 8(r30)
/* 80043B5C 00040ABC  81 83 00 04 */	lwz r12, 4(r3)
/* 80043B60 00040AC0  81 8C 00 44 */	lwz r12, 0x44(r12)
/* 80043B64 00040AC4  7D 88 03 A6 */	mtlr r12
/* 80043B68 00040AC8  4E 80 00 21 */	blrl 
/* 80043B6C 00040ACC  38 03 00 00 */	addi r0, r3, 0
/* 80043B70 00040AD0  38 7F 00 00 */	addi r3, r31, 0
/* 80043B74 00040AD4  81 9F 00 00 */	lwz r12, 0(r31)
/* 80043B78 00040AD8  7C 1F 03 78 */	mr r31, r0
/* 80043B7C 00040ADC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80043B80 00040AE0  7D 88 03 A6 */	mtlr r12
/* 80043B84 00040AE4  4E 80 00 21 */	blrl 
/* 80043B88 00040AE8  7F E3 FB 78 */	mr r3, r31
/* 80043B8C 00040AEC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80043B90 00040AF0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80043B94 00040AF4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80043B98 00040AF8  38 21 00 20 */	addi r1, r1, 0x20
/* 80043B9C 00040AFC  7C 08 03 A6 */	mtlr r0
/* 80043BA0 00040B00  4E 80 00 20 */	blr 

.global flush__9AtxStreamFv
flush__9AtxStreamFv:
/* 80043BA4 00040B04  7C 08 02 A6 */	mflr r0
/* 80043BA8 00040B08  90 01 00 04 */	stw r0, 4(r1)
/* 80043BAC 00040B0C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80043BB0 00040B10  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80043BB4 00040B14  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80043BB8 00040B18  7C 7E 1B 78 */	mr r30, r3
/* 80043BBC 00040B1C  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80043BC0 00040B20  83 E4 02 78 */	lwz r31, 0x278(r4)
/* 80043BC4 00040B24  81 9F 00 00 */	lwz r12, 0(r31)
/* 80043BC8 00040B28  7F E3 FB 78 */	mr r3, r31
/* 80043BCC 00040B2C  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80043BD0 00040B30  7D 88 03 A6 */	mtlr r12
/* 80043BD4 00040B34  4E 80 00 21 */	blrl 
/* 80043BD8 00040B38  80 7E 00 08 */	lwz r3, 8(r30)
/* 80043BDC 00040B3C  81 83 00 04 */	lwz r12, 4(r3)
/* 80043BE0 00040B40  81 8C 00 54 */	lwz r12, 0x54(r12)
/* 80043BE4 00040B44  7D 88 03 A6 */	mtlr r12
/* 80043BE8 00040B48  4E 80 00 21 */	blrl 
/* 80043BEC 00040B4C  7F E3 FB 78 */	mr r3, r31
/* 80043BF0 00040B50  81 9F 00 00 */	lwz r12, 0(r31)
/* 80043BF4 00040B54  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80043BF8 00040B58  7D 88 03 A6 */	mtlr r12
/* 80043BFC 00040B5C  4E 80 00 21 */	blrl 
/* 80043C00 00040B60  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80043C04 00040B64  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80043C08 00040B68  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80043C0C 00040B6C  38 21 00 20 */	addi r1, r1, 0x20
/* 80043C10 00040B70  7C 08 03 A6 */	mtlr r0
/* 80043C14 00040B74  4E 80 00 20 */	blr 

.global setPosition__13AtxFileStreamFi
setPosition__13AtxFileStreamFi:
/* 80043C18 00040B78  7C 08 02 A6 */	mflr r0
/* 80043C1C 00040B7C  90 01 00 04 */	stw r0, 4(r1)
/* 80043C20 00040B80  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80043C24 00040B84  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80043C28 00040B88  7C 7F 1B 78 */	mr r31, r3
/* 80043C2C 00040B8C  90 83 00 08 */	stw r4, 8(r3)
/* 80043C30 00040B90  38 7F 00 10 */	addi r3, r31, 0x10
/* 80043C34 00040B94  38 80 00 66 */	li r4, 0x66
/* 80043C38 00040B98  81 9F 00 14 */	lwz r12, 0x14(r31)
/* 80043C3C 00040B9C  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80043C40 00040BA0  7D 88 03 A6 */	mtlr r12
/* 80043C44 00040BA4  4E 80 00 21 */	blrl 
/* 80043C48 00040BA8  38 7F 00 10 */	addi r3, r31, 0x10
/* 80043C4C 00040BAC  80 9F 00 08 */	lwz r4, 8(r31)
/* 80043C50 00040BB0  81 9F 00 14 */	lwz r12, 0x14(r31)
/* 80043C54 00040BB4  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80043C58 00040BB8  7D 88 03 A6 */	mtlr r12
/* 80043C5C 00040BBC  4E 80 00 21 */	blrl 
/* 80043C60 00040BC0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80043C64 00040BC4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80043C68 00040BC8  38 21 00 18 */	addi r1, r1, 0x18
/* 80043C6C 00040BCC  7C 08 03 A6 */	mtlr r0
/* 80043C70 00040BD0  4E 80 00 20 */	blr 

.global read__13AtxFileStreamFPvi
read__13AtxFileStreamFPvi:
/* 80043C74 00040BD4  7C 08 02 A6 */	mflr r0
/* 80043C78 00040BD8  90 01 00 04 */	stw r0, 4(r1)
/* 80043C7C 00040BDC  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80043C80 00040BE0  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80043C84 00040BE4  3B E5 00 00 */	addi r31, r5, 0
/* 80043C88 00040BE8  93 C1 00 20 */	stw r30, 0x20(r1)
/* 80043C8C 00040BEC  3B C4 00 00 */	addi r30, r4, 0
/* 80043C90 00040BF0  38 80 00 64 */	li r4, 0x64
/* 80043C94 00040BF4  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 80043C98 00040BF8  3B A3 00 00 */	addi r29, r3, 0
/* 80043C9C 00040BFC  38 7D 00 10 */	addi r3, r29, 0x10
/* 80043CA0 00040C00  81 9D 00 14 */	lwz r12, 0x14(r29)
/* 80043CA4 00040C04  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80043CA8 00040C08  7D 88 03 A6 */	mtlr r12
/* 80043CAC 00040C0C  4E 80 00 21 */	blrl 
/* 80043CB0 00040C10  38 7D 00 10 */	addi r3, r29, 0x10
/* 80043CB4 00040C14  81 9D 00 14 */	lwz r12, 0x14(r29)
/* 80043CB8 00040C18  7F E4 FB 78 */	mr r4, r31
/* 80043CBC 00040C1C  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80043CC0 00040C20  7D 88 03 A6 */	mtlr r12
/* 80043CC4 00040C24  4E 80 00 21 */	blrl 
/* 80043CC8 00040C28  38 7D 00 10 */	addi r3, r29, 0x10
/* 80043CCC 00040C2C  81 9D 00 14 */	lwz r12, 0x14(r29)
/* 80043CD0 00040C30  38 9E 00 00 */	addi r4, r30, 0
/* 80043CD4 00040C34  38 BF 00 00 */	addi r5, r31, 0
/* 80043CD8 00040C38  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 80043CDC 00040C3C  7D 88 03 A6 */	mtlr r12
/* 80043CE0 00040C40  4E 80 00 21 */	blrl 
/* 80043CE4 00040C44  80 1D 00 08 */	lwz r0, 8(r29)
/* 80043CE8 00040C48  7C 00 FA 14 */	add r0, r0, r31
/* 80043CEC 00040C4C  90 1D 00 08 */	stw r0, 8(r29)
/* 80043CF0 00040C50  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80043CF4 00040C54  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80043CF8 00040C58  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 80043CFC 00040C5C  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 80043D00 00040C60  38 21 00 28 */	addi r1, r1, 0x28
/* 80043D04 00040C64  7C 08 03 A6 */	mtlr r0
/* 80043D08 00040C68  4E 80 00 20 */	blr 

.global write__13AtxFileStreamFPvi
write__13AtxFileStreamFPvi:
/* 80043D0C 00040C6C  7C 08 02 A6 */	mflr r0
/* 80043D10 00040C70  90 01 00 04 */	stw r0, 4(r1)
/* 80043D14 00040C74  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80043D18 00040C78  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80043D1C 00040C7C  3B E5 00 00 */	addi r31, r5, 0
/* 80043D20 00040C80  93 C1 00 20 */	stw r30, 0x20(r1)
/* 80043D24 00040C84  3B C4 00 00 */	addi r30, r4, 0
/* 80043D28 00040C88  38 80 00 65 */	li r4, 0x65
/* 80043D2C 00040C8C  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 80043D30 00040C90  3B A3 00 00 */	addi r29, r3, 0
/* 80043D34 00040C94  38 7D 00 10 */	addi r3, r29, 0x10
/* 80043D38 00040C98  81 9D 00 14 */	lwz r12, 0x14(r29)
/* 80043D3C 00040C9C  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80043D40 00040CA0  7D 88 03 A6 */	mtlr r12
/* 80043D44 00040CA4  4E 80 00 21 */	blrl 
/* 80043D48 00040CA8  38 7D 00 10 */	addi r3, r29, 0x10
/* 80043D4C 00040CAC  81 9D 00 14 */	lwz r12, 0x14(r29)
/* 80043D50 00040CB0  7F E4 FB 78 */	mr r4, r31
/* 80043D54 00040CB4  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80043D58 00040CB8  7D 88 03 A6 */	mtlr r12
/* 80043D5C 00040CBC  4E 80 00 21 */	blrl 
/* 80043D60 00040CC0  38 7D 00 10 */	addi r3, r29, 0x10
/* 80043D64 00040CC4  81 9D 00 14 */	lwz r12, 0x14(r29)
/* 80043D68 00040CC8  38 9E 00 00 */	addi r4, r30, 0
/* 80043D6C 00040CCC  38 BF 00 00 */	addi r5, r31, 0
/* 80043D70 00040CD0  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80043D74 00040CD4  7D 88 03 A6 */	mtlr r12
/* 80043D78 00040CD8  4E 80 00 21 */	blrl 
/* 80043D7C 00040CDC  80 1D 00 08 */	lwz r0, 8(r29)
/* 80043D80 00040CE0  7C 00 FA 14 */	add r0, r0, r31
/* 80043D84 00040CE4  90 1D 00 08 */	stw r0, 8(r29)
/* 80043D88 00040CE8  80 7D 00 08 */	lwz r3, 8(r29)
/* 80043D8C 00040CEC  80 1D 00 0C */	lwz r0, 0xc(r29)
/* 80043D90 00040CF0  7C 03 00 00 */	cmpw r3, r0
/* 80043D94 00040CF4  40 81 00 08 */	ble lbl_80043D9C
/* 80043D98 00040CF8  90 7D 00 0C */	stw r3, 0xc(r29)
lbl_80043D9C:
/* 80043D9C 00040CFC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80043DA0 00040D00  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80043DA4 00040D04  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 80043DA8 00040D08  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 80043DAC 00040D0C  38 21 00 28 */	addi r1, r1, 0x28
/* 80043DB0 00040D10  7C 08 03 A6 */	mtlr r0
/* 80043DB4 00040D14  4E 80 00 20 */	blr 

.global close__13AtxFileStreamFv
close__13AtxFileStreamFv:
/* 80043DB8 00040D18  7C 08 02 A6 */	mflr r0
/* 80043DBC 00040D1C  38 80 00 67 */	li r4, 0x67
/* 80043DC0 00040D20  90 01 00 04 */	stw r0, 4(r1)
/* 80043DC4 00040D24  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80043DC8 00040D28  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80043DCC 00040D2C  3B E3 00 00 */	addi r31, r3, 0
/* 80043DD0 00040D30  38 7F 00 10 */	addi r3, r31, 0x10
/* 80043DD4 00040D34  81 9F 00 14 */	lwz r12, 0x14(r31)
/* 80043DD8 00040D38  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80043DDC 00040D3C  7D 88 03 A6 */	mtlr r12
/* 80043DE0 00040D40  4E 80 00 21 */	blrl 
/* 80043DE4 00040D44  38 7F 00 10 */	addi r3, r31, 0x10
/* 80043DE8 00040D48  81 9F 00 14 */	lwz r12, 0x14(r31)
/* 80043DEC 00040D4C  81 8C 00 54 */	lwz r12, 0x54(r12)
/* 80043DF0 00040D50  7D 88 03 A6 */	mtlr r12
/* 80043DF4 00040D54  4E 80 00 21 */	blrl 
/* 80043DF8 00040D58  38 7F 00 10 */	addi r3, r31, 0x10
/* 80043DFC 00040D5C  81 9F 00 14 */	lwz r12, 0x14(r31)
/* 80043E00 00040D60  81 8C 00 08 */	lwz r12, 8(r12)
/* 80043E04 00040D64  7D 88 03 A6 */	mtlr r12
/* 80043E08 00040D68  4E 80 00 21 */	blrl 
/* 80043E0C 00040D6C  38 7F 00 10 */	addi r3, r31, 0x10
/* 80043E10 00040D70  81 9F 00 14 */	lwz r12, 0x14(r31)
/* 80043E14 00040D74  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 80043E18 00040D78  7D 88 03 A6 */	mtlr r12
/* 80043E1C 00040D7C  4E 80 00 21 */	blrl 
/* 80043E20 00040D80  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80043E24 00040D84  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80043E28 00040D88  38 21 00 18 */	addi r1, r1, 0x18
/* 80043E2C 00040D8C  7C 08 03 A6 */	mtlr r0
/* 80043E30 00040D90  4E 80 00 20 */	blr 

.global getPending__13AtxFileStreamFv
getPending__13AtxFileStreamFv:
/* 80043E34 00040D94  80 83 00 08 */	lwz r4, 8(r3)
/* 80043E38 00040D98  80 03 00 0C */	lwz r0, 0xc(r3)
/* 80043E3C 00040D9C  7C 64 00 50 */	subf r3, r4, r0
/* 80043E40 00040DA0  4E 80 00 20 */	blr 

.global getPosition__13AtxFileStreamFv
getPosition__13AtxFileStreamFv:
/* 80043E44 00040DA4  80 63 00 08 */	lwz r3, 8(r3)
/* 80043E48 00040DA8  4E 80 00 20 */	blr 

.global getLength__13AtxFileStreamFv
getLength__13AtxFileStreamFv:
/* 80043E4C 00040DAC  80 63 00 0C */	lwz r3, 0xc(r3)
/* 80043E50 00040DB0  4E 80 00 20 */	blr 

.global setLength__13AtxFileStreamFi
setLength__13AtxFileStreamFi:
/* 80043E54 00040DB4  90 83 00 0C */	stw r4, 0xc(r3)
/* 80043E58 00040DB8  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_80228F00:
	.asciz "AtxFileStream"
.balign 4
lbl_80228F10:
	.asciz "RandomAccessStream"
.balign 4
lbl_80228F24:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte 0
lbl_80228F30:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte __RTTI__18RandomAccessStream
	.4byte 0
	.4byte 0
.global __vt__13AtxFileStream
__vt__13AtxFileStream:
	.4byte __RTTI__13AtxFileStream
	.4byte 0
	.4byte readInt__6StreamFv
	.4byte readByte__6StreamFv
	.4byte readShort__6StreamFv
	.4byte readFloat__6StreamFv
	.4byte readString__6StreamFPci
	.4byte readString__6StreamFR6String
	.4byte readString__6StreamFv
	.4byte writeInt__6StreamFi
	.4byte writeByte__6StreamFUc
	.4byte writeShort__6StreamFs
	.4byte writeFloat__6StreamFf
	.4byte writeString__6StreamFPc
	.4byte writeString__6StreamFR6String
	.4byte read__13AtxFileStreamFPvi
	.4byte write__13AtxFileStreamFPvi
	.4byte getPending__13AtxFileStreamFv
	.4byte getAvailable__6StreamFv
	.4byte close__13AtxFileStreamFv
	.4byte getClosing__6StreamFv
	.4byte flush__6StreamFv
	.4byte getPosition__13AtxFileStreamFv
	.4byte setPosition__13AtxFileStreamFi
	.4byte getLength__13AtxFileStreamFv
	.4byte setLength__13AtxFileStreamFi
.balign 4
lbl_80228FAC:
	.asciz "AtxStream"
.balign 4
lbl_80228FB8:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte 0
.global __vt__9AtxStream
__vt__9AtxStream:
	.4byte __RTTI__9AtxStream
	.4byte 0
	.4byte readInt__6StreamFv
	.4byte readByte__6StreamFv
	.4byte readShort__6StreamFv
	.4byte readFloat__6StreamFv
	.4byte readString__6StreamFPci
	.4byte readString__6StreamFR6String
	.4byte readString__6StreamFv
	.4byte writeInt__6StreamFi
	.4byte writeByte__6StreamFUc
	.4byte writeShort__6StreamFs
	.4byte writeFloat__6StreamFf
	.4byte writeString__6StreamFPc
	.4byte writeString__6StreamFR6String
	.4byte read__9AtxStreamFPvi
	.4byte write__9AtxStreamFPvi
	.4byte getPending__9AtxStreamFv
	.4byte getAvailable__6StreamFv
	.4byte close__9AtxStreamFv
	.4byte getClosing__6StreamFv
	.4byte flush__9AtxStreamFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DD470:
	.asciz "Stream"
.balign 4
__RTTI__6Stream:
	.4byte lbl_803DD470
	.4byte 0
__RTTI__18RandomAccessStream:
	.4byte lbl_80228F10
	.4byte lbl_80228F24
__RTTI__13AtxFileStream:
	.4byte lbl_80228F00
	.4byte lbl_80228F30
__RTTI__9AtxStream:
	.4byte lbl_80228FAC
	.4byte lbl_80228FB8
