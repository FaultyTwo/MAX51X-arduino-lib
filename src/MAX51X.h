/*
  MAX51X - Arduino for MAX517/518/519, 8-bit DAC I2C with R2R Output
  By: Chawin 'FaultyTwo' Treesugol <https://github.com/FaultyTwo/LTC166X-arduino-lib>
*/

#ifndef MAX51X_ft
#define MAX51X_ft

#include "Arduino.h"
#include "Wire.h"

#define DAC0 false
#define DAC1 true

// @warning shared class, do not use
class MAX51X{
  public:
    /// @brief Initial a MAX518/519 device
    /// @param wire The i2c address of MAX518/519
    void begin(TwoWire &wire = Wire);
    /// @brief Set a DAC value
    /// @param dac The DAC device (logic 0 = DAC0, logic 1 = DAC1)
    /// @param data The DAC value
    void setDac(bool dac, uint8_t data);
    /// @brief Set both DAC values
    /// @param dac0 The value of DAC0
    /// @param dac1 The value of DAC1
    void setBothDac(uint8_t dac0, uint8_t dac1);
    /// @brief Power down a DAC
    /// @param dac The DAC device (logic 0 = DAC0, logic 1 = DAC1)
    void powerOff(bool dac);
    /// @brief Power down a DAC and and set the output when power on
    /// @param dac The DAC device (logic 0 = DAC0, logic 1 = DAC1)
    /// @param data The DAC value
    void powerOff(bool dac, uint8_t data);
    /// @brief Power down both DACs
    void powerOffBoth();
    /// @brief Power on a DAC
    /// @param dac The DAC device (logic 0 = DAC0, logic 1 = DAC1)
    void powerOn(bool dac);
    /// @brief Power on both DACS
    void powerOnBoth();
    /// @brief Reset a DAC output
    /// @param dac The DAC device (logic 0 = DAC0, logic 1 = DAC1)
    void resetDac(bool dac);
    /// @brief Reset both DAC outputs
    void resetBothDac();
  protected:
    TwoWire *_wire;
    uint8_t _adr;
};

// MAX517 shouldn't inherit from MAX51X due to base class access
// although it shouldn't be a problem since MAX517 would just ignore the signal anyway ...

/// @brief A MAX517 class
class MAX517{
  public:
    /// @brief Specify a MAX517 device
    /// @param adr The i2c address of MAX517
    MAX517(uint8_t adr);
    /// @brief Initial a MAX517 device
    /// @param wire A TwoWire class, leave blank for default
    void begin(TwoWire &wire = Wire);
    /// @brief Set a DAC output
    /// @param data The DAC value
    void setDac(uint8_t data);
    /// @brief Reset a DAC output
    void resetDac();
    /// @brief Power down a DAC
    void powerOff();
	  /// @brief Power down a DAC and and set the output when power on
	  /// @param data The DAC value
	  void powerOff(uint8_t data);
    /// @brief Power on a DAC
    void powerOn();
  protected:
    TwoWire *_wire;
    uint8_t _adr;
};

/// @brief A MAX518 class
class MAX518: public MAX51X{
  public:
    /// @brief Specify a MAX518 device
    /// @param adr The i2c address of MAX518
    MAX518(uint8_t adr);
};

/// @brief A MAX519 class
class MAX519: public MAX51X{
  public:
    /// @brief Specify a MAX519 device
    /// @param adr The i2c address of MAX519
    MAX519(uint8_t adr);
};

#endif
