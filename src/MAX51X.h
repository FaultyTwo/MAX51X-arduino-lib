#ifndef MAX51X_ft
#define MAX51X_ft

#include "Arduino.h"
#include "Wire.h"

#define DAC0 false
#define DAC1 true

class MAX51X{ // shared methods
  // there's no constructor
  // now give me your liver
  public:
    void begin(TwoWire &wire = Wire);
    void setDac(bool dac, uint8_t data);
    void setBothDac(uint8_t dac0, uint8_t dac1);
    
    void powerOff(bool dac);
    void powerOff(bool dac, uint8_t data);
    void powerOffBoth();
    void powerOn(bool dac); //still keep its orignal value
    void powerOnBoth();
    
    void resetDac(bool dac);
    void resetBothDac();
  protected:
    TwoWire *_wire;
    uint8_t _adr;
};

class MAX517: public MAX51X{
  // MAX517 only has one dac
  // so much for inheritance..
  public:
    MAX517(uint8_t adr);
    void setDac(uint8_t data);
    void resetDac();
    void powerOff();
	  void powerOff(uint8_t data);
	  void powerOn();
    // DON'T EVEN TRY TO ACCESS THEM THRU BASE VERSION
    void resetBothDac() = delete;
    void setBothDac() = delete;
    void powerOffBoth() = delete;
    void powerOnBoth() = delete;
};

class MAX518: public MAX51X{
  public:
    MAX518(uint8_t adr);
};

class MAX519: public MAX51X{
  public:
    MAX519(uint8_t adr);
};

#endif
