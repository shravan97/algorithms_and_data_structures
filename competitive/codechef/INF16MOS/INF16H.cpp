#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	node* chars[26];
	ll freq[26];
	bool isEnd;
	node()
	{
		isEnd=0;
		memset(freq,0,sizeof(freq));
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
			{
				curr_root->isEnd=1;
			}
			return curr_root;
		}

		if(curr_root==NULL)
		{
			curr_root = new node;
			// cout<<" inserted "<<s[pos]<<endl;
			curr_root->freq[s[pos]-'a']++;
			curr_root->chars[s[pos]-'a']=insert(NULL,s,pos+1);
		}

		else
		{
			// cout<<" inserted1 "<<s[pos]<<endl;
			curr_root->freq[s[pos]-'a']++;
			curr_root->chars[s[pos]-'a']=insert(curr_root->chars[s[pos]-'a'],s,pos+1);
		}

		return curr_root;

	}

	node * get_root()
	{
		return root;
	}

	ll trie_search(node * root,string s,ll pos)
	{
		if(pos==s.size())
		{
			if(root==NULL)
				return 1;
			ll sm=(root->isEnd==1);
			for(int i=0;i<26;i++)
			{
				sm+=root->freq[i];
			}
			return sm;
		}

		if(!root->chars[s[pos]-'a'])
		{
			// cout<<" here for "<<s<<" at pos "<<pos<<"  char "<<s[pos]<<endl;
			return 0;
		}
		return trie_search(root->chars[s[pos]-'a'],s,pos+1); 
	}

	~Trie()
	{

	}
	
};
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	std::vector<string> v;

	for(ll i=0;i<n;i++)
	{

		string s;
		cin>>s;
		v.push_back(s);

	}

	ll s;
	cin>>s;

	while(s--)
	{
		ll num,th;
		cin>>num>>th;

		Trie t;

		for(ll i=0;i<num;i++)
		{
			string s1;
			cin>>s1;
			t.insertWord(s1);
		}

		ll sum=0;
		bool flg=0;

		for(ll i=0;i<n;i++)
		{
			ll k;
			k=t.trie_search(t.get_root(),v[i],0);
			// cout<<k<<endl;
			sum+=k;
			if(sum>=th)
			{
				cout<<i+1<<endl;
				flg=1;
				break;
			}
		}
		if(flg)
			continue;
		cout<<-1<<endl;
	}
	return 0;
}
