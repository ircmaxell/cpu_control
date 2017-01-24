
namespace DEBUG {
#if DEBUG_ENABLE 
  void setup() {

    Serial.begin(9600);
  }

  void log(char *value) {
    Serial.println(value);
    delay(50);
  }
  
  void write(ADDRESS_BUS::address a) {
    Serial.print("Address: ");
    Serial.print(a, HEX);
    Serial.print("\n");
  }
  
  void write(int data) {
    Serial.print("Integer: ");
    Serial.print(data);
    Serial.print("\n");
  }
  void write(long data) {
    Serial.print("Long: ");
    Serial.print(data);
    Serial.print("\n");
  }
  void write(unsigned long data) {
    Serial.print("ULong: ");
    Serial.print(data, HEX);
    Serial.print("\n");
  }


#define DEBUG_ALU_OP(name_) case ALU::OP_##name_ : Serial.print(#name_); Serial.print("\n"); break;

  void write(ALU::OP op) {
    Serial.print("ALU Op: ");
    switch (op) {
      DEBUG_ALU_OP(ADD);
      DEBUG_ALU_OP(SUB);
      DEBUG_ALU_OP(AND);
      DEBUG_ALU_OP(OR);
      DEBUG_ALU_OP(XOR);
      DEBUG_ALU_OP(INC);
      DEBUG_ALU_OP(DEC);
      DEBUG_ALU_OP(FF);
      DEBUG_ALU_OP(00);
      DEBUG_ALU_OP(NOT);
    }
  }
  
#undef DEBUG_ALU_OP

  void write(byte data) {
    Serial.print("Byte: ");
    Serial.print(data, BIN);
    Serial.print("\n");
  }
  
#define DEBUG_REGISTER(name_) case REGISTERS::REGISTER_##name_ : Serial.print(#name_); Serial.print("\n"); break;

  void write(REGISTERS::REGISTER r) {
    Serial.print("Register: ");
    switch (r) {
      DEBUG_REGISTER(A);
      DEBUG_REGISTER(B);
      DEBUG_REGISTER(C);
      DEBUG_REGISTER(J1);
      DEBUG_REGISTER(J2);
      DEBUG_REGISTER(J);
      DEBUG_REGISTER(PC);
      DEBUG_REGISTER(INCDEC);
      DEBUG_REGISTER(INC);
      DEBUG_REGISTER(DEC);
      DEBUG_REGISTER(ALU);
      DEBUG_REGISTER(ALU_RESULT);
      DEBUG_REGISTER(ALU_FLAGS);
      DEBUG_REGISTER(MEMORY);
    }
  }
  
#undef DEBUG_REGISTER

  
  void instruction(char *name) {
    Serial.print("Executing instruction ");
    Serial.print(name);
    Serial.print("\n");
  }
#else
  void setup() {
  }

  void log(char *value) {
  }
  
  void write(ADDRESS_BUS::address a) {
  }
  
  void write(int data) {
  }
  void write(long data) {
  }
  void write(unsigned long data) {
  }

  void write(ALU::OP op) {
  }
  
  void write(byte data) {
  }
  
  void write(REGISTERS::REGISTER r) {
  }
  
  void instruction(char *name) {
  }
#endif
}
