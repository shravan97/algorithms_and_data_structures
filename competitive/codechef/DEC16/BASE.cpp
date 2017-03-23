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
		ll count=0;
		// ll sqr=sqrt((n));
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

		ll prev=n,c=1;
		float fprev = (float)prev;
		ll next=ceil((float)pow((float)((float)n+1.0)/2.0,(float)(1.0/(float)c)));

		while(prev>1 && next>1)
		{
			// cout<<prev<<' '<<ceil((float)pow((float)((float)n+1.0)/2.0,(float)(1.0/(float)c)))<<endl;
			// ll v = ceil((float)pow((float)((float)n+1.0)/2.0,(float)(1.0/(float)c)));
			// if(v>prev)
			// {

			// 	count++;
			// }
			// else

			if(prev>=next)
				count+=(prev-next)+1;
			cout<<" count "<<count<<endl;
			c++;

			fprev=(float)pow((float)(n),(float)(1.0/(float)c));
			prev=fprev;
			next=ceil((float)pow((float)((float)n+1.0)/2.0,(float)(1.0/(float)c)));
			cout<<" prev : "<<prev<<"  ,  next : "<<next<<endl;
		}

		
		// cout<<" count so far : "<<count<<endl;

		// count+=((n-1)/2);
		// count+=1;

		cout<<count<<endl;
		cout<<(float)pow(125.0,(float)(1.0/3.0))-5.000<<endl;
		cout<<ceil(5.0000)<<endl;


	}
	return 0;
}
