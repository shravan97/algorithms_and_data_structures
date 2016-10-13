#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

bool rec(int st[],bool truth[]  ,int k , bool visited[],int base_st , bool base_tr, bool prev)
{
	cout<<st[st[k]-1]-1;
	if(visited[k]==-1)
		visited[k]=(prev)?truth[k]:!truth[k];
	else if(visited[k]!=-1)
		return !(visited[k]==prev);
	if(st[st[k]-1]-1 == k)
	{
		if(visited[st[st[k]-1]-1]!=-1)
		{
			if(visited[st[st[k]-1]-1]!=(prev)?truth[k]:!truth[k])
				return true;
		}
		return false;
	}
	else if(base_st==k)
	{
		if(base_tr==truth[k])return false;
		else return true;
	}
	return rec(st , truth ,st[st[k]-1]-1 , visited,base_st,true,truth[k]);
}

int main(int argc, char const *argv[])
{
	while(true)
	{
		int n,i=0;
		cin>>n;
		if(!n)break;
		int st[n];
		bool truth[n];
		memset(truth,0,n);
		while(i<n)
		{
			string s;
			cin>>st[i]>>s;
			if(s=="true")
			{
				truth[i]=true;
			}
			else truth[i]=false;
			i++;
		}

		int visited[n];
		memset(visited,-1,n);
		i=0;
		int count=0;

		while(count<n)
		{
			if(visited[i]==-1)
			{
				visited[i]=1;
				if(rec(st , truth ,st[st[i]-1]-1 , visited,i,true,truth[i])==1)
				{
					flag=1;
					cout<<"PARADOX\n";
					break;
				}
			}

			i++;
		}
		if(!flag)cout<<"NOT PARADOX\n";
	}
	return 0;
}