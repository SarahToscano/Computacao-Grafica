CC = gcc

all:
	$(CC) -Wall -Wextra -Wpedantic -std=c99 -O0 mygl.c main.c -lglut -lm -ldl -lGLU -lGL -o mygl

clean:
	rm mygl
