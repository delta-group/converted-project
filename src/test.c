#include <avr/io.h>
#include <util/delay.h>

/************************************************************************/
/*                           Defining Constants                         */
/************************************************************************/

//--- PIN Assignments ----------------------------------------------------
#define GREEN_PIN           4
#define BLUE_PIN            5
#define BUZZ_PIN            1
#define TRIG_PIN            2
#define ECHO_PIN            4

//--- PIN Controls -------------------------------------------------------
#define RED_ON              (PORTB |= (0x0F))
#define RED_OFF             (PORTB &= ~(1<<RED_PIN))
#define GREEN_ON            (PORTB |= (0x10))
#define GREEN_OFF           (PORTB &= ~(1<<GREEN_PIN))
#define YELLOW_ON           (PORTB |= (1<<RED_PIN) | (1<<GREEN_PIN))
#define YELLOW_OFF          (PORTB &= (0x00))

#define TRIG_ON             (PORTD |= (1<<TRIG_PIN))
#define	TRIG_OFF            (PORTD &= ~(1<<TRIG_PIN))
#define BUZZ_ON             (PORTB |= (1<<BUZZ_PIN))
#define BUZZ_OFF            (PORTB &= ~(1<<BUZZ_PIN))

//--- Port Setup ---------------------------------------------------------
#define OUTPUT_CONFIG		(DDRB |= (1<<RED_PIN) | (1<<GREEN_PIN) | (1<<BUZZ_PIN))

//--- Clock/Timer Setup --------------------------------------------------
#define CPU_PRESCALE(n)		(CLKPR = 0x80, CLKPR = (n))

/************************************************************************/
/*                     Device function definitions                      */
/************************************************************************/

//--- Buzzer -------------------------------------------------------------
void buzzEnable(void) {
	// turn on the buzzer (using the method from lab 8)
}

void buzzDisable(void) {
	// turn off the buzzer (called when target is out of range)
}

//--- LED ----------------------------------------------------------------
void LEDColor(int distance) {
	if (distance >= 200) {
		// when object is far away, turn on red LED
		// and disable buzzer
		RED_ON;
		buzzDisable();
	}
	else if (distance >= 130) {
		// when object is at medium range, turn on yellow LED
		// and disable buzzer
		YELLOW_ON;
		buzzDisable();
	}
	else {
		// when object is in range, turn on green LED
		// and enable buzzer
		GREEN_ON;
		buzzEnable();
	 }
}

/************************************************************************/
/*                           MAIN function	                            */
/************************************************************************/

int main(void) {
	/*** Device Setup ***/
	CPU_PRESCALE(2);
	OUTPUT_CONFIG;
    
	/*** Infinite Loop ***/
	while(1){
    
	}

}
