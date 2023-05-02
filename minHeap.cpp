#include "minHeap.h"

MinHeap::MinHeap(int capacity) {
    heap_capacity = capacity;
    heap = new Node*[capacity];
    size = 0;
}
 
void MinHeap::push(Node* node) {
    if (size == heap_capacity) {
        return;
    }
    heap[size] = node;
    size++;
}

void MinHeap::heapify(int i) {
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < size && heap[left]->distance < heap[smallest]->distance)
        smallest = left;

    if (right < size && heap[right]->distance < heap[smallest]->distance)
        smallest = right;

    if (smallest != i) {
        Node* temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(smallest);
    }
}

Node* MinHeap::pop() {
    if (size == 0)
        return nullptr;

    Node* root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapify(0);

    return root;
}

void MinHeap::build_heap(){
    for(int i = size/2 - 1; i >=0; i--){
        heapify(i);
    }
}

