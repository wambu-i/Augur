CC:=gcc

OUTPUT:=analyzer
OBJECTS:=main.o nfa_simulation.o structures.o

LOCATION:=$(shell pwd)

CFLAGS:=-g -Wall -Wextra
INCLUDE:=-I$(LOCATION)/include/

COMPILE:=$(CC) $(CFLAGS) $(INCLUDE)

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(COMPILE) -o $@ $^

%.o: %.c
	$(COMPILE) -c $< -o $@

clean:
	rm -f *.o *.out analyzer