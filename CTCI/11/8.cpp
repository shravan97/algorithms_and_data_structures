#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	int data,numNodes;
	node * left, * right;
	node():numNodes(0),left(NULL),right(NULL){}
};

class Tracker
{
	node * root;
	node * insert(node * root, int num)
	{
		if(root==NULL)
		{
			root=new node;
			root->data=num;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			if(root->data > num)
			{
				root->numNodes++;
				root->left=insert(root->left,num);
			}
			else
			{
				root->numNodes++;
				root->right=insert(root->right,num);

			}
		}


		return root;
	}

public:
	Tracker()
	{
		root=NULL;
	}

	void add(int x)
	{
		root=insert(root,x);
	}

	int getRank(int x,node * root,int rank=1)
	{
		if(root==NULL)
			return -1;
		if(root->data==x)
		{
			if(root->left==NULL)
				return rank;
			// cout<<" here at "<<root->data<<' '<<root->left->numNodes<<endl;
			return rank+root->left->numNodes+1;
		}
		if(root->data > x)
		{
			if(root->left==NULL)
				return -1;
			return getRank(x,root->left,rank);
		}
		if(root->right==NULL)
			return -1;
		if(root->left==NULL)
			return getRank(x,root->right,rank+1);
		// cout<<" here at "<<root->data<<' '<<root->left->numNodes<<endl;
		return getRank(x,root->right,rank+root->left->numNodes+2);

	}
	int getRank(int x)
	{
		return getRank(x,root);
	}
	
};



int main(int argc, char const *argv[])
{
	Tracker t;
	t.add(5);
	t.add(1);
	t.add(4);
	cout<<t.getRank(5)<<endl;
	t.add(4);
	t.add(5);
	t.add(9);
	cout<<t.getRank(5)<<endl;

	t.add(7);
	cout<<t.getRank(7)<<endl;

	cout<<t.getRank(9)<<endl;
	t.add(2);
	cout<<t.getRank(2)<<endl;

	return 0;
}
