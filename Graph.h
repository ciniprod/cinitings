#include "minHeap.h"
#include <cmath>

class Graph{
    public:

    Node* nodes;
    int num_nodes;

    Graph(int);
    void add_edge(string, string, int);
    void add_node(string);
    int find_index(string);
    int distance_to(string);
    void dijkstra(string);
};