#include "sim.h"

void init(char cg[][SIM_Y_SIZE])
{
  for (int i = 0; i != SIM_X_SIZE; ++i)
  {
    for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      cg[i][j] = 0;
    }
  }

  cg[1][6] = 1;
  cg[1][7] = 1;
  cg[2][6] = 1;
  cg[2][7] = 1;

  cg[11][6] = 1;
  cg[11][7] = 1;
  cg[11][8] = 1;

  cg[12][5] = 1;
  cg[12][9] = 1;
  
  cg[13][4] = 1;
  cg[13][10] = 1;
  cg[14][4] = 1;
  cg[14][10] = 1;

  cg[15][7] = 1;

  cg[16][5] = 1;
  cg[16][9] = 1;

  cg[17][6] = 1;
  cg[17][7] = 1;
  cg[17][8] = 1;

  cg[18][7] = 1;

  cg[21][6] = 1;
  cg[21][5] = 1;
  cg[21][4] = 1;
  cg[22][6] = 1;
  cg[22][5] = 1;
  cg[22][4] = 1;
  
  cg[23][3] = 1;
  cg[23][7] = 1;

  cg[25][2] = 1;
  cg[25][3] = 1;
  cg[25][7] = 1;
  cg[25][8] = 1;

  cg[35][4] = 1;
  cg[35][5] = 1;
  cg[36][4] = 1;
  cg[36][5] = 1;
}

void clear(char array[][SIM_Y_SIZE])
{
  for (int i = 0; i != SIM_X_SIZE; ++i)
  {
    for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      array[i][j] = 0;
    }
  }
}

void dump(char array[][SIM_Y_SIZE])
{
  for (int i = 0; i != SIM_X_SIZE; ++i)
  {
    for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      if (array[i][j] == 1)
        simPutPixel(i, j, 0x0);
      else
        simPutPixel(i, j, 0xffffffff);
    }
  }
  simFlush();
}

int get(int n, int mod)
{
  return ((n % mod) + mod) % mod;
}

void next_generation(int* halt, char cg[][SIM_Y_SIZE], char tg[][SIM_Y_SIZE])
{
  for (int i = 0; i != SIM_X_SIZE; ++i)
  {
    for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      int alive = cg[get(i - 1, SIM_X_SIZE)][get(j - 1, SIM_Y_SIZE)]
        + cg[get(i - 1, SIM_X_SIZE)][j]
        + cg[get(i - 1, SIM_X_SIZE)][get(j + 1, SIM_Y_SIZE)]
        + cg[i][get(j - 1, SIM_Y_SIZE)]
        + cg[i][get(j + 1, SIM_Y_SIZE)]
        + cg[get(i + 1, SIM_X_SIZE)][get(j - 1, SIM_Y_SIZE)]
        + cg[get(i + 1, SIM_X_SIZE)][j]
        + cg[get(i + 1, SIM_X_SIZE)][get(j + 1, SIM_Y_SIZE)];
      if (alive == 3 || alive == 2 && cg[i][j] == 1)
        tg[i][j] = 1;
      else
        tg[i][j] = 0;
    }
  }
  int same = 1;
  for (int i = 0; i != SIM_X_SIZE; ++i)
  {
    for (int j = 0; j != SIM_Y_SIZE; ++j)
    {
      if (cg[i][j] != tg[i][j])
        same = 0;
      cg[i][j] = tg[i][j];
      tg[i][j] = 0;
    }
  }
  if (same == 1)
    halt = 0;
}

void app()
{
  int halt = 1;
  char current_generation[SIM_X_SIZE][SIM_Y_SIZE];
  init(current_generation);
  char temporary_generation[SIM_X_SIZE][SIM_Y_SIZE];
  clear(temporary_generation);
  while (halt) {
    dump(current_generation);
    next_generation(&halt, current_generation, temporary_generation);
  }
}
