#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,c;
		cin>>n>>m>>c;
		ll minV = min(n,m) , maxV=max(n,m),count=0;

		for(ll i=1;i<=minV;i++)
		{
			if(c%i==0)
				if(c/i <= maxV)
				{
					// cout<<i<<' '<<c/i<<endl;
					count++;
				}
		}
		cout<<count<<endl;
	}
	return 0;
}