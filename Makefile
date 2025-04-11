all: main

main: main.o
	gcc -m32 -o main main.o

main.o:
	nasm -f elf32 -o main.o main.asm

clean:
	rm main main.o
