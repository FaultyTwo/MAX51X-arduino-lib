// MAX517 methods only

#include "MAX51X.h"

MAX517::MAX517(uint8_t adr){
  _adr = adr;
}

void MAX517::setDac(uint8_t data){
  _wire->beginTransmission(_adr);
  _wire->write(0x00); //517 only has one dac
  _wire->write(data);
  _wire->endTransmission();
}

void MAX517::resetDac(){
  _wire->beginTransmission(_adr);
  _wire->write(0x10); // dac reset
  _wire->endTransmission();
}

void MAX517::powerOff(){
  _wire->beginTransmission(_adr);
  _wire->write(0x08);
  _wire->endTransmission();
}

void MAX517::powerOff(uint8_t data){
  _wire->beginTransmission(_adr);
  _wire->write(0x08);
  _wire->write(data);
  _wire->endTransmission();
}

void MAX517::powerOn(){
  _wire->beginTransmission(_adr);
  _wire->write(0x00);
  _wire->endTransmission();
}
