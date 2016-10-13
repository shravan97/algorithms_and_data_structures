#include <cstdio>
struct vals
{
	long long int sum , nd;
};

vals get_digits(long long int num)
{
	vals v;
	v.sum=v.nd=0;
	long long int x=num;
	while(x>0)
	{
		int r = x%10;
		v.sum+=r;
		v.nd++;
		x/=10;
	}
	return v;
}

int main(int argc, char const *argv[])
{
	long long int n , count=0;
	scanf("%lld",&n);
	long long int num =n;
	vals v1;
	v1 = get_digits(n);
	int ndigits = v1.nd;
	int ndig = v1.nd;

	while(num>=n-90 && num>=0)
	{
		v1 = get_digits(num);
		vals v2 = get_digits(v1.sum);
		ndig = v1.nd;
		if(ndig<=ndigits-2)break;
		if(num+v1.sum+v2.sum == n)count++;
		num--;
	}

	printf("%lld\n",count );

	return 0;
}