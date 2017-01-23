
namespace DEBUG {
 
  void setup();
  
  void log(char *value);
  
  void write(ADDRESS_BUS::address a);
  
  void write(ALU::OP op);
  
  void write(byte data);
  
  void write(REGISTERS::REGISTER r);
  
  void instruction(char *name);
  
}
