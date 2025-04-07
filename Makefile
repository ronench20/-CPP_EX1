#ronen.chereshn@msmail.ariel.ac.il

HEADERS = Algorithms.hpp Graph.hpp doctest.h Queue.hpp Stack.hpp UnionFind.hpp
FLAGS = -g -Wall

main: main.o Algorithms.o Graph.o Queue.o Stack.o UnionFind.o
	g++ $(FLAGS) -o main main.o Algorithms.o Graph.o Queue.o Stack.o UnionFind.o

Main: main
	./main

test: Test.o Algorithms.o Graph.o Queue.o Stack.o UnionFind.o
	g++ $(FLAGS) -o test Test.o Algorithms.o Graph.o Queue.o Stack.o UnionFind.o
	./test

Algorithms.o: Algorithms.cpp $(HEADERS)
	g++ $(FLAGS) -c Algorithms.cpp
Graph.o: Graph.cpp $(HEADERS)
	g++ $(FLAGS) -c Graph.cpp

main.o: main.cpp $(HEADERS)
	g++ $(FLAGS) -c main.cpp

Queue.o: Queue.cpp $(HEADERS)
	g++ $(FLAGS) -c Queue.cpp

Stack.o: Stack.cpp $(HEADERS)
	g++ $(FLAGS) -c Stack.cpp

Test.o: Test.cpp $(HEADERS)
	g++ $(FLAGS) -c Test.cpp

UnionFind.o: UnionFind.cpp $(HEADERS)
	g++ $(FLAGS) -c UnionFind.cpp

valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

valgrind-test: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

clean:
	rm -f *.o main test

.PHONY: Main main test valgrind clean
