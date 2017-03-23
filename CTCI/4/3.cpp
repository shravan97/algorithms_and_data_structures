#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	int data;
	node * left;
	node * right;
};

class Tree
{// A Binary search tree 
	node * root;
public:
	Tree()
	{
		root=NULL;
	}
	node * get_root()
	{
		return root;
	}
	void set_root(node * leaf)
	{
		root = leaf;
	}

	node * insert(int val,node * leaf)
	{
		if(leaf==NULL)
		{
			leaf= new node;
			leaf->data = val;
			leaf->left = NULL;
			leaf->right = NULL;
			return leaf;
		}
		else
		{
			if(leaf->data > val)
			{
				leaf->left = insert(val,leaf->left);
			}
			else
			{
				leaf->right=insert(val,leaf->right);
			}
			return leaf;
		}
	}
};


	node * insert(int val,node * leaf)
	{
		if(leaf==NULL)
		{
			leaf= new node;
			leaf->data = val;
			leaf->left = NULL;
			leaf->right = NULL;
			return leaf;
		}
		else
		{
			if(leaf->data > val)
			{
				leaf->left = insert(val,leaf->left);
			}
			else
			{
				leaf->right=insert(val,leaf->right);
			}
			return leaf;
		}
	}

node * root=NULL;


void BuildTree(vector <ll> &l, int lower, int upper, node * &n)
{
	/*
		
	*/
	if(lower>upper)
	{
		n=NULL;
		return;
	}

	// cout<<" here "<<lower<<' '<<upper<<endl;
	
	int mid=(lower+upper)/2;
	n->data = l[mid];


	n->left = new node;
	n->left->left=NULL;
	n->left->right=NULL;


	n->right = new node;
	n->right->left=NULL;
	n->right->right=NULL;


	BuildTree(l,lower,mid-1,n->left);
	BuildTree(l,mid+1,upper,n->right);
	
	
}


node * GetTree(vector <ll> &l)
{
	if(l.empty())
		return root;
	
	root=new node;
	root->left=NULL;
	root->right=NULL;
	BuildTree(l,0,l.size()-1,root);
	
	return root;
}


void insert_to_tree(node* &root,vector<ll> v,ll l,ll u )
{
	if(u==l)
	{
		root=insert(v[u],root);
		return;
	}

	if(u<l)
		return;

	// cout<<

	ll mid=(l+u)/2;
	cout<<" Here "<<mid<<endl;
	root= insert(v[mid],root);
	insert_to_tree(root,v,l,mid-1);
	insert_to_tree(root,v,mid+1,u);
	
		

}
void preorder(node * leaf)
{
	if(leaf!=NULL)
	{
		cout<<leaf->data<<' ';
		preorder(leaf->left);
		preorder(leaf->right);
	}
}

void inorder(node * leaf)
{
	if(leaf!=NULL)
	{
		inorder(leaf->left);
		cout<<leaf->data<<' ';
		inorder(leaf->right);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<ll> ls;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll k;
		cin>>k;
		ls.push_back(k);
	}

	Tree t;

	// node * root=NULL;

	// insert_to_tree(root,ls,0,n-1);


	root=GetTree(ls);

	cout<<root->data<<endl;
	preorder(root);



	return 0;
}
