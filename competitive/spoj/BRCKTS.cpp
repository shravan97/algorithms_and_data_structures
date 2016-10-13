#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
bool check(string s)
{
	long long int i,no_open=0,no_close=0;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='(')no_open++;
		else no_close++;
		if(no_open < no_close)return false;
	}

	return (no_open==no_close);
}

int main(int argc, char const *argv[])
{
	int t=10;
	while(t--)
	{
		long long int n,m;
		scanf("%lld",&n);
		string s,scopy;
		cin>>s;
		scanf("%lld",&m);
		scopy = s;
		printf("Test %d:\n",10-t );
		bool len=0;

		if((s.length())%2 != 0)
			len=1;

		while(m--)
		{
			long long int k;
			scanf("%lld",&k);
			if(k!=0)
				scopy[k-1]=(scopy[k-1]==')')?'(':')';
			else if(len==1)
				printf("NO\n");
			else
			{
				printf("%s\n",(check(scopy))?"YES":"NO" );
				scopy = s;
			}
		}
	}
	return 0;
}