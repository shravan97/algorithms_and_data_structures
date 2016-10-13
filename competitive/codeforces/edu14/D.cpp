#include <cstdio>
#include <vector>
typedef long long int ll;
using namespace std;
int main(int argc, char const *argv[])
{
	ll n,m,i;
	scanf("%lld %lld",&n,&m);
	vector<ll> curr_lex(n) , prev(n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&curr_lex[i]);
		prev[i]=curr_lex[i];
	}

	for(i=0;i<m;i++)
	{
		ll a,b,temp;
		scanf("%lld %lld",&a,&b);
		temp = prev[a];
		prev[a]=prev[b];
		prev[b]=temp;

		bool flag=0;
		for(ll j=0;j<n;j++)
			if(curr_lex[j] > prev[j])
			{
				flag=1;
				break;
			}
			else if(curr_lex[j] < prev[j])
			{
				break;
			}
			
		if(flag==0)
			curr_lex
	}

	return 0;
}