#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	std::map<char, node*> chars;
	bool isEnd;
	node(){
		isEnd=0;
	}
};

class Trie
{
	node * root;
public:
	Trie()
	{
		root=NULL;
	}

	void insertWord(string s)
	{
		root = insert(root,s,0);
	}

	node * insert(node * curr_root,string s, ll pos)
	{
		
		if(pos==s.size())
		{
			if(curr_root==NULL)
			{
				curr_root=new node;
				curr_root->isEnd=1;
			}
			else
				curr_root->isEnd=1;
			return curr_root;
		}

		if(curr_root==NULL)
		{
			curr_root = new node;
			// cout<<" inserted "<<s[pos]<<endl;
			curr_root->chars[s[pos]]=insert(NULL,s,pos+1);
		}

		else
		{
			// cout<<" inserted1 "<<s[pos]<<endl;
			curr_root->chars[s[pos]]=insert(curr_root->chars[s[pos]],s,pos+1);
		}

		return curr_root;

	}

	node * get_root()
	{
		return root;
	}

	bool search(string s)
	{
		return trie_search(root,s,0);
	}

	bool trie_search(node * root,string s,ll pos)
	{
		if(pos==s.size())
		{
			if(root==NULL)
				return 0;
			return (root->isEnd==1);
		}

		if(!root->chars[s[pos]])
			return 0;
		return trie_search(root->chars[s[pos]],s,pos+1); 
	}

	~Trie()
	{

	}
	
};



int main(int argc, char const *argv[])
{
	Trie tr;
	// node * local_root=NULL;
	tr.insertWord("wow");
	tr.insertWord("nice");

	cout<<" search for 'nice' "<<tr.search("nice")<<endl;
	

	return 0;
}
