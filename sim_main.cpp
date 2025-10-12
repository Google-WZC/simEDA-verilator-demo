#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Vtop.h"      // 从 "top.v" 生成的类
#include "verilated.h" // Verilator 核心库
#include "verilated_vcd_c.h"

int main(int argc, char **argv) {
  // 2. 初始化 Verilator
  Verilated::commandArgs(argc, argv);

  // 3. 实例化你的 Verilog 模块
  Vtop *top = new Vtop;
  // Vtop *top = {0};

  // 初始化随机数种子
  srand(time(NULL));

  // --- 波形设置开始 ---
  Verilated::traceEverOn(true); // 开启波形追踪
  VerilatedVcdC *tfp = new VerilatedVcdC;
  top->trace(tfp, 99);       // 99是追踪深度
  tfp->open("waveform.vcd"); // 打开要写入的VCD文件
  int i = 0;
  while (i < 10) {
    i++;
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->eval();
    printf("a = %d, b = %d, f = %d\n", a, b, top->f);
    assert(top->f == (a ^ b));

    tfp->dump(i);
  }

  // --- 清理 ---
  tfp->close(); // 关闭 VCD 文件
  delete top;
  exit(0);
}