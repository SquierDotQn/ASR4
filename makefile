CC = gcc
CFLAGS = -Wall -Werror -g -pedantic

main : chaine.o main.o
	$(CC) -o $@ $^
clear :
	rm main *.o
