// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
   vdata.push_back(value); // Add value to the end
    int index = vdata.size() - 1; // Index of the newly added element
    // Heapify up
    while (index != 0 && vdata[index] < vdata[(index - 1) / 2]) {
        std::swap(vdata[index], vdata[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()) return; // Heap is empty
    vdata[0] = vdata.back(); // Replace root with the last element
    vdata.pop_back(); // Remove the last element
    std::vector<int>::size_type index = 0;
    // Heapify down
    while (true) {
        std::vector<int>::size_type smallest = index;
        std::vector<int>::size_type leftChild = 2 * index + 1;
        std::vector<int>::size_type rightChild = 2 * index + 2;
        if (leftChild < vdata.size() && vdata[leftChild] < vdata[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < vdata.size() && vdata[rightChild] < vdata[smallest]) {
            smallest = rightChild;
        }
        if (smallest == index) break; // No more heapifying needed
        std::swap(vdata[index], vdata[smallest]);
        index = smallest;
    }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata.empty() ? throw std::runtime_error("Heap is empty") : vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    