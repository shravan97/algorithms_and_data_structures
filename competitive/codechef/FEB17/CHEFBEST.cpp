#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;

		// std::vector<bool> v;
		std::vector<ll> ones,zr;
		for(ll i=0;i<n;i++)
		{
			bool z;
			cin>>z;
			if(z)
				ones.push_back(i);
			else
				zr.push_back(i);
		}

		ll prev=0;

		for(ll i=0;i<ones.size();i++)
		{
			// cout<<ones[i]<<' ';
			if(i==0)
			{
				prev=ones[0];
			}
			else
			{
				if(((ones[i-1]+1)==ones[i]) && prev!=0)
				{
					prev+=1;
				}
				else
					prev+=(ones[i]-ones[i-1]-1);
			}
		}
		// cout<<endl;

		printf("%lld\n",prev );

		// ll mx=INT_MIN,index=0;

		// for(ll i=0;i<ones.size();i++)
		// {
		// 	if(abs(index-ones[i]) > mx)
		// 		mx=abs(index-ones[i]);
		// 	index++;
		// }
		// for(ll i=0;i<zr.size();i++)
		// {
		// 	if(abs(index-zr[i]) > mx)
		// 		mx=abs(index-zr[i]);
		// 	index++;
		// }

		// cout<<mx<<endl;

	}
	return 0;
}