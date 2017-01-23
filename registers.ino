namespace REGISTERS {

  void setup() {
    setupRegister(PINS::registers.a);
    setupRegister(PINS::registers.b);
    setupRegister(PINS::registers.c);
    setupRegister(PINS::registers.j1);
    setupRegister(PINS::registers.j2);
    setupRegister(PINS::registers.j);
    setupRegister(PINS::registers.pc);
    setupRegister(PINS::registers.incdec);
    setupRegister(PINS::registers.inc);
    setupRegister(PINS::registers.dec);
    setupRegister(PINS::registers.alu);
    setupRegister(PINS::registers.alu_result);
    setupRegister(PINS::registers.alu_flags);
    setupRegister(PINS::registers.memory);  
  }

#define WRITE_REGISTER(name_,uname_,value) \
case REGISTER_##uname_ :\
  digitalWrite(PINS::registers.name_.write, value);\
        break;

  void writeRegister(REGISTER r, int value) {
    switch (r) {
      WRITE_REGISTER(a, A, value);
      WRITE_REGISTER(b, B, value);
      WRITE_REGISTER(c, C, value);
      WRITE_REGISTER(j1, J1, value);
      WRITE_REGISTER(j2, J2, value);
      WRITE_REGISTER(pc, PC, value);
      WRITE_REGISTER(inc, INC, value);
      WRITE_REGISTER(dec, DEC, value);
      WRITE_REGISTER(alu, ALU, value);
      WRITE_REGISTER(memory, MEMORY, value);
    case REGISTER_J:
    case REGISTER_INCDEC:
    case REGISTER_ALU_RESULT:
    case REGISTER_ALU_FLAGS:
      // ignore
      break;
    }
  }

#undef WRITE_REGISTER

  void beginWrite(REGISTER r) {
    DEBUG::log("Begining register write");
    DEBUG::write(r);
    writeRegister(r, HIGH);
  }

  void endWrite(REGISTER r) {
    DEBUG::log("Ending register read");
    DEBUG::write(r);
    writeRegister(r, LOW);
  }

#define READ_REGISTER(name_,uname_,value) \
case REGISTER_##uname_ :\
  digitalWrite(PINS::registers.name_.read, value); \
        break;

  void readRegister(REGISTER r, int value) {
    switch (r) {
      READ_REGISTER(a, A, value);
      READ_REGISTER(b, B, value);
      READ_REGISTER(c, C, value);
      READ_REGISTER(j, J, value);
      READ_REGISTER(pc, PC, value);
      READ_REGISTER(incdec, INCDEC, value);
      READ_REGISTER(alu_result, ALU_RESULT, value);
      READ_REGISTER(alu_flags, ALU_FLAGS, value);
      READ_REGISTER(memory, MEMORY, value);
    case REGISTER_J1:
    case REGISTER_J2:
    case REGISTER_INC:
    case REGISTER_DEC:
    case REGISTER_ALU:
      // ignore
      break;
    }
  }

#undef READ_REGISTER

  void beginRead(REGISTER r) {
    DEBUG::log("Begining register read");
    DEBUG::write(r);
    readRegister(r, HIGH);
  }

  void endRead(REGISTER r) {
    DEBUG::log("Ending register read");
    DEBUG::write(r);
    readRegister(r, LOW);
  }

  REGISTER decodeRead(byte r) {
    return (REGISTER) (r & 0xF);
  }

  REGISTER decodeWrite(byte r) {
    return (REGISTER) ((r >> 4) & 0xF);
  }

  void setupRegister(PINS::REGISTER_RW r) {
    setupPin(r.read);
    setupPin(r.write);
  }

  void setupRegister(PINS::REGISTER_RO r) {
    setupPin(r.read);
  }

  void setupRegister(PINS::REGISTER_WO r) {
    setupPin(r.write);
  }

  void setupPin(byte pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}




