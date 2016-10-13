#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,c,co=0,num=0,prev;
	cin>>n>>c;
	while(n--)
	{
		ll k;
		cin>>k;
		if(co!=0)
		{
			if(k-prev<=c)
				num++;
			else num=1;

			prev=k;
		}
		else
		{
			num++;
			prev=k;
		}
		co++;
	}

	cout<<num<<endl;

	return 0;
}