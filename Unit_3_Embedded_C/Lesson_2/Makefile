#Written by Hossam Eid
CC = arm-none-eabi-
CFLAGS = -g -mcpu=arm926ej-s
INC = -I .
LIBS = 	
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
As_OBJ = $(As:.s=.o)
LINKER_SCRIPT_FILE = linker_script.ld
PROJECT_NAME = learn-in-depth

all: $(PROJECT_NAME).bin
	@echo "Build is done!." 


%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INC) -c $< -o $@

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(PROJECT_NAME).elf:$(OBJ) $(As_OBJ)
	$(CC)ld.exe  -T  $(LIBS) $(LINKER_SCRIPT_FILE) -Map=Map_file.map $(OBJ) $(As_OBJ) -o $(PROJECT_NAME).elf

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O  binary $(PROJECT_NAME).elf $(PROJECT_NAME).bin 


clean_all:
	rm *.o *.bin *.elf

clean: 
	rm *.bin *.elf