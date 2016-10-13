#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(int argc, char const *argv[])
{
	ll n,m,i,nr=0,nc=0;
	scanf("%lld %lld",&n,&m);

	map <ll , bool> row;
	map <ll ,bool> col;

	for(i=0;i<m;i++)
	{
		ll r ,c;
		scanf("%lld %lld",&r,&c);
		if(!row[r])
			nr++;
		if(!col[c])
			nc++;
		row[r]=1;
		col[c]=1;

		printf("%lld ",n*n-(nr*n + nc*n - nr*nc) );

	}


	return 0;
}