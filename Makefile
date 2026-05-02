CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

SRC = src/simple_functions.c src/matrix_functions.c
OBJ = build/simple_functions.o build/matrix_functions.o

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