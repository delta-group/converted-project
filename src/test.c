#include <avr/io.h>
#include <util/delay.h>

#define GREEN_PIN		4
#define BLUE_PIN		5

#define BUZZ_PIN		1

#define TRIG_PIN		2	
#define ECHO_PIN		4

#define RED_ON          (PORTB |= (0x0F))
#define RED_OFF         (PORTB &= ~(1<<RED_PIN))
#define GREEN_ON        (PORTB |= (0x10))
#define GREEN_OFF       (PORTB &= ~(1<<GREEN_PIN))
#define YELLOW_ON		(PORTB |= (1<<RED_PIN) | (1<<GREEN_PIN))
#define YELLOW_OFF		(PORTB &= (0x00))

#define TRIG_ON			(PORTD |= (1<<TRIG_PIN))
#define	TRIG_OFF		(PORTD &= ~(1<<TRIG_PIN))
#define BUZZ_ON          (PORTB |= (1<<BUZZ_PIN))
#define BUZZ_OFF         (PORTB &= ~(1<<BUZZ_PIN))

#define OUTPUT_CONFIG   (DDRB |= (1<<RED_PIN) | (1<<GREEN_PIN) | (1<<BUZZ_PIN))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

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

// Buzzer
void buzzEnable(void) {
	// turn on the buzzer (using the method from lab 8)
	// tone(buzzPin,1000);
}

void buzzDisable(void) {
	// turn off the buzzer (called when target is out of range)
	// noTone(buzzPin);
}

// LED
int LEDColor(int distance) {
  if (distance >= 200) {
    // RED is represented by 2
    return 2;           

  }
  else if (distance >= 130) {
    // YELLOW is represented by 1
    return 1;
  }
  else {
    // GREEN is represented by 0
    return 0;
  }
}

void turnOnLED(int color) {
	switch(color){
		case 0: 
			// GREEN
			GREEN_ON;
			buzzEnable();
			break;
		case 1: 
			// YELLOW
			YELLOW_ON;	
			buzzDisable();
			break;
		case 2: 
			// RED
			RED_ON;		
			buzzDisable();
			break;
	  }
}

int main(void) {

	//CPU_PRESCALE(2);
	OUTPUT_CONFIG;
    
	while(1){
    
	}

}
