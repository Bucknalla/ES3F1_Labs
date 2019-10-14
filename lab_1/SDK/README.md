<p align="center"> 
<img src="../img/banner.png">
</p>

# Xilinx SDK Setup

Once you've exported your bitstream from Vivado and selected the "Launch SDK" option ("File"->"Launch SDK"), you'll need to create a new C/C++ project (we'll be working C for this lab).

### Application Project

1. Create a new **Application Project** ("File"->"New"->"Application Project").
   1. Give your project a name.
   2. Select **standalone** as the OS Platform (We won't be using an OS for this lab).
   3. Ensure that the hardware wrapper is the bitstream that you exported earlier from Vivado (should be something like **base_zynq_wrapper_hw_platform_0**).
   4. Select the **ps7_cortexa9_0** processor (the Zynq 7020 is dual core but we only need one for now)
   5. Choose **C** as your language.
   6. Select **Create New** for the Board Support Package (this file defines the peripherals available to the PS).
2. Select the template for **Hello World**, we'll use this as a boilerplate for configuring additional headers, etc. Press **Finish** and this will generate a new project along side the hardware wrapper. 
3. For convention, rename **helloworld.c** to **main.c** (this isn't important but it makes it clear where the entry point of the program is located)
4. Either copy or replace the code from [template.c](template.c) into the main.c file within the Xilinx SDK. Use this as a starting point to begin writing your program.
5. Ensure that the Zybo Z7 is plugged into the host PC (via the USB UART port) and that the jumper JP5 is set to JTAG. To program the FPGA (PL), click the **Program FPGA** button on the tool bar.
   1. Accept the default settings by pressing **Program**
   2. The Zybo Z7 board will illuminate the **Done** LED when it has finished programming.
6. Now we need to program the PS. Do this by **right clicking the code source of the project** (it will be named the same as the project name from section 1.1).
   1. Select **run as -> Launch on Hardware (System Debugger)**.
7. In the bottom of the SDK Window, there should be a tab named **SDK Terminal**. If your board is connected correctly, you'll be able to click the **green +** button to add a new serial connection.
   1. Under port, select your device's port (if using windows this will be **COM #**).
   2. The remainder of the settings should be as follows:
      - Data Bits: 8
      - Stop Bits: 1
      - Flow Control: None
      - Timeout (sec): *leave blank*
8. You should now have a serial connection open with the board and be able to see it receiving xil_printf() information from your application.
