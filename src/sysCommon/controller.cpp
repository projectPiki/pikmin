#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
  // UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
  // UNUSED FUNCTION
}

struct Controller
{
  u8 unknown00[0x20];
  u32 _20;
  u32 _24;
  u32 _28;
  u32 _2C;
  u32 _30;
  u32 _34;
  u32 _38;
  u32 _3C;
  u32 _40;
  bool _44;

  void reset(unsigned long);
  void updateCont(unsigned long);
  void update();
  void getMainStickX();
  void getMainStickY();
  void getSubStickX();
  void getSubStickY();
};

/*
 * --INFO--
 * Address:	800409B0
 * Size:	000024
 */
void Controller::reset(unsigned long arg1)
{
  _3C = -1;
  _44 = false;
  _38 = arg1;
  _40 = 0;
  _20 = 0;
  _24 = 0;
}

/*
 * --INFO--
 * Address:	800409D4
 * Size:	00009C
 */
void Controller::updateCont(unsigned long arg1)
{
  _24 = _20;
  _20 = 0;

  if (!_44)
  {
    _20 = arg1;
  }

  _28 = _20 & ~_24;
  _20 = _24 & ~_20;

  if (_40)
  {
    _30 = 0;

    if (!(_34 = _28))
    {
      return;
    }

    _40 = 10;
  }
  else
  {
    if (!(--_40))
    {
      return;
    }

    if (!(_30 = _34 & _28))
    {
      return;
    }

    _40 = 0;
  }
}

/*
 * --INFO--
 * Address:	80040A70
 * Size:	00002C
 */
struct ControllerManager
{
  void updateController(Controller *);
};

struct System
{
  u8 data[0x27C];
  ControllerManager *m_contManager;
};

extern System *gsys;

void Controller::update()
{
  gsys->m_contManager->updateController(this);
}

/*
 * --INFO--
 * Address:	80040A9C
 * Size:	000038
 */
void Controller::getMainStickX()
{
  /*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x4330
  lbz       r3, 0x45(r3)
  lfd       f2, -0x7C00(r2)
  extsb     r3, r3
  lfs       f0, -0x7C08(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x14(r1)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80040AD4
 * Size:	000038
 */
void Controller::getMainStickY()
{
  /*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x4330
  lbz       r3, 0x46(r3)
  lfd       f2, -0x7C00(r2)
  extsb     r3, r3
  lfs       f0, -0x7C08(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x14(r1)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80040B0C
 * Size:	000038
 */
void Controller::getSubStickX()
{
  /*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x4330
  lbz       r3, 0x47(r3)
  lfd       f2, -0x7C00(r2)
  extsb     r3, r3
  lfs       f0, -0x7C08(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x14(r1)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80040B44
 * Size:	000038
 */
void Controller::getSubStickY()
{
  /*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x4330
  lbz       r3, 0x48(r3)
  lfd       f2, -0x7C00(r2)
  extsb     r3, r3
  lfs       f0, -0x7C08(r2)
  xoris     r3, r3, 0x8000
  stw       r3, 0x14(r1)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  addi      r1, r1, 0x18
  blr
*/
}
