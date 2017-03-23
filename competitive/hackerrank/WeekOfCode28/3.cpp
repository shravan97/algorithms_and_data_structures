#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007
typedef long long int ll;

vector< vector<string> > v(10);

// void generate(char prev, ll num,int n, string s)
// {
// 	if(n==3)
// 	{
// 		if(num%8==0)
// 		{
// 			v[prev-48].push_back(s);
// 		}
// 	}
// 	if(n==2 || n==1)
// 		if(num%8==0)
// 			v[prev-48].push_back(s);

// 	for(char i='0';i<'9';i++)
// 	{
// 		generate(i,(i-48)*pow(10,n),n+1,i+s);
// 	}

// }

int main(int argc, char const *argv[])
{
	ll n;

	cin>>n;

	string s;
	cin>>s;

	std::map<int, ll> map;
	ll eve[n],odd[n];
	memset(eve,0,sizeof(eve));
	memset(odd,0,sizeof(odd));

	ll num=0;

	for(ll i=s.size()-1;i>=0;i--)
	{

		if((s[i]-48)%8==0)
			num=(num+1)%mod;

		if((s[i]-48)&1)
		{
			if(((10*(s[i]-48)+2)/4)&1)
			{
				odd[i] += map[2];
				// if(map[2] && (10*(s[i]-48)+2)%8==0)
				// 	num=(num+map[2])%mod;
				// cout<<" num1 : "<<num<<endl;
			}
			else
			{
				eve[i]+=map[2];
				if(map[2] && (10*(s[i]-48)+2)%8==0)
					num=(num+map[2])%mod;
				// cout<<" num2 : "<<num<<endl;
			}
			if(((10*(s[i]-48)+6)/4)&1)
			{
				odd[i] += map[6];
				// if(map[6] && (10*(s[i]-48)+6)%8==0)
				// 	num=(num+map[6])%mod;
				// cout<<" num3 : "<<num<<endl;
			}
			else
			{
				eve[i]+=map[6];
				if(map[6] && (10*(s[i]-48)+6)%8==0)
					num=(num+map[6])%mod;
				// cout<<" num4 : "<<num<<endl;
			}
			
		}
		else
		{
			if(((10*(s[i]-48)+4)/4)&1)
			{
				odd[i] += map[4];
				// if(map[4] && (10*(s[i]-48)+4)%8==0)
				// 	num=(num+map[4])%mod;
				// cout<<" num5 : "<<num<<endl;
			}
			else
			{
				eve[i]+=map[4];
				if(map[4] && (10*(s[i]-48)+4)%8==0)
					num=(num+map[4])%mod;
				// cout<<" num6 : "<<num<<endl;
			}
			if(((10*(s[i]-48)+8)/4)&1)
			{
				odd[i] += map[8];
				// cout<<" here at "<<i<<' '<<odd[i]<<endl;
				// if(map[8] && (10*(s[i]-48)+8)%8==0)
				// 	num=(num+map[8])%mod;
				// cout<<" num7 : "<<num<<endl;
			}
			else
			{
				eve[i]+=map[8];
				// cout<<" here1 "<<map[8]<<endl;
				if(map[8] && (10*(s[i]-48)+8)%8==0)
					num=(num+map[8])%mod;
				// cout<<" num8 : "<<num<<endl;
			}
			if(((10*(s[i]-48))/4)&1)
			{
				odd[i] += map[0];
				// if(map[0]  && (10*(s[i]-48))%8==0)
				// 	num=(num+map[0])%mod;
			}
			else
			{
				eve[i]+=map[0];
				if(map[0] && (10*(s[i]-48))%8==0)
					num=(num+map[0])%mod;
			}
			
		}

		map[s[i]-48]++;

	}

	// cout<<num<<endl;

	for(ll i=s.size()-2;i>=0;i--)
	{

		// cout<<" odd at "<<i<<" : "<<odd[i]<<endl;
		// cout<<" even at "<<" : "<<eve[i]<<endl;
		
		if((s[i]-48)&1)
		{
			if(odd[i+1])
				num=(num+(2<<(i-1))+odd[i+1])%mod;
		}
		else
			if(eve[i+1])
				num=(num+(2<<(i-1))+eve[i+1])%mod;
	}

	cout<<num<<endl;
	return 0;
}
