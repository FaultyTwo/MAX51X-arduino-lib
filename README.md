# MAX51X
An Arduino library for MAX517/MAX518/MAX519, 8-bit DAC I2C with R2R Outputs.

For technical details, please refer to the [datasheet.](https://datasheets.maximintegrated.com/en/ds/MAX517-MAX519.pdf)

## Overview
MAX51X is a complete Arduino library for MAX517/MAX518/MAX519.

**Differences between each devices:**<br>
- MAX517: Only has 1 DAC, reference voltage can be adjusted.
- MAX518: Have 2 DACs, reference voltage is the same as supply voltage for the device.
- MAX519: Have 2 DACs, both reference voltage can be adjusted to each own DACs.

## Analog Output
Analog output can be calculated by using the following formula:

Vout : Vref \* (DAC_CONTENT/256)


## How To Use The Library
Include the library, then simply create an object according to each device numbers like this:
```C
#include <MAX51X.h>
MAX517 dvc517(0x2F);
MAX518 dvc518(0x2C);
MAX519 dvc519(0x27);
```

To use this library with other I2C ports, you can simply create a TwoWire object then parse it into the 'begin' function:
```C
// ESP32
#define I2C_SDA 33
#define I2C_SCL 32

TwoWire esp = TwoWire(0);
MAX518 dvc518(0x2C);

void setup(){
  esp.begin(I2C_SDA, I2C_SCL, 1000000);
  dvc518.begin(&esp);
}
```

# Methods
```C
void begin(TwoWire &wirePort = Wire);
```
Initiate the MAX51X library.

Can be configured to use other I2C ports from a 'TwoWire' object. For default I2C port, just leave the parameter blank.

```C
void setDac(bool dac, uint8_t data); // FOR MAX518/MAX519
void setDac(uint8_t data); // FOR MAX517
```
Set a DAC output.

For MAX518/MAX519:<br>
Use logic 0 to choose 'DAC0', and use logic 1 to choose 'DAC1'.

**^DAC values shouldn't exceed 255, otherwise it will overflow.**

```C
void setBothDac(uint8_t dac0, uint8_t dac1); // FOR MAX518/MAX519
```
Set both DAC outputs at the same time.

**^Limited to MAX518/519, and is considered as error when invoked with MAX517 class.**<br>
**^DAC values shouldn't exceed 255, otherwise it will overflow.**

```C
void powerOff(bool dac); // FOR MAX518/MAX519
void powerOff(); // FOR MAX517
```
Power down a DAC.

For MAX518/MAX519:<br>
Use logic 0 to choose 'DAC0', and use logic 1 to choose 'DAC1'.

```C
void powerOff(bool dac, uint8_t data); // FOR MAX518/MAX519
void powerOff(uint8_t data);; // FOR MAX517
```
Power down a DAC, and set the analog output voltage when turned back on.

For MAX518/MAX519:<br>
Use logic 0 to choose 'DAC0', and use logic 1 to choose 'DAC1'.

**^DAC values shouldn't exceed 255, otherwise it will overflow.**

```C
void powerOffBoth(); // FOR MAX518/MAX519
```
Power down both DACs at the same time.

**^Limited to MAX518/519, and is considered as error when invoked with MAX517 class.**

```C
void powerOn(bool dac); // FOR MAX518/MAX519
void powerOn(); // FOR MAX517
```
Power on a DAC.

For MAX518/MAX519:<br>
Use logic 0 to choose 'DAC0', and use logic 1 to choose 'DAC1'.

```C
void powerOnBoth(); // FOR MAX518/MAX519
```
Power on both DACs at the same time.

**^Limited to MAX518/519, and is considered as error when invoked with MAX517 class.**

```C
void resetDac(bool dac); // FOR MAX518/MAX519
void resetDac(); // FOR MAX517
```
Reset an output of a 'DAC' to zero.

For MAX518/MAX519:<br>
Use logic 0 to choose 'DAC0', and use logic 1 to choose 'DAC1'.

**^Doesn't work with DAC1 in MAX518/MAX519 for a strange reason.**

```C
void resetBothDac(); // FOR MAX518/MAX519
```
Reset both outputs of DACs to zero.

**^Limited to MAX518/519, and is considered as error when invoked with MAX517 class.**
