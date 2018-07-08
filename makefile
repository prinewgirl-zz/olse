olse: iomisc.o alglin.o  main.o
	gcc $^  -lm -o  olse

iomisc.o:
	gcc -lm -c  -Wall iomisc.c

alglin.o:
	gcc -lm -c -Wall alglin.c

main.o:
	gcc -c  main.c

clean:
	rm *.o
