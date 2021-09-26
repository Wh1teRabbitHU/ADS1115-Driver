#include "Arduino.h"
#include "ADS1115-Driver.h"

ADS1115 ads1115 = ADS1115(ADS1115_I2C_ADDR_SDA);

uint16_t readValue(uint8_t input) {
	ads1115.setMultiplexer(input);
	ads1115.startSingleConvertion();

	delayMicroseconds(25); // The ADS1115 needs to wake up from sleep mode and usually it takes 25 uS to do that

	while (ads1115.getOperationalStatus() == 0);

	return ads1115.readConvertedValue();
}

void setup() {
	Serial.begin(9600);

	ads1115.reset();
	ads1115.setDeviceMode(ADS1115_MODE_SINGLE);
	ads1115.setDataRate(ADS1115_DR_250_SPS);
	ads1115.setPga(ADS1115_PGA_4_096);
}

void loop() {
	uint16_t value0 = readValue(ADS1115_MUX_AIN0_GND);
	uint16_t value1 = readValue(ADS1115_MUX_AIN1_GND);
	uint16_t value2 = readValue(ADS1115_MUX_AIN2_GND);
	uint16_t value3 = readValue(ADS1115_MUX_AIN3_GND);

	Serial.println("Values: ");
	Serial.print("IN 0: ");
	Serial.print(value0);
	Serial.print(" IN 1: ");
	Serial.print(value1);
	Serial.print(" IN 2: ");
	Serial.print(value2);
	Serial.print(" IN 3: ");
	Serial.print(value3);
	Serial.print("");

	delay(100);
}