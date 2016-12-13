// Sonar 
int getDistance() {
  // establish variables for duration of the ping, 
  // and the distance result in centimeters:
  long duration, centimeters;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	TRIG_OFF;
	_delay_ms(2);
	TRIG_ON;
	_delay_ms(10);
	TRIG_OFF;
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH, 20);

  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  centimeters = duration / 29 / 2;

    return centimeters;
}
