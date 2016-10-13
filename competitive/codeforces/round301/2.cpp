#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,p,k,x,y,t;
	cin>>n>>k>>p>>x>>y;
	t=k;
	vector<ll> a,added;
	ll s=0;
	while(t--)
	{
		ll z;
		cin>>z;
		a.push_back(z);
		s+=z;
	}
	if(s>x)
	{
		cout<<-1<<endl;
		return 0;
	}
	// cout<<" h5 "<<endl;

	sort(a.begin(),a.end());
	ll sz=k, last=0;

	for(ll i=k;i<n;i++)
	{

		float m;
		if(sz!=0)
			m = (sz&1)?(float)(a[sz/2]):(float)((float)(a[(sz-1)/2]+a[sz/2])/2.0);
		else m=0;
		// cout<<" med "<<m<<endl;
		if(m<(float)(y))
		{
			if(i==n-1)last=1;
			a.push_back(y);
			added.push_back(y);
			s+=y;
			// cout<<" here  "<<endl;
		}
		else
		{ 
			a.push_back(1);
			added.push_back(1);
			s++;
		}
		sort(a.begin(),a.end());
		sz++;
	}
	// cout<<" h6 "<<endl;
	if(s>x)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(a.begin(),a.end());

	// cout<<a[n/2]<<endl;
	if(a[n/2]<y)
	{
		if(last==0)
		{
			// cout<<" h1 "<<endl;
			added.erase(added.end()-1);
			a.erase(a.begin());
			// cout<<" h2 "<<endl;

			a.push_back(y);
			added.push_back(y);
			sort(a.begin(),a.end());
			s+=y-1;
			if(a[n/2]<y || s>x)
			{
				cout<<-1<<endl;
				return 0;
			}
			else
			{
				// cout<<" h3 "<<endl;
				for(ll i=0;i<n-k;i++)
				{
					cout<<added[i]<<' ';
				}
				cout<<endl;
				return 0;
			}

		}

		cout<<-1<<endl;
	}
	else
	{
		// cout<<" h4 "<<endl;
		for(ll i=0;i<n-k;i++)
		{
			cout<<added[i]<<' ';
		}
		cout<<endl;
	}

	return 0;
}