#Generic Makefile for C coding projects
#Prepared by: Hossam Eid


#Files directories--------------------

#Source files 
SRC_DIR = src 

#Header files
INC_DIR = inc

#Object files
OBJ_DIR = obj

#Assembly files
ASM_DIR = asm

#Executables
EXEC_DIR = bin

#------------------------------------

#Input parametes list

#C source files
SRC = $(wildcard src/*.c)

#Object files
OBJ = $(SRC:src/%.c=obj/%.o)

#Assmebly source files
ASM_SRC = $(wildcard $(ASM_DIR)/*.s)

#Object files
ASM_OBJ = $(ASM_SRC:$(ASM_DIR)/%.s=$(OBJ_DIR)/%.o)

#------------------------------------ 

#Target file name
Target_name = Students_Database

Target = $(EXEC_DIR)/$(Target_name)
#------------------------------------ 

#Compiler flags---------------------

#C standard
STD = -std=c89

#Warnings
WRN = -pedantic

#Header files directory

INC = -I $(INC_DIR)/

CFLAGS = $(STD) $(INC)

#----------------------------------

#Toolchain------------------------
# Compiler
CC = gcc.exe

# Assembler
AS = as.exe

# Linker
LD = ld.exe
#----------------------------------

.PHONY: all 

all: $(Target).exe
	@echo "" 
	@echo "---------------Build is Done!.----------------"


obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(ASM_DIR)/%.s
	$(AS) $(INC) $< -o $@

$(Target).exe: $(OBJ) $(ASM_OBJ)
	$(CC) -o $(Target).exe $(OBJ) $(ASM_OBJ) 


clean:
	rm $(EXEC_DIR)/*.exe

clean_all:
	rm $(EXEC_DIR)/*.exe $(OBJ_DIR)/*.o

run:
	./$(Target)