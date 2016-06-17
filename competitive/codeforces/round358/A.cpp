#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int n , m , s=0;
	scanf("%lld %lld",&n,&m);
	long long int l = (m>n)?m:n;
	long long int sm = m+n-l;
	s+=(l/10)*2*sm;
	for(long long int i=1;i<=l%10;i++)
	{
		s+=(sm/10)*2;

		if(i<5)
		{
			if((sm%10)>=(5-i))
				s++;
			if((sm%10)>=(10-i))
				s++;
		}
		else
		{
			if((sm%10)>=(10-i))
				s++;
			if((sm%10)>=(15-i))
				s++;
		}
	}
	printf("%lld\n",s );

	return 0;
}