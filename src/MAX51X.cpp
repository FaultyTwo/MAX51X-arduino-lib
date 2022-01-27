#include "MAX51X.h"
// universal methods (exclude some of MAX517)

void MAX51X::begin(TwoWire &wire){
  _wire = &wire;
}

void MAX51X::setDac(bool dac, uint8_t data){
  _wire->beginTransmission(_adr);
  _wire->write(dac); //either 0x00 or 0x01
  _wire->write(data);
  _wire->endTransmission();
}

void MAX51X::setBothDac(uint8_t dac0, uint8_t dac1){
  _wire->beginTransmission(_adr);
  _wire->write(0x00);
  _wire->write(dac0);
  _wire->write(0x01);
  _wire->write(dac1);
  _wire->endTransmission();
}

void MAX51X::resetDac(bool dac){
  _wire->beginTransmission(_adr);
  _wire->write(0x10 | dac);
  // TODO: doesn't work with dac1 in MAX518/519
  _wire->endTransmission();
}

void MAX51X::resetBothDac(){
  _wire->beginTransmission(_adr);
  _wire->write(0x10); // dac reset
  _wire->write(0x00); // dummy bytes
  _wire->write(0x11); // another dac
  _wire->endTransmission();
}

void MAX51X::powerOff(bool dac){
  _wire->beginTransmission(_adr);
  _wire->write(0x08 | dac);
  _wire->endTransmission();
}

void MAX51X::powerOff(bool dac, uint8_t data){
  _wire->beginTransmission(_adr);
  _wire->write(0x08 | dac);
  _wire->write(data);
  _wire->endTransmission();
}

void MAX51X::powerOffBoth(){ //this is stupid
  powerOff(0); powerOff(1);
}

void MAX51X::powerOn(bool dac){
  _wire->beginTransmission(_adr);
  _wire->write(dac);
  _wire->endTransmission();
}

void MAX51X::powerOnBoth(){ //this is also stupid
  powerOn(0); powerOn(1);
}
