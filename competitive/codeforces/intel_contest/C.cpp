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

void update(vector<ll> &arr, ll x , ll y, ll l,ll r)
{
	// cout<<" up "<<x<<' '<<y<<endl;
	if(root!=NULL && root->data==1)return root;
	if(x==y && x>=l && y<=r)
	{
		ll k = root->data;
		ll num = arr[x]/root->data;

		// cout<<" num  "<<num<<" k "<<k<<endl;

		if(num<1000)
			root->data=ld[num];
		else
		{
			root->data =lpd(num);
			ld[num]=root->data;
		}
		// cout<<" here \n";
		arr[x]/=k;
		return root;
	}
	else if(x>r || y<l) return root;

	ll mid=(x+y)/2;
	
	// cout<<" up "<<x<<' '<<y<<endl;

	root->left=update(root->left,arr,x,mid,l,r);
	root->right=update(root->right,arr,mid+1,y,l,r);

	root->data = max(root->left->data,root->right->data);
	return root;

}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll req[n],max_s=0;
	memset(req,make_pair(-1,-1),sizeof(req));
	std::vector<ll> arr,ord,ans;
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		max_s+=a;
		arr.push_back(a);
	}

	for(ll i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		ord.push_back(a);
	}
	ans.push_back(0);
	std::vector<ll>::iterator it;
	ll max_b=0,max_e=n-1;

	for(it=ord.begin();it!=ord.end();it++)
	{
		if(*it>=max_b+1 && *it<=max_e+1)

	}

	return 0;
}