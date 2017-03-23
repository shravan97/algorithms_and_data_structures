#include <iostream>
#include <string>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		string l1,l2,l3;
		ll n,r3=0,r2=0,r21=0,r1=0;
		cin>>l1>>l2>>l3>>n;
		bool n0=0,n2=0;

		for(ll i=l3.size()-1;i>=0;i--)
			if(l3[i]=='0')
				n0=1;
			else if(n0==1)
				r3++;

		for(ll i=l2.size()-1;i>=0;i--)
			if(l2[i]=='0')
			{
				if(n0==0)
					n2=1;
				n0=1;
			}
			else if(n0==1)
				r2++;

		for(ll i=l2.size()-1;i>=0;i--)
			if(l2[i]=='1')
				r21++;


		for(ll i=l1.size()-1;i>=0;i--)
			if(l1[i]=='0')
				n0=1;
			else if(n0==1)
				r1++;
		
		// cout<<r1<<' '<<r2<<' '<<r3<<endl;

		if(n2==1)
			cout<<r1+(n-1)*r21+r2+r3+1<<endl;
		else
			cout<<r1+n*r2+r3+1<<endl;


	}
	return 0;
}