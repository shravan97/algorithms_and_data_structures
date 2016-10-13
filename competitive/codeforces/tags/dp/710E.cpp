#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// ll dp(ll n,ll x,ll y,std::vector<ll> &v,ll max_n)
// {
// 	// cout<<" at this point "<<n<<' '<<x<<' '<<y<<endl;
// 	if(n>max_n)
// 		return n-max_n;
// 	else if(n==max_n)
// 		return 0;


// 	ll val1=0,val2=0;

// 	if(v[n+1]!=0)
// 		val1=v[n+1];
// 	else
// 	{
// 		val1=dp(n+1,x,y,v,max_n);
// 		v[n+1]=val1;
// 	}

// 	if(v[2*n]!=0)
// 		val2=v[2*n];
// 	else
// 	{
// 		val2=dp(n*2,x,y,v,max_n);
// 		v[2*n]=val2;
// 	}

// 	v[n] =  min(x+val1,y+val2);
// 	return v[n];
// }

int main(int argc, char const *argv[])
{
	ll n,x,y;
	cin>>n>>x>>y;
	std::vector<ll> v(2*n+1);
	// cout<<x+dp(1,x,y,v,n)<<endl;

	v[1]=x;
	for(ll i=1;i<n;i++)
	{
		if(v[i+1]==0)
		{
			v[i+1]=v[i]+x;
			// cout<<i+1<<" assigned to "<<v[i+1]<<endl;
		}
		else
		{
			v[i+1]=min(v[i+1],v[i]+x);
			// cout<<i+1<<" assigned to "<<v[i+1]<<endl;
		}
		if(2*i>n)
		{
			if(v[n]==0)
				v[n]=y+v[i]+x*(2*i-n-1);
			else
				v[n]=min(v[n],y+v[i]+x*(2*i-n-1));
			// cout<<i<<' '<<v[i+1]<<' '<<v[2*n]<<endl;
			continue;
		}
		if(v[2*i]==0)
		{
			v[2*i]=v[i]+y;
			// cout<<2*n<<" is assigned to "<<v[i]+y<<endl;
		}
		else
		{
			v[2*i]=min(v[2*i],y+v[i]);
			// cout<<2*i<<" is assigned to "<<v[2*i]<<endl;
		}

		// cout<<i<<' '<<v[i+1]<<' '<<v[2*n]<<endl;
	}

	for(ll i=1;i<=n;i++)
		cout<<v[i]<<' ';


	cout<<v[n]<<endl;

	return 0;
}