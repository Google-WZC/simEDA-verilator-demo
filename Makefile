file := $(shell find . -name "*.v")
TOP := TOP

.PHONY: all run view clean

all:
	@echo "------------------------------parse------------------------------"
	verilator -j 0 --cc $(file) --trace --exe sim_main.cpp --top-module $(TOP)
	@echo "\n------------------------------compile------------------------------"
	make -C obj_dir -f V$(TOP).mk V$(TOP)
	@echo "\n------------------------------open------------------------------"
	./obj_dir/V$(TOP) 
	@echo "\n------------------------------wavelook------------------------------"
	gtkwave waveform.vcd

clean:
	@echo "Cleaning up..."
	rm -rf obj_dir waveform.vcd
