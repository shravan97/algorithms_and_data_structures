#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long int ll;

/* 

Question from : http://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/

*/


int BitDiff(std::vector<int> &v)
{

	std::map<int, int> bits;
	for(auto n:v)
	{
		int count=1;

		while(count<=32)
		{
			if((n&(1<<(count-1)))!=0)
				bits[count]++;
			count++;
		}

	}

	int diff=0;

	for(int i=1;i<=32;i++)
	{
		// cout<<" i "<<i<<"  "<<bits[i]<<endl;
		diff+=((2*bits[i])%mod*((v.size()-bits[i])%mod))%mod;
	}

	return diff;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<int> v;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		v.push_back(k);
	}

	cout<<BitDiff(v)<<endl;

	return 0;
}
/*

001
011
101

*/
