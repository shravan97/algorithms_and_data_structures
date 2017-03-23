#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	std::map<char, node*> chars;
	bool isEnd;
	std::map<char, ll> freq;
	node(){
		isEnd=0;
	}
};

class Trie
{
	node * root;
public:
	ll val;
	Trie()
	{
		root=NULL;
		val=0;
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
			curr_root->freq[s[pos]]++;
			curr_root->chars[s[pos]]=insert(NULL,s,pos+1);
		}

		else
		{
			// cout<<" inserted1 "<<s[pos]<<endl;
			curr_root->freq[s[pos]]++;
			curr_root->chars[s[pos]]=insert(curr_root->chars[s[pos]],s,pos+1);
		}

		return curr_root;

	}

	node * get_root()
	{
		return root;
	}


	void search(node * root,string s,ll pos)
	{
		if(pos==s.size())
		{
			return;
		}

		if(!root->chars[s[pos]])
			return;
		val++;

		if(root->freq[s[pos]]>1)
			search(root->chars[s[pos]],s,pos+1); 
	}

	~Trie()
	{

	}
	
};

int main(int argc, char const *argv[])
{
	ll n,m;
	cin>>n>>m;
	std::vector<string> alice;

	for(ll i=0;i<n;i++)
	{
		string k;
		cin>>k;
		alice.push_back(k);
	}

	Trie t;


	for(ll i=0;i<m;i++)
	{
		string k;
		cin>>k;
		t.insertWord(k);

	}
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		t.search(t.get_root(),alice[i],0);
		sum+=t.val;
		t.val=0;
	}
	cout<<sum<<endl;

	return 0;
}
