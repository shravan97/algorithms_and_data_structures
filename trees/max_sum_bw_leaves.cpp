#include <iostream>
#include <climits>
using namespace std;
typedef long long int ll;

struct node
{
	int data;
	node * left;
	node * right;
};
struct tree
{
	node * root;
};

ll sum1=INT_MIN,sum2=0;

ll find_sum(node * root)
{
	if(root==NULL)
		return 0;
	ll lsum = find_sum(root->left);
	ll rsum = find_sum(root->right);
	cout<<" val nw : "<<root->data<<" "<<lsum+rsum+root->data<<" "<<sum1<<'\n';
	if(lsum+rsum+root->data > sum1)
		if(root->right != NULL && root->left!=NULL)
		{
			sum1 = lsum+rsum+root->data;
			cout<<" Assign : "<<sum1<<'\n';
		}
	return root->data + lsum + rsum;
}

node * bst_insert(int data , node * root)
{
	if(root==NULL)
	{
		root = new node;
		root->data = data;
		root->left=NULL;
		root->right=NULL;
	}
	else 
	{
		if(root->data > data)
			root->left = bst_insert(data , root->left);
		else root->right = bst_insert(data,root->right);
	}
	return root;
}

int main(int argc, char const *argv[])
{
	tree t;
	t.root = NULL;
	t.root = bst_insert(-7,t.root);
	t.root = bst_insert(-5,t.root);
	t.root = bst_insert(-11,t.root);
	t.root = bst_insert(-9,t.root);
	t.root = bst_insert(-15,t.root);
	t.root = bst_insert(-6,t.root);
	// t.root = bst_insert(-4,t.root);
	
	ll totsum = find_sum(t.root);
	cout<<sum1<<'\n';
	return 0;
}