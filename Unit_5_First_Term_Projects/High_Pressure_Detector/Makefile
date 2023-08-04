CC = arm-none-eabi-
CFLAGS =  -mcpu=cortex-m3 -gdwarf-2 -g
INC = -I inc/.
LIBS=
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
As = $(wildcard *.s)
As_OBJ = $(As:.s=.o)
linker_file = linker_script.ld  
Project_Name = bin/P1_High_Pressure_Detector

all: $(Project_Name).bin
	@echo "The build is done"

obj/%.o: src/%.c
	$(CC)gcc.exe $(CFLAGS) $(INC) -c $< -o $@

%.o: %.s
	$(CC)as.exe $(CFLAGS) $(INC) $< -o $@

$(Project_Name).elf: $(OBJ) $(As_OBJ)
	$(CC)ld.exe -T $(linker_file) $(LIBS) -Map=bin/Map_file.map $(OBJ) $(As_OBJ) -o $(Project_Name).elf

$(Project_Name).bin:$(Project_Name).elf 
	$(CC)objcopy.exe -O binary  $(Project_Name).elf $(Project_Name).bin

clean_all:
	rm obj/*.o bin/*.elf bin/*.bin

clean:
	rm bin/*.elf bin/*.bin