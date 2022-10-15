all: clear compile run clean

compile:
	g++ -c *.cpp
	g++ -o main *.o

clean:
	rm *.o
	rm *.out

clear:
	clear

run:
	./main

mem: clear compile clean
	 valgrind --leak-check=yes ./main

debug:
	g++ -g *.cpp
	gdb ./a.out