#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		if(s.size()==3 )
		{
			int m1=0,m2=0;
			if(s[0]=='o')
			{
				m1++;
			}
			if(s[0]=='t')m2++;
			if(s[1]=='n')m1++;
			if(s[1]=='w')m2++;
			if(s[2]=='e')m1++;
			if(s[1]=='o')m2++;
			if(m1>m2)cout<<1<<endl;
			else cout<<2<<endl;
		}
		else cout<<3<<endl;
	}
	return 0;
}