#  http://jmandon.free.fr/sdcc/sdcc.htm
#
#
#


CC := sdcc
INCDIR:=/home/caio/mcu/include

CFLAGS :=   -V --vc  -mpic16 -p18f4550  --main-return  --use-non-free -I/$(INCDIR)  -L/. 

OBJDIR:=./obj/
OBJECTS:= main.o 
SRC:=  main.c

all: main.hex

main.hex: $(OBJDIR)$(OBJECTS)
	@echo "---------- main.hex ----------"
	$(CC) $(CFLAGS) ./obj/main.o $(INCDIR)/delay.o -o $(OBJDIR)main.hex


$(OBJDIR)$(OBJECTS): $(SRC)
	mkdir -p $(OBJDIR)
	@echo " --------- main.o ------------" 
	$(CC) $(CFLAGS) -c main.c    -o $(OBJDIR)



.PHONY: clean

clean:
	rm -rf $(OBJDIR) *.lst *.hex *.cod *.adb 


compteste:
	sdcc -mpic16 -p18f4550 teste.c   -I .

burn:
	sudo pk2cmd -PPIC18F4550 -M -F/`pwd`/obj/main.hex

burnteste:
	sudo pk2cmd -PPIC18F4550 -M -F/`pwd`/obj/teste.hex
