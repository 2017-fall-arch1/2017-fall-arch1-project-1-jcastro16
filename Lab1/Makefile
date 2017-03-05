all: bstDemo

CFLAGS=-g -O3

# Symbols helpful for undertsnading the productions
#  $@ is the production's target
#  $^ are the production's prerequisites

bstDemo: bst.o bstDemo.o stateManager.o
	cc -o$@ $^
	./bstDemo

bst.o: bst.c bst.h
	cc -c $(CFLAGS) bst.c

bstDemo.o: bstDemo.c bst.h
	cc -c $(CFLAGS) bstDemo.c

stateManager.o: stateManager.c bst.h
	cc -c $(CFLAGS) stateManager.c
clean:
	rm -f *.o bstDemo names.txt

run: bstDemo
	./bstDemo
