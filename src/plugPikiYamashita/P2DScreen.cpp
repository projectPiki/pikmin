#include "DebugLog.h"
#include "P2D/Graph.h"
#include "P2D/Picture.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "P2D/Window.h"
#include "sysNew.h"
#include "zen/ogSub.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(37)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("P2DScreen")

/*
 * --INFO--
 * Address:	801B2B50
 * Size:	00004C
 */
void P2DScreen::update()
{
	P2DPane::update();
	if (mAlphaMgr) {
		mAlphaMgr->update();
	}
	if (mTexAnimMgr) {
		mTexAnimMgr->update();
	}
}

/*
 * --INFO--
 * Address:	801B2B9C
 * Size:	000064
 */
P2DScreen::~P2DScreen()
{
}

/*
 * --INFO--
 * Address:	801B2C00
 * Size:	00012C
 */
void P2DScreen::set(const char* bloFileName, bool useAlphaMgr, bool useTexAnimMgr, bool p4)
{
	char path[PATH_MAX];
	makeResName(bloFileName, path);

	RandomAccessStream* file = gsys->openFile(path, p4, true);
	if (file) {
		makeHiearachyPanes(this, file, true, true);
		file->close();
	} else {
		PRINT("ERROR! Cannot open file.[%s] \n", path);
		ERROR("Cannot open file.[%s] \n", path);
	}

	loadResource();

	if (useAlphaMgr) {
		mAlphaMgr = new zen::PikaAlphaMgr(this);
		mAlphaMgr->start();
	} else {
		mAlphaMgr = nullptr;
	}

	if (useTexAnimMgr) {
		mTexAnimMgr = new zen::ogTexAnimMgr(this);
	} else {
		mTexAnimMgr = nullptr;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void P2DScreen::set(RandomAccessStream* input)
{
	makeHiearachyPanes(this, input, true, true);
}

/*
 * --INFO--
 * Address:	801B2D2C
 * Size:	0001A0
 */
void P2DScreen::makeHiearachyPanes(P2DPane* parent, RandomAccessStream* input, bool, bool doExpandBounds)
{
	P2DPane* currPane = parent;
	while (true) {
		u16 paneType = input->readShort();
		switch (paneType) {
		case PANETYPE_Unk0:
			return;

		case PANETYPE_Unk1:
			input->readShort();
			makeHiearachyPanes(currPane, input, true, false);
			break;

		case PANETYPE_Unk2:
			input->readShort();
			return;

		case PANETYPE_Pane:
			currPane = new P2DPane(parent, input, paneType);
			if (doExpandBounds) {
				setBounds(PUTRect(0, 0, currPane->getWidth(), currPane->getHeight()));
			}
			break;

		case PANETYPE_Window:
			currPane = new P2DWindow(parent, input, PANETYPE_Window);
			break;

		case PANETYPE_Picture:
			currPane = new P2DPicture(parent, input, PANETYPE_Picture);
			break;

		case PANETYPE_TextBox:
			currPane = new P2DTextBox(parent, input, PANETYPE_TextBox);
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	801B2ECC
 * Size:	000008
 */
P2DPane* P2DScreen::makeUserPane(u16, P2DPane*, RandomAccessStream*)
{
	PRINT("There is a unknown pane in SCRN resource\n");
	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
P2DPane* P2DScreen::stop()
{
	PRINT("There is a unknown pane in SCRN resource\n");
	return nullptr;
}

/*
 * --INFO--
 * Address:	801B2ED4
 * Size:	000328
 */
void P2DScreen::draw(int x, int y, const P2DGrafContext* grafContext)
{
	if (grafContext) {
		P2DGrafContext context(*grafContext);
		P2DPane::draw(x, y, grafContext, _EC);
		context.setScissor();
	} else {
		P2DOrthoGraph ortho(0, 0, 640, 480);
		ortho.setPort();
		P2DPane::draw(x, y, &ortho, _EC);
		ortho.setScissor();
	}

	GXSetNumTexGens(0);
	GXSetNumTevStages(1);
	GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
	GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
	GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
	GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
	GXSetCullMode(GX_CULL_NONE);
}

/*
 * --INFO--
 * Address:	801B31FC
 * Size:	000030
 */
P2DPane* P2DScreen::search(u32 tag, bool p2)
{
	if (!tag) {
		return nullptr;
	}

	return P2DPane::search(tag, p2);
}

/*
 * --INFO--
 * Address:	801B322C
 * Size:	000020
 */
void P2DScreen::loadResource()
{
	loadChildResource();
}

/*
 * --INFO--
 * Address:	801B324C
 * Size:	000028
 */
void P2DScreen::makeResName(const char* fileName, char* outPath)
{
	zen::makePathName(gsys->mBloDir, fileName, outPath);
	PRINT("makeResName:[%s] \n", outPath);
}
