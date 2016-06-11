#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int l;
l magic_num(l rank)
{
	int pow5 = (log(rank))/(log(5));
	l val = 2*(pow(10,pow5));
	l r = (pow(5,pow5))+1;	

	if(rank!=1 && (rank-r)== -1)
		return (magic_num(rank-1) + 2);
	else if(rank==1)
		return 0;
	else if((rank-r)<5)
	{
		l i;
		for(i=0;i<(rank-r);i++)
			val+=2;
		return val;
	}
	else
		return val+magic_num(rank-r+1);

}

int main()
{
	l t;
	scanf("%lld",&t);
	for(;t>0;t--)
	{
		l k , count=0,num=2;
		scanf("%lld",&k);
		l val = magic_num(k);
		printf("%lld\n",val );
	}
	return 0;
}