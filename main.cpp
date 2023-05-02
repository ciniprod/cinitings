#include "Graph.h"
#include <fstream>
#include <iostream>


int main(int argc, char* argv[]){
    string fname = argv[1];

    ifstream input_file(fname);

    if(!input_file){
        cout << "Error opening file \n";
        return 1;
    }

    Graph graph(1);
    string start_node, end_node;

    input_file >> start_node >> end_node;

    string start, end;
    int weight;
    while(input_file >> start >> end >> weight){
        int start_index = graph.find_index(start);
        int end_index = graph.find_index(end);

        if(start_index == -1){
            start_index = graph.num_nodes; // Add a new node
            graph.add_node(start);
        }

        if(end_index == -1){
            end_index = graph.num_nodes; // Add a new node
            graph.add_node(end);
        }

        graph.add_edge(start, end, weight);
    }

    graph.dijkstra(start_node);

    int total_distance = graph.distance_to(end_node);

    cout << "Shortest distance to node " << end_node << " From Node " << start_node << "Is " << total_distance << endl;

    return 0;
}