这是使用 verilator 仿真的单模块demo

在当前目录

1 make 
产生 obj_dir

2 make -C obj_dir -f Vtop.mk Vtop
使用 obj_dir 中的.mk

3 ./obj_dir/Vtop 
产生波形图

4 gtkwave waveform.vcd
X11forward 配置参见
https://blog.csdn.net/qq_62573253/article/details/135369581