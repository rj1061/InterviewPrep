#include <iostream>
#include <list>

using namespace std;

class Graph{
	private:
		int V; //No of vertices
		list<int> *adj; //pointer to the array containing the adjacency list
		void DFSUtil(int v, bool visited[]);
	public:
		Graph(int v); //Constructor
		void addEdge(int v, int w); //Adding an edge from v
		void DFS(int v); //DFS of vertices reachable from v
};

Graph::Graph(int v){
	this->V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	//add w to V's list
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
	// Mark the current node as visited and print it
	visited[v] = true;
	cout<<v<<" ";

	// Recur for all the vertices adjacent to the vertice
	list<int>::iterator i;
	for(i = adj[v].begin(); i!= adj[v].end(); ++i)
		if(!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::DFS(int v){
	bool *visited = new bool[V];
	for(int i=0; i<V; i++)
		visited[i] = false;

	DFSUtil(v, visited);
}

int main(int argc, char* argv[]){
	Graph g(4);
	g.addEdge(0, 1);
    	g.addEdge(0, 2);
    	g.addEdge(1, 2);
    	g.addEdge(2, 0);
    	g.addEdge(2, 3);
    	g.addEdge(3, 3);

	cout<<"Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2);

	return 0;
}
