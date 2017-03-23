#include <bits/stdc++.h>
using namespace std;

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

	void inorder(node * leaf)
	{
		if(leaf!=NULL)
		{
			inorder(leaf->left);
			cout<<leaf->data<<' ';
			inorder(leaf->right);
		}
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

	void postorder(node * leaf)
	{
		if(leaf!=NULL)
		{
			postorder(leaf->left);
			postorder(leaf->right);
			cout<<leaf->data<<' ';
		}
	}

	void level_order(node * root)
	{
		queue <node *> q;

		q.push(root);

		while(!q.empty())
		{
			node * top = q.front();
			if(top==NULL)
				q.pop();
			else
			{
				cout<<top->data<<endl;
				q.push(top->left);
				q.push(top->right);
			}
			q.pop();
		}
	}
	
};

int main(int argc, char const *argv[])
{
	node * root;
	Tree t;
	root = t.insert(7,root);
	root = t.insert(10,root);
	root = t.insert(5,root);
	root = t.insert(17,root);
	root = t.insert(9,root);
	root = t.insert(2,root);
	root = t.insert(6,root);
	
	
	t.set_root(root);
	// t.postorder(root);
	t.level_order(root);
	return 0;
}