/*
 Name:		KalmanFilter.ino
 Created:	12/2/2022 10:11:28 AM
 Author:	Imami Joel Betofe
*/
#include "FilterSetup.h"
Set Set_main;
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	Set_main.init();
	
}

// the loop function runs over and over again until power down or reset
void loop() {
	Set_main.run();
}
