#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int BinSearch(std::vector<int> &v,int l,int u,int elem)
{
	int mid=(l+u)/2;

	while(l<=u)
	{
		if(v[mid]==elem)
			return mid;
		if(v[mid]>elem)
			u=mid-1;
		else if(v[mid]<elem)
			l=mid+1;
		mid=(u+l)/2;
	}

	return -1;
}

int FindElem(vector <int> &v, int num)
{
	/*
		3 4 5 6 7 1 2
	*/


	if(v.size()==1)
	{
		if(v[0]==num)
			return 0;
		return -1;
	}
	if(v.size()==2)
	{
		if(v[0]==num)
			return 0;
		if(v[1]==num)
			return 1;
		return -1;
		
	}


	int l=0,r=v.size()-1,mid=(l+r)/2;
	bool isRotated=1;
	while(l<r)
	{
		cout<<" l, r and mid : "<<l<<' '<<r<<' '<<mid<<endl;
		// if(mid==0 || mid==v.size()-1)
		// {
		// 	if(mid==0)
		// 		if(v[mid+1]<v[mid])
		// 		{
		// 			mid+=1;
		// 			break;
		// 		}
		// 	if(mid==v.size()-1)
		// 		if(v[mid-1]>v[mid])
		// 		{
		// 			mid-=1;
		// 			break;
		// 		}
		// 	isRotated=0;
		// 	break;
		// }
		if(v[mid-1]>v[mid])
		{
			break;
		}
		if(v[mid+1]<v[mid])
		{
			mid+=1;
			break;
		}
		if(v[mid]<v[l])
			r=mid-1;
		else if(v[mid] > v[r])
			l=mid+1;
		else
		{
			isRotated=0;
			break;
		}
		mid=(l+r)/2;
	}

	// cout<<" transition at : "<<mid<<endl;
	
	if(isRotated)
	{
		int l_search = BinSearch(v,0,mid-1,num);
		int r_search = BinSearch(v,mid,v.size()-1,num);
		
		if(l_search==-1)
			return r_search;
		return l_search;
	}
	
	return BinSearch(v,0,v.size()-1,num);
}


int main(int argc, char const *argv[])
{
	std::vector<int> v;
	
	v.push_back(8);
	v.push_back(10);
	v.push_back(11);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	
	cout<<FindElem(v,5)<<endl;
	return 0;
}
