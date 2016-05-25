#include <iostream>
#include <cstring>
#define max_val 100
#define min(a,b)((a>b)?b:a)
using namespace std;

//Function to implement Dijkstara's algorithm for undirected graphs
void dijkstra(int graph[9][9] , int v , int src)
{
	int i , j ,count=0 , dist[v];
	memset(dist , max_val , v);
	dist[src]=0;
	// cout<<dist[v-2]<<'\n';
	// cout<<max_val<<'\n';

	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i!=src && j!=i)
			{
				// cout<<dist[j]<<"here";
				dist[i] = min(dist[i],graph[i][j]+dist[j]);
				// cout<<dist[i]<<'\n';
			}
		}
	}

	for(i=0;i<v;i++)
		cout<<dist[i]<<' ';
}

int main()
{
	int graph[9][9]= {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

	dijkstra(graph , 9,1);
	return 0;
}