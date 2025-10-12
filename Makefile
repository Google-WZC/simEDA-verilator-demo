file := $(shell find . -name "*.v")
TOP := "TOP"

all:
	verilator -j 0 --cc $(file) --trace --exe sim_main.cpp --top-module $(TOP)