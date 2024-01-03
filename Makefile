#CC = gcc
#CFLAGS = -g

main: dijkstra.o main.o

clean:
	/bin/rm -f main *.o *~
