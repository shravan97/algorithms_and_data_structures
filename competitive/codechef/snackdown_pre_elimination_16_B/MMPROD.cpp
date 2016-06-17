#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long int l;
int main()
{
	l t;
	scanf("%lld",&t);

	for(;t>0;t--)
	{
		l n ,k,i,no_pos=0,no_neg=0,prod=1;
		scanf("%lld %lld",&n,&k);
		l a[n];

		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>=0) no_pos++;
			else no_neg++;
		}

		if(no_neg==0)
		{
			for(i=n-1;i>=0;i--)
				prod*=a[i];
		}
		else if(no_pos==0)
		{
			if(k&1)
			{
				for(i=n-1;i>=n-k;i--)
					prod*=a[i];
			}
			else
				for(i=0;i<k;i++)
					prod*=a[i];
		}
		else
		{
			sort(a,a+n);
			l left=0 , right=n-1, count=0,last_neg=0,last_pos=n-1;
			while(count<k)
			{
				if(llabs(a[l]) >= llabs(a[r]))
				{
					prod*=a[l];
					if(a[l]>=0)
						no_pos--;
					else no_neg--;
					count++;
					l++;
				}
				else
				{
					prod*=a[r];
					if(a[r]>=0)
						no_pos--;
					else no_neg--;
					count++;
					r--;
				}
				if(count==k)
				{
					if(prod<0)
					{
						if(no_pos>0 && no_neg==0)
						{

						}
					}
				}
			}
		}
	}

	return 0;
}