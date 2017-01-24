
namespace PINS {

  typedef struct ALU_CONTROL {
    const byte mode4;
    const byte mode2;
    const byte mode1;
    const byte zero;
    const byte invert;
  } 
  ALU_CONTROL;

  const ALU_CONTROL alu = {
    2, // mode4
    3, // mode2
    4, // mode1
    5, // zero
    6  // invert
  };

  const byte data_bus[] = {
    38,
    40,
    42,
    44,
    46,
    48,
    50,
    52
  };

  const byte address_bus[] = {
    23,
    25,
    27,
    29,
    31,
    33,
    35,
    37,
    39,
    41,
    43,
    45,
    47,
    49,
    51,
    53
  };

  typedef struct REGISTER_RO {
    byte read;
  } 
  REGISTER_RO;

  typedef struct REGISTER_WO {
    byte write;
  } 
  REGISTER_WO;

  typedef struct REGISTER_RW {
    byte read;
    byte write;
  }
  REGISTER_RW;

  const struct {
    REGISTER_RW a;
    REGISTER_RW b;
    REGISTER_RW c;
    REGISTER_WO j1;
    REGISTER_WO j2;
    REGISTER_RO j;
    REGISTER_RW pc;
    REGISTER_RO incdec;
    REGISTER_WO inc;
    REGISTER_WO dec;
    REGISTER_WO alu;
    REGISTER_RO alu_result;
    REGISTER_RO alu_flags;
    REGISTER_RW memory;
  } 
  registers = {
    {
      36,15    }
    , // a
    {
      32,30    }
    , // b
    {
      28,26    }
    , // c
    {
      24    }
    , //j1
    {
      22    }
    , //j2
    {
      21    }
    , //j
    {
      20,19 }
    , //pc
    {
      18    }
    , //incdec
    {
      17    }
    , //inc
    {
      16    }
    , //dec
    {
      13    }  
    , //alu
    {
      12    }
    , //alu_result
    {
      11    }
    , //alu_flags
    {
      10, 9  }
      //memory
  };
}





