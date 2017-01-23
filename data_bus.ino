namespace DATA_BUS {

  void setup() {
    setPinModes(INPUT);
  }

  void beginWrite(byte data) {
    DEBUG::log("Writing to data bus:");
    DEBUG::write(data);
    setPinModes(OUTPUT);
    for (int i = 0; i < 8; i++) {
      digitalWrite(PINS::data_bus[i], data & (1 << i) ? HIGH : LOW);
    }
  }

  void endWrite() {
    DEBUG::log("End data bus write");
    setPinModes(INPUT);
  }

  byte read() {
    DEBUG::log("Reading from data bus");
    byte result = 0;
    setPinModes(INPUT);
    for (int i = 0; i < 8; i++) {
      result |= digitalRead(PINS::data_bus[i]) == HIGH ? 1 << i : 0;
    }
    DEBUG::write(result);
    return result;
  }

  void setPinModes(int mode) {
    for (int i = 0; i < 8; i++) {
      pinMode(PINS::data_bus[i], mode);
    }
  }

}

