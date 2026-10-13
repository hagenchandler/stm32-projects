CC	= arm-none-eabi-gcc
CFLAGS	= -mcpu=cortex-m4 -mthumb -Wall -O0 -g -ffreestanding

all: main.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
