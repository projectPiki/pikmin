#include "types.h"

#define PI 3.14159265359

extern "C" float sinf(float);

struct CollTriInfo{
    char filler[24];
    f32 float1;
    f32 float2;
    f32 float3;
    char filler2[4];
    f32 float4;
    f32 float5;
    f32 float6;
    f32 float7;
};

class MapCode {
    u32 _00;
    u32 _04;
    u32 _08;
    u32 _0C;
    u32 _10;
    u32 _14;
    u32 _18;
    f32 _1C;

    u32 getAttribute(CollTriInfo*);
    char* getAttributeName(int); // UNUSED
    u32 getSlipCode(CollTriInfo *);
    bool isBald(CollTriInfo *);
};

/*
 * --INFO--
 * Address:	80116080
 * Size:	00000C
 */
u32 MapCode::getAttribute(CollTriInfo*)
{
    return _00 >> 29;
};


/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
char* MapCode::getAttributeName(int)
{
	// UNUSED FUNCTION
	return "UNUSED";
};

/*
 * --INFO--
 * Address:	8011608C
 * Size:	00001C
 */
u32 MapCode::getSlipCode(CollTriInfo *)
{
  if (this != (nullptr)) {
    return _00 >> 27 & 3;
  }
  else { return 0; }
};

/*
 * --INFO--
 * Address:	801160A8
 * Size:	000068
 */
bool MapCode::isBald(CollTriInfo *)
{
return (this != nullptr) ? ( _1C < sinf(45*PI/180)) ? true : ((_00 >> 25 & 1) != 0) ? false : true : true;
}
