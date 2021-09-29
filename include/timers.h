#include "types.h"

struct Graphics;
struct Font;

struct Timers
{
  /*TimerInf* m_timers <-- instead of m_word0*/
  u32 m_word0;
  u32 m_frameCount;
  u32 m_word8;

  void reset();
  void newFrame();
  void _start(char *, bool);
  void _stop(char *);
  void showTimes();
  void draw(Graphics &, Font *);
};