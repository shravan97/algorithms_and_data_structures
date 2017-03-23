#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector < vector<int> > subsets;
ll op=0;

void FindSubsets(vector <int> v,int index,vector <int> subset)
{
	op++;
	if(index==v.size())
	{
		subsets.push_back(subset);
		return;
	}
	
	FindSubsets(v,index+1,subset);
	subset.push_back(v[index]);
	FindSubsets(v,index+1,subset);
	
}
vector < vector<int> > FindSubsets(vector <int> v)
{
	vector <int> subset;
	FindSubsets(v,0,subset);
	return subsets;
}


int main(int argc, char const *argv[])
{
	std::vector< std::vector<int> > v;
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	
	

	v=FindSubsets(v1);

	cout<<op<<endl;
	for(auto e:v)
	{
		for(auto e1:e)
			cout<<e1<<' ';
		cout<<endl;
	}

	return 0;
}
