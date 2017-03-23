#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node
{
	int data;
	node * left;
	node * right;
};

struct Tree
{
	node * root;
};
node * Tree_insert(node * root ,int val)
{
	if(root==NULL)
	{
		root = new node;
		root->data = val;
		root->left = NULL;
		root -> right = NULL;
	}
	else
	{
		if(root->data <= val)
			root->right = Tree_insert(root->right , val);
		else
			root->left = Tree_insert(root->left , val);
	}
	return root;
}

bool flag=1;

ll chck_balanced(node * root,ll ht)
{
	if(root==NULL)
		return ht-1;

	ll hl=chck_balanced(root->left,ht+1);
	ll hr=chck_balanced(root->right,ht+1);

	if(abs(hr-hl)>1)
		flag=0;

	return max(hl,hr);
}

int main(int argc, char const *argv[])
{
	Tree t;
	t.root = NULL;
	t.root = Tree_insert(t.root,7);
	t.root = Tree_insert(t.root,10);
	t.root = Tree_insert(t.root,5);
	t.root = Tree_insert(t.root,4);
	t.root = Tree_insert(t.root,6);
	t.root = Tree_insert(t.root,11);
	t.root = Tree_insert(t.root,9);

	ll k = chck_balanced(t.root,0);
	cout<<flag<<endl;

	return 0;
}