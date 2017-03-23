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


void traverse(node * root,int &cl,int data)
{

	if(root==NULL)
		return;
	if(abs(root->data-data)<abs(cl-data))
		cl=root->data;
	traverse(root->left,cl,data);
	traverse(root->right,cl,data);
}

int closest(node * root,int data)
{
	int cl=INT_MAX;
	traverse(root,cl,data);
	return cl;
}

node * insert(node * root , int val)
{
	if(root==NULL)
	{
		root= new node;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if(root->data > val)
		{
			root->left = insert(root->left,val);
		}
		else
			root->right = insert(root->right,val);
	}
	return root;
}

int main(int argc, char const *argv[])
{

	tree t;
	t.root=NULL;
	t.root=insert(t.root,7);
	t.root=insert(t.root,9);
	t.root=insert(t.root,5);
	t.root=insert(t.root,6);
	t.root=insert(t.root,8);
	t.root=insert(t.root,4);

	cout<<closest(t.root,5)<<endl;

	return 0;
}
