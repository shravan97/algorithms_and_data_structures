#include <bits/stdc++.h>
#define R 0
#define B 1
using namespace std;
typedef long long int ll;

struct node
{
	int data;
	node * left, * right, * parent;
	bool color;
	node(int val,node * p):data(val),color(R),left(NULL),right(NULL),parent(p){}
};

class Tree
{

	node * root;

	void left_rotate(node * &x)
	{
		/*

		x				y
	   / \			   / \
	  a   y     ->    x   c    
	     / \         / \
	    b   c 		a   b

	    */

	    if(!x)
	    	return;
	    node * a =x->left, * y=x->right, * temp;
	    int swp;

	    // Interchange values of x and y
	    swp = x->data;
	    x->data = y->data;
	    y->data = swp;

	    // Interchange y's left and right
	    temp = x->left;
	    x->left = x->right;
	    x->right = temp;

	    // Interchange x's right and y's left
	    temp = x->right;
	    x->right=y->left;
	    y->left = temp;

	    // Interchange x's right and y's right
	    temp = x->right;
	    x->right=y->right;
	    y->right = temp;

	    if(x->left)
	    	x->left->parent = x;
	    if(x->right)
	    	x->right->parent=x;
	    if(y->left)
	    	y->left->parent=y;
	    if(y->right)
	    	y->right->parent=y;


	}

	void right_rotate(node * &y)
	{
		/*

		x				y
	   / \			   / \
	  a   y     <-    x   c    
	     / \         / \
	    b   c 		a   b

	    */

	    if(!x)
	    	return;
	    node * a =x->left, * y=x->right, * temp;
	    int swp;

	    // Interchange values of x and y
	    swp = x->data;
	    x->data = y->data;
	    y->data = swp;

	    // Interchange y's left and right
	    temp = x->left;
	    x->left = x->right;
	    x->right = temp;

	    // Interchange x's right and y's left
	    temp = x->right;
	    x->right=y->left;
	    y->left = temp;

	    // Interchange x's left and y's left
	    temp = x->left;
	    x->left=y->left;
	    y->left = temp;

	    if(x->left)
	    	x->left->parent = x;
	    if(x->right)
	    	x->right->parent=x;
	    if(y->left)
	    	y->left->parent=y;
	    if(y->right)
	    	y->right->parent=y;

	}

	void insert_fix(node * &z)
	{
		node * y;
		while(z->parent && z->parent->color==R)
		{
			if(z->parent==z->parent->parent->left)
			{
				y = z->parent->parent->right;
				if(y->color==R)
				{
					z->parent->color=B;
					y->color=B;
					z->parent->parent->color=R;
					z=z->parent->parent;
				}
				else if(z==z->parent->right)
				{
					z=z->parent;
					left_rotate(z);
				}
			}
		}
	}


public:
	Tree()
	{
		root=NULL;
	}

	node * get_root()
	{
		return root;
	}

	node * insert(node * z,int val,node * p)
	{
		if(!z)
		{
			z = new node(val,p);
			
			insert_fix(z);

			return z;
		}
		if(val < z->data)
		{
			z->left= insert(z->left,val,z);
		}

		z->right = insert(z->right,val,z);
		return z;
	}

	~Tree();
	
};
int main(int argc, char const *argv[])
{
	
	return 0;
}
