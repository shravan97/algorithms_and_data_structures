#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n,m,k,x,y;
	cin>>n>>m>>k>>x>>y;

	ll b=0,mn=0,mx=0,s=0;

	if(n!=1 && n!=2)
	{
		b=k/((2*n-2)*m);

		mn=b;
		mx=2*b;
		if(x==1 || x==n)
			s=mn;
		else
			s=mx;

		ll num=(k/((2*n-2)*m))*(2*n-2)*m;
		bool gr=0;
		ll i=0;

		for(i=1;num<k&&i<=n;i++)
		{
			if(i>1)
				gr=1;
			// if(num==k)
				// break;
			if(x==i)
			{
				if((num+y)<=k)
					s++;
			}
			num+=m;
		}
		if(gr)
			mx++;
		if()
			mn
		gr=0;
		for(i=n-1;i>=0 && num<k;i--)
		{
			gr=1;
			// if(num==k)
				// break;
			if(x==i)
			{
				if((num+y)<=k)
					s++;
			}
			num+=m;
		}
		if(gr)
			mx++;
		

		if(k%((2*n-2)*m)==0)
			mn++;

	}

	else
	{
		if(n==1)
		{
			mx=mn=s=k/m;

			if(k%m!=0)
				mx+=1;
			if(y<=(k%m)+1)
				s++;
		}
		else
		{
			m=2*m;
			mx=mn=s=k/m;

			if(k%m!=0)
				mx+=1;
			if(y<=(k%m)+1)
				s++;
		}
	}

	cout<<mx<<' '<<mn<<' '<<s<<endl;
	return 0;
}
