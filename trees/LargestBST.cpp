#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	int data;
	node * left;
	node * right;
};

int maxSubtree=0;

int Traverser(node * root)
{
	if(root==NULL)
		return 0;
	int l=Traverser(root->left), r=Traverser(root->right);
	// cout<<" here at : "<<root->data<<endl;
	if(l==-1 || r==-1)
		return -1;
	if(root->left!=NULL)
	{
		if(root->data < root->left->data)
		{
			return -1;
		}
	}
	if(root->right!=NULL)
	{
		if(root->data > root->right->data)
		{
			return -1;
		}


	}
	
	maxSubtree = max(maxSubtree, l+r+1);
	
	return l+r+1;
	
}


int LargestBST(node * root)
{
	int num = Traverser(root);
	return maxSubtree;
}

node * insert(node * leaf,int val)
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
			leaf->left = insert(leaf->left,val);
		}
		else
		{
			leaf->right=insert(leaf->right,val);
		}
		return leaf;
	}
}


int main(int argc, char const *argv[])
{
	node * root=NULL;
	root=insert(root,7);
	root=insert(root,9);
	root=insert(root,6);
	root=insert(root,5);
	root=insert(root,4);
	root=insert(root,8);
	root=insert(root,10);
	root=insert(root,12);
	root=insert(root,11);

	root->data=2;

	cout<<LargestBST(root)<<endl;
	return 0;
}
