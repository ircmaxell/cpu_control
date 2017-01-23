
namespace ADDRESS_BUS {
  
  void setup() {
    setPinModes(INPUT);
  }
  
  void beginWrite(address data) {
    setPinModes(OUTPUT);
    for (int i = 0; i < 16; i++) {
      digitalWrite(PINS::address_bus[i], data & (1 << i) ? HIGH : LOW);
    }
  }
  
  void endWrite() {
    setPinModes(INPUT);
  }
  
  address read() {
    setPinModes(INPUT);
    address result = 0;
    for (int i = 0; i < 16; i++) {
      result |= digitalRead(PINS::address_bus[i]) == HIGH ? 1 << i : 0;
    }
    return result;
  }
  
  void setPinModes(int mode) {
    for (int i = 0; i < 16; i++) {
      pinMode(PINS::address_bus[i], mode);
    }
  }

}
