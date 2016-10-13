#include <iostream>
#include <cstring>
#include <string>
#define max(a,b)((a>b)?a:b)
using namespace std;
int lpsb[6100][6100];
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.length();

		int i,j;
		for(i=0;i<n;i++)
		{
			memset(lpsb[i],0,n);
			lpsb[i][i]=1;
			if(i>=1)
			{
				if(s[i]==s[i-1])
					lpsb[i-1][i]=2;
				else lpsb[i-1][i]=1;
			}
		}
		lpsb[0][0]=1;

		for(i=n-3;i>=0;i--)
		{
			for(j=i+2;j<n;j++)
			{
				if(s[i]==s[j])
					lpsb[i][j]=2+lpsb[i+1][j-1];
				else lpsb[i][j] = max(lpsb[i+1][j] , lpsb[i][j-1]);
				// cout<<lpsb[i][j]<<' ';
			}
			// cout<<'\n';
		}
		cout<<n-lpsb[0][n-1]<<'\n';
	}
	return 0;
}