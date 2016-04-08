#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class graph
{
	int v;//No. of vertices
	list <int> *adj;//Adjacency list

public:
	graph(int V)
	{
		this->v=V;
		adj = new list<int>[V];
	}

	void DFS_traverser(int V , bool visited[]) //This function loops over recursively and traverses the vertices
	{
		visited[V] = true;
		cout<<V<<' ';

		list<int>::iterator i;
		for(i=adj[V].begin();i!=adj[V].end();i++)
		{
			if(!visited[*i])
				DFS_traverser(*i,visited);
		}
	}

	void addEdge(int V, int w) //This function adds an edge to the graph
	{
		adj[V].push_back(w);
	}

	void DFS_initiator(int start);// This function initiates the DFS process from the given vertex

	~graph()
	{
		delete[] adj;
	}

};

void graph::DFS_initiator(int V)
{
	bool *visited = new bool[V];
	memset(visited , false , V);

	DFS_traverser(V , visited);
	delete visited;
}

int main()
{
	//Sample test
	graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(4,1);
	g.DFS_initiator(4);

	return 0;

}