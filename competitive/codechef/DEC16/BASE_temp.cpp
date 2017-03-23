#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll num=3,count=0;
		ll sqr=sqrt((n));
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==1)
		{
			cout<<"INFINITY\n";
			continue;
		}
		if(n==2)
		{
			cout<<1<<endl;
			continue;
		}
		if(n==3)
		{
			cout<<2<<endl;
			continue;
		}
 
 
		float lg = log((float)(n));
 
		while((num)<= sqr)
		{
			// ll val=n,pow=1;
			// while(val>=num)
			// {
			// 	val/=num;
			// 	pow*=num;
			// }
			if(n<=2*pow(num,(ll)(lg/log(num))) - 1)
				count++;
			num++;
			// cout<<" here "<<pow<<endl;
		}
		// cout<<" count so far : "<<count<<endl;
 
		count+=((n-1)/2);
		count+=2;
 
		cout<<count<<endl;
 
 
	}
	return 0;
}