#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n,a,b,c;
	bool mcd=0;
	cin>>n>>a>>b>>c;
	if((n%4)==0)
	{
		cout<<0<<endl;
		return 0;
	}
	int m = (n/4 + 1)*4;
	m=m-n;
	int ma = m*a;
	int mb=INT_MAX,mc=INT_MAX;
	// if(m==3)
	// {
	// 	mb=a+b;
	// 	mc=c;
	// 	mcd=1;
	// }
	// else if(m==2)
	// 	mb=b;

	// if(!mcd)

	// cout<<" m "<<m<<endl;

	if(m&1)
	{
		ma=m*a;
		if(m==3)
		{
			mb=a+b;
			mc=c;
		}
		if(m==1)
		{
			mb=b+c;
			mc=3*c;
		}
	}
	else
	{
		ma=m*a;
		if(m==2)
		{
			mb=b;
			mc=min(2*c,min(a+3*c,3*a+c));
		}
	}


	if(mc<0)
		mc=INT_MAX;
	if(mb<0)
		mb=INT_MAX;
	if(ma<0)
		ma=INT_MAX;
	


	cout<<min(ma,min(mb,mc))<<endl;
	return 0;
}
