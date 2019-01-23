#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include "xtime_l.h"
#include <stdlib.h>
#include "xil_printf.h"

/* uncomment to see each stage of multiplication */
//#define DEBUG

#define SIZE 5
#define MAX_VAL 10
#define MIN_VAL 0

void generate(int **array)
{
  int i, j;

  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
    {
      /* populate rows and columns with rand() values */
      array[i][j] = rand() % (MAX_VAL + 1 - MIN_VAL) + MIN_VAL;
      xil_printf("%d\t", array[i][j]);
    }
    xil_printf("\n\r");
  }
  xil_printf("\n\r");
};

void multiply(int **array_x, int **array_y, int **array_z)
{
  int i, j, k;

  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
    {
      array_z[i][j] = 0;
      for (k = 0; k < SIZE; k++)
      {
        array_z[i][j] += (array_x[i][k] * array_y[k][j]);

#if defined(DEBUG)
        xil_printf("z: %d = x: %d * y %d\n\r", array_x[i][j], array_x[i][k], array_y[k][j]);
#endif
      }
    }
  }
};

int main()
{
  XTime tSeed, tStart, tEnd;

  init_platform();
  xil_printf("Seeding rand()...\n\r");

  /* use start time as a seed for rand() */
  XTime_GetTime(&tSeed);
  srand(tSeed);

  int rows = SIZE, cols = SIZE, i, j;
  int **x, **y, **z;

  /* allocate the array in memory */
  x = malloc(rows * sizeof *x);
  y = malloc(rows * sizeof *y);
  z = malloc(rows * sizeof *x);

  for (i = 0; i < rows; i++)
  {
    x[i] = malloc(cols * sizeof *x[i]);
    y[i] = malloc(cols * sizeof *y[i]);
    z[i] = malloc(cols * sizeof *z[i]);
  }

  xil_printf("Generating Matrices X, Y & Z...\n\n\r");

  xil_printf("Matrix X\n\r");
  generate(x);

  xil_printf("Matrix Y\n\r");
  generate(y);

  xil_printf("Multiplying X & Y and starting timer...\n\n\r");

  /* get time at start of multiplication */
  XTime_GetTime(&tStart);

  /* no print statements within this function */
  multiply(x, y, z);

  /* get time at end of multiplication */
  XTime_GetTime(&tEnd);

  xil_printf("Stopping timer...\n\n\r");

  xil_printf("Result Matrix Z\n\r");

  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
    {
      xil_printf("%d\t", z[i][j]);
    }
    xil_printf("\n\r");
  }

  /* deallocate the array from memory */
  for (i = 0; i < rows; i++)
  {
    free(x[i]);
    free(y[i]);
  }
  free(x);
  free(y);

  /* 2 clock cycles per unit of time */
#if !defined(DEBUG)
  printf("\nMultiplication of X & Y took %llu clock cycles.\n", 2 * (tEnd - tStart));
  printf("Multiplication of X & Y took %.3f us.\n", 1.0 * (tEnd - tStart) / (COUNTS_PER_SECOND / 1000000));
#else
  /* printing text over serial is clock cycle expensive and introduces additional overhead */
  printf("\nMultiplication was run under DEBUG, timer is no longer accurate.\n\r");
#endif
  cleanup_platform();
  return 0;
}
