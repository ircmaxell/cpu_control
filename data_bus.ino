namespace DATA_BUS {

  void setup() {
    setPinModes(INPUT);
  }

  void beginWrite(byte data) {
    setPinModes(OUTPUT);
    for (int i = 0; i < 8; i++) {
      digitalWrite(PINS::data_bus[i], data & (1 << i) ? HIGH : LOW);
    }
  }

  void endWrite() {
    setPinModes(INPUT);
  }

  byte read() {
    byte result = 0;
    setPinModes(INPUT);
    for (int i = 0; i < 8; i++) {
      result |= digitalRead(PINS::data_bus[i]) == HIGH ? 1 << i : 0;
    }
    return result;
  }

  void setPinModes(int mode) {
    for (int i = 0; i < 8; i++) {
      pinMode(PINS::data_bus[i], mode);
    }
  }

}

