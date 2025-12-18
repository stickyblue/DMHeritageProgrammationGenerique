FLAGS=-Wall -Werror -lm -g -std=c++20

Exercice : o/main.o 
	g++ $(FLAGS) o/main.o 

o/main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp -o o/main.o

