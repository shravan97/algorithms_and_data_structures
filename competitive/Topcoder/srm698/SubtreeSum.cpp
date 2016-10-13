#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;
class SubtreeSum
{
public:

	int traverse(list<int> *adj,int v , bool *visited,int pos , std::vector<int> &x)
	{
		visited[v]=1;
		list<int>::iterator it;

		int val=adj[v].size()*((pos%mod)*(x[v])%mod)%mod;
		cout<<" val at "<<v<<' '<<val<<endl;
		for(it=adj[v].begin();it!=adj[v].end();it++)
		{
			if(!visited[*it])
			{
				val+=traverse(adj,*it,visited,pos+1,x);
			}
		}

		if(v==0)
			return val+x[0];

		return val;
	}

	int getSum(vector <int> p, vector <int> x)
	{
		list<int> adj[x.size()];
		vector <int>::iterator it;
		int i=1;
		for(it=p.begin();it!=p.end();it++)
		{
			adj[*it].push_back(i);
			adj[i].push_back(*it);
			i++;
		}

		bool visited[x.size()];
		memset(visited,0,sizeof(visited));
		return traverse(adj,0,visited,1,x);
	}
};

int main(int argc, char const *argv[])
{
	SubtreeSum s;
	std::vector<int> p={0,1},x={1,2,4};
	// p.push_back(0);
	// x.push_back(1);
	// x.push_back(2);
	
	cout<<s.getSum(p,x)<<endl;
	return 0;
}