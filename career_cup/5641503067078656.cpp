#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * left, * right;
};

class Tree
{ 
	node * root;
public:
	Tree()
	{
		root=NULL;
	}
	~Tree()
	{

	}
	node * insert(node * root,int data);
	void set_root(node * r)
	{
		root = r;
	}
	
};

node * Tree::insert(node * root,int data)
{
	if(root==NULL)
	{
		root = new node;
		root->data=data;
		root->left=NULL;
		root->right=NULL;

	}
	else
	{
		if(root->data<data)
			root->right=insert(root->right,data);
		else
			root->left=insert(root->left,data);
	}

	return root;
}

void compute(string path,node * root,std::vector<string> &paths)
{
	if (root !=NULL)
	{
		if(path.empty())
			path.push_back((char)(root->data + 48));
		else
		{
			path+="->";
			path.push_back((char)(root->data + 48));
		}

		
		if(root->left==NULL && root->right==NULL)
			paths.push_back(path);
		else
		{
			compute(path,root->left,paths);
			compute(path,root->right,paths);
		}
	}
	

}

int main(int argc, char const *argv[])
{
	Tree t;
	node * root=NULL;
	root=t.insert(root,7);
	root=t.insert(root,2);
	root=t.insert(root,1);
	root=t.insert(root,9);
	root=t.insert(root,3);
	
	std::vector<string> paths;
	compute("",root,paths);

	for(auto p:paths)
	{
		cout<<p<<endl;
	}
	
	return 0;
}