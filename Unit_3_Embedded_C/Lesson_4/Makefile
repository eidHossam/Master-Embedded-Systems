CC = arm-none-eabi-
CFLAGS =  -mcpu=cortex-m4 -gdwarf-2 -g
INC = -I . 
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
As_OBJ = $(As:.s=.o)
linker_file = linker_script.ld  
Project_Name = Unit3_Lab4_cortexM4

all: $(Project_Name).bin
	@echo "The build is done"

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(Project_Name).elf: $(OBJ) $(As_OBJ)
	$(CC)ld.exe -T $(linker_file) $(LIBS) -Map=Map_file.map $(OBJ) $(As_OBJ) -o $(Project_Name).elf
	cp $(Project_Name).elf $(Project_Name).axf

$(Project_Name).bin:$(Project_Name).elf 
	$(CC)objcopy.exe -O binary  $(Project_Name).elf $(Project_Name).bin

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin