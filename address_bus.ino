
namespace ADDRESS_BUS {
  
  void setup() {
    setPinModes(INPUT);
  }
  
  void beginWrite(address data) {
    DEBUG::log("Writing to address bus:");
    DEBUG::write(data);
    setPinModes(OUTPUT);
    for (int i = 0; i < 16; i++) {
      digitalWrite(PINS::address_bus[i], data & (1UL << i) ? HIGH : LOW);
    }
  }
  
  void endWrite() {
    DEBUG::log("End address bus write");
    setPinModes(INPUT);
  }
  
  address read() {
    DEBUG::log("Reading from address bus");
    setPinModes(INPUT);
    address result = 0;
    for (int i = 0; i < 16; i++) {
      result |= digitalRead(PINS::address_bus[i]) == HIGH ? 1 << i : 0;
    }
    DEBUG::write(result);
    return result;
  }
  
  void setPinModes(int mode) {
    for (int i = 0; i < 16; i++) {
      pinMode(PINS::address_bus[i], mode);
    }
  }

}
