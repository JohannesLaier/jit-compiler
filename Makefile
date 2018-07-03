CC      = /usr/bin/g++
CFLAGS  = -Wall -g
LDFLAGS =

OBJ = parser.o code.o memory.o jsparser.o jsscope.o jsvar.o jsvarnumber.o jsvarstring.o jsvarfunction.o jslexer.o jslexem.o jsvararray.o

all:
	$(CC) $(CFLAGS) -c src/parser.h src/parser.cpp
	$(CC) $(CFLAGS) -c src/code.h src/code.cpp
	$(CC) $(CFLAGS) -c src/memory.h src/memory.cpp
	$(CC) $(CFLAGS) -c src/js/jsparser.h src/js/jsparser.cpp
	$(CC) $(CFLAGS) -c src/js/jsscope.h src/js/jsscope.cpp
	$(CC) $(CFLAGS) -c src/js/jsvar.h src/js/jsvar.cpp
	$(CC) $(CFLAGS) -c src/js/jsvararray.h src/js/jsvararray.cpp
	$(CC) $(CFLAGS) -c src/js/jsvarnumber.h src/js/jsvarnumber.cpp
	$(CC) $(CFLAGS) -c src/js/jsvarstring.h src/js/jsvarstring.cpp
	$(CC) $(CFLAGS) -c src/js/jsvarfunction.h src/js/jsvarfunction.cpp
	$(CC) $(CFLAGS) -c src/js/jslexer.h src/js/jslexer.cpp
	$(CC) $(CFLAGS) -c src/js/jslexem.h src/js/jslexem.cpp

	$(CC) $(CFLAGS) -o jit src/jit.cpp $(OBJ) $(LDFLAGS)
	
install:
	cp jit /usr/bin

clean:
	rm -rf *.o
	rm -rf *.gch
	rm -rf *~
	rm -rf src/*.o
	rm -rf src/*.gch
	rm -rf src/*~
	rm -rf src/js/*.o
	rm -rf src/js/*.gch
	rm -rf src/js/*~
	rm -rf jit
