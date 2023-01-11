#ifndef MAX51X_ft
#define MAX51X_ft

#include "Arduino.h"
#include "Wire.h"

#define DAC0 false
#define DAC1 true

class MAX51X{ // shared methods, use at your own risk
  public:
    // Initial a MAX51X
    void begin(TwoWire &wire = Wire);
    // Set a DAC output.
    // For MAX518/MAX519:
    // Use logic 0 to choose 'DAC0', and use logic 1 to choose 'DAC1'.
    void setDac(bool dac, uint8_t data);
    // Set both DAC outputs at the same time.
    void setBothDac(uint8_t dac0, uint8_t dac1);
    // Power down a DAC.
    void powerOff(bool dac);
    // Power down a DAC, and set the analog output voltage when turned back on.
    void powerOff(bool dac, uint8_t data);
    // Power down both DACs at the same time.
    void powerOffBoth();
    // Power on a DAC.
    void powerOn(bool dac); //still keep its orignal value
    // Power on both DACs at the same time.
    void powerOnBoth();
    // Reset an output of a 'DAC' to zero.
    // For MAX518/MAX519:
    // Use logic 0 to choose 'DAC0', and use logic 1 to choose 'DAC1'.
    void resetDac(bool dac);
    // Reset both outputs of DACs to zero.
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
    // Set a DAC output.
    void setDac(uint8_t data);
    // Reset an output of a 'DAC' to zero.
    void resetDac();
    // Power down a DAC.
    void powerOff();
    // Power down a DAC, and set the analog output voltage when turned back on.
	  void powerOff(uint8_t data);
    // Power on a DAC.
	  void powerOn();
    // Don't use these with MAX517, waste of cycles.
    void resetBothDac() = delete;
    // Don't use these with MAX517, waste of cycles.
    void setBothDac() = delete;
    // Don't use these with MAX517, waste of cycles.
    void powerOffBoth() = delete;
    // Don't use these with MAX517, waste of cycles.
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
