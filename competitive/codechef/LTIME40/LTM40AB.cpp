#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;

		ll s=0;
		for(ll i=a;i<=b;i++)
		{
			if(i<c)
				s+=d-c+1;
			else if(i>=c)
			{
				if(i<d)
					s+=d-i;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}