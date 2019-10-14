#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include <stdlib.h>
#include "xil_printf.h"

#define SIZE 2

void generate_array(/* ARRAY */)
{
  /* Logic to generate array with rand() */
};

void multiply_arrays(/* ARRAY_X, ARRAY_Y, ARRAY_Z*/)
{
  /* Logic to multiply two arrays together and store in a result array */
};

int main()
{
  init_platform();
  xil_printf("Starting Program...");

  /* Declaration of the matrices and instantiate into memory */
  int rows = SIZE, cols = SIZE, i, j;
  int **x, **y, **z;

  x = malloc(rows * sizeof *x);
  y = malloc(rows * sizeof *y);
  z = malloc(rows * sizeof *x);

  for (i = 0; i < rows; i++)
  {
    x[i] = malloc(cols * sizeof *x[i]);
    y[i] = malloc(cols * sizeof *y[i]);
    z[i] = malloc(cols * sizeof *z[i]);
  }

  generate_array(/* ARRAY */);

  multiply_arrays(/* ARRAY_X, ARRAY_Y, ARRAY_Z*/);
  
  cleanup_platform();
  return 0;
};
