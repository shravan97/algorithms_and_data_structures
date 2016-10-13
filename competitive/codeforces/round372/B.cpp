#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	std::map<char, ll> f;
	string s;
	cin>>s;
	ll sz=s.size(),q=0;
	if(sz<26)
	{
		cout<<-1<<endl;
		return 0;
	}
	std::vector<ll> pos,gpos;
	ll chck=0,at=0,atv=0;
	bool possible=0,done=0;
	std::vector<ll> uniq;
	ll i;
	// for(ll i=0;i<sz;i++)
	// {
	// 	if(s[i]!='?')
	// 	{
	// 		if(i!=0)
	// 		{
	// 			if(s[i]!=s[i-1])
	// 			{
	// 				if(!f[s[i]])
	// 					chck++;
	// 					f[s[i]]++;
	// 			}
	// 			else
	// 			{
	// 				if(!possible)
	// 					f.erase(f.begin(),f.end());
	// 				chck=0;
	// 			}
	// 		}
	// 		else
	// 		{
	// 		 	f[s[i]]++;
	// 			chck++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		chck++;
	// 		q++;
	// 		pos.push_back(i);
	// 	}
	// 	// cout<<chck<<" at "<<s[i]<<' ';

	// 	if(chck==26 && !possible)
	// 	{
	// 		possible=1;
	// 		chck=0;
	// 		at=i;
	// 		atv=pos.size()-1;
	// 		cout<<" possible ! "<<f.size()<<" "<<i<<endl;
	// 	}
	// }

	// if(!possible)
	// {
		// cout<<-1<<endl;
		// return 0;
	// }

	// if(26-f.size()>q)
	// {
	// 	cout<<-1<<endl;
	// 	return 0;
	// }



	ll p=atv;
	char k;

	// for(k='A';(int)k<91;k++)
	// {
	// 	// cout<<k<<" and "<<p<<endl;
	// 	if(f[k]==0)
	// 	{
	// 		s[pos[p]]=k;
	// 		p--;
	// 	}
	// }
	// 	for(p=atv+1;p!=pos.size();p++)
	// 	{
	// 		s[pos[p]]='A';
	// 	}
	ll num=0;

	for(i=0;i<26;i++)
	{
		if(s[i]=='?')
		{
			pos.push_back(i);
			gpos.push_back(i);
			q++;
			num++;
		}
		else if(!f[s[i]])
			num++;
		f[s[i]]++;
	}

	if(num==26)
	{
		ll pk=0;
		for(k='A';(int)k!=91;k++)
		{
			if(f[k]==0)
			{
				s[pos[pk]]=k;
				pk++;
			}
		}

		for(ll x=26;x<s.size();x++)
			if(s[x]=='?')
				s[x]='A';
			cout<<s<<endl;
			return 0;
	}
	ll z=26;
	// cout<<num<<' '<<s[z]<<endl;

	for(i=1;i<s.size() && z<s.size();i++,z++)
	{
		// if(!pos.empty())
		// pos.erase(pos.begin());
		if(s[i-1]=='?')
		{
			num--;
			pos.erase(pos.begin());
		}
		else
			f[s[i-1]]--;

		if(s[i-1]!='?'&&f[s[i-1]]==0)
		{
			// cout<<" at "<<s[z]<<' '<<num<<' '<<s[i-1]<<" reduced "<<f[s[i-1]]<<endl;
			num--;
		}
		if(s[z]!='?'&&f[s[z]]==0)
		{
			// cout<<" for "<<s[i]<<'-'<<s[z]<<num<<endl;
			f[s[z]]++;
			num++;
		}
		else if(s[z]=='?')
		{
			num++;
			pos.push_back(z);
			gpos.push_back(z);
		}
		else if(s[z]!='?')
			f[s[z]]++;
		// cout<<num<<' '<<s[i]<<' '<<z<<' ';
		if(num==26)
		{
			// cout<<" here at pos "<<i<<endl;
		ll pk=0;
		for(k='A';(int)k!=91;k++)
		{
			if(f[k]==0)
			{
				// cout<<" here "<<pos[pk]<<' ';
				s[pos[pk]]=k;
				pk++;
			}
		}

		for(ll x=26;x<s.size();x++)
			if(s[x]=='?')
				s[x]='A';
		std::vector<ll>::iterator gt;
		for(gt=gpos.begin();gt!=gpos.end();gt++)
			if(s[*gt]=='?')
				s[*gt]='A';
			cout<<s<<endl;
			return 0;
		}
	}


	cout<<-1<<endl;

	return 0;
}