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

#define DISPATCH(code_,name_) \
      case code_:\
        INSTRUCTIONS::name_();\
        break;

  int dispatch(byte instruction) {
    switch (instruction) {
      case 0x00:
        return 1;
      DISPATCH(0x01, move);
      DISPATCH(0x02, load);
      DISPATCH(0x03, load_immediate);
      DISPATCH(0x04, load_address);
      DISPATCH(0x05, store);
      DISPATCH(0x06, store_address);
      
    }
  }



}
