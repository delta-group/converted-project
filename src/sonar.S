; ASM code for the HC-SRO4 Sonar device

	.section	.text
	.global		sonar

sonar:
	ldi		r24, 210
	ret
