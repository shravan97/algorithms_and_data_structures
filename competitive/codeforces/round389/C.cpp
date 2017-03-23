#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	string s;
	cin>>s;

	pair <ll,ll> pt=make_pair(0,0), prev;

	ll dist=0;
	bool p=0;
	ll count=0;

	for(auto c:s)
	{
		pair <ll,ll> newpt=pt;
		if(c=='L')
		{
			if(p)
			{
				newpt.first--;
				dist+=1;
				if(dist>abs(prev.first-newpt.first) + abs(prev.second-newpt.second))
				{
					prev=pt;
					dist=0;
					count++;
				}
			}
			else
			{
				newpt.first--;
				p=1;
			}
		}
		if(c=='R')
		{
			if(p)
			{
				newpt.first++;
				dist+=1;
				if(dist>abs(prev.first-newpt.first) + abs(prev.second-newpt.second))
				{
					prev=pt;
					dist=0;
					count++;
				}
			}
			else
			{
				newpt.first++;
				p=1;
			}
		}
		if(c=='D')
		{
			if(p)
			{
				newpt.second--;
				dist+=1;
				if(dist>abs(prev.first-newpt.first) + abs(prev.second-newpt.second))
				{
					prev=pt;
					dist=0;
					count++;
				}
			}
			else
			{
				newpt.second--;
				p=1;
			}
		}
		if(c=='U')
		{
			if(p)
			{
				newpt.second++;
				dist+=1;
				if(dist>abs(prev.first-newpt.first) + abs(prev.second-newpt.second))
				{
					prev=pt;
					dist=0;
					count++;
				}
			}
			else
			{
				newpt.second++;
				p=1;
			}
		}


		pt=newpt;
	}

	cout<<count+1<<endl;
	return 0;
}