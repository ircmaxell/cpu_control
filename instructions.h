
namespace INSTRUCTIONS {
  const int cycleDelay = 100; // microseconds

  void wait();
  
#define PC_READ_START() \
    REGISTERS::beginRead(REGISTERS::REGISTER_PC); \
    REGISTERS::beginRead(REGISTERS::REGISTER_MEMORY); \
    REGISTERS::beginWrite(REGISTERS::REGISTER_INC);

#define PC_READ_END() \
    REGISTERS::endWrite(REGISTERS::REGISTER_INC); \
    REGISTERS::endRead(REGISTERS::REGISTER_MEMORY); \
    REGISTERS::endRead(REGISTERS::REGISTER_PC);
    
#define PC_READ(r_) \
    PC_READ_START() \
    wait(); \
    r_ = DATA_BUS::read(); \
    PC_READ_END()
    
    
#define PC_INC_START() \
    REGISTERS::beginRead(REGISTERS::REGISTER_INCDEC); \
    REGISTERS::beginWrite(REGISTERS::REGISTER_PC);

#define PC_INC_END() \
    REGISTERS::endWrite(REGISTERS::REGISTER_PC); \
    REGISTERS::endRead(REGISTERS::REGISTER_INCDEC);

#define PC_INC() \
    PC_INC_START() \
    wait(); \
    PC_INC_END()
    
#define ALU_OP(name_,op_name_)                        \
  void name_() {                                      \
    byte r;                                           \
    PC_READ(r);                                       \
    PC_INC_START();                                   \
    REGISTERS::beginRead(REGISTERS::decodeRead(r));   \
    ALU::setMode(ALU::OP_##op_name_);                 \
    REGISTERS::beginWrite(REGISTERS::REGISTER_ALU);   \
    wait();                                           \
    REGISTERS::endWrite(REGISTERS::REGISTER_ALU);     \
    REGISTERS::endRead(REGISTERS::decodeRead(r));     \
    PC_INC_END();                                     \
    REGISTERS::beginRead(REGISTERS::REGISTER_ALU);    \
    REGISTERS::beginWrite(REGISTERS::decodeWrite(r)); \
    wait();                                           \
    REGISTERS::endWrite(REGISTERS::decodeWrite(r));   \
    REGISTERS::endRead(REGISTERS::REGISTER_ALU);      \
  }
  
#define READ_REGISTER(name_,dest_) \
    REGISTERS::beginRead(REGISTERS::REGISTER_##name_); \
    wait(); \
    dest_ = DATA_BUS::read(); \
    REGISTERS::endRead(REGISTERS::REGISTER_##name_);

#define JUMP_FLAG(name_, flag_name_, direction_)     \
  void jump_##name_() {                             \
    byte f;                                         \
    READ_REGISTER(ALU_FLAGS, f);                    \
    PC_READ_START();                                \
    REGISTERS::beginWrite(REGISTERS::REGISTER_J1);  \
    wait();                                         \
    REGISTERS::endWrite(REGISTERS::REGISTER_J1);    \
    PC_READ_END();                                  \
    PC_INC();                                       \
    PC_READ_START();                                \
    REGISTERS::beginWrite(REGISTERS::REGISTER_J2);  \
    wait();                                         \
    REGISTERS::endWrite(REGISTERS::REGISTER_J2);    \
    PC_READ_END();                                  \
    if (direction_ ^ ALU::hasFlag(f, ALU::FLAG_##flag_name_)) { \
      REGISTERS::beginRead(REGISTERS::REGISTER_J);              \
      REGISTERS::beginWrite(REGISTERS::REGISTER_PC);            \
      wait();                                                   \
      REGISTERS::endWrite(REGISTERS::REGISTER_PC);              \
      REGISTERS::endRead(REGISTERS::REGISTER_J);                \
    } else {                                                    \
      PC_INC();                                                 \
    }                                                           \
  }
    
    
    
    
    
    
    
}
