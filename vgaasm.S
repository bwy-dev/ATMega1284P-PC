.global write_line
.global start_up
.equ TCCR1B,    0x81
.equ OCR1AH,    0x89
.equ OCR1AL,    0x88
.equ TIMSK1,    0x6F
.equ TCNT1,	    0x84
.equ PORTA,     0x02
.equ OC1Aaddr,  0x0034
.equ FBUFSTART, 0x0370
.equ FBUFEND,   0x326F

.org OC1Aaddr
            rjmp write_line  

start_up:  
			ldi r16, 0b00001001 ; set timer1 to clock
            sts TCCR1B, r16     ;
            ldi r16, 0b00000110 ; set timer1 match a interrupt
            sts TIMSK1, r16     ;
            ldi r16, hi8(800)   ; set interrupt timings to
            sts OCR1AH, r16     ; 800 cycles.
            ldi r16, lo8(800)   ;
            sts OCR1AL, r16     ;
            sei                 ; set global interrupts
			sts TCNT1, 0		; set timer to 0
			ret					;

write_line: 
			ldi r29, hi8(FBUFSTART)
			ldi r28, lo8(FBUFSTART)
			sts TCNT1, 0
loop:
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ld  r18, Y+
            out PORTA, r18;
            nop;
			nop;
			ldi r27, lo8(FBUFSTART)
			ldi r26, hi8(FBUFSTART)
			cp  r27, r28
			cpc r26, r29
			brlt indicator
			nop;
            ret;

indicator:
			jmp loop