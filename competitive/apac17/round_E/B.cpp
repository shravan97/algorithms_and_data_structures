#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int calc(ll a,ll p,ll n)
{
	ll res=1;
	// cout<<" at "<<a<<endl;

	for(int i=1;i<p;i++)
	{
		// cout<<res<<endl;
		if(a>1e9 && i>=2)
			return 1;
		res+=pow(a,i);

		if(res>n)
			return 1;
	}
	if(res<n)
		return -1;
	return 0;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	int c=1;

	ofstream ofile;
	ofile.open("out.txt");

	while(t--)
	{
		ll n;
		cin>>n;

		for(int i=55;i>=2;i--)
		{
			ll u=n,l=2,mid=(l+u)/2;

			int chck = calc(mid,i,n);
			// cout<<" u "<<u<<endl;
			// cout<<" l "<<l<<endl;
			// cout<<" ichck "<<chck<<endl;

			while((chck!=0) && (mid>1) && (u>=l))
			{
				if(chck==1)
				{
					u=mid-1;
				}
				else if(chck==-1)
					l=mid+1;
				else
					break;

				mid=(l+u)/2;
				
				if(mid<=1)
					break;
				// cout<<" i "<<i<<endl;
				
				// cout<<" eq "<<(u>=l)<<endl;
				// cout<<" vals "<<chck<<' '<<mid<<' '<<i<<endl;
				// // cout<<" mid "<<mid<<endl;
				// cout<<" u "<<u<<endl;
				// cout<<" l "<<l<<endl;

				chck=calc(mid,i,n);
			}

			// cout<<" vals "<<chck<<' '<<mid<<' '<<i<<endl;

			if(chck==0)
			{
				cout<<mid<<endl;
				ofile<<"Case #"<<c<<": "<<mid<<endl;
				c++;
				break;
			}

		}

	}
	return 0;
}
