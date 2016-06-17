#include <cstdio>
#include <cmath>
using namespace std;

int last_dig(int a , long long int b)
{
	a = a%10;
	if(a==1 || a==0)
		return a;
	else if(b==0)
		return 1;
	else
	{
		int rem = b%4;
		rem = (rem==0)?4:rem;
		int k = pow(a,rem);
		return k%10;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		int a;
		long long int b;
		scanf("%d %lld",&a,&b);
		printf("%d\n",last_dig(a,b) );

	}
	return 0;
}	