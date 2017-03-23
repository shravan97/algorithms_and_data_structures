#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;

	ll pa,pb,cur=0,sa=0,r=-100000,num=0;
	bool done=0,ans=1,r1=0,r2=0;

	for(ll i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		if(a<0)
			num++;
		if(done)
			continue;
		if(i==0)
		{
			pa=sa=a;
			pb=b;
			continue;
		}
		// else
		// {
		// 	if(pb==1)
		// 	{
		// 		if(b==2)
		// 		{
		// 			if(sa>=0)
		// 			{
		// 				done=1;
		// 				ans=0;
		// 			}
		// 			else
		// 			{
		// 				if(r!=-100000)
		// 					r=r+sa+a;
		// 				else
		// 					r=1900+sa+a;
		// 			}

		// 		}
		// 		else
		// 		{
		// 			if(r!=-100000)
		// 				r+=a;
		// 		}
		// 	}
		// 	else
		// 	{
		// 		if(b==1)
		// 		{
		// 			if(sa<=0)
		// 			{
		// 				done=1;
		// 				ans=0;
		// 			}
		// 			else
		// 			{
		// 				if(r!=-100000)
		// 					r=r+a;
		// 				else
		// 					r=1900+a;
		// 			}
		// 		}
		// 		else
		// 		{
		// 			if(r!=-100000)
		// 				r+=a;
		// 		}

		// 	}
		// }

		if(b==1)
		{
			if(r!=-100000)
			{
				if(r<1900)
				{
					done=1;
					ans=0;
				}
				else
					r+=a;
			}
			else
			{
				if(pb==2)
				{
					if(sa>0)
					{
						r=1899+sa+a;
					}
					else
					{
						done=1;
						ans=0;
					}
				}
			}

			r1=1;
		}
		else
		{
			if(r!=-100000)
			{
				if(r>1900)
				{
					// if()
					// done=1;
					// ans=0;
					if(pb==2)
					{
						r=1899+a;
					}
				}
				else
				{
					r+=a;
				}
			}
			else
			{
				if(pb==1)
				{
					if(sa>0)
					{
						done=1;
						ans=0;
					}
					else
					{
						r=1899+a;
					}
				}
			}
		}

		sa+=a;
		pa=a;
		pb=b;

	}
	if(done)
	{
		if(!ans)
			cout<<"Impossible\n";
	}
	else
	{
		if(r==-100000)
		{
			if(pb==1)
				cout<<"Infinity\n";
			else
			{
				if(sa<0 || pa<0)
					cout<<1899+sa<<endl;
				else if(sa>0)
				{
					if(num>0)
						cout<<
				}

			}
		}
		else
			cout<<r<<endl;

	}
	return 0;
}
