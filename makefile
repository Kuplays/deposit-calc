all : prog

main.o :src/main.c 
	gcc -o build/main.o src/main.c 
deposit.o : src/deposit.c
	gcc -o build/deposit.o src/deposit.c

prog : main.o deposit.o
	gcc -Wall -Werror -o bin/prog.exe build/main.o build/deposit.o

clean:
	rm -rf *.o *.exe
