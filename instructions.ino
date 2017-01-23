
namespace INSTRUCTIONS {
  
  void wait() {
    delayMicroseconds(cycleDelay);
  }

  byte decode() {
    byte instruction = 0;
    PC_READ(instruction);
    PC_READ_END();
    PC_INC();
    return instruction;
  }
  
  void move() {
    byte r = 0;
    PC_READ(r);
    PC_INC_START();
    REGISTERS::beginRead(REGISTERS::decodeRead(r));
    REGISTERS::beginWrite(REGISTERS::decodeWrite(r));
    wait();
    REGISTERS::endWrite(REGISTERS::decodeWrite(4));
    REGISTERS::endRead(REGISTERS::decodeRead(r));
    PC_INC_END();
  }
  
  void load() {
    byte r = 0;
    PC_READ(r);
    PC_INC();
    REGISTERS::beginRead(REGISTERS::REGISTER_MEMORY);
    REGISTERS::beginWrite(REGISTERS::decodeWrite(r));
    wait();
    REGISTERS::endWrite(REGISTERS::decodeWrite(r));
    REGISTERS::endRead(REGISTERS::REGISTER_MEMORY);   
  }
  
  void load_immediate() {
    byte r = 0;
    PC_READ(r);
    PC_INC();
    PC_READ_START();
    REGISTERS::beginWrite(REGISTERS::decodeWrite(r));
    wait();
    REGISTERS::endWrite(REGISTERS::decodeWrite(r));
    PC_READ_END();
    PC_INC();
  }
  
  void load_address() {
    byte r;
    PC_READ(r);
    PC_INC();
    PC_READ_START();
    REGISTERS::beginWrite(REGISTERS::REGISTER_J1);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_J1);
    PC_READ_END();
    PC_INC();
    PC_READ_START();
    REGISTERS::beginWrite(REGISTERS::REGISTER_J2);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_J2);
    PC_READ_END();
    PC_INC();
    REGISTERS::beginRead(REGISTERS::REGISTER_J);
    REGISTERS::beginRead(REGISTERS::REGISTER_MEMORY);
    REGISTERS::beginWrite(REGISTERS::decodeWrite(r));
    wait();
    REGISTERS::endWrite(REGISTERS::decodeWrite(r));
    REGISTERS::endRead(REGISTERS::REGISTER_MEMORY);
    REGISTERS::endRead(REGISTERS::REGISTER_J);
  }
  
  void store() {
    byte r;
    PC_READ(r);
    PC_INC();
    REGISTERS::beginRead(REGISTERS::REGISTER_J);
    REGISTERS::beginRead(REGISTERS::decodeRead(r));
    REGISTERS::beginWrite(REGISTERS::REGISTER_MEMORY);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_MEMORY);
    REGISTERS::endRead(REGISTERS::decodeRead(r));
    REGISTERS::endRead(REGISTERS::REGISTER_J);
  }
  
  void store_address() {
    byte r;
    PC_READ(r);
    PC_INC();
    PC_READ_START();
    REGISTERS::beginWrite(REGISTERS::REGISTER_J1);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_J1);
    PC_READ_END();
    PC_INC();
    PC_READ_START();
    REGISTERS::beginWrite(REGISTERS::REGISTER_J2);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_J2);
    PC_READ_END();
    PC_INC();
    REGISTERS::beginRead(REGISTERS::REGISTER_J);
    REGISTERS::beginRead(REGISTERS::decodeRead(r));
    REGISTERS::beginWrite(REGISTERS::REGISTER_MEMORY);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_MEMORY);
    REGISTERS::endRead(REGISTERS::decodeRead(r));
    REGISTERS::endRead(REGISTERS::REGISTER_J);
  }

  ALU_OP(add, ADD)
  ALU_OP(sub, SUB)
  ALU_OP(bw_and, AND)
  ALU_OP(bw_or, OR)
  ALU_OP(bw_xor, XOR)
  ALU_OP(inc, INC)
  ALU_OP(dec, DEC)
  ALU_OP(ff, FF)
  ALU_OP(zero, 00)
  ALU_OP(bw_not, NOT)  

  void jump() {
    PC_READ_START();
    REGISTERS::beginWrite(REGISTERS::REGISTER_J1);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_J1);
    PC_READ_END();
    PC_INC();
    PC_READ_START();
    REGISTERS::beginWrite(REGISTERS::REGISTER_J2);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_J2);
    PC_READ_END();
    REGISTERS::beginRead(REGISTERS::REGISTER_J);
    REGISTERS::beginWrite(REGISTERS::REGISTER_PC);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_PC);
    REGISTERS::endRead(REGISTERS::REGISTER_J);
  }
  
  void jump_indirect() {
    REGISTERS::beginRead(REGISTERS::REGISTER_J);
    REGISTERS::beginWrite(REGISTERS::REGISTER_PC);
    wait();
    REGISTERS::endWrite(REGISTERS::REGISTER_PC);
    REGISTERS::endRead(REGISTERS::REGISTER_J);
  }
  
  JUMP_FLAG(zero, ZERO, 0);
  JUMP_FLAG(not_zero, ZERO, 1);
  JUMP_FLAG(negative, SIGN, 0);
  JUMP_FLAG(positive, SIGN, 1);
  JUMP_FLAG(carry, CARRY, 0);
  JUMP_FLAG(no_carry, CARRY, 1);

  
  
 
}
