#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,m;
	cin>>n>>m;
	ll apos=0;
	bool dir=1;
	while(m--)
	{
		int typ;
		ll val;
		cin>>typ>>val;
		if(typ==1)
			apos=(apos+val)%n;
		else
		{
			dir=!dir;
			if(!(val&1))
			{
				apos = ((val/2)+(n-apos+val/2))%n;
				// cout<<" h "<<apos<<endl;
			}
			else
			{
				apos = (((val-1)/2)+(n-apos)+(val/2)+1)%n;
				// cout<<" h "<<apos<<endl;
			}

		}
	}
	// cout<<apos<<endl;
	if(dir)
		cout<<1<<' '<<(n-apos)%n<<endl;
	else if(!(n&1))
	{
		if(apos>n/2)
		{
			ll dist = n-apos;
			if(dist&1)
			{
				cout<<2<<' '<<n-dist/2-1<<endl;
			}
			else cout<<2<<' '<<n-dist/2<<endl;
		}
		else
			cout<<2<<' '<<apos<<endl;
	}
	else
	{
		if(apos>n/2)
		{
			ll dist = n-apos;
			if(dist&1)
			{
				cout<<2<<' '<<n-dist/2<<endl;
			}
			else cout<<2<<' '<<n-dist/2-1<<endl;
		}
		else
			cout<<2<<' '<<apos<<endl;

	}

	return 0;
}