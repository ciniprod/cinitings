#include <iostream>
#include <cstring>

using namespace std;

struct Edge{
    string destination;
    int weight;
};

struct Node{
    string data;
    bool visited;
    int distance;
    int num_adjacencies;
    Edge* adjacencies;

};

class MinHeap{
    public:
        Node** heap;
        int heap_capacity;
        int size;

        MinHeap(int);
        ~MinHeap();

        void push(Node*);
        void heapify(int i);
        Node* pop ();
        void build_heap();
};