#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,m,i,min_dist=0;
	scanf("%lld %lld",&n,&m);
	ll a[n],b[m];

	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<m;i++)
		scanf("%lld",&b[i]);


	for(i=0;i<n;i++)
	{
		ll curr_min = (ll)abs(a[i] - b[0]);
		int prev=0;
		ll l_l=0 , u_l=m-1 , mid=(l_l+u_l)/2 , least=(ll)abs(a[i] - b[mid]);
		while(l_l<u_l && b[mid]!=a[i])
		{
			// printf("%lld %lld \n",l_l,u_l );
			if(b[mid]>a[i])
			{
				u_l=mid-1;
				prev=1;
			}
			else
			{
				l_l=mid+1;
				prev=-1;
			}

			mid = (l_l+u_l)/2;
			if(least > (ll)abs(a[i] - b[mid]))
				least = (ll)abs(a[i] - b[mid]);

		}

		// if(l_l==u_l)
		// {
		// 	curr_min = ((ll)abs(a[i]-b[mid]) > (ll)abs(a[i]-b[mid+prev]))?(ll)abs(a[i]-b[mid+prev]):(ll)abs(a[i]-b[mid]);
		// }
		// else curr_min = (ll)abs(a[i]-b[mid]);

		curr_min = least;
		// printf("%lld\n",curr_min );

		if(curr_min > min_dist)
			min_dist = curr_min;
	}
	printf("%lld\n",min_dist );
	
	return 0;
}