CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)
GCCFLAGS = -Wall -nostdinc -nostdlib -nostartfiles -ffreestanding -g
LDFLAGS = -g -m aarch64elf -nostdlib -T linker.ld
OBJFLAGS = -O binary
OBJDFLAGS = -D -S

ARMGNU = aarch64-none-elf

all: clean kernel8.img

boot.o: boot.S
	@$(ARMGNU)-gcc $(INCLUDES) $(GCCFLAGS) -c boot.S -o boot.o

%.o: %.c
	@$(ARMGNU)-gcc $(INCLUDES) $(GCCFLAGS) -c $< -o $@

kernel8.img: boot.o io.o $(OFILES)
	@$(ARMGNU)-ld $(LDFLAGS) boot.o $(OFILES) -o kernel8.elf
	@$(ARMGNU)-objcopy $(OBJFLAGS) kernel8.elf kernel8.img
	@$(ARMGNU)-objdump $(OBJDFLAGS) kernel8.elf > kernel8.elf.lst

clean:
	@rm -rf *.o *.img *.elf *.lst

