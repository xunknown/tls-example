TARGET=tls.elf
SRC=$(wildcard ./*.c)
OBJ=$(patsubst ./%.c, ./%.o, $(SRC))

CC=gcc
CFLAGS=
LDFLAGS= -lpthread

.PHONY:all clean

all:clean $(TARGET)

$(TARGET):$(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o:%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
