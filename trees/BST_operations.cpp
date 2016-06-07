#include <iostream>
using namespace std;

class Node
{   int data;
	Node * left;
	Node * right;
public:
	Node(){
		left=NULL;
		right=NULL;
	}

 Node * ret_left(){
 	return left;
 }
 Node * ret_right(){
return right;
 }
int ret_data()
{
	return data;
}	
void setdata(int inp_data)
{
	data = inp_data;
}
void setleft(Node * leaf){
	left = leaf;
}
void setright(Node * leaf){
	right = leaf;
}


};

class Tree
{	Node * root;
public:
	Tree(){
		root=NULL;
	}
	Node * newnode(int data_inp)
	{
		Node * node = new Node;
		node->setdata(data_inp);
		return node;
	}
	Node * insert(Node * tree_root , int data)
	{
		if(tree_root==NULL)
		{
			tree_root = newnode(data);
		}
		else if(tree_root->ret_data() >= data)
		{
			tree_root->setleft(insert(tree_root->ret_left() , data));
		}
		else
		{
			tree_root->setright(insert(tree_root->ret_right() , data));
		}cout<<"Here i am";
	return tree_root;

	}

	bool search(Node * tree_root , int sdata)
	{
		if(tree_root==NULL)return false;
		else if(tree_root->ret_data() > sdata){
			return search(tree_root->ret_left(),sdata );
		}
		else if(tree_root->ret_data()==sdata)
			return true;
		else{
			return search(tree_root->ret_right(),sdata );
		}
	}
	~Tree();
	
};
main()
{
Tree * t;
Node * root;

root=t->insert(root,10);
root=t->insert(root,12);
cout<<t->search(root,12);
return 0;
}