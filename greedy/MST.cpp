/* Implementation of Kruskal's algorithm on minimum spanning tree */

#include <iostream>
#include <vector>
using namespace std;

bool in_vector( vector<int> v , int val)
{
	std::vector<int>::iterator i;
	bool flag=0;

	for(i=v.begin(); i!=v.end();i++)
	{
		if(val==v[*i])
		{
			flag=1;
			break;
		}
	}

	return flag;
}

struct Edge
{
	int weight , v1 , v2;
};

class Graph
{
	int V;
	Edge *adj, *MST;
	int num_edges;

public:
	Graph(int v)
	{
		if(v < 2)
			cout<<"Number of edges is not enough !";
		else
		{
			this->V = v;
			adj = new Edge [v*(v-1) / 2];
			MST = new Edge [v-1];
			num_edges=0;
	    }
	}

	void addEdge(int v1 , int v2 , int weight)
	{
		adj[num_edges].v1 = v1;
		adj[num_edges].v2 =v2;
		adj[num_edges].weight = weight;
		num_edges++;
	}

	void MST_find()
	{
		//To sort the edges based on their weights, P.S use a better sorting algorithm if needed
		for(int k =0;k<num_edges;k++)
		{
			for(int j=k+1;j<num_edges;j++)
				if(adj[j].weight<adj[k].weight)
				{
					Edge temp = adj[j];
					adj[j] = adj[k];
					adj[k] = temp;
				}
		}

		int mst_counter =0;
		std::vector< vector<int> > set;

		for(int i=0;i<num_edges;i++)
		{
			int j=0;
			bool added=0;
			for(j=0;j<set.size();j++)
				if(in_vector(set[j], adj[i].v1) && in_vector(set[j],adj[i].v2))
					break;
				else if(in_vector(set[j] , adj[i].v1))
				{
					set[j].push_back(adj[i].v2);
					MST[mst_counter]=adj[i];
					added=1;
				}
				else if(in_vector(set[j] , adj[i].v2))
				{
					set[j].push_back(adj[i].v1);
					MST[mst_counter]=adj[i];
					added=1;
				}

			if(!added)
			{
				std::vector<int> v;
				v.push_back(adj[i].v1);
				v.push_back(adj[i].v2);
				MST[mst_counter]=adj[i];				
				set.push_back(v);
			}

			mst_counter++;
		}

	}

	
};

int main()
{

	return 0;
}