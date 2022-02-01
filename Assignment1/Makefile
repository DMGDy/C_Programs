CC=clang

hello: hello.o
	$(CC) -o hello hello.o

hello.o: hello.c
	$(CC) -c hello.c

clean:
	rm -rf hello.o
