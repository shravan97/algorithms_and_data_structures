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

struct lnode
{
	int data;
	lnode * next;
};

std::map<ll, vector<node *> > links;

lnode * insert_link(lnode * start,int data)
{
	if(start==NULL)
	{
		start = new lnode;
		start->data=data;
		start->next=NULL;
		return start;
	}

	lnode * newNode = new lnode;
	newNode->data = data;
	newNode->next = start;
	start = newNode;
	return start;

}

void linkLevels(node * root,ll lvl)
{
	if(root!=NULL)
	{
		links[lvl].push_back(root);
		linkLevels(root->left,lvl+1);
		linkLevels(root->right,lvl+1);
	}
}

void link_traverse(lnode * start)
{
	while(start!=NULL)
	{
		cout<<start->data<<' ';
		start = start->next;
	}
}

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
	linkLevels(root,1);

	for(auto l:links)
	{
		for(auto e:l.second)
			cout<<e->data<<' ';
		cout<<endl;
	}
	return 0;
}
