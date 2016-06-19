#include <cstdio>
#include <cstring>
# define vs 5
using namespace std;

bool add_to_path(int v , int graph[vs][vs], int path[],int pos)
{
	if(graph[path[pos-1]][v]==0)
		return false;
	for(int i=0;i<pos;i++)
		if(path[i]==v)
			return false;
	return true;	
}

bool chck_hamcycle(int graph[vs][vs], int path[] , int pos)
{
	if(pos==vs)
	{
		if(graph[path[pos-1]][path[0]])
			return true;
		return false;
	}

	for(int v=1;v<vs;v++)
	{
		if(add_to_path(v,graph , path , pos))
		{
			path[pos]=v;
			if(chck_hamcycle(graph,path,pos+1))
				return true;
			path[pos]=-1;

		}
	}
	return false;
}
bool hamcycle(int graph[vs][vs])
{
	int path[vs];
	memset(path,-1,vs);
	path[0]=0;

	if(chck_hamcycle(graph,path,1))
	{
		printf("Hamiltonian cycle exists and the path is : \n");
		for(int i=0;i<vs;i++)
			printf("%d ",path[i] );
		printf("%d\n",path[0] );
	}
	else
		printf("Hamiltonian cycle doesn't exist \n");
}

int main(int argc, char const *argv[])
{
	int graph[vs][vs] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
    hamcycle(graph);

	return 0;
}