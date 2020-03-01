DEVICE = atmega1284p
OBJS= main.o keyboard.o
COMPILE= avr-gcc -Wall -Os -mmcu=$(DEVICE)

all: main.hex

.c.o: 
		$(COMPILE) -c $< -o $@

main.elf: $(OBJS)
		$(COMPILE)  $(OBJS) -o main.elf

main.hex: main.elf
		rm -f main.hex
		avr-objcopy -j .text -j .data -O ihex main.elf main.hex

clean: 
		rm -f main.elf $(OBJS)