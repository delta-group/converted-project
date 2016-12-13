; ASM code for the HC-SRO4 Sonar device

	.section	.text
	.global		sonar

sonar:
	clr		r25
	ldi		r24, 120
	ret
