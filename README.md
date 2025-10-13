This is verilog simlation demo using oepn-source EDA tool verilator

In current directory with *.v

Step1 make 
produce obj_dir

Step2 make -C obj_dir -f Vtop.mk Vtop
using .mk in obj_dir 

Step3 ./obj_dir/Vtop 
produce waveform.vcd

Step4 gtkwave waveform.vcd
Open with gtkwave tool, through X11forward link between PC-client and VM-server 
the X11forward configuration in CSDN [https://blog.csdn.net/qq_62573253/article/details/135369581]
