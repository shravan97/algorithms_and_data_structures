#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll c=0;

void calc(ll num,int pos, std::vector<ll> &nums)
{
	if(pos<0)
	{
		nums.push_back(num);
		return;
	}

	std::vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	for(int i=0;i<4;i++)
	{
		// cout<<num<<endl;
		int dig=(num/(ll)(pow(10,pos)))%10;
		calc(num+(v[i]-dig)*pow(10,pos),pos-1,nums);

	}
	
}

int numdig(ll n)
{
	int d=0;
	while(n>0)
		n/=10,d++;
	return d;
}

bool chck_dig(ll n)
{
	while(n)
	{
		if(n%10 !=2 && n%10 !=3 && n%10 !=5 && n%10 !=7)
			return 0;
		else
			n/=10;
	}

	return 1;

}

int main(int argc, char const *argv[])
{
	ll l,u,count=0;
	cin>>l>>u;


	int ld = numdig(l), ud=numdig(u);
	std::vector<ll> lv;

	// cout<<"hi\n";

	ll ls=0,us=0;

	// calc(2222222222,9,lv);
	// for(auto e:lv)
		// cout<<e<<endl;

	for(int i=0;i<10;i++)
	{
		if(i<ld)
			ls = ls*10+2;
		us = us*10+2;
	}

	// cout<<ls<<' '<<us<<endl;
	// cout<<l<<endl;

	for(int i=ld;i<=9;i++)
	{
		// cout<<i<<endl;
		calc(ls,i-1,lv);
		ls=ls*10+2;
	}

	for(auto e:lv)
	{
		// cout<<e<<endl;
		if(e>=l && e<=u)
		{
			if(!(e%2==0 || e%3==0||e%5==0||e%7==0))
			{
				count++;
				cout<<" here for "<<e<<endl;
			}
			else if(e==2 || e==3 || e==5 || e==7)
				count++;
		}
	}


	std::vector<ll> uv;

	if(ud>9)
	{
		calc(us,9,uv);


		ll t8=pow(10,9), b=u/t8;
		// cout<<b<<endl;
		if(!chck_dig(b))
			b-=1;
		if(b>0 && !chck_dig(b))
		{
			cout<<0<<endl;
			return 0;
		}

		// cout<<b<<endl;
	

		for(auto e:uv)
		{
			e = b*t8 + e ;
			// cout<<e<<endl;
			if(e>=l && e<=u)
			{
				if(!(e%2==0 || e%3==0||e%5==0||e%7==0))
					count++;
			}
		}
	}


	cout<<count<<endl;


	return 0;
}