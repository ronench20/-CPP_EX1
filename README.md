# -CPP_EX1
### This project is an implementation of graph algorithms.

## compilation
to compile the project, you can use the following command:
```bash
make                #compile the project
make test           #compiles the tests executable and runs the tests
make Main           #runs the main program
make valgrind       #runs valgrind on the main program
make valgrind-test  #runs valgrind on the tests
make clean          #Deletes all .o files

```


## in this project I had to implement an undirected graph that has the following features:
- addEdge
- removeEdge
- print_graph

Those functions are declared in Graph.hpp and implemented in Graph.cpp. 


## Following algorithms that had to be implemented:
- BFS
- DFS
- Dijkstra
- Prim
- Kruskal

Those algorithms are declared in Algorithms.hpp and implemented in the Algorithms.cpp.

## In order to implement the following algorithms, I used the following data structures:
- Queue
- Stack 
- Union Find

Those data structures are implemented and declared in files by their names.

## sources
for the intuition on how to build the bfs and dfs algorithms, I used the following YouTube video:
https://www.youtube.com/watch?v=pcKY4hjDrxk&t=846s

for the intuition on how to build the Dijkstra Prim and Kruskal algorithms, I used the pseudocode from the file that is attached below.
[summery algorithms1](blob:https://github.com/ae358c43-910d-4868-b53d-2a7c5f414870) (if there is a problem to open the summery is located also in the github under "ninth commit")
## Author
- Name: Ronen Chereshnya
- ID: 207304338
- Email: ronen.chereshn@msmail.ariel.ac.il