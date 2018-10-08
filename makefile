main:main.c list.o
	gcc -o main main.c list.o

list.o:list.c list.h
	gcc -c list.c

clean:
	rm main list.o

