
namespace ADDRESS_BUS {

  typedef unsigned int address;
  
  void setup();
  
  void beginWrite(address data);
  
  void endWrite();
  
  address read();
  
  void setPinModes(int mode);

}
