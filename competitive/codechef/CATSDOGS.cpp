#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll c,d,l;
		
		cin>>c>>d>>l;

		if(d==0 && 4*c!=l)
		{
			cout<<"no\n";
			continue;
		}

		if(l>4*(c+d) || l<4*d)
			cout<<"no\n";
		else if(l%4==0)
		{
			if(c>=2*d)
			{
				if(l>=(c-d)*4)
				{
					cout<<"yes\n";
				}
				else
					cout<<"no\n";
			}
			else
				cout<<"yes\n";
		}
		else
			cout<<"no\n";

	}
	return 0;
}
