file := $(shell find . -name "*.v")

all:
	# verilator --binary -j 0 -Wall $(file)
	verilator -j 0 --cc $(file) --trace --exe sim_main.cpp