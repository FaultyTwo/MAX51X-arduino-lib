// MAX518 and MAX519 constructors only
// i have no idea why i did put them in this file

#include "MAX51X.h"

MAX518::MAX518(uint8_t adr, TwoWire &wire = Wire){
  _adr = adr;
  _wire = &wire;
}

MAX519::MAX519(uint8_t adr, TwoWire &wire = Wire){
  _adr = adr;
  _wire = &wire;
}
