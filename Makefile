CC:=gcc

OUTPUT:=augur
OBJECTS:=main.o analyzer.o automata.o regex.o get_language.o
CFLAGS:=-Wall -Wextra

LIBRARIES:=-lpcre

COMPILE:=$(CC) $(CFLAGS) $(LIBRARIES)


all: $(OUTPUT)


$(OUTPUT): $(OBJECTS)
	$(COMPILE) -o $@ $^

%.o: %.c 
	$(COMPILE) -c $< -o $@

clean:
	rm -rf *.o