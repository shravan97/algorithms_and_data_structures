#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
typedef long long int ll;
using namespace std;
ll inv_num=0;

void merge(ll * a , ll l1 , ll r1 , ll l2 , ll r2)
{
	// cout<<"Heading "<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<'\n';
	ll temp[r2-l1+10] ,count=0, left=l1,right=l2;
	bool done_l=0,done_r=0;
	while(count<(r2-l1+1))
	{
		if((a[left]<a[right] || done_r) && !done_l)
		{
			// cout<<a[left]<<'-'<<a[right]<<" lshift\n";
			temp[count]=a[left];
			count++;
			if(left==r1)
				done_l=1;
			else
				left++;
		}
		else if((a[left]>=a[right] || done_l) && !done_r)
		{
			// cout<<a[left]<<'-'<<a[right]<<" rshift "<<"\n";
			if(a[left]>a[right])inv_num+=r1-left+1;

			temp[count]=a[right];
			if(right==r2)
				done_r=1;
			else right++;
			count++;
		}
	}

	ll i=l1;
	// cout<<"so far...\n";
	while(i<=r2)
	{
		a[i]=temp[i-l1];
		// cout<<a[i]<<' ';
		i++;
	}
	// cout<<'\n';
}

void mergesort(ll *a,ll l1 , ll r1)
{
	ll mid=(l1+r1)/2;

	if(l1!=r1)
	{
		mergesort(a,l1,mid);
		mergesort(a,mid+1,r1);
		merge(a,l1,mid,mid+1,r1);

	}

}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--)
	{
		ll n,i;
		cin>>n;
		ll a[n];

		for(i=0;i<n;i++)
			cin>>a[i];

		mergesort(a,0,n-1);

		cout<<inv_num<<'\n';
		inv_num=0;
	}
	return 0;
}