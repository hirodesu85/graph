#CC = gcc
#CFLAGS = -g

main: dijkstra.o main.o

floyd: floyd.o floyd_main.o

clean:
	/bin/rm -f main floyd *.o *~
