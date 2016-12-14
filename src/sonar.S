; ASM code for the HC-SRO4 Sonar device
#define	"config.inc"

	.section	.text
	.global		sonar

sonar:
        sbi             _DDRD, TRIG_PIN         ; sets pin 2's direction to output => Trig Pin
        cbi             _DDRD, ECHO_PIN         ; sets pin 4's direction to input  <= Echo Pin
        cbi             _PORTD,	TRIG_PIN        ; sets the output to LOW
send:						
        sbi             _PORTD, TRIG_PIN        ; set Trig Pin to HIGH to send a burst of 8 pings
        call            tenMicroDelay           ; HIGH signal must continue for 10 microseconds
        cbi             _PORTD,	TRIG_PIN        ; set the output to LOW after pings are sent
receive:
        call            hundredCMDelay          ; wait long enough for the sound to travel 100 cm (each way)
						; check for a ping response
                                                ; break out of loop if response received
        rjmp		receive			; otherwise keep waiting for the response
	clr		r25			; zero out high 8 bits of 16-bit return register
        ldi		r24, 120		; set lower 8 bits to the value 120
        ret					; return to calling function
tenMicroDelay:
        ldi             r18, 2                  ; set outer loop to 2
1:
        ldi             r19, 80                 ; set inner loop to 80 (160 cycles total)
2:
        dec             r19                     ; decrement inner loop
        brne            2b                      ; keep looping until (r19 == 0)
        dec             r18                     ; decrement outer loop
        brne            1b                      ; keep looping until (r18 == 0)
        ret                                     ; return after 10 microseconds
hundredCMDelay:
        ldi             r18, 100                ; set outer loop to 100 (centimeters)
1:
        ldi             r19, 58                 ; set middle loop to 58 (microseconds per centimeter)
2:      
        ldi             r20, 16                 ; set inner loop to 16  (cycles per microsecond)
3:
        dec             r20                     ; decrement inner loop
        brne            3b                      ; keep looping until (r20 == 0)
        dec             r19                     ; decrement middle loop
        brne            2b                      ; keep looping until (r19 == 0)
        dec             r18                     ; decrement outer loop
        brne            1b                      ; keep looping until (r18 == 0)
        ret                                     ; return after a delay equal to 100 centimeters
