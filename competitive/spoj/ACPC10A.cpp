#include <cstdio>
int main(int argc, char const *argv[])
{
	while(1)
	{
		long long int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==0 && b==0 && c==0)break;

		if((a-b)==(b-c))
			printf("AP %lld\n",2*c-b );
		else if(b*b == a*c)
			printf("GP %lld\n",(c*c)/b );
	}
	return 0;
}