#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long int ll;
using namespace std;
ll min(ll x , ll y , ll z)
{
	ll min1 = (x>y)?y:x;
	return (min1>z)?z:min1;
}

int main()
{
	char s1[1000] , s2[1000];

	fflush(stdin);
	printf("Enter the strings : \n");
	scanf("%s %s",s1,s2);

	ll ed[strlen(s1)+1][strlen(s2)+1];

	for(ll i=0;i<=strlen(s1);i++)
	{
		for(ll j=0;j<=strlen(s2);j++)
		{
			if(i==0)
				ed[0][j]=j;
			else if(j==0)
				ed[i][0]=i;
			else if(s1[i-1]==s2[j-1])
				ed[i][j]=ed[i-1][j-1];
			else if(s1[i-1]!=s2[j-1])
				ed[i][j]=1+min(ed[i-1][j],ed[i][j-1],ed[i-1][j-1]);
		}
	}

	printf("The edit distance is : %lld \n",ed[strlen(s1)][strlen(s2)] );

	return 0;
}