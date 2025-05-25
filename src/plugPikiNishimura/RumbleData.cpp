#include "RumbleMgr.h"

RumbleTable patternTable[16] = {
	{ 16, 0 },   { 8, 0x5557 }, { 6, 0x557 }, { 4, 0x17 },  { 3, 0x7 },    { 4, 0x57 }, { 3, 0x17 },   { 3, 0xF },
	{ 4, 0x3F }, { 5, 0xFF },   { 6, 0x3FF }, { 7, 0xFFF }, { 8, 0x3FFF }, { 4, 0x7F }, { 8, 0x7FFF }, { 1, 3 },
};

static int rumblePoint_00[] = { 11 };
static f32 rumbleFrame_00[] = { 0.0f, 0.05f, 0.1f, 0.15f, 0.2f, 0.23f, 0.28f, 0.33f, 0.38f, 0.43f, 0.46f };
static f32 rumblePower_00[] = { 0.2f, 0.9f, 1.0f, 0.9f, 0.0f, 0.0f, 0.4f, 0.0f, 0.2f, 0.02f, 0.0f };

static int rumblePoint_01[] = { 24 };
static f32 rumbleFrame_01[] = {
	0.0f,  0.16f,       0.19f, 0.23999999f, 0.25999999f, 0.37f, 0.4f,  0.44999999f, 0.46f, 0.54f, 0.56f, 0.61f,
	0.62f, 0.69999999f, 0.73f, 0.77999997f, 0.79f,       0.86f, 0.92f, 0.95999998f, 1.03f, 1.13f, 1.17f, 1.4f,
};
static f32 rumblePower_01[] = {
	1.0f,        0.94999999f, 0.0f, 0.0f, 0.89999998f, 0.85f,       0.0f, 0.0f,  0.8f,  0.73f, 0.0f,          0.0f,
	0.63999999f, 0.52999997f, 0.0f, 0.0f, 0.44f,       0.34999999f, 0.0f, 0.27f, 0.02f, 0.16f, 0.0099999998f, 0.0f,
};

static int rumblePoint_02[] = { 5 };
static f32 rumbleFrame_02[] = {
	0.0f, 0.079999998f, 0.1f, 0.16f, 0.3f,
};
static f32 rumblePower_02[] = {
	0.8f, 0.69999999f, 0.3f, 0.039999999f, 0.0099999998f,
};

static int rumblePoint_03[] = { 28 };
static f32 rumbleFrame_03[] = {
	0.0f,  0.039999999f, 0.09f,       0.11f, 0.13f, 0.15f,       0.18f,       0.20999999f, 0.23999999f, 0.27f, 0.3f,  0.33f, 0.36f, 0.4f,
	0.44f, 0.47999999f,  0.51999998f, 0.56f, 0.6f,  0.64999998f, 0.69999999f, 0.75f,       0.8f,        0.85f, 0.93f, 1.01f, 1.1f,  1.2f,
};
static f32 rumblePower_03[] = {
	0.89999998f, 0.87f, 0.3f,  0.15f, 0.27f, 0.14f, 0.25f, 0.13f, 0.23f, 0.12f, 0.20999999f, 0.12f,        0.19f, 0.12f,
	0.17f,       0.11f, 0.15f, 0.11f, 0.13f, 0.1f,  0.12f, 0.09f, 0.11f, 0.09f, 0.1f,        0.079999998f, 0.05f, 0.0f,
};

static int rumblePoint_04[] = { 6 };
static f32 rumbleFrame_04[] = {
	0.0f, 0.1f, 0.15f, 0.2f, 0.25f, 0.3f,
};
static f32 rumblePower_04[] = {
	0.89999998f, 0.89999998f, 0.1f, 0.3f, 0.3f, 0.0f,
};

static int rumblePoint_05[] = { 21 };
static f32 rumbleFrame_05[] = {
	0.0f,  0.18f,       0.20999999f, 0.28f, 0.28f, 0.4f,  0.44999999f, 0.50999999f, 0.51999998f, 0.63999999f, 0.69f,
	0.75f, 0.82999998f, 0.88999999f, 0.99f, 1.03f, 1.12f, 1.19f,       1.25f,       1.3f,        1.4f,
};
static f32 rumblePower_05[] = {
	1.0f,        0.92f,        0.0f,  0.0f,         0.79f, 0.63f,        0.0f, 0.02f,        0.44999999f,  0.31f, 0.02f,
	0.23999999f, 0.029999999f, 0.18f, 0.039999999f, 0.13f, 0.039999999f, 0.1f, 0.039999999f, 0.059999999f, 0.0f,
};

static int rumblePoint_06[] = { 20 };
static f32 rumbleFrame_06[] = {
	0.0f, 0.05f, 0.1f, 0.15f,       0.2f,        0.25f,       0.3f, 0.34999999f, 0.4f,        0.44999999f,
	0.5f, 0.55f, 0.6f, 0.64999998f, 0.69999999f, 0.75999999f, 0.8f, 0.85f,       0.89999998f, 1.0f,
};
static f32 rumblePower_06[] = {
	0.85f, 0.8f, 0.15f, 0.4f, 0.12f, 0.25f, 0.11f, 0.2f, 0.1f, 0.19f, 0.1f, 0.17f, 0.1f, 0.16f, 0.1f, 0.15f, 0.1f, 0.14f, 0.1f, 0.0f,
};

static int rumblePoint_07[] = { 20 };
static f32 rumbleFrame_07[] = {
	0.0f,        0.11f,       0.12f,       0.13f, 0.2f,  0.20999999f, 0.28999999f, 0.31f, 0.33f, 0.41f,
	0.41999999f, 0.51999998f, 0.52999997f, 0.54f, 0.62f, 0.63999999f, 0.72f,       0.74f, 0.75f, 1.0f,
};
static f32 rumblePower_07[] = {
	0.94999999f, 0.97f, 0.85f,       0.0f, 0.0f, 0.75f,       0.73f,       0.55f, 0.0f,  0.0f,
	0.6f,        0.63f, 0.31999999f, 0.0f, 0.0f, 0.50999999f, 0.47999999f, 0.19f, 0.02f, 0.0f,
};

static int rumblePoint_08[] = { 10 };
static f32 rumbleFrame_08[] = {
	0.0f, 0.09f, 0.09f, 0.1f, 0.17f, 0.17f, 0.18f, 0.25999999f, 0.25999999f, 0.5f,
};
static f32 rumblePower_08[] = {
	0.85f, 0.85f, 0.1f, 0.44999999f, 0.44999999f, 0.05f, 0.25f, 0.25f, 0.0099999998f, 0.0f,
};

static int rumblePoint_09[] = { 11 };
static f32 rumbleFrame_09[] = {
	0.0f, 0.0099999998f, 0.05f, 0.12f, 0.12f, 0.16f, 0.23999999f, 0.25999999f, 0.34f, 0.34f, 0.38999999f,
};
static f32 rumblePower_09[] = {
	0.19f, 0.64999998f, 0.52999997f, 0.64999998f, 0.25f, 0.4f, 0.25f, 0.50999999f, 0.36f, 0.50999999f, 0.1f,
};

static int rumblePoint_10[] = { 6 };
static f32 rumbleFrame_10[] = {
	0.0f, 0.1f, 0.15f, 0.2f, 0.25f, 0.3f,
};
static f32 rumblePower_10[] = {
	0.75f, 0.75f, 0.1f, 0.27f, 0.27f, 0.0f,
};

static int rumblePoint_11[] = { 14 };
static f32 rumbleFrame_11[] = {
	0.0f, 0.12f, 0.19f, 0.28f, 0.34f, 0.43f, 0.49f, 0.6f, 0.66f, 0.75999999f, 0.82999998f, 0.92f, 0.98f, 1.15f,
};
static f32 rumblePower_11[] = {
	0.89999998f, 0.77999997f, 0.22f,       0.64999998f,  0.18f,       0.54f, 0.14f,
	0.41999999f, 0.1f,        0.31999999f, 0.059999999f, 0.25999999f, 0.02f, 0.0f,
};

static int rumblePoint_12[] = { 25 };
static f32 rumbleFrame_12[] = {
	0.0f, 0.1f,        0.17f, 0.2f, 0.22f, 0.3f, 0.4f,  0.5f,  0.57999998f, 0.6f,  0.63f, 0.69999999f, 0.75999999f,
	0.8f, 0.81999999f, 0.85f, 1.1f, 1.12f, 1.2f, 1.25f, 1.35f, 1.37f,       1.47f, 1.49f, 1.7f,
};
static f32 rumblePower_12[] = {
	0.8f, 0.75f, 0.6f,  0.5f,  0.4f,  0.25f, 0.2f, 0.25f, 0.4f,        0.5f,        0.61f,         0.64999998f, 0.61f,
	0.5f, 0.38f, 0.02f, 0.02f, 0.55f, 0.55f, 0.0f, 0.0f,  0.52999997f, 0.52999997f, 0.0099999998f, 0.0f,
};

static int rumblePoint_13[] = { 14 };
static f32 rumbleFrame_13[] = {
	0.0f, 0.1f, 0.2f, 0.25f, 0.3f, 0.34999999f, 0.4f, 0.44999999f, 0.5f, 0.55f, 0.6f, 0.64999998f, 0.69999999f, 0.75f,
};
static f32 rumblePower_13[] = {
	0.8f, 0.69999999f, 0.1f, 0.05f, 0.1f, 0.34999999f, 0.4f, 0.34999999f, 0.1f, 0.05f, 0.1f, 0.17f, 0.2f, 0.17f,
};

static int rumblePoint_14[] = { 8 };
static f32 rumbleFrame_14[] = {
	0.0f, 0.12f, 0.13f, 0.16f, 0.22f, 0.28999999f, 0.3f, 0.5f,
};
static f32 rumblePower_14[] = {
	0.92f, 0.88999999f, 0.0f, 0.0f, 0.68f, 0.64999998f, 0.02f, 0.0f,
};

static int rumblePoint_15[] = { 6 };
static f32 rumbleFrame_15[] = {
	0.0f, 0.079999998f, 0.09f, 0.1f, 0.19f, 0.2f,
};
static f32 rumblePower_15[] = {
	0.44999999f, 0.4f, 0.0f, 0.25f, 0.2f, 0.0f,
};

static int rumblePoint_16[] = { 27 };
static f32 rumbleFrame_16[] = {
	0.0f,        0.1f,        0.16f,       0.22f, 0.3f,        0.38999999f, 0.41999999f, 0.44999999f, 0.52999997f,
	0.6f,        0.61f,       0.63999999f, 0.68f, 0.69999999f, 0.75999999f, 0.75999999f, 0.8f,        0.82999998f,
	0.83999997f, 0.88999999f, 0.91f,       0.97f, 0.99f,       1.03f,       1.09f,       1.13f,       1.2f,
};
static f32 rumblePower_16[] = {
	0.75f, 0.67f,        0.4f,        0.15f,        0.1f,  0.15f,        0.4f,        0.62f,       0.66f,
	0.63f, 0.23f,        0.51999998f, 0.20999999f,  0.47f, 0.41f,        0.17f,       0.38999999f, 0.12f,
	0.38f, 0.079999998f, 0.34999999f, 0.059999999f, 0.31f, 0.029999999f, 0.28999999f, 0.02f,       0.0f,
};

static int rumblePoint_17[] = { 38 };
static f32 rumbleFrame_17[] = {
	0.0f,  0.059999999f, 0.1f,  0.1f,  0.15f,       0.17f, 0.22f, 0.25999999f, 0.31f, 0.31f, 0.4f,        0.4f,  0.46f,
	0.47f, 0.52999997f,  0.55f, 0.62f, 0.64999998f, 0.69f, 0.74f, 0.79f,       0.81f, 0.88f, 0.88999999f, 0.94f, 0.98f,
	1.02f, 1.0599999f,   1.07f, 1.12f, 1.15f,       1.2f,  1.26f, 1.3099999f,  1.37f, 1.38f, 1.46f,       1.6f,
};
static f32 rumblePower_17[] = {
	0.8f,         0.73f, 0.28f,        0.64999998f, 0.58999997f,  0.23999999f, 0.54f,        0.19f,        0.5f,  0.18f,
	0.47999999f,  0.15f, 0.44999999f,  0.14f,       0.41f,        0.13f,       0.38999999f,  0.13f,        0.38f, 0.11f,
	0.36f,        0.1f,  0.09f,        0.34f,       0.1f,         0.34f,       0.09f,        0.079999998f, 0.33f, 0.31f,
	0.079999998f, 0.3f,  0.059999999f, 0.28999999f, 0.059999999f, 0.28f,       0.029999999f, 0.0f,
};

static int rumblePoint_18[] = { 15 };
static f32 rumbleFrame_18[] = {
	0.0f, 0.079999998f, 0.1f, 0.13f, 0.18f, 0.23999999f, 0.28999999f, 0.33f, 0.33f, 0.36f, 0.41f, 0.43f, 0.44999999f, 0.5f, 0.8f,
};
static f32 rumblePower_18[] = {
	1.0f,        0.97f, 0.8f,        0.4f, 0.23f, 0.2f,          0.25999999f,   0.50999999f,
	0.76999998f, 0.8f,  0.76999998f, 0.6f, 0.05f, 0.0099999998f, 0.0099999998f,
};

static int rumblePoint_19[] = { 3 };
static f32 rumbleFrame_19[] = {
	0.0f,
	0.079999998f,
	0.1f,
};
static f32 rumblePower_19[] = {
	1.0f,
	0.89999998f,
	0.0f,
};

ChannelData channelDataTbl[20] = {
	{ rumblePoint_00, rumbleFrame_00, rumblePower_00 }, // RUMBLE_Unk0
	{ rumblePoint_01, rumbleFrame_01, rumblePower_01 }, // RUMBLE_Unk1
	{ rumblePoint_02, rumbleFrame_02, rumblePower_02 }, // RUMBLE_Unk2
	{ rumblePoint_03, rumbleFrame_03, rumblePower_03 }, // RUMBLE_Unk3
	{ rumblePoint_04, rumbleFrame_04, rumblePower_04 }, // RUMBLE_Unk4
	{ rumblePoint_05, rumbleFrame_05, rumblePower_05 }, // RUMBLE_Unk5
	{ rumblePoint_06, rumbleFrame_06, rumblePower_06 }, // RUMBLE_Unk6
	{ rumblePoint_07, rumbleFrame_07, rumblePower_07 }, // RUMBLE_Unk7
	{ rumblePoint_08, rumbleFrame_08, rumblePower_08 }, // RUMBLE_Unk8
	{ rumblePoint_09, rumbleFrame_09, rumblePower_09 }, // RUMBLE_Unk9
	{ rumblePoint_10, rumbleFrame_10, rumblePower_10 }, // RUMBLE_Unk10
	{ rumblePoint_11, rumbleFrame_11, rumblePower_11 }, // RUMBLE_Unk11
	{ rumblePoint_12, rumbleFrame_12, rumblePower_12 }, // RUMBLE_Unk12
	{ rumblePoint_13, rumbleFrame_13, rumblePower_13 }, // RUMBLE_Unk13
	{ rumblePoint_14, rumbleFrame_14, rumblePower_14 }, // RUMBLE_Unk14
	{ rumblePoint_15, rumbleFrame_15, rumblePower_15 }, // RUMBLE_Unk15
	{ rumblePoint_16, rumbleFrame_16, rumblePower_16 }, // RUMBLE_Unk16
	{ rumblePoint_17, rumbleFrame_17, rumblePower_17 }, // RUMBLE_Unk17
	{ rumblePoint_18, rumbleFrame_18, rumblePower_18 }, // RUMBLE_Unk18
	{ rumblePoint_19, rumbleFrame_19, rumblePower_19 }, // RUMBLE_Unk19
};
