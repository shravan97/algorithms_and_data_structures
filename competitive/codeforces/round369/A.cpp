#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s[n];
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		for(int j=0;j<s[i].size();j++)
		{
			if(i!=s[i].size()-1)
			{
				if(!flag && s[i][j]=='O' && s[i][j+1]=='O')
				{
					s[i][j]='+';
					s[i][j+1]='+';
					flag=1;
				}
			}
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
			cout<<s[i]<<endl;

	}
	else cout<<"NO\n";
	return 0;
}