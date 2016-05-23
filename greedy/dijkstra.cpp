#include <iostream>
#include <cstring>
#include <limits.h>
#define min(a,b)((a>b)?b:a)
using namespace std;

//Function to implement Dijkstara's algorithm for undirected graphs
void dijkstra(int graph[][] , int v , int src)
{
	int i , j ,count=0 , dist[v];
	memset(dist , INT_MAX , v);
	dist[src]=0;

	for(i=0;i<v;i++)
	{
		for(j=0;j<i;j++)
		{
			if(src!=i && min(graph[i][j] , ))
		}
	}
}

int main()
{
	return 0;
}