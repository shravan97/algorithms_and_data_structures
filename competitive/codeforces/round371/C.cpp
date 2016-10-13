#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// bool chck(string s , string p)
// {
// 	if(s.size() < p.size())
// 	{
// 		s.insert(s.begin(),p.size()-s.size(),'0');
// 	}
// 	else p.insert(p.begin(),s.size()-p.size(),'0');

// 	for(int i=s.size()-1;i>=0;i--)
// 	{
// 		if(p[i]=='1')
// 		{
// 			if(((int)(s[i])-48)%2==0)
// 				return 0;
// 		}
// 		else
// 		{
// 			if(((int)(s[i])-48)%2)
// 				return 0;
// 		}
// 	}
// 	return 1;
// }strring
string cvt(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(((int)(s[i])-48)&1)s[i]='1';
		else s[i]='0';
	}
	return s;
}

int main(int argc, char const *argv[])
{
	long long int t;
	cin>>t;
	map<string,ll> m;
	while(t--)
	{
		char k;
		string s;
		cin>>k>>s;
		if(k=='+')
		{
			m[cvt(s)]++;
			continue;
		}
		else if(k=='-')
		{ 
			m[cvt(s)]--;
			continue;
		}
		else
		{
			map<string,ll>::iterator it;
			ll c=0;
			for(it=m.begin();it!=m.end();it++)
			{
				string k1=it->first , k2=s;
				if(k1.size()<k2.size())
					k1.insert(k1.begin(),k2.size()-k1.size(),'0');
				else k2.insert(k2.begin(),k1.size()-k2.size(),'0');

				if(k1==k2)c+=it->second;
			}
			cout<<c<<endl;
		}

	}
	return 0;
}