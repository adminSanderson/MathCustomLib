CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

SRC = src/nd_array_functions.c
OBJ = build/nd_array_functions.o

LIB = lib/libmathcustomlib.a

all: $(LIB)

build/%.o: src/%.c
	if not exist build mkdir build
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJ)
	if not exist lib mkdir lib
	ar rcs $@ $^

clean:
	del /Q build\*.o lib\*.a *.exe