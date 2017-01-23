#include "alu_control.h"
#include "data_bus.h"
#include "address_bus.h"
#include "pins.h"
#include "registers.h"
#include "instructions.h"
#include "vm.h"

void setup() {
  ALU::setup();
  DATA_BUS::setup();
  ADDRESS_BUS::setup();
  REGISTERS::setup();
}

void loop() {
}

void loadMemory() {
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
