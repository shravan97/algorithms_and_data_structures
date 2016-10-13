#include <bits/stdc++.h>
using namespace std;
#define max(a,b)((a>b)?a:b)
typedef long long int ll;

vector <ll> primes;
bool chck[1000];

int ld[1000001];
void sieve()
{
	ll val=2;
	while(val<1000)
	{
		if(chck[val])
		{
			val+=2;
			continue;
		}
		ll v=val,c=3;
		if(val==2)c=2;
		primes.push_back(val);
		ld[val]=val;
		// cout<<val<<" here  \n";
		while(v*c<1000)
		{
			// cout<<" for  "<<v*c<<'\n';
			chck[v*c]=1;
			if(ld[v*c]==0)
				ld[v*c]=val;
			if(val==2)c++;
			else
			c+=2;
		}
		if(val==2)val++;
		else
		val+=2;
	}
}

ll lpd(ll x)
{
	bool flag=0;
	vector<ll>::iterator it;
	if(x==1)return 1;

	for(it=primes.begin();it!=primes.end();it++)
	{
		if(x%(*it)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		return *it;
	}
	else return x;
}

struct node
{
	ll data;
	node * left , * right;
};

struct tree
{
	node * root;
};

node * build(node * root , std::vector<ll> &arr , ll l, ll r)
{
	if(l==r)
	{
		node * t = new node ;
		t->left=NULL;
		t->right=NULL;
		if(arr[l]<1000)
			t->data = ld[arr[l]];
		else
		{
			ld[arr[l]]=lpd(arr[l]);
			t->data = ld[arr[l]];
		}
		return t;
	}
	// cout<<" h "<<l<<' '<<r<<endl;

	ll mid = (l+r)/2;
	root = new node;
	root->data=0;

	root->left=build(root,arr,l ,mid);
	root->right=build(root,arr,mid+1,r);
	root->data=max(root->left->data,root->right->data);
	return root;
}


ll get(node * root , ll x, ll y , ll l ,ll r)
{
	if(x>=l && y<=r )
		return root->data;
	else if(y<l || x>r) return 0;
	else if(root!=NULL && root->data==1)return 1;

	// cout<<" here "<<x<<' '<<y<<endl;

	ll mid=(x+y)/2;
	ll rl = get(root->left ,x,mid,l,r );
	ll rr = get(root->right,mid+1,y,l,r);
	return max(rl,rr);
}

node * update(node * root ,vector<ll> &arr, ll x , ll y, ll l,ll r)
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

// void preorder(node * root)
// {
// 	if(root!=NULL)
// 	{
// 		cout<<root->data<<" ";
// 		preorder(root->left);
// 		preorder(root->right);
// 	}

// }

int main(int argc, char const *argv[])
{
	ld[2]=2;
	ld[1]=1;
	// std::ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	primes.push_back(2);
	sieve();

	while(t--)
	{
		ll n,i,m;
		scanf("%lld %lld",&n,&m);
		std::vector<ll> v;

		for(i=0;i<n;i++)
		{
			ll z;
			scanf("%lld",&z);
			v.push_back(z);
		}

		// vector<ll>::iterator it1;
		// for(it1=primes.begin();it1!=primes.end();it1++)
		// {
		// 	cout<<" inside \n";
		// 	cout<<*it1<<endl;
		// }

		tree t;
		// cout<<" here \n";
		t.root = NULL;
		t.root = build(t.root,v,0,n-1);
		// preorder(t.root);


		while(m--)
		{
			ll typ,l,r;
			scanf("%lld %lld %lld",&typ,&l,&r);
			if(typ==1)
			{
				printf("%lld ",get(t.root,0,n-1,l-1,r-1));
			}
			else
			{
				t.root=update(t.root,v,0,n-1,l-1,r-1);
			}
		}
		printf("\n");

	}

	return 0;
}