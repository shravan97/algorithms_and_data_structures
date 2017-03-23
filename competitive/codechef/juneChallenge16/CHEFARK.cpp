#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
typedef long long int l;
// l comb(l n , l r)
// {
// 	l de=1,comb=1;
// 	if(n-r<r)
// 		r=n-r;
// 	while(de<=r)
// 	{
// 		comb*=((n--)/(de++))%1000000007;
// 	}
// 	return comb%1000000007;
// }
std::vector<l> fact;
l powmod(l a , l b , l m)
{
	if(b==1)
		return a%m;
	else if(b==0) return 1;
	else
	{
		l t = powmod(a,b/2,m);
		if(b&1)
		{
			return (((t*t)%m)*a)%m;
		}
		else return ((t)*(t))%m;
	}
}

l modInv(l a,l mod)
{
	// Assume 'a' and 'mod' are coprime and mod is prime

	return powmod(a,mod-2,mod);
}

l nCr(l n, l r, l mod)
{
	/*
	nCr = n!/r!*(n-r)!
	*/

	// cout<<fact[n]<<' '<<modInv(fact[r],mod)<<' '<<modInv(fact[n-r],mod)<<endl;
	// cout<<fact[n]<<' '<<modInv(fact[r]*fact[n-r],mod)<<endl;

	return (fact[n]*((modInv((fact[r]*fact[n-r])%mod,mod))%mod))%mod;
}

void facts(l n,l mod)
{
	fact.push_back(1);
	// inv.push_back(0);
	// inv.push_back(1);
	for(l i=1;i<=n;i++)
	{
		fact.push_back((i*(fact[i-1]%mod))%mod);
		// if(i!=1)
		// 	inv.push_back((mod - (mod/i)*inv[mod%i]%mod)%mod);
		// cout<<fact[i]<<' ';
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	facts(100000,1000000007);

	for(;t>0;t--)
	{
		l n ,k,i;
		scanf("%lld %lld",&n,&k);
		l no_zeroes=0;

		for(i=0;i<n;i++)
		{
			l temp;
			scanf("%lld",&temp);
			if(temp==0)
				no_zeroes++;
		}

		n-=no_zeroes;
		if(n==0)
			printf("1\n");
		else if(n==1)
		{
			if(no_zeroes>0)
				if(k>1)
					printf("2\n");
				else printf("1\n");
			else printf("1\n");	
		}
		else if(no_zeroes>0 && k>=n)
		{
			printf("%lld\n",(long long int)pow(2,n));
		}
		else
		{
			l sum;

			if(k%2)
			{
				sum=0;
				l limit=k;
				if(k>n)
				{
					if(n%2)
						limit=n;
					else 
						limit=n-1;
				}

				for(i=1;i<=limit;i+=2)
					sum+=((nCr(n,i,Mod)));
			}
			else
			{
				l limit=k;
				if(k>n)
				{
					if(n%2)
						limit=n-1;
					else 
						limit=n;
				}

				sum=1;
				for(i=2;i<=limit;i+=2)
					sum+=(nCr(n,i,Mod));
			}
			printf("%lld\n",sum );
		}
	}
	return 0;
}