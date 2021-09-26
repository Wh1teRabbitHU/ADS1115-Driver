# ADS1115-Driver

- [ADS1115-Driver](#ads1115-driver)
	- [Description](#description)
	- [Type definitions](#type-definitions)
	- [Methods](#methods)
		- [Initialization](#initialization)
		- [Low level requests](#low-level-requests)
		- [Value reading](#value-reading)
		- [Operation mode related configurations](#operation-mode-related-configurations)
	- [Macro values](#macro-values)
		- [I2C addresses.](#i2c-addresses)
		- [Operational status](#operational-status)
		- [Input multiplexer](#input-multiplexer)
		- [Programmable gain amplifier](#programmable-gain-amplifier)
		- [Device operation mode](#device-operation-mode)
		- [Data rate](#data-rate)
		- [Comparator mode](#comparator-mode)
		- [Comparator polarity](#comparator-polarity)
		- [Latching comparator](#latching-comparator)
		- [Comparator queue and disable](#comparator-queue-and-disable)
		- [Value multipliers](#value-multipliers)

## Description

Driver for Texas Instrument's ADS1115 analog to digital converter IC. It's somewhat compatible with the ADS1113 and ADS1114 variants. More details in the [official datasheet](https://www.ti.com/lit/ds/symlink/ads1113.pdf)

## Type definitions

- typedef uint8_t i2c_addr_t;
- typedef uint8_t reg_addr_t;
- typedef uint16_t reg_val_t;
- typedef uint8_t flag_pos_t;
- typedef uint8_t flag_val_t;

## Methods

### Initialization

- void reset();

### Low level requests

- reg_val_t readRegister(reg_addr_t dataAddress);
- void writeRegister(reg_addr_t dataAddress, reg_val_t data);

### Value reading

- reg_val_t readRawValue();
- reg_val_t readConvertedValue();

### Operation mode related configurations

- void startSingleConvertion();
- uint8_t getOperationalStatus();
- void setMultiplexer(uint8_t mux);
- uint8_t getMultiplexer();
- void setPga(uint8_t pga);
- uint8_t getPga();
- void setDeviceMode(uint8_t mode);
- uint8_t getDeviceMode();
- void setDataRate(uint8_t dataRate);
- uint8_t getDataRate();
- void setComparatorMode(uint8_t mode);
- uint8_t getComparatorMode();
- void setComparatorPolarity(uint8_t polarity);
- uint8_t getComparatorPolarity();
- void setLatching(bool latching);
- bool isLatching();
- void setComparatorQueue(uint8_t queue);
- uint8_t getComparatorQueue();
- void setLowTreshold(reg_val_t lowTreshold);
- reg_val_t getLowTreshold();
- void setHighTreshold(reg_val_t highTreshold);
- reg_val_t getHighTreshold();

## Macro values

### I2C addresses.

You have to connect the address pin with the corresponding data line

- ADS1115_I2C_ADDR_GND
- ADS1115_I2C_ADDR_VDD
- ADS1115_I2C_ADDR_SDA
- ADS1115_I2C_ADDR_SCL

### Operational status

- ADS1115_OS_START_SINGLE
- ADS1115_OS_ONGOING_CONV
- ADS1115_OS_NO_CONV

### Input multiplexer

- ADS1115_MUX_AIN0_AIN1
- ADS1115_MUX_AIN0_AIN3
- ADS1115_MUX_AIN1_AIN3
- ADS1115_MUX_AIN2_AIN3
- ADS1115_MUX_AIN0_GND
- ADS1115_MUX_AIN1_GND
- ADS1115_MUX_AIN2_GND
- ADS1115_MUX_AIN3_GND

### Programmable gain amplifier

- ADS1115_PGA_6_144
- ADS1115_PGA_4_096
- ADS1115_PGA_2_048
- ADS1115_PGA_1_024
- ADS1115_PGA_0_512
- ADS1115_PGA_0_256

### Device operation mode

- ADS1115_MODE_CONTINOUS
- ADS1115_MODE_SINGLE

### Data rate

- ADS1115_DR_8_SPS
- ADS1115_DR_16_SPS
- ADS1115_DR_32_SPS
- ADS1115_DR_64_SPS
- ADS1115_DR_128_SPS
- ADS1115_DR_250_SPS
- ADS1115_DR_475_SPS
- ADS1115_DR_860_SPS

### Comparator mode

- ADS1115_COMP_MODE_TRADITIONAL
- ADS1115_COMP_MODE_WINDOW

### Comparator polarity

- ADS1115_COMP_POL_LOW
- ADS1115_COMP_POL_HIGH

### Latching comparator

- ADS1115_COMP_LAT_NO_LATCH
- ADS1115_COMP_LAT_LATCH

### Comparator queue and disable

- ADS1115_COMP_QUE_ONE_CONV
- ADS1115_COMP_QUE_TWO_CONV
- ADS1115_COMP_QUE_FOUR_CONV
- ADS1115_COMP_QUE_DISABLE

### Value multipliers

- ADS1115_PGA_6_144_MULT
- ADS1115_PGA_4_096_MULT
- ADS1115_PGA_2_048_MULT
- ADS1115_PGA_1_024_MULT
- ADS1115_PGA_0_512_MULT
- ADS1115_PGA_0_256_MULT