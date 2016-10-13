#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,k,disq=0,i,tot=0;
		scanf("%d %d",&n,&k);

		std::map<int, int> votes;

		for(i=0;i<n;i++)
		{
			int p;
			scanf("%d",&p);
			if(i+1==p)votes[p]=-1;
			if(votes[p]!=-1)votes[p]++;
		}

		std::map<int, int>::iterator it;
		for(it=votes.begin(); it!=votes.end();it++)
		{
			if(it->second >=k)
				tot++;
		}
		cout<<tot<<'\n';
	}
	return 0;
}