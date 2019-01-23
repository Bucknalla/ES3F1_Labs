# Xilinx Vivado Setup

Created an HDL project in Xilinx Vivado to instantiate the Processing Unit and the Programable Logic Region.

### Vivado

1. Open Vivado and select Zybo Z7 board
2. Create an new Vivado Project
   1. Select **RTL Project** and **Do not specify sources at this time** and press **Next**
   2. Click on the **Boards** tab and scroll to find the **Zybo Z7-20**. Click **Next**.
   3. Accept these options by pressing **Finish**
3. Create empty block design inside the new project
   1. Add the **ZYNQ7 Processing System** IP core to the block diagram and run the **Block Automation**, accepting the default settings.
      1. We do not need to add any additional cores as we are only using the processing system in this lab. In future labs we will look at how to communicate between the PS and PL.
   2. Validate, save and generate the block design
   3. Create an HDL system wrapper (Right click on the block diagram, which will be called "design_1.bd" if you didn't rename it, under **Sources->Design Sources**)
   4. Run Synthesis and Implementation to generate the netlist and floor planning
   5. Generate Bitstream file
   6. Export Hardware Design (**File->Export->Export Hardware**) including the generated bitstream file to SDK tool
   7. Launch SDK (**File->Launch SDK**)
