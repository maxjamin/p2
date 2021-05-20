proc1: p2.c
		gcc -o p2 p2.c -pthread

clean:
		rm *.o p2 a.out
