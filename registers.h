namespace REGISTERS {
  
  typedef enum REGISTER {
    REGISTER_A,
    REGISTER_B,
    REGISTER_C,
    REGISTER_J1,
    REGISTER_J2,
    REGISTER_J,
    REGISTER_PC,
    REGISTER_INCDEC,
    REGISTER_INC,
    REGISTER_DEC,
    REGISTER_ALU,
    REGISTER_ALU_RESULT,
    REGISTER_ALU_FLAGS,
    REGISTER_MEMORY
  } REGISTER;

  void setup();
 
  void setupRegister(PINS::REGISTER_RW r);
  void setupRegister(PINS::REGISTER_RO r);
  void setupRegister(PINS::REGISTER_WO r);
  
  void setupPin(byte pin);

  void beginWrite(REGISTER r);
  void endWrite(REGISTER r);
  
  void beginRead(REGISTER r);
  void endRead(REGISTER r);
  
  REGISTER decodeRead(byte r);
  REGISTER decodeWrite(byte r);

}
