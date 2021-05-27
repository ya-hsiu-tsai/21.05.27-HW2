all: main.c insertData.o searchData.o array.o BSarray.o linkedList.o BStree.o
	gcc main.c insertData.o searchData.o array.o BSarray.o linkedList.o BStree.o -o main

insertData.o: insertData.c insertData.h
	gcc -c insertData.c -o insertData.o

searchData.o: searchData.c searchData.h
	gcc -c searchData.c -o searchData.o

array.o: array.c array.h
	gcc -c array.c -o array.o

BSarray.o: BSarray.c BSarray.h
	gcc -c BSarray.c -o BSarray.o

linkedList.o: linkedList.c linkedList.h
	gcc -c linkedList.c -o linkedList.o

BStree.o: BStree.c BStree.h
	gcc -c BStree.c -o BStree.o

clean: 
	rm -f insertData.o searchData.o array.o BSarray.o linkedList.o BStree.o main