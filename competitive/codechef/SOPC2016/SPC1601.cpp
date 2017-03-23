#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll t;
	t=1;
	while(t--)
	{
		ll m,n,len;
		string s;
		
		cin>>m>>n>>len;
		if(len!=0)
			cin>>s;

		pair <int,int> pos[4],corners[4];
		corners[0]=make_pair(0,0);
		corners[1]=make_pair(0,m-1);
		corners[2]=make_pair(n-1,0);
		corners[3]=make_pair(n-1,m-1);
		

		for(int i=0;i<4;i++)
		{
			pair <int,int> cur=corners[i];
			for(auto c:s)
				if(c=='U')
				{
					if(cur.first>0)
						cur.first--;
				}
				else if(c=='D')
				{
					if(cur.first<n-1)
						cur.first++;
				}
				else if(c=='L')
				{
					if(cur.second>0)
						cur.second--;
				}
				else if(c=='R')
				{
					if(cur.second<m-1)
						cur.second++;
				}
			pos[i]=cur;
			// cout<<cur.first<<' '<<cur.second<<endl;
		}

		ll mv[4][4];
		// corners[3]=make_pair(4,3);

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				mv[i][j]=abs(corners[j].first-pos[i].first)+abs(corners[j].second-pos[i].second);
				// cout<<mv[i][j]<<' ';
			}
			// cout<<endl;

		}

		ll minval=INT_MAX;

		for(int i=0;i<4;i++)
		{
			ll maxval=INT_MIN;
			for(int j=0;j<4;j++)
				maxval=max(maxval,mv[j][i]);
			minval=min(maxval,minval);
		}

		cout<<minval<<endl;


	}
	return 0;
}
