#include "Graph.h"
#include "minHeap.h"


Graph::Graph(int size){
    nodes = new Node[size];
    num_nodes = size;
}

int Graph::find_index(string data){
    for(int i = 0; i < num_nodes; i++){
        if(nodes[i].data == data){
            return i;
        }
    }
    return -1;
}

int Graph::distance_to(string final_destination){
    int destination_index = find_index(final_destination);
    if(destination_index == -1){
        return -1;
    }

    return nodes[destination_index].distance;
}


void Graph::add_node(string data){
    if(find_index(data) == -1){
        Node new_node;
        new_node.data = data;
        nodes[num_nodes] = new_node;
        num_nodes++;
    }
}

void Graph::add_edge(string start, string end, int weight){
    int start_index = find_index(start);
    int end_index = find_index(end);

    if(start_index != -1 && end_index != -1){
        Edge* adjacencies = nodes[start_index].adjacencies;
        int num_adjacencies = nodes[start_index].num_adjacencies;
        adjacencies[num_adjacencies].destination = end;
        adjacencies[num_adjacencies].weight = weight;
        nodes[start_index].num_adjacencies++;
    }

}

void Graph::dijkstra(string start){
    MinHeap heap(num_nodes);

    for(int i = 0; i < num_nodes; i++){
        nodes[i].distance = INFINITY;
        nodes[i].visited = false;
    }


    int start_index = find_index(start);
    if(start_index == -1)
        return;
    nodes[start_index].distance = 0;

    heap.push(&nodes[start_index]);

    while(heap.size > 0){

        Node* current = heap.pop();

        // skip if already visited
        if(current->visited)
            continue;


        current->visited = true;
        for(int i = 0; i < current->num_adjacencies; i++){

            string destination = current->adjacencies[i].destination;
            int dest_index = find_index(destination);
            if(dest_index == -1)
                continue;


            int new_distance = current->distance + current->adjacencies[i].weight;


            if(new_distance < nodes[dest_index].distance){
                nodes[dest_index].distance = new_distance;
                heap.push(&nodes[dest_index]);
            }
        }
    }
}