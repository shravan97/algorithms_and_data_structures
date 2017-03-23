#include <bits/stdc++.h>
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


bool chckBST(node * root,int prev_root=INT_MAX,bool l=0)
{
	if(root==NULL)
		return 1;
	bool l_BST=1,r_BST=1;
	if(root->left!=NULL)
	{
		if(root->left->data>root->data)
			return 0;
		// cout<<" here l \n";
		l_BST=chckBST(root->left,root->data,1);
	}
	if(root->right!=NULL)
	{
		if(root->right->data < root->data || root->right->data > prev_root )
			return 0;
		// cout<<" here r \n";
		if(l)
		{
			// cout<<prev_root<<" <-prev "<<root->data<<endl;
			r_BST=chckBST(root->right,prev_root,1);
		}
		else
			r_BST=chckBST(root->right);
	}

	// cout<<l_BST<<" and "<<r_BST<<" at "<<root->data<<endl;
	if((l_BST==0) || (r_BST==0))
		return 0;
	return 1;
}
/*
	   2
	1     9
	  2    12
	 1  4
	     6 
	    5
*/

int prevVal=INT_MIN;
bool chckForBST=1;


void Traverse(node * root)
{
	if(root==NULL)
		return;
	Traverse(root->left);


	/* Access the current element */
	if(prevVal > root->data)
	{
		chckForBST=0;
		return;
	}
	prevVal = root->data;
	Traverse(root->right);
}

bool chckSearchTree(node * root)
{
	Traverse(root);
	return chckForBST;

}

int main(int argc, char const *argv[])
{
	tree t;
	t.root=NULL;
	t.root=insert(7,t.root);
	t.root=insert(1,t.root);
	t.root=insert(2,t.root);
	t.root=insert(9,t.root);
	t.root=insert(4,t.root);
	t.root=insert(6,t.root);
	t.root=insert(1,t.root);
	t.root=insert(5,t.root);
	t.root=insert(12,t.root);
	t.root->data=2;
	cout<<chckSearchTree(t.root)<<endl;
	
	return 0;
}
