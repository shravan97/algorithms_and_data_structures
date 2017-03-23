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
void inorder_chck(node * root1,node * root2)
{
	
	if(root1!=NULL && root2!=NULL)
	{
		if(root1->left==NULL && root2->left!=NULL)
		{
			inorder_chck(root1,root2->left);
			if(root1->data!=root2->data)
			{
				cout<<" condition 1 "<<root1->data<<' '<<root2->data<<endl;
				flag=0;
				return;
			}
			inorder_chck(root1->right,root2);

		}
		else if(root2->left==NULL && root1->left!=NULL)
		{
			inorder_chck(root1->left,root2);
			if(root1->data!=root2->data)
			{
				cout<<" condition 2 "<<root1->data<<' '<<root2->data<<endl;
				flag=0;
				return;
			}
			inorder_chck(root1,root2->right);

		}
		else if(root1->left!=NULL && root2->left!=NULL)
		{
			inorder_chck(root1->left,root2->left);
			if(root1->data!=root2->data)
			{
				cout<<" condition 3 "<<root1->data<<' '<<root2->data<<endl;
				flag=0;
				return;
			}

			inorder_chck(root1->right,root2->right);

		}

	}
}

int main(int argc, char const *argv[])
{
	Tree t;
	t.root = NULL;
	t.root = Tree_insert(t.root,9);
	t.root = Tree_insert(t.root,8);
	t.root = Tree_insert(t.root,7);
	t.root = Tree_insert(t.root,6);
	t.root = Tree_insert(t.root,5);
	t.root = Tree_insert(t.root,4);
	t.root = Tree_insert(t.root,3);
	t.root = Tree_insert(t.root,2);
	t.root = Tree_insert(t.root,1);

	Tree t1;
	t1.root = NULL;
	t1.root = Tree_insert(t1.root,1);
	t1.root = Tree_insert(t1.root,2);
	t1.root = Tree_insert(t1.root,3);
	t1.root = Tree_insert(t1.root,4);
	t1.root = Tree_insert(t1.root,5);
	t1.root = Tree_insert(t1.root,6);
	t1.root = Tree_insert(t1.root,7);
	t1.root = Tree_insert(t1.root,8);
	t1.root = Tree_insert(t1.root,9);

	inorder_chck(t.root,t1.root);

	cout<<flag<<endl;
	return 0;
}
