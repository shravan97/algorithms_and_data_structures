#include <iostream>
#include <cstring>
#define max(a,b) ((a>b)?a:b)
using namespace std;
typedef long long int ll;

//!!Input format needs improvement !!

int main()
{
	ll n , m;
	cout<<"Please enter the length of the strings in order : ";
	cin>>n>>m;
	string s1 , s2;

	getline(std::cin,s1);
	getline(std::cin,s2);

	ll l[n+1][m+1];

	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=m;j++)
		{
			if(i==0||j==0)
				l[i][j]=0;
			else if(s1[i-1]==s2[j-1])
			{
				l[i][j]=l[i-1][j-1]+1;
				// cout<<s1[i-1]<<' '<<s2[j-1]<<'\n';
			}
			else
				l[i][j]=max(l[i-1][j] , l[i][j-1]);

			// cout<<l[i][j]<<' ';
		}
		// cout<<'\n';
	}
	// cout<<s1[0]<<s2[0];
	cout<<'\n'<<"The length of the longest common subsequence is : "<<l[n][m];
	return 0;
}