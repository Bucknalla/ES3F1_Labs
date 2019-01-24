#include <stdio.h>
#include "platform.h"
#include "xparameters.h"
#include <stdlib.h>
#include "xil_printf.h"

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

  generate_array(/* ARRAY */);

  multiply_arrays(/* ARRAY_X, ARRAY_Y, ARRAY_Z*/);
  
  cleanup_platform();
  return 0;
};
