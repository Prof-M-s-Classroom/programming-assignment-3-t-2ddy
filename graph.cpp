#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>

Graph::Graph(int vertices) {
    numVertices = vertices;

    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0; 
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    int* parentOfVertex = new int[numVertices];
    int* keyValue = new int[numVertices];
    bool* isIncludedInMST = new bool[numVertices];

    for (int i = 0; i < numVertices; i++) {
        keyValue[i] = INT_MAX;
        isIncludedInMST[i] = false;
    }

    MinHeap minHeap(numVertices);

    keyValue[0] = 0;
    minHeap.insert(0, 0);

    for (int i = 1; i < numVertices; i++) {
        minHeap.insert(i, INT_MAX);
    }

    int totalMSTWeight = 0;
    std::cout << "Minimum Spanning Tree Edges:" << std::endl;

    while (!minHeap.isEmpty()) {
        int currentVertex = minHeap.extractMin();
        isIncludedInMST[currentVertex] = true;

        if (currentVertex != 0) {
            std::cout << parentOfVertex[currentVertex] << " - " << currentVertex 
                      << " : " << adjMatrix[currentVertex][parentOfVertex[currentVertex]] << std::endl;
            totalMSTWeight += adjMatrix[currentVertex][parentOfVertex[currentVertex]];
        }

        for (int neighborVertex = 0; neighborVertex < numVertices; neighborVertex++) {
            int edgeWeight = adjMatrix[currentVertex][neighborVertex];
            
            if (edgeWeight != 0 && !isIncludedInMST[neighborVertex]) {
                if (edgeWeight < keyValue[neighborVertex]) {
                    keyValue[neighborVertex] = edgeWeight;
                    parentOfVertex[neighborVertex] = currentVertex;
                    minHeap.decreaseKey(neighborVertex, keyValue[neighborVertex]);
                }
            }
        }
    }

    std::cout << "Total MST Weight: " << totalMSTWeight << std::endl;

    delete[] parentOfVertex;
    delete[] keyValue;
    delete[] isIncludedInMST;
}