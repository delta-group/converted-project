; ASM code for the HC-SRO4 Sonar device
#define	"config.inc"

	.section	.text
	.global		sonar

sonar:
        sbi             _DDRD, TRIG_PIN         ; sets pin 2's direction to output => Trig Pin
        cbi             _DDRD, ECHO_PIN         ; sets pin 4's direction to input  <= Echo Pin
        cbi             _PORTD,	TRIG_PIN        ; sets the output to LOW
send:						
						; set Trig Pin to HIGH to send a burst of 8 pings
        rjmp            send                    ; HIGH signal must continue for 10 microseconds
receive:
						; check for a ping response
                                                ; break out of loop if response received
        rjmp		receive			; otherwise keep waiting for the response
	clr		r25			; zero out high 8 bits of 16-bit return register
        ldi		r24, 120		; set lower 8 bits to the value 120
        ret					; return to calling function
