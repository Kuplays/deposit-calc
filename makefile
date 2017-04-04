CC = gcc
CFLAGS = -c -Wall -Werror
EXECUTABLE = bin/prog
SOURCES = src/main.c src/deposit.c
OBJECTS = $(SOURCES: .c = .o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o *.exe
