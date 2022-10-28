all: clear compile run clean

compile:
	g++ -c */*.cpp
	g++ -o main *.o -LC:/dev/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

clean:
	rm *.o

clear:
	clear

run:
	./main

mem: clear compile clean
	 valgrind --leak-check=yes ./main

debug:
	g++ -g */*.cpp
	gdb ./a.out