/*
	CH-231-A
	hw2_p3.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "WindGauge.h"

int main() {
    // Create WindGauge object
    WindGauge newWindGauge;

    // Place new values of wind speed into history of WindGauge object
    newWindGauge.currentWindSpeed(15);
    newWindGauge.currentWindSpeed(16);
    newWindGauge.currentWindSpeed(12);
    newWindGauge.currentWindSpeed(15);
    newWindGauge.currentWindSpeed(15);

    // Output highest, lowest and average wind speed values into stdout
    newWindGauge.dump();

    // Place new values of wind speed into history of WindGauge object
    newWindGauge.currentWindSpeed(16);
    newWindGauge.currentWindSpeed(17);
    newWindGauge.currentWindSpeed(16);
    newWindGauge.currentWindSpeed(16);
    newWindGauge.currentWindSpeed(20);
    newWindGauge.currentWindSpeed(17);
    newWindGauge.currentWindSpeed(16);
    newWindGauge.currentWindSpeed(15);
    newWindGauge.currentWindSpeed(16);
    newWindGauge.currentWindSpeed(20);

    // Output highest, lowest and average wind speed values into stdout after
    // placing new values
    newWindGauge.dump();

    return 0;
}