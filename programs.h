
typedef struct PROGRAM {
  int length;
  byte *data;
} PROGRAM;

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
