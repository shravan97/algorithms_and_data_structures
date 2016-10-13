#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int sz = s.size();
		bool flag=1;
		for(int i=0;i<sz;i++)
		{
			if(s[i]!='.' && s[sz-1-i]!='.'&& s[i]!=s[sz-1-i])
			{
				flag=0;
				break;
			}
			else if(s[sz-1-i]!='.')
			{
				s[i]=s[sz-1-i];
			}
			else if(s[i]!='.')
				s[sz-1-i]=s[i];
			else
			{ 
				s[i]='a';
				s[sz-1-i]='a';
			}
		}

		if(flag)
			cout<<s<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}