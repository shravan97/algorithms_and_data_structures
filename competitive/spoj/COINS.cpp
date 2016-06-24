#include <cstdio>
#include <cstring>
#include <map>
#define max(a,b)((a>b)?a:b)
using namespace std;

// Recursive formula : f(n) = f(n/2) + f(n/3) + f(n/4);
std::map<long long , long long> coins;
long long func(long long  n)
{
	if(n==0)
		return n;

	if(coins[n]==0)
		coins[n]=max(n,func(n/2)+func(n/3)+func(n/4));
	return coins[n];
}

int main()
{
	long long  n,count=0;

    while(scanf("%lld",&n)==1)
    {    	
   		printf("%lld\n",func(n) );

   		if(count>=9)
   			break;

    	count++;
    }
    
    return 0;
}