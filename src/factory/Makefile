CC=g++
CFLAGS=-c -Wall
LDFLAGS=
OBJECTS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))

OUTPUT=factory_test

ALL=$(OUTPUT)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTPUT): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f *.o $(OUTPUT)

