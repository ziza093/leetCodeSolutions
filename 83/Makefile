main: main.o functions.o
	gcc main.o functions.o -Wall -o main

main.o: main.c header.h
	gcc -c -Wall main.c

functions.o: functions.c header.h
	gcc -c -Wall functions.c

.PHONY: clean
clean:
	rm -f *.o
	rm main
