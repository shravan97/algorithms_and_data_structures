#include <bits/stdc++.h>
using namespace std;
#define min(a,b)((a<b)?a:b)
#define max(a,b)((a>b)?a:b)

typedef long long int ll;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s,s1="",s2="";
	cin>>s;

	// s1=s;
	char prev,curr='r';
	ll ch=0;
	std::map<char, ll> c,c1;
	for(int i=0;i<s.size();i++)
	{
		s1+=curr;
		s2+=(curr=='r')?'b':'r';
		curr=(curr=='r')?'b':'r';
	}
	// cout<<s1<<endl;
	// cout<<s2<<endl;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			c[s1[i]]++;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s2[i])
		{
			c1[s2[i]]++;
		}
	}
	// prev = s[0];
	// if(s[0]==)
	// for(int i=0;i<s.size();i++)
	// {
	// 	if(i!=n-1)
	// 	{
	// 		if(s1[i]==s1[i+1])
	// 		{
	// 			char req = (s1[i]=='r')?'b':'r';
	// 			cout<<" change at "<<i<<endl;
	// 			c1[req]++;
	// 			s1[i]=req;
	// 		}

	// 	}
	// }

	// cout<<c['r']<<' '<<c['b']<<' '<<c1['r']<<' '<<c1['b']<<endl;

	cout<<min(max(c['r'],c['b']),max(c1['r'],c1['b']))<<endl;
	return 0;
}