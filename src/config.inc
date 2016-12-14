#include <avr/io.h>
#include "../include/AVRSpecialRegs.inc"

#define RED_PIN		3	
#define BLUE_PIN	5
#define TRIG_PIN	2
#define ECHO_PIN	4
#define TRIG_ON		(PORTD |= (1<<TRIG_PIN))
#define	TRIG_OFF	(PORTD &= ~(1<<TRIG_PIN))


