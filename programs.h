
typedef struct PROGRAM {
  int length;
  byte *data;
} PROGRAM;

const PROGRAM program0 = {
  15,
  (byte[]) {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0X0C, 0x0D, 0x0E, 0x0F
  },
};

const PROGRAM test_all_registers = {
  16,
  (byte[]) {
    0x03, 0x00, 0xFF, // load 255 into A register
    0x03, 0x10, 0xFF, // load 255 into B register
    0x03, 0x20, 0xFF, // load 255 into C register
    0x03, 0x30, 0xFF, // load 255 into J1
    0x03, 0x40, 0xFF, // load 255 into J2
    0x00
  }
};


const PROGRAM program1 = {
  15,
  (byte[]) {
    0x03, 0x00, 0x01, // Load 0x01 into the A register
    0x03, 0x10, 0x02, // Load 0x02 into the B register
    0x03, 0x20, 0x03, // load 0x03 into the C register
    0x10, 0x11, // add A+B and store into B
    0x20, 0x00, 0x09, // Jump to previous instruction
    0x00 // halt
  },
};

const PROGRAM fibo = {
  19,
  (byte[]) {
    0x03, 0x00, 0x01, // start: MOV A 1     - Load 0x01 into the A register
    0x03, 0x10, 0x01, //        MOV B 1     - load 0x01 into the B register
    0x10, 0x21, //       j1:    ADD C B     - Add A + B and store in C
    0x01, 0x01, //              MOV A B     - copy b to a
    0x01, 0x12, //              MOV B C     - copy c to b
    0x24, 0x00, 0x00, //        JMPZ start  - jump to start if negative (overflow)
    0x20, 0x00, 0x06, //        JMP j1      - jump to add if not
    0x00 //                     HALT        - halt
  }
};
