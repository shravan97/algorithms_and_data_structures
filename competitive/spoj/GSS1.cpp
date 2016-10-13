#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void build(std::vector<ll> &st , ll *a , ll l , ll r , ll id=0)
{
	if(l==r)
	{
		st[id]=a[l];
		return;
	}
	
	ll mid=(l+r)/2;
	build(st,a,l,mid,id*2+1);
	build(st,a,mid+1,r,id*2+2);
	st[id]=st[id*2+1]+st[id*2+2];
}

ll findSum(std::vector<ll> &st ,ll cl , ll cr , ll id, ll l, ll r)
{
	// cout<<" params "<<cl<<" "<<cr<<" "<<st[id]<<" "<<l<<" "<<r<<" \n";
	if(cl>=l && cr<=r) return st[id];
	else if(cl>r || cr<l) return 0;

	ll mid = (cl+cr)/2;
	return findSum(st,cl,mid,id*2+1,l,r)+findSum(st,mid+1,cr,id*2+2,l,r);
}


int main(int argc, char const *argv[])
{
	long int n,i;
	scanf("%ld",&n);
	long long int a[n];

	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	long int m;
	scanf("%ld",&m);
	long int q[m][2];

	for(i=0;i<m;i++)
		scanf("%ld %ld",&q[i][0],&q[i][1]);
	i=0;

	while(i<m)
	{
		long int u=q[i][0],l=q[i][1],it,no_pos=0;
		long long int max=0 , val=0,ma;
		ma=a[u-1];

		for(it=u-1;it<l;it++)
		{
			if(a[it]>=0)no_pos++;
			val = ((val+a[it])>0)?(val+a[it]):val;
			max = (max>val)?max:val;
			if(a[it]>m)
				ma=a[it];

		}
		if(no_pos>0)
			printf("%lld\n",max );
		else printf("%lld\n",ma );

		i++;
	}
	return 0;
}