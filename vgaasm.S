.global write_line
.global start_up
.equ TCCR1B,    0x81
.equ OCR1AH,    0x89
.equ OCR1AL,    0x88
.equ TIMSK1,    0x6F
.equ TCNT1L,	0x84
.equ TCNT1H,	0x85
.equ PORTA,     0x02
.equ PORTC,		0x08
.equ OC1Aaddr,  0x0034
.equ FBUFSTART, 0x0570
.equ FBUFEND,   0x346F
.equ HSYNC,     0x01
.equ VSYNC,		0x02
.equ HMASK,     0b11111110
.equ VMASK,		0b11111101

start_up:  
			ldi r16, 0b00001001 ; set timer1 to clock
            sts TCCR1B, r16     ;
            ldi r16, 0b00000010 ; set timer1 match a interrupt
            sts TIMSK1, r16     ;
            ldi r16, hi8(800)   ; set interrupt timings to
            sts OCR1AH, r16     ; 800 cycles.
            ldi r16, lo8(800)   ;
            sts OCR1AL, r16     ;
            sei                 ; set global interrupts
			sts TCNT1L, 0		; set timer to 0
			ret					;

write_line: 
			ldi r29, hi8(FBUFSTART)
			ldi r28, lo8(FBUFSTART)
			mov r16, PORTC	; copy PORTC into r16	
			ori r16, HSYNC  ; OR it with HSYNC pin
			out PORTC, r16	; 1 Cycle : Set HSYNC high
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;			5 Total Cycles per Pixel, 128 pixels per line				  ;
;		  = 640 cycles to match the 640 pixel cycles of VGA				  ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
loop:
			sts TCNT1H, 0x00
			sts TCNT1L, 0x00	; 2 Cycles  : Set timer back to 0
			ld  r18, Y+			; 2 Cycles : Load pixel data from Y register
            out PORTA, r18		; 1 Cycle  : Send pixel data to screen
            nop;				; 1 Cycle  : Do Nothing (Padding)
			nop;				; 1 Cycle  : 5 total cycles per pixel
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
			nop;					; 640 cycles from start of loop to here.
			out PORTA, 0x00			; 1 Cycle  : stop outputting to PORTA
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop					    ; 13 Cycles of nop : Padding
			mov  r16, PORTC
			andi r16, HMASK
			out  PORTC, r16      ; 1 Cycle : Set HSYNC low	
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop				; 92 nop cycles : Padding
			mov r16, PORTC	; copy PORTC into r16	
			ori r16, HSYNC  ; OR it with HSYNC pin
			out PORTC, r16	; 1 Cycle : Set HSYNC high again
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop
			nop						; 38 Cycles of nop : padding
			ldi r27, lo8(FBUFSTART) ; 1 Cycle
			ldi r26, hi8(FBUFSTART) ; 1 Cycle
			cp  r27, r28			; 1 Cycle
			cpc r26, r29			; 1 Cycle
			brlo indicator			; 2 Cycles during loop
			
            ret;

indicator:
			jmp loop			    ; 3 Cycles : have to jump here from branch because it does an rjmp and loop is too far away for it to reach.