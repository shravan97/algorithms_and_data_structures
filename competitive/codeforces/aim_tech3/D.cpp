#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct st
{
	string s;
	ll n10;
};

st rearrange(string s1 ,string s0 , ll z , ll o , ll n01)
{
	bool done=0;
	ll no_01=z*o , no_10=0;
	while(!done)
	{
		// cout<<s1<<' '<<s0<<'\n';
		if((z-1)*o >=n01)
		{
			no_01 = (z-1)*o;
			s1+='0';
			if(s0.size()>1)
				s0=s0.substr(1,s0.size());
			else s0="";
			z=(z>0)?z-1:0;
			no_10+=o;
		}
		else 
		{
			ll k;
			string t1 = s1.substr(0,no_01-n01);
			string t2="0";
			string t3 = s1.substr(no_01-n01,s1.size());
			// cout<<t1<<" "<<t2<<' '<<t3<<'\n';
			s1 = t1+t2+t3;
			if(s0.size()!=1)
				s0=s0.substr(1,s0.size());
			else s0="";
			no_10+=no_01-n01;
			no_01 = n01;
		}

		if(no_01==n01)
			done=1;
	}

	// cout<<s0<<' '<<s1<<'\n';
	// cout<<no_10<<'\n';
	st k;
	k.s = s0+s1;
	k.n10 = no_10;
	return k;
}

int main(int argc, char const *argv[])
{
	ll a00 , a01 , a10,a11;
	cin>>a00>>a01>>a10>>a11;

	ll k1=(1+sqrt(1+8*a00)), k2=(1+sqrt(1+8*a11));

	if((double)fmod(sqrt((1+8*a00)),1.0) !=0.0)
	{
		cout<<"Impossible\n";
		return 0;
	}
	else if((k1&1)==1)
	{
		cout<<"Impossible\n";
		return 0;
	}

	if((double)fmod(sqrt((1+8*a11)),1.0) !=0.0)
	{
		cout<<"Impossible\n";
		return 0;
	}
	else if(k2&1)
	{
		cout<<"Impossible\n";
		return 0;
	}

	ll no_zeroes = (1+sqrt(1+8*a00))/2;
	ll no_ones = (1+sqrt(1+8*a11))/2;


	if(a00==0 && a01==0 && a10==0)
	{
		if(a11==0)
		{
			cout<<"0\n";
			return 0;
		}
		else 
		{
			ll temp=0;
			for(temp=0;temp<no_ones;temp++)
				cout<<"1";
			cout<<'\n';
			return 0;
		}
	}
	else if(a11==0 && a01==0 && a10==0)
	{
		if(a00==0)
		{
			cout<<"0\n";
			return 0;
		}
		else 
		{
			ll temp=0;
			for(temp=0;temp<no_zeroes;temp++)
				cout<<"0";
			cout<<'\n';
			return 0;
		}
	}

	if(a01 > no_ones*no_zeroes)
	{
		cout<<"Impossible\n";
		return 0;
	}

	string s1="",s0="";
	for (ll i = 0; i < no_ones+no_zeroes; ++i)
	{
		if(i<no_zeroes)
			s0+='0';
		else s1+='1';
	}

	st res = rearrange(s1,s0,no_zeroes,no_ones,a01);
	if(res.n10!=a10)
		cout<<"Impossible\n";
	else
		cout<<res.s<<'\n';

	return 0;
}