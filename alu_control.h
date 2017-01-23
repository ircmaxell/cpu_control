#include <Arduino.h>

namespace ALU {

  typedef struct CONTROL_OP {
    boolean mode4;
    boolean mode2;
    boolean mode1;
    boolean zero;
    boolean invert;
  } 
  CONTROL_OP;

  typedef enum OP {
    OP_ADD,
    OP_SUB,
    OP_AND,
    OP_OR,
    OP_XOR,
    OP_INC,
    OP_DEC,
    OP_FF,
    OP_00,
    OP_NOT
  } 
  OP;

  const CONTROL_OP ops[] = {
    {
      false, false, false, false, false    }
    , // add
    {
      false, false, false, false, true    }
    , // sub
    {
      false, true, true, false, false    }
    , // and
    {
      false, true, false, false, false    }
    , // or
    {
      false, false, true, false, false    }
    , // xor
    {
      false, false, false, true, false    }
    , // inc
    {
      false, false, false, true, true    }
    , // dec
    {
      false, true, false, true, true    }
    , // FF
    {
      false, true, true, true, false    }
    , // 00
    {
      false, false, true, true, true    } 
      // NOT
  };

  void setup();

  void setMode(OP op);

}



