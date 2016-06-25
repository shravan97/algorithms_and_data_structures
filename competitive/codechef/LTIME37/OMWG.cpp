#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long int n,m,i,j;
		scanf("%ld %ld",&n,&m);
		printf("%ld\n",n-1 + (m-1)*(2*n - 1) );
	}
	return 0;
}