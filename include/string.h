#include "types.h"

struct String
{
  u32 m_length; // _00
  u8 *m_str;    // _04

  int getLength();
};