#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	long long int i;
	bool picked=0;
	long long c=0,a=0;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='a')a++;

		if(!picked)
			if(s[i]!='a')
			{
				s[i]-=1;
				c++;
			}
			else if(c!=0)
				picked=1;

	}
	if(s.size()==a)
		s[s.size()-1]='z';

	cout<<s<<'\n';
	return 0;
}