#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
	long long int num;
	scanf("%lld",&num);
	long long int lg = log(num)/log(2);
	printf("%lld\n",(long long int)pow(2,lg+1) );
	return 0;
}