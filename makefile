CC = gcc
CFLAGS = -Wall -Werror -g
TARGET = digitcompress
OBJ = encodemain.o compress.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: encodemain.c compress.h
	$(CC) $(CFLAGS) -c main.c

compress.o: compress.c compress.h
	$(CC) $(CFLAGS) -c compress.c

clean:
	rm -f $(TARGET) $(OBJ) 
	rm -f *.txt *.bin

.PHONY: all clean