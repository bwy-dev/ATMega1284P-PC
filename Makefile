DEVICE = atmega1284p
OBJS= main.o keyboard.o vga.o characters.o vgaasm.o
COMPILE= avr-gcc -Wall -Os -mmcu=$(DEVICE)

all: main.hex

.c.o: 
		$(COMPILE) -c $< -o $@

.S.o:
		$(COMPILE) -x assembler-with-cpp -c $< -o $@

main.elf: $(OBJS)
		$(COMPILE)  $(OBJS) -o main.elf

main.hex: main.elf
		rm -f main.hex
		avr-objcopy -j .text -j .data -O ihex main.elf main.hex
		avr-size -C --mcu=$(DEVICE) main.elf
		avr-objdump -d main.elf
		make clean

clean: 
		rm -f $(OBJS)