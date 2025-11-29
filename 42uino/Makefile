
NAME = main
SRCS = $(NAME).c
ELF = $(NAME).elf
HEX = $(NAME).hex

MCU = atmega328p
F_CPU = 16000000UL
BAUDRATE = 115200
PORT = /dev/ttyUSB0
PROTOCOL = arduino 

CC = avr-gcc
OBJCOPY = avr-objcopy
# -Os optimize for size
# specify cpu frequency and target microcontroller
CFLAGS = -Os -Wall -Wextra -Werror -DF_CPU=$(F_CPU) -mmcu=$(MCU)

RM = rm -rf


# Enable debug mode: make DEBUG=1
ifeq ($(DEBUG),1)
CFLAGS += -DDEBUG
endif

#compile program for atmega328p module
#and flash it
all: $(HEX) flash

# compile and link to an ELF
$(ELF): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

# convert ELF to hex
$(HEX): $(ELF)
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# NOTE: :i is really important at the end
flash: $(HEX)
	avrdude -F -V -c $(PROTOCOL) -p $(MCU) -P $(PORT) -b $(BAUDRATE) -D -U flash:w:$(HEX):i



clean:
	$(RM) $(ELF) $(HEX) 


show: all
	screen $(PORT) $(BAUDRATE)

uart:
	screen $(PORT) $(BAUDRATE)


.PHONY: all hex flash clean show uart
