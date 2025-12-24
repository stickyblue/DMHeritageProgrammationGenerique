FLAGS=-Wall -Werror -lm -g -std=c++20

Exercice : o/main.o
	g++ $(FLAGS) o/main.o -o Exercice

o/main.o: src/main.cpp head/Container.h head/Vector.h inl/Vector.inl head/PriorityQueue.h inl/PriorityQueue.inl
	g++ $(FLAGS) -c src/main.cpp -o o/main.o

