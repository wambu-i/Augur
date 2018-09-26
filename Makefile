CC:=gcc

OUTPUT:=augur
DEPS:=structures.h automata.h
OBJECTS:=main.o analyzer.o structures.o nfa_simulation.o dfa_simulation.o regex.o get_language.o dfa_automata.o
CFLAGS:=-Wall -Wextra

LIBRARIES:=-lpcre

COMPILE:=$(CC) $(CFLAGS)


all: $(OUTPUT)


$(OUTPUT): $(OBJECTS)
	$(COMPILE) -o $@ $^ $(LIBRARIES)

%.o: %.c $(DEPS)
	$(COMPILE) -c $< -o $@ $(LIBRARIES)

clean:
	rm -rf *.o
