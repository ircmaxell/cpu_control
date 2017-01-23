namespace VM {

  void run() {
    byte instruction;
    int s = 0;
    while (true) {
      instruction = INSTRUCTIONS::decode();
      s = dispatch(instruction);
      if (s == 1) {
        // halt
        return;
      }
    }
  }

  int dispatch(byte instruction) {
    switch (instruction) {
      case 0x00:
        return 1;
      case 0x01:
        INSTRUCTIONS::move();
        break;
      case 0x02:
        INSTRUCTIONS::load();
        break;
      case 0x03:
        INSTRUCTIONS::load_immediate();
        break;
    }
  }



}
