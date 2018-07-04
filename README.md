# Just in time compiler for Javascript #

Prototype of a small just in time compiler for javascript written in c++. This compiler just supports the basic featurs like variables, arithmetic operations, ans so on.

## Build ##

To build this project use the make file to copmile to projekt.

```sh
user@johannes:~/workspace/jit-compiler$ make
/usr/bin/g++ -Wall -g -c src/parser.h src/parser.cpp
/usr/bin/g++ -Wall -g -c src/code.h src/code.cpp
/usr/bin/g++ -Wall -g -c src/memory.h src/memory.cpp
/usr/bin/g++ -Wall -g -c src/js/jsparser.h src/js/jsparser.cpp
/usr/bin/g++ -Wall -g -c src/js/jsscope.h src/js/jsscope.cpp
/usr/bin/g++ -Wall -g -c src/js/jsvar.h src/js/jsvar.cpp
/usr/bin/g++ -Wall -g -c src/js/jsvararray.h src/js/jsvararray.cpp
/usr/bin/g++ -Wall -g -c src/js/jsvarnumber.h src/js/jsvarnumber.cpp
/usr/bin/g++ -Wall -g -c src/js/jsvarstring.h src/js/jsvarstring.cpp
/usr/bin/g++ -Wall -g -c src/js/jsvarfunction.h src/js/jsvarfunction.cpp
/usr/bin/g++ -Wall -g -c src/js/jslexer.h src/js/jslexer.cpp
/usr/bin/g++ -Wall -g -c src/js/jslexem.h src/js/jslexem.cpp
/usr/bin/g++ -Wall -g -o jit src/jit.cpp parser.o code.o memory.o jsparser.o jsscope.o jsvar.o jsvarnumber.o jsvarstring.o jsvarfunction.o jslexer.o jslexem.o jsvararray.o 
user@johannes:~/workspace/jit-compiler$ 
```
## Execute ##
The compiler cli:
```
johannes@johannes:~/workspace/jit/jit-compiler$ ./jit 
Just in Time Compiler <JohannesLaier@gmail.com> V0.1
Usage: ./jit [sourcefile]
johannes@johannes:~/workspace/jit/jit-compiler$
```
Execute a test file:
```
johannes@johannes:~/workspace/jit/jit-compiler$ ./jit test/test4.m 
test => 4
johannes@johannes:~/workspace/jit/jit-compiler$
```
The content of a test4.m file:
```
var test = 4 / 2;
```
