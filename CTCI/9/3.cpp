#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int FindMagicNum(vector <int> &v)
{
	int l=0,r=v.size()-1,mid=(l+r)/2;
	bool done=0;


	while(l<=r)
	{
		if(v[mid]==mid)
		{
			done=1;
			break;
		}
		if(v[mid]<mid)
			l=mid+1;
		else if(v[mid]>mid)
			r=mid-1;
		mid=(l+r)/2;
	}
	if(done)
		return mid;
	return -1;
}


int main(int argc, char const *argv[])
{
	std::vector<int> v;

	for(int i=0;i<5;i++)
	{
		int k;
		cin>>k;
		v.push_back(k);
	}

	cout<<FindMagicNum(v)<<endl;

	return 0;
}
