#include <iostream>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll no_od=0;
	bool flag=0;
	while(n--)
	{
		ll k;
		cin>>k;

		if(k&1)
		{
			no_od++;
		}
		else if(k==0)
			if(no_od&1)
			{
				flag=1;
				break;
			}
	}

	if(flag)
		cout<<"NO\n";
	else if(no_od&1)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}