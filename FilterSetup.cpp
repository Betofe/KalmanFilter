// 
// 
// 

#include "FilterSetup.h"

void Set::init() {
    

	// kalman variables
	varVolt = 1.12184278324081E-05;  // variance determined using excel and reading samples of raw sensor data
	varProcess = 1e-8;
	Pc = 0.0;
	G = 0.0;
	P = 1.0;
	Xp = 0.0;
	Zp = 0.0;
	Xe = voltage;
	sensorVal = analogRead(sensorPin);     // read the value on AnalogIn pin 0 and store it in a variable
	voltage = (((sensorVal * 3.3) / 4095) * 2.55);
}
void Set::run() {
	// convert the ADC reading to voltage
	sensorVal = analogRead(sensorPin);     // read the value on AnalogIn pin 0 and store it in a variable
	voltage = (((sensorVal * 3.3) / 4095) * 2.55);
	// kalman process
	Pc = P + varProcess; //Predict the next variance
	G = Pc / (Pc + varVolt);    // Computer the kalman gain
	P = (1 - G) * Pc; // Update variance estimation
	Xp = Xe; // Predict the next state
	Zp = Xp; // Predict the next state
	Xe = G * (voltage - Zp) + Xp;    // Update the Kalman state estimation


	Serial.print("Reading: ");
	Serial.println(voltage);
	delay(300);
	Serial.print("Filtered: ");
	Serial.println(Xe);
	delay(300);
}

