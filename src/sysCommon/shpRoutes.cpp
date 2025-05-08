#include "Route.h"
#include "CmdStream.h"
#include "Graphics.h"
#include "Font.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("shpRoutes")

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
RoutePoint::RoutePoint()
    : CoreNode("rp")
{
	mLink.initCore("");
	_20     = 8.0f;
	mIndex  = 0;
	mState  = 1;
	mRadius = 10.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001D4
 */
void RoutePoint::refresh(Graphics& gfx)
{
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	if (gfx.initParticle(true)) {
		gfx.drawParticle(*gfx.mCamera, Vector3f(mPosition.x, mPosition.y + 12.0f, mPosition.z), _20);
	}
	Vector3f pos(mPosition.x, mPosition.y + 12.0f, mPosition.z);
	mScreenDepth = gfx.mCamera->projectWorldPoint(gfx, pos);
	mScreenX     = pos.x;
	mScreenY     = pos.y;
	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	Vector3f pos2(mPosition.x, mPosition.y + 12.0f, mPosition.z);
	pos2.multMatrix(gfx.mCamera->mLookAtMtx);
	char buf[PATH_MAX];
	sprintf(buf, "%d", mIndex);
	gfx.perspPrintf(gsys->mConsFont, pos2, -(gsys->mConsFont->stringWidth(buf) / 2), 0, buf);
}

/*
 * --INFO--
 * Address:	80036474
 * Size:	000184
 */
void RoutePoint::loadini(CmdStream* s)
{
	while (!s->endOfCmds() && !s->endOfSection()) {
		s->getToken(true);

		if (s->isToken("index")) {
			sscanf(s->getToken(true), "%d", &mIndex);
		} else if (s->isToken("pos")) {
			sscanf(s->getToken(true), "%f", &mPosition.x);
			sscanf(s->getToken(true), "%f", &mPosition.y);
			sscanf(s->getToken(true), "%f", &mPosition.z);
		} else if (s->isToken("state")) {
			sscanf(s->getToken(true), "%d", &mState);
		} else if (s->isToken("width")) {
			sscanf(s->getToken(true), "%f", &mRadius);
		}
	}

	if (!s->endOfCmds()) {
		s->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	800365F8
 * Size:	000184
 */
RouteGroup::RouteGroup()
    : EditNode("")
{
	setID('none');
	sprintf(mRouteName, "sample route");
	mPointListRoot.initCore("");
	mColour.set(0xFF, 0xFF, 0xFF, 0xC0);
}

/*
 * --INFO--
 * Address:	8003677C
 * Size:	0009A0
 */
void RouteGroup::refresh(Graphics& gfx, EditNode* node)
{
	bool lighting = gfx.setLighting(false, nullptr);
	int alpha     = mColour.a;
	gfx.setCBlending(0);

	FOREACH_NODE(RoutePoint, mPointListRoot.mChild, point)
	{
		FOREACH_NODE(RouteLink, point->mLink.mChild, link)
		{
			Vector3f vec1(point->mPosition.x, point->mPosition.y + 8.0f, point->mPosition.z);
			Vector3f vec2(link->mPoint->mPosition.x, link->mPoint->mPosition.y + 8.0f, link->mPoint->mPosition.z);
			Vector3f vec3(0.0f, 4.0f, 0.0f);

			gfx.useTexture(nullptr, 0);
			gfx.setColour(Colour(255, 255, 255, alpha), true);
			gfx.drawLine(vec1 + vec3, vec2 + vec3);
			f32 ratio = (!point->mState || !link->mPoint) ? 0.2f : 1.0f;
			gfx.setColour(Colour(int(mColour.r * ratio), int(mColour.g * ratio), int(mColour.b * ratio), alpha), true);

			Vector3f vec4 = (vec1 + vec2) * 0.5f + vec3;

			Vector3f vec5 = vec2 - vec1;
			vec5.normalise();
			vec5.multiply(8.0f);

			Vector3f vec6(-(vec2.z - vec1.z), 0.0f, vec2.x - vec1.x);
			vec6.normalise();

			Vector3f vec7(vec6);
			vec7.multiply(point->mRadius);
			Vector3f vec8(vec6);
			vec8.multiply(link->mPoint->mRadius);

			Vector3f vecs3D[4];
			Vector2f vecs2D[4];
			vecs2D[0].set(0.0f, 0.0f);
			vecs2D[1].set(0.0f, 0.0f);
			vecs2D[2].set(0.0f, 0.0f);
			vecs2D[3].set(0.0f, 0.0f);

			vecs3D[0] = vec1 + vec7;
			vecs3D[1] = vec1 - vec7;
			vecs3D[2] = vec2 - vec8;
			vecs3D[3] = vec2 + vec8;

			gfx.drawOneTri(vecs3D, nullptr, vecs2D, 4);
			vec6.multiply(4.0f);
			gfx.setColour(Colour(255, 255, 255, 255), true);

			gfx.drawLine(vec4 - vec5 - vec5 - vec6, vec4 - vec5);
			gfx.drawLine(vec4 - vec5, vec4 - vec5 - vec5 + vec6);
		}
	}

	gfx.setColour(Colour(mColour.r, mColour.g, mColour.b, alpha), true);

	FOREACH_NODE(RoutePoint, mPointListRoot.mChild, point)
	{
		gfx.useTexture(nullptr, 0);
		gfx.setColour(Colour(255, 255, 0, 64), true);
		gfx.drawLine(point->mPosition, Vector3f(point->mPosition.x, point->mPosition.y + 8.0f, point->mPosition.z));
		gfx.setColour(Colour(255, 255, 255, alpha), true);
		gfx.useTexture(_BC, 0);

		point->refresh(gfx);
	}

	gfx.setLighting(lighting, nullptr);
}

/*
 * --INFO--
 * Address:	80037138
 * Size:	000060
 */
void RouteGroup::render2d(Graphics& gfx, int& p3)
{
	gfx.texturePrintf(gsys->mConsFont, 0, p3 += 12, "route [ %s ]", mRouteName);
}

/*
 * --INFO--
 * Address:	80037198
 * Size:	0003CC
 */
void RouteGroup::loadini(CmdStream* s)
{
	while (!s->endOfCmds() && !s->endOfSection()) {
		s->getToken(true);

		if (s->isToken("id")) {
			sprintf(mStringID, s->getToken(true));
			updateID();
		} else if (s->isToken("name")) {
			sprintf(mRouteName, s->getToken(true));
		} else if (s->isToken("colour")) {
			int r;
			sscanf(s->getToken(true), "%d", &r);
			int g;
			sscanf(s->getToken(true), "%d", &g);
			int b;
			sscanf(s->getToken(true), "%d", &b);
			int a;
			sscanf(s->getToken(true), "%d", &a);

			mColour.set(r, g, b, 0x61);
		} else if (s->isToken("point")) {
			s->getToken(true);
			RoutePoint* point = new RoutePoint();
			point->loadini(s);
			mPointListRoot.add(point);
		} else if (s->isToken("link")) {
			s->getToken(true);

			int sourceId;
			sscanf(s->getToken(true), "%d", &sourceId);
			int destId;
			sscanf(s->getToken(true), "%d", &destId);

			// Link the source and destination points
			if (sourceId != destId) {
				RoutePoint* sourcePoint      = nullptr;
				RoutePoint* destinationPoint = nullptr;

				FOREACH_NODE(RoutePoint, mPointListRoot.mChild, c)
				{
					if (c->mIndex == sourceId) {
						sourcePoint = c;
					}
					if (c->mIndex == destId) {
						destinationPoint = c;
					}
				}

				if (sourcePoint && destinationPoint) {
					RouteLink* link = new RouteLink();
					link->mPoint    = destinationPoint;
					sourcePoint->mLink.add(link);
				}
			}

			s->getToken(true);
		}
	}

	if (!s->endOfCmds()) {
		s->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001C0
 */
void RouteGroup::saveini(char* name, RandomAccessStream& s)
{
	s.print("\n%sroute {\n", name);
	s.print("%s\tid\t\t%s\n", name, mStringID);
	s.print("%s\tname\t'%s'\n", name, mRouteName);
	s.print("%s\tcolour\t%d %d %d %d\n", name, mColour.r, mColour.g, mColour.b, mColour.a);

	int idx = 0;
	FOREACH_NODE(RoutePoint, mPointListRoot.mChild, point)
	{
		point->mIndex = idx++;
		s.print("\n%s\tpoint {\n", name);
		s.print("%s\t\tindex\t%d\n", name, point->mIndex);
		s.print("%s\t\tstate\t%d\n", name, point->mState);
		s.print("%s\t\tpos\t%f %f %f\n", name, point->mPosition.x, point->mPosition.y, point->mPosition.z);
		s.print("%s\t\twidth\t%f\n", name, point->mRadius);
		s.print("%s\t\t}\n", name);
	}
	s.print("\n");
	FOREACH_NODE(RoutePoint, mPointListRoot.mChild, point)
	{
		FOREACH_NODE(RouteLink, point->mLink.mChild, link)
		{
			s.print("%s\tlink { %d %d }\n", name, point->mIndex, link->mPoint->mIndex);
		}
	}

	s.print("%s\t}\n", name);
}
