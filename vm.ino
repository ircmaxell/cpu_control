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
        
      // Data Functions
      DISPATCH(0x01, move);
      DISPATCH(0x02, load);
      DISPATCH(0x03, load_immediate);
      DISPATCH(0x04, load_address);
      DISPATCH(0x05, store);
      DISPATCH(0x06, store_address);
      
      // ALU Functions
      DISPATCH(0x10, add);
      DISPATCH(0x11, sub);
      DISPATCH(0x12, bw_and);
      DISPATCH(0x13, bw_or);
      DISPATCH(0x14, bw_xor);
      DISPATCH(0x15, inc);
      DISPATCH(0x16, dec);
      DISPATCH(0x17, bw_not);
      DISPATCH(0x18, zero);
      DISPATCH(0x19, ff);
      
      // Jumps
      DISPATCH(0x20, jump);
      DISPATCH(0x21, jump_indirect);
      DISPATCH(0x22, jump_zero);
      DISPATCH(0x23, jump_not_zero);
      DISPATCH(0x24, jump_negative);
      DISPATCH(0x25, jump_positive);
      DISPATCH(0x26, jump_carry);
      DISPATCH(0x27, jump_no_carry);
      
      
    }
  }



}
