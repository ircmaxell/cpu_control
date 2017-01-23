

#include "alu_control.h"
#include "data_bus.h"
#include "address_bus.h"
#include "pins.h"
#include "registers.h"
#include "instructions.h"
#include "vm.h"
#include "programs.h"
#include "debug.h"

void setup() {
  DEBUG::setup();
  ALU::setup();
  DATA_BUS::setup();
  ADDRESS_BUS::setup();
  REGISTERS::setup();
}

void loop() {
  //loadProgram(program1);
  //VM::run();
  loadMemoryTest();
  exit(0);
}

void loadMemoryTest() {
  for (int i = 0; i < 1<<16; i++) {
    ADDRESS_BUS::beginWrite(i & 0xFFFF);
    DATA_BUS::beginWrite(i & 0xFF);
    REGISTERS::beginWrite(REGISTERS::REGISTER_MEMORY);
    INSTRUCTIONS::wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_MEMORY);
    DATA_BUS::endWrite();
    ADDRESS_BUS::endWrite();
  }
}

void loadProgram(PROGRAM p) {
  DEBUG::log("Loading program...");
  for (int i = 0; i < p.length; i++) {
    ADDRESS_BUS::beginWrite(i & 0xFFFF);
    DATA_BUS::beginWrite(p.data[i]);
    REGISTERS::beginWrite(REGISTERS::REGISTER_MEMORY);
    INSTRUCTIONS::wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_MEMORY);
    DATA_BUS::endWrite();
    ADDRESS_BUS::endWrite();
  }
  DEBUG::log("Loaded");
}


