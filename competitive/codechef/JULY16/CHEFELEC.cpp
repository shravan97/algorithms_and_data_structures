#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		long long int n,i;

		scanf("%lld",&n);
		cin>>s;

		long long int c[n],ones[n],num_ones=0,len=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&c[i]);
			if(s[i]=='1')
			{
				ones[num_ones]=i;
				num_ones++;
			}
		}
		
		i=0;
		while(i<num_ones)
		{
			if(i!=num_ones-1)
			{
				long long int j,s=0,max=0;
				for(j=ones[i]+1;j<=ones[i+1];j++)
				{
					s+=c[j] - c[j-1];
					if(c[j]-c[j-1]>max)
						max=c[j]-c[j-1];
				}
				len+=s-max;
			}
			i++;

		}

		if(num_ones>0)
		{
			len +=(c[ones[0]]-c[0]) + (c[n-1]-c[ones[num_ones-1]]);
		}
		printf("%lld\n",len );
	}
	return 0;
}