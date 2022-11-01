all: clear compile run clean

gui: clear guiComp run clean

guiComp:
	g++ -c *.cpp
	g++ -o main *.o -LC:/dev/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

compile:
	g++ -c *.cpp
	g++ -o main *.o -LC:/dev/lib -lsfml-system -lsfml-window -lsfml-graphics

clean:
	rm *.o

clear:
	clear

run:
	./main

mem: clear compile clean
	 valgrind --leak-check=full --show-leak-kinds=all ./main

debug:
	g++ -g *.cpp
	gdb ./a.out