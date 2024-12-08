/*
* Project myProject
* Author: Your Name
* Date:
* For comprehensive documentation and examples, please visit:
* https://docs.particle.io/firmware/best-practices/firmware-template/
*/


// Include Particle Device OS APIs
#include "Particle.h"
#include <google-maps-device-locator.h>

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE (AUTOMATIC) ;
SYSTEM_THREAD (ENABLED) ; 

void locationCallback(float lat, float lon, float accuracy);

GoogleMapsDeviceLocator locator;

void setup() {
  Serial.begin(9600);
  // Scan for visible networks and publish to the cloud every 30 seconds
  // Pass the returned location to be handled by the locationCallback() method
  locator.withSubscribe(locationCallback).withLocatePeriodic(30);
}

void locationCallback(float lat, float lon, float accuracy) {
  // Handle the returned location data for the device. This method is passed three arguments:
  // - Latitude
  // - Longitude
  // - Accuracy of estimated location (in meters)
  Serial.printlnf("Location: %.5f, %.5f, Accuracy: %.2fm", lat, lon, accuracy);
}

void loop() {
  locator.loop();
}
    



