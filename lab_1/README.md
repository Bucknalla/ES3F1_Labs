<p align="center"> 
<img src="img/banner.png">
</p>

### ES3F1 Lab 1

Lab 1 is an introduction to Xilinx's Zynq SoC Architecture using the Digilent Zybo Z7-20 series FPGA boards. We'll walk through setting up the processing system in hardware, exporting this from Vivado to the Xilinx SDK environment and writing some software in C to run on one of the ARM cores.

### Objectives

Successfully export a basic Processing System layer in hardware to the SDK in order to write a C program that computes the multiplication of two square matrices and returns the solution + the time taken for program execution.

Follow the set up example in the rtl instructions, moving onto the src instructions when you've successfully exported the hardware bitstream.

1. Visit the Xilinx Documentation for information on the what timers are available and which is best suited for timing clock cycles. Create an instance of your chosen timer at the entry point of your program. We'll use this later to time our multiplication function. A starting C template can be found in [src](src).

- Hint: Read through the xtime_l.h header file to see which functions are available (https://github.com/Xilinx/embeddedsw/blob/master/lib/bsp/standalone/src/arm/cortexa9/xtime_l.h)

2. Create a C function that takes a int pointer to a pointer and initialises the passed 2D array with a random function using the rand() function. Make sure to allocate memory for each array. Don't forget to seed your rand() function with srand() to ensure that you don't get the same results each time the program runs.

3. Allow for a macro to set the size of the input 2D array (i.e. #define SIZE). We'll use this to see the effect on matrix size against the required clock cycles for computation.

4. Write a function that takes 3 array pointers and multiplies the first two, storing the result in the 3rd.

5. Use the timer from step 1. to sample the time before and after the multiplication and calculate the time taken for the computation.

6. Don't forget to deallocate memory and run "cleanup_platform()" at the end of your program to release any used instances from memory.

Note - you can print data to the serial terminal (within the Xilinx SDK) using the "xil_printf.h" library. This function however does not support floating point values, so you will need to use printf() from the <stdio.h> library with standard "%f" formatting, instead.

### Extra

1. Modify your function to handle 2D arrays that contain floats, how does this affect the computation time? 

2. Think about how we might do this multiplication on an FPGA? Could we offload the multiplication from the processing system to the FPGA to improve performance? What are the constraints with working with floating point numbers on an FPGA? 
