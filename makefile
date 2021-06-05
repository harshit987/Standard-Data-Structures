CC = g++
CFLAGS = -g -Wall
default: run

run: main.o avl_update.o query.o custom.o update.o
	$(CC) $(CFLAGS) -o a.out main.o avl_update.o query.o custom.o update.o

main.o: $(arg1) 
	$(CC) $(CFLAGS) -c $(arg1)

avl_update.o: 
	$(CC) $(CFLAGS) -c avl_update.cpp
update.o: 
	$(CC) $(CFLAGS) -c update.cpp

query.o: 
	$(CC) $(CFLAGS) -c Query.cpp -o query.o

custom.o: 
	$(CC) $(CFLAGS) -c custom.cpp

clean: 
	rm a.out *.o


