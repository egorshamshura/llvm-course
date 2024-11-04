#include "sim.h"

int px[SIM_X_SIZE * SIM_Y_SIZE];

void dump()
{
  for (int i = 0; i != SIM_X_SIZE; ++i)
  {
    for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      simPutPixel(i, j, px[j * SIM_X_SIZE + i]);
    }
  }
  simFlush();
}

void left_right(int color)
{
  for (int i = 0; i != SIM_X_SIZE; ++i)
  {
    for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      px[j * SIM_X_SIZE + i] = color;
    }
    dump();
  }
}

void right_left(int color)
{
  for (int i = SIM_X_SIZE - 1; i > 0; --i)
    {
      for (int j = 0; j != SIM_Y_SIZE; ++j)
      {
        px[j * SIM_X_SIZE + i] = color;
      }
      dump();
    }
}

void up_down(int color)
{
  for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      for (int i = 0; i != SIM_X_SIZE; ++i)
      {
        px[j * SIM_X_SIZE + i] = color;
      }
      dump();
    }
}

void down_up(int color)
{
  for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      for (int i = SIM_X_SIZE - 1; i > 0; --i)
      {
        px[j * SIM_X_SIZE + i] = color;
      }
      dump();
    }
}

void app()
{
  int const colors[] = {0xffff6347, 0xffa4ffa4, 0xffe580ff, 0xffffcc00, 0xff91d2ff};
  while (1) {
    int color = colors[(unsigned) simRand() % 5];
    int type = (unsigned) simRand() % 4;
    if (type == 0)
      left_right(color);
    if (type == 1)
      right_left(color);
    if (type == 2)
      up_down(color);
    if (type == 3)
      down_up(color);
  }
 }
