#include "heap.h"
#include <algorithm>
#include <iostream>

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

void MinHeap::insert(int vertex, int key) {
    if (size >= capacity) {
        return;
    }
   
    int currentIndex = size;
    heapArray[currentIndex] = vertex;
    keyArray[currentIndex] = key;
    position[vertex] = currentIndex;
    size++;
   
    while (currentIndex != 0) {
        int parentIndex = (currentIndex - 1) / 2;
       
        if (keyArray[parentIndex] <= keyArray[currentIndex]) {
            break;
        }
       
        std::swap(heapArray[currentIndex], heapArray[parentIndex]);
        std::swap(keyArray[currentIndex], keyArray[parentIndex]);
        position[heapArray[currentIndex]] = currentIndex;
        position[heapArray[parentIndex]] = parentIndex;
       
        currentIndex = parentIndex;
    }
}

int MinHeap::extractMin() {
    if (size <= 0) {
        return -1;
    }
   
    if (size == 1) {
        size--;
        return heapArray[0];
    }
   
    int minElement = heapArray[0];
   
    heapArray[0] = heapArray[size - 1];
    keyArray[0] = keyArray[size - 1];
    position[heapArray[0]] = 0;
    size--;
   
    minHeapify(0);
   
    return minElement;
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int currentIndex = position[vertex];
    keyArray[currentIndex] = newKey;
   
    while (currentIndex != 0) {
        int parentIndex = (currentIndex - 1) / 2;
       
        if (keyArray[parentIndex] <= keyArray[currentIndex]) {
            break;
        }
       
        std::swap(heapArray[currentIndex], heapArray[parentIndex]);
        std::swap(keyArray[currentIndex], keyArray[parentIndex]);
        position[heapArray[currentIndex]] = currentIndex;
        position[heapArray[parentIndex]] = parentIndex;
       
        currentIndex = parentIndex;
    }
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

void MinHeap::minHeapify(int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
   
    if (leftChild < size && keyArray[leftChild] < keyArray[smallest]) {
        smallest = leftChild;
    }
   
    if (rightChild < size && keyArray[rightChild] < keyArray[smallest]) {
        smallest = rightChild;
    }
   
    if (smallest != index) {
        std::swap(heapArray[index], heapArray[smallest]);
        std::swap(keyArray[index], keyArray[smallest]);
        position[heapArray[index]] = index;
        position[heapArray[smallest]] = smallest;
       
        minHeapify(smallest);
    }
}