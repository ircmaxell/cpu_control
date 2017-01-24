

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
  loadProgram(fibo);
  reset();
  VM::run();
 
  DEBUG::log("Exiting");
  delay(1000);
  
  ADDRESS_BUS::beginWrite(0x000F);
  delay(1000);
  
  exit(0);
}

void loadMemoryTest() {
  DEBUG::log("Loading memory test...");
  long i = 0;
  long j = 1UL << 16;
  DEBUG::write(j);
  for (i = 0; i < j; i++) {
    DEBUG::write(i);
    delay(10);
    ADDRESS_BUS::beginWrite(((int) i) & 0xFFFFUL);
    DATA_BUS::beginWrite(((int) i) & 0xFF);
    REGISTERS::beginWrite(REGISTERS::REGISTER_MEMORY);
    INSTRUCTIONS::wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_MEMORY);
    DATA_BUS::endWrite();
    ADDRESS_BUS::endWrite();
  }
  DEBUG::log("Memory test completed");
}

void loadProgram(PROGRAM p) {
  DEBUG::log("Loading program...");
  REGISTERS::beginWrite(REGISTERS::REGISTER_PC);
  for (unsigned int i = 0; i < p.length; i++) {
    ADDRESS_BUS::beginWrite(((int) i) & 0xFFFFUL);
    DATA_BUS::beginWrite(p.data[i]);
    REGISTERS::beginWrite(REGISTERS::REGISTER_MEMORY);
    INSTRUCTIONS::wait();
    delay(5);
    REGISTERS::endWrite(REGISTERS::REGISTER_MEMORY);
    DATA_BUS::endWrite();
    ADDRESS_BUS::endWrite();
  }
  REGISTERS::endWrite(REGISTERS::REGISTER_PC);
  DEBUG::log("Loaded");
}

void reset() {
  ADDRESS_BUS::beginWrite(0);
  REGISTERS::beginWrite(REGISTERS::REGISTER_PC);
  INSTRUCTIONS::wait();
  REGISTERS::endWrite(REGISTERS::REGISTER_PC);
  ADDRESS_BUS::endWrite();
}


