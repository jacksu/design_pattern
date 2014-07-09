CC=g++
CFLAGS=-Wall
LDFLAGS=
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))

OUTPUT=abstract_factory_test

all:$(OUTPUT)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUTPUT): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(OUTPUT)

