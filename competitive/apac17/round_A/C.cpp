#include <bits/stdc++.h>
#define lval 1e-10
using namespace std;
double eqn(long long int c[] , int n , double r)
{
	double val = 0.0;
	cout<<" n "<<n<<'\n';
	for(int i=n;i>0;i--)
	{
		if(i==n)
			val=-((double)c[n-i])*pow(1.0+r,(double)(i-1));
		else
			val+=((double)c[n-i])*pow(1.0+r,(double)(i-1));
		cout<<" pow "<<val<<'\n';
		// cout<<" split "<<c[n-i]<<' '<<i-1<<' '<<1.0+r<<endl;
	}
	return val;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,i,nearest=0;
		double vals[19] = {-0.9 ,-0.8 , -0.7 , -0.6 , -.5 , -.4,-.3,-.2,-.1,0.0,.1,.2,.3,.4,.5,.6,.7,.8,.9 };
		double closest;
		cin>>m;
		long long int c[m+1];
		for(i=0;i<m+1;i++)
			cin>>c[i];
		cout<<m<<'\n';
		double r=0.5;
		cout<<eqn(c,m+1,r)<<'\n';
		for(i=0;i<19;i++)
		{
			if(i==0)
				closest = eqn(c,m+1,vals[i]);
			else
			{
				double temp = eqn(c,m+1,vals[i]);
				cout<<" temp "<<temp<<endl;
				if(abs(temp)<abs(closest))
				{
					closest=temp;
					nearest=i;
				}
			}
		}
		cout<<closest<<' '<<nearest<<endl;
		// while(eqn(c,m+1,r)>lval || eqn(c,m+1,r) < -lval)
		// {
		// 	double calc1 = eqn(c,m+1,r-r/2.0);
		// 	double calc2 = eqn(c,m+1,r+r/2.0);
		// 	cout<<"here "<<r<<' '<<calc1<<' '<<calc2<<'\n';
		// 	if(abs(calc1)<abs(calc2))
		// 		r-=r/2.0;
		// 	else r+=r/2.0;
		// }
		// cout<<r<<'\n';

	}
	return 0;
}