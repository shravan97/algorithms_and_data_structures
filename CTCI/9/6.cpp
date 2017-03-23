#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector <string> brackets;


void findCombinations(int n,int o,int c, string comb)
{
	if(o==n)
	{
		for(int i=c;i<n;i++)
			comb+= ")";
		brackets.push_back(comb);
		return;
	}
	if(o==c)
	{
		comb+="(";
		findCombinations(n,o+1,c,comb);
	}
	else
	{
		findCombinations(n,o+1,c,comb+"(");
		findCombinations(n,o,c+1,comb+")");
	}
}


vector <string> returnCombinations(int n)
{

	findCombinations(n,0,0,"");
	return brackets;
}


int main(int argc, char const *argv[])
{
	std::vector<string> v = returnCombinations(3);
	for(auto s:v)
		cout<<s<<endl;
	return 0;
}
