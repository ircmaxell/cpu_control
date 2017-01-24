
namespace DEBUG {
 
#define DEBUG_ENABLE 0
  
  void setup();
  
  void log(char *value);
  
  void write(ADDRESS_BUS::address a);
  
  void write(ALU::OP op);
  
  void write(byte data);
  
  void write(int data);
  void write(long data);
  void write(unsigned long data);
  
  void write(REGISTERS::REGISTER r);
  
  void instruction(char *name);
  
}
