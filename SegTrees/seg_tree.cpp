#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	ll data;
	node * left, * right;
};

struct tree
{
	node * root;
};

node * build(node * root , ll *a , ll l , ll r)
{
	if(l==r)
	{
		node * t = new node;
		t->data = a[l];
		t->left=NULL;
		t->right=NULL;
		return t;
	}
	ll mid = (l+r)/2;

	root = new node;
	root->left = NULL;
	root->right = NULL;
	root->data=0;

	// cout<<" here "<<l<<' '<<r<<endl;

	root->left = build(root->left,a,l,mid);
	root->right = build(root->right,a,mid+1,r);

	if(root->left!=NULL)
		root->data=root->left->data;
	if(root->right!=NULL)
		root->data+=root->right->data;

	return root;

}

void preorder(node * root)
{
	if(root!=NULL)
	{
		cout<<root->data<<' ';
		preorder(root->left);
		preorder(root->right);
	}
}

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
	ll n = 10;
	ll a[n];
	for(ll i =0;i<n;i++)
		a[i]=i;
	// cout<<" size "<<pow(2,ceil(log(6)/log(2))+1)-1<<'\n';
	std::vector<ll> segTree(pow(2,ceil(log(n)/log(2))+1)-1);
	// cout<<segTree.size()<<'\n';
	build(segTree,a,0,n-1);
	for(ll i=0;i<segTree.size();i++)
		cout<<segTree[i]<<' ';
	tree t;
	t.root = build(t.root,a,0,n-1);
	preorder(t.root);

	// cout<<'\n'<<findSum(segTree,0,n-1,0,231,440)<<'\n';

	return 0;
}