
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

}
