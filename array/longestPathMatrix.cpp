/*
LeetCode 329 - Longest Increasing Path in a Matrix
*/

#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct Node{
	bool visited = false;
	bool tmp = false;
};


/**************
 * Make Adjacency List Graph
 **************/
vector<vector<int> >* buildGraph(vector<vector<int> >* matrix){
	
	int n = (*matrix).size() * (*matrix)[0].size(); // no. nodes
	vector<vector<int> >* graph = new vector<vector<int> >(n);
	int idx = 0;
	for (int i = 0; i<(*matrix).size(); i++){
		int rowSize = (*matrix)[i].size();
		
		for (int j=0; j<rowSize; j++){
			int current = (*matrix)[i][j];
			int neighbor;
			
			// top element valid
			if (i-1 >= 0){
				neighbor = (*matrix)[i-1][j];
				if (current < neighbor){(*graph)[idx].push_back(idx - rowSize);}
			}
			
			// bottom element valid
			if ( i+1 <= (*matrix).size()-1 ){
				neighbor = (*matrix)[i+1][j];
				if (current < neighbor){(*graph)[idx].push_back(idx + rowSize);}
			}
			
			// left element valid
			if (j-1 >= 0){
				neighbor = (*matrix)[i][j-1];
				if (current < neighbor){(*graph)[idx].push_back(idx-1);}
			}
			
			// right element valid
			if ( j+1 <= (*matrix)[i].size()-1 ){
				neighbor = (*matrix)[i][j+1];
				if (current < neighbor){(*graph)[idx].push_back(idx+1);}
			}
			idx++;
		}
	}
	return graph;
}

/****************************
 * Topological Sort Functions
 ****************************/

// DFS traversal for visiting nodes
void visit(int v, vector<Node> &nodes, unordered_set<int> &unvisitedNodes, vector<vector<int> >* graph, stack<int> &S){
	if(nodes[v].tmp){
		printf("ERROR: Cycle detected");
		return;
	}
	
	if (!nodes[v].visited){
		nodes[v].tmp = true;
		for(int neighbor: (*graph)[v] ){
			visit(neighbor, nodes, unvisitedNodes, graph, S);
		}
		nodes[v].visited = true;
		nodes[v].tmp = false;
		unvisitedNodes.erase(v);
		S.push(v);
	}
}

vector<int> TopologicalSort(vector<vector<int> >* graph){
	
	// Initialization
	int n = (*graph).size();
	vector<Node> nodes(n); // contains information about visited status of nodes
	unordered_set<int> unvisitedNodes; // maintains set of unvisited nodes
	for (int i=0; i<n; i++){unvisitedNodes.insert(i);}
	stack<int> S; // data structure to record topological ordering
	
	// Topological sort algorithm
	while (!unvisitedNodes.empty()){
		unordered_set<int>::iterator a = unvisitedNodes.begin(); // select unmarked node
		int v = *a;
		visit(v, nodes, unvisitedNodes, graph, S); // visit node
	}
	
	// record topological ordering in list
	vector<int> L;
	while (!S.empty()){ L.push_back(S.top()); S.pop();}
	return L;
}

/***********
 Calculation
 **********/

// calculate length of longest increasing path in matrix
int computeAnswer(vector<vector<int> >* graph, vector<int> L){
	vector<int> lengths(L.size(), 0);
	int longestPath = 0;
	
	for (int i = L.size()-1; i>=0; i--){
		int cur = L[i];
		if ((*graph)[cur].size() == 0){continue;} // no neighbors ahead in topological ordering
		
		for (int neighbor:(*graph)[cur]){
			int newDistance = 1 + lengths[neighbor];
			if (newDistance > lengths[cur]){lengths[cur] = newDistance;}
			if (newDistance > longestPath){longestPath = newDistance;}
		}
	}
	return longestPath + 1;
}

/****************
 * Main Functions
 ****************/

int longestIncreasingPath(vector<vector<int>>& matrix) {
	
	// convert matrix into a graph
	vector<vector<int> >* m = &matrix;
	vector<vector<int> >* graph = buildGraph(m);
	
	// run topological sort
	vector<int> L = TopologicalSort(graph);
	
	// compute longest path
	return computeAnswer(graph,L);
}

int main(){
	vector<vector<int>> matrix1 {
		{ 9, 9, 4},
		{ 6, 6, 8 },
		{ 2, 1, 1 }
	};
	
	vector<vector<int>> matrix2 {
		{ 3, 4, 5},
		{ 3, 2, 6 },
		{ 2, 2, 1 }
	};
	
	printf("longest path: %d \n",longestIncreasingPath(matrix1));
	//printf("longest path: %d \n",longestIncreasingPath(matrix2));
	
	return 0;
}



