#include <cstdio>
#include <cmath>
#define max(a,b)((a>b)?a:b)
using namespace std;
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

int d=0;
node * insert(node * root,int val)
{
	if(root==NULL)
	{
		root = new node;
		root->data = val;
		root->left=NULL;
		root->right = NULL;
	}
	else
	{
		if(root->data < val)
			root->right = insert(root->right,val);
		else 
		{
			root->left = insert(root->left,val);
		}
	}
	return root;
}

int height(node * root)
{
	if(root==NULL)
		return -1;
	else
		return max(height(root->left) , height(root->right))+1;
}

void diameter(node * root)
{
	if(root!=NULL)
	{
		int temp_d = height(root->left)+height(root->right)+2;
		if(temp_d>d)
			d=temp_d;
		diameter(root->left);
		diameter(root->right);
	}
}

int main(int argc, char const *argv[])
{
	tree t;
	t.root = NULL;
	t.root = insert(t.root , 1);
	t.root = insert(t.root , 2);
	t.root = insert(t.root , 3);
	t.root = insert(t.root , 4);
	t.root = insert(t.root , 5);
	// t.root = insert(t.root , 120);
	// t.root = insert(t.root , 170);
	// t.root = insert(t.root , 9);
	// t.root = insert(t.root , 17);
	// t.root = insert(t.root , 12);
	// t.root = insert(t.root , 11);
	// t.root = insert(t.root , 10);
	// t.root = insert(t.root , 15);
	// t.root = insert(t.root , 20);
	// t.root = insert(t.root , 14);
	// t.root = insert(t.root , 25);
	// t.root = insert(t.root , 100);
	// t.root = insert(t.root , 150);
	// t.root = insert(t.root , 110);
	// t.root = insert(t.root , 200);
	// t.root = insert(t.root , 270);
	// t.root = insert(t.root , 250);
	// t.root = insert(t.root , 220);
	// t.root = insert(t.root , 210);


	diameter(t.root);

	printf("%d\n",d );
	
	return 0;
}