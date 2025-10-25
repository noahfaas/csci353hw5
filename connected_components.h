#ifndef CONNECTED_COMPONENTS
#define CONNECTED_COMPONENTS

#include <iostream>
#include <queue>
#include "adjacency_list.h"

void connected_components(AdjacencyList* graph, int numNodes){
	// takes a pointer to the adjacency list of a graph and the total number of nodes
	// discovers the connected components, printing the nodes in each component, with line breaks in between the components.

	// WHEN YOU START WORKING ON THIS, DELETE OR COMMENT THE NEXT TWO LINES
	//std::cout << "connected_components not implemented" << std::endl;
	//return;

	// this is all up to you - reference the pseudocode from class to help, and you might also want to look back at the implementations for bfs and dfs
	bool* visited = new bool[numNodes];
	for (int i = 0; i < numNodes; ++i) visited[i] = false;
	for (int start = 0; start < numNodes; ++start) {
    	if (visited[start]) continue;
    	std::queue<int> q;
    	q.push(start);
    	while (!q.empty()) {
        	int u = q.front(); q.pop();
        	if (visited[u]) continue;
        	visited[u] = true;
        	std::cout << u << " ";
        	for (auto v : *(graph->neighbors(u))) {
            	if (!visited[v]) q.push(v);
        	}
    	}
    std::cout << std::endl;
}

delete[] visited;
}

#endif