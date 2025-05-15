[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author

Theo Leonard - 825318930

## Description

Briefly describe what your program does and how the code is structured.
The program is an implamentation of Prim's algorithem, ment to find the minimum spanning trees of a weighted and undirected graph. The graph class made up of graph.cpp/h represnt the graph as an adjacency matrix where the matrix stores the edge weights. The MinHap class made up of heap.cpp/h is made to be a specialized min-heap for Prim's algorithm where we keep vertexes in heap oerder with heapArray[], keep the min edge weights for each vertex with keyArray[], and map each vertex to their heap position with position[]. And the main program just provides the graph for testing the rest of the code, calling primMST() to find and print the min spanning tree.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysiss

| Operation            | Time Complexity   |
|----------------------|-------------------|
| Insert in MinHeap    |     O(log N)      |
| Extract Min          |     O(log N)      |
| Decrease Key         |     O(log N)      |
| Prim’s MST Overall   |     O(ElogV)    |

_Explain why your MST implementation has the above runtime._

Insert in MinHeap: The steps are as follows: inset new element at the end of the heap; compare with parent by bubbling and swapping if nessecary; where worst case is from leaf to root making this operation O(log N).
Extract Min: The steps are as follows: remove the root; replace the root position with the last element in the heap; then we bubble down from the root; where the worst case is root to leaf making this operation O(log N).
Decrease Key: The steps are as follows: decrease the key value for a specific vertex; bubble up; where the worst case is from current position to root making this operation O(log N).
Prim’s MST Overall: For the over all run time complexity we get O(E log V), where E is impacted by our edges and V is impacted by our nodes or vertices and how we are processing them. Worst case, we hit up to O(E) traversing through all edges and for O(log V), which , we get that from insertions and/or insertions. All together, worst case can be interpreted as doing up to O(E) operations, each operation including an O(log V) step.

Input:

Graph g(4);
g.addEdge(0, 1, 1);
g.addEdge(2, 3, 2);

Graph g(1);