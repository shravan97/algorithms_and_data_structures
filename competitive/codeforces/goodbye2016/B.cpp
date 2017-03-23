#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	ll y=0;
	// std::vector<ll> v1;
	// std::vector<string> v2;
	bool ans=1,done=0;
	for(int i=0;i<n;i++)
	{

		ll a;
		string s;
		cin>>a>>s;

		if(done)
			continue;

		if(y==20000)
		{
			if(s!="North")
			{
				// cout<<"NO\n";
				ans=0;
				done=1;
			}
		}
		else if(y==0)
		{
			if(s!="South")
			{
				// cout<<"NO\n";
				ans=0;
				done=1;
			}
		}

		if(s=="North")
		{
			y-=a;
		}
		else if(s=="South")
		{
			y+=a;
		}
		
		if(y>20000 || y<0)
		{
			// cout<<"NO\n";
				ans=0;
				done=1;
		}

	}

	if(done)
	{
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		return 0;
	}

	if(y!=0)
	{
		cout<<"NO\n";
	}
	else
		cout<<"YES\n";
	return 0;
}
