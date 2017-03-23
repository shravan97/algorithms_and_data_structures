#include <iostream>
using namespace std;
typedef long long int ll;
ll store[2001];
ll fact(ll a)
{
    // store[0]=store[1]=1;
	if(a<=1)
		return 1;
	else 
	{
	    if(!store[a])
	    {
	        //cout<<store[a-1]<<endl;
	        store[a]=a*fact(a-1);
	    }
		return store[a];
	}
}
ll nCr(ll n,ll r)
{
	if(r>n/2)
		r=n-r;
	return fact(n)/(fact(r)*fact(n-r));
}

ll calc(ll a,ll b,ll n,ll m)
{
	if(b==m)
		return 1;
	if(a==n)
		return 1;
	// if(b>=a && !(a==0 && b==0))
	// 	return -1;

	// cout<<" here "<<a<<" "<<b<<endl;

	if(b>=a-1)
		return calc(a+1,b,n,m);

	return calc(a+1,b,n,m)+calc(a,b+1,n,m);

}

int main(int argc, char const *argv[])
{
	int t,t1;
	cin>>t;
	t1=t;

	while(t--)
	{
		int n,m;
		cin>>n>>m;

		ll s=0;
		// for(int i=1;i<=m;i++)
		// {
		// 	ll k =(fact(n+m-i)*nCr(m,i));
		// 	cout<<k<<endl;
		// 	s+=k;
		// }
		// cout<<"loop2\n";

		// for(int i=1;i<=m;i++)
		// {
		// 	ll k=0;
		// 	// if(i>1)
		// 		k=((fact(2*i))*fact(n+m-2*i)*nCr(m,i)*nCr(n,i));
		// 	// else
		// 		// k=2*fact(n+m-2)*m*n;
		// 	cout<<k<<endl;
		// 	s+=k;
		// }	
		// s = (fact(2*m)*fact(n-m))*nCr(n,m);
		// 	cout<<" s "<<calc(0,0,n,m)<<endl;

		s = calc(0,0,n,m)*fact(n)*fact(m);

		cout<<"Case #"<<t1-t<<": "<<(float)((float)(s)/(float)(fact(n+m)))<<endl;

	}
	return 0;
}