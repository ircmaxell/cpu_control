
namespace ALU {

  void setup() {
    pinMode(PINS::alu.mode4, OUTPUT);
    pinMode(PINS::alu.mode2, OUTPUT);
    pinMode(PINS::alu.mode1, OUTPUT);
    pinMode(PINS::alu.zero, OUTPUT);
    pinMode(PINS::alu.invert, OUTPUT);
  }
  
  void setMode(OP op) {
    digitalWrite(PINS::alu.mode4, ops[op].mode4 ? HIGH : LOW);
    digitalWrite(PINS::alu.mode2, ops[op].mode2 ? HIGH : LOW);
    digitalWrite(PINS::alu.mode1, ops[op].mode1 ? HIGH : LOW);
    digitalWrite(PINS::alu.zero, ops[op].zero ? HIGH : LOW);
    digitalWrite(PINS::alu.invert, ops[op].invert ? HIGH : LOW);
  }

}

