# Graph Algorithms Program

This program includes implementations of various graph algorithms and a graph class in C++.

## 1. Overview of Files

The program consists of the following files:

1. **Graph.hpp** and **Graph.cpp**: These files define the `Graph` class, which represents a graph and provides functionalities to manipulate and analyze it.

2. **Algorithms.hpp** and **Algorithms.cpp**: These files contain implementations of various graph algorithms, including connectivity checks, shortest path finding, cycle detection, bipartiteness check, and negative cycle detection.

## 2. Function Explanation

### 2.1 `Graph` Class Methods:

1. **`loadGraph(std::vector<std::vector<int>> matrix)`**: Loads the graph from an adjacency matrix. The method takes a 2D vector representing the adjacency matrix as input and initializes the graph accordingly.

2. **`printGraph()`**: Prints information about the graph, such as the number of vertices and edges.

### 2.2 `Algorithms` Class Methods:

1. **`isConnected(Graph g)`**: Checks if the graph is connected using Breadth-First Search (BFS).

2. **`shortestPath(Graph g, int start, int end)`**: Finds the shortest path between two vertices using BFS.

3. **`isContainsCycle(Graph g)`**: Checks if the graph contains a cycle using Depth-First Search (DFS).

4. **`isBipartite(Graph g)`**: Checks if the graph is bipartite using BFS.

5. **`negativeCycle(Graph g)`**: Checks for the presence of a negative cycle using the Bellman-Ford algorithm.

## 3. Compilation and Execution


To compile the program, navigate to the directory containing the source code and the Makefile, and run the following command:

```bash
make
This will compile the and run the source files and generate an executable named main.
and you will receive the output of main.cpp as similar as demo.cpp.



3.1 Running Tests
To run the tests, follow these steps:

3.1.1 Compilation
Type the following command to compile the tests:

make test

This will compile the test files and generate an executable named myTest.

3.1.2 Execution
Run the tests by executing the following command:


./myTest
This will execute the myTest.cpp file, which tests the functions using DocTest.

3.2 Cleaning Up
To delete compiled files, executables, and object files, type:


make clean
This command will remove all compiled files, executables (including myprogram and myTest), and object files from the directory.
