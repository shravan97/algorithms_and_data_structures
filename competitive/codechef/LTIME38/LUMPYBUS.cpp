#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,p,q,i,count=0;
		cin>>n>>p>>q;

		ll a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);

		for(i=0;i<n;i++)
		{
			if((a[i]>1) && ((a[i]/2) <= q))
			{
				if((a[i]&1)==1)
				{
					if(p>0)
					{
						// cout<<a[i]<<"- here1 "<<p<<' '<<q<<'\n';
						count++;
						q-=a[i]/2;
						p--;
					}
				}
				else 
				{
					// cout<<a[i]<<"- here2 "<<p<<' '<<q<<'\n';
					count++;
					q-=a[i]/2;
				}

			}
			else if(a[i]/2>q)
			{
				if(p>=2*(a[i]/2-q)+a[i]%2)
				{
					// cout<<a[i]<<"- here3 "<<p<<' '<<q<<'\n';
					count++;
					p-=(2*((a[i]/2-q))+a[i]%2);
					q=0;
					// cout<<p<<' '<<q<<'\n';
				}
			}
			else if(a[i]<=p)
			{
				// cout<<a[i]<<"- here4 "<<p<<' '<<q<<'\n';
				count++;
				p-=a[i];
			}

			if(p==0 && q==0)break;
		}
		cout<<count<<'\n';
	}
	return 0;
}