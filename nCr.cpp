#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

std::vector<ll> fact,inv;

// #define MOD 1000000007
// /* This function calculates (a^b)%MOD */
// long long pow(int a, int b)
// {
//     long long x=1,y=a; 
//     while(b > 0)
//     {
//         if(b%2 == 1)
//         {
//             x=(x*y);
//             if(x>MOD) x%=MOD;
//         }
//         y = (y*y);
//         if(y>MOD) y%=MOD; 
//         b /= 2;
//     }
//     return x;
// }
 
// /*  Modular Multiplicative Inverse
//     Using Euler's Theorem
//     a^(phi(m)) = 1 (mod m)
//     a^(-1) = a^(m-2) (mod m) */
// long long InverseEuler(int n)
// {
// 	cout<<pow(n,MOD-2)<<endl;
//     return pow(n,MOD-2);
// }
 
// long long factMOD(int n)
// {
//     long long res = 1; 
//     while (n > 0)
//     {
//         for (int i=2, m=n%MOD; i<=m; i++)
//             res = (res * i) % MOD;
//         if ((n/=MOD)%2 > 0) 
//             res = MOD - res;
//     }
//     return res;
// }
// long long C(int n, int r)
// {
// 	cout<<factMOD(n)<<' '<<InverseEuler(factMOD(r))<<' '<<InverseEuler(factMOD(n-r))<<endl;
//     return (factMOD(n) *
//             ((InverseEuler(factMOD(r)) * 
//             InverseEuler(factMOD(n-r))) % MOD)) % MOD;
// }
ll powmod(ll a , ll b , ll m)
{
	if(b==1)
		return a%m;
	else if(b==0) return 1;
	else
	{
		ll t = powmod(a,b/2,m);
		if(b&1)
		{
			return (((t*t)%m)*a)%m;
		}
		else return ((t)*(t))%m;
	}
}

ll modInv(ll a,ll mod)
{
	// Assume 'a' and 'mod' are coprime and mod is prime

	return powmod(a,mod-2,mod);
}

ll nCr(ll n, ll r, ll mod)
{
	/*
	nCr = n!/r!*(n-r)!
	*/

	// cout<<fact[n]<<' '<<modInv(fact[r],mod)<<' '<<modInv(fact[n-r],mod)<<endl;
	// cout<<fact[n]<<' '<<modInv(fact[r]*fact[n-r],mod)<<endl;

	return (fact[n]*((modInv((fact[r]*fact[n-r])%mod,mod))%mod))%mod;
}

void facts(ll n,ll mod)
{
	fact.push_back(1);
	inv.push_back(0);
	inv.push_back(1);
	for(ll i=1;i<=n;i++)
	{
		fact.push_back((i*(fact[i-1]%mod))%mod);
		if(i!=1)
			inv.push_back((mod - (mod/i)*inv[mod%i]%mod)%mod);
		// cout<<fact[i]<<' ';
	}
}

int main(int argc, char const *argv[])
{
	facts(10,1000000007);
	cout<<nCr(20,10,1000000007)<<endl;
	// cout<<C(10,2)<<endl;
	return 0;
}
