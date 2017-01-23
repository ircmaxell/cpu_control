
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
    1, // mode4
    1, // mode2
    1, // mode1
    1, // zero
    1  // invert
  };

  const byte data_bus[] = {
    1,1,1,1,1,1,1,1
  };

  const byte address_bus[] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1    
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
      1,1    }
    , // a
    {
      1,1    }
    , // b
    {
      1,1    }
    , // c
    {
      1    }
    , //j1
    {
      1    }
    , //j2
    {
      1    }
    , //j
    {
      1,1    }
    , //pc
    {
      1    }
    , //incdec
    {
      1    }
    , //inc
    {
      1    }
    , //dec
    {
      1    }
    , //alu
    {
      1    }
    , //alu_result
    {
      1    }
    , //alu_flags
    {
      1,1  }
      //memory
  };
}





