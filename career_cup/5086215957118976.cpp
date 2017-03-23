#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minDiff(int y)
{
	bool arr[33];
	memset(arr,0,sizeof(arr));

	for(int i=1;i<=32;i++)
	{
		arr[i]=(y&(1<<(i-1)));
	}

	int pos1=1,pos2=0,first_bit=arr[1];

	for(int i=2;i<=32;i++)
	{
		if(arr[i]!=first_bit)
		{
			pos2=i;
			break;
		}
		else
			pos1=i;
	}

	swap(arr[pos2],arr[pos1]);

	int num=0;

	for(int i=1;i<=32;i++)
	{
		if(arr[i])
			num+=pow(2,i-1);
	}

	return num;
}

int main(int argc, char const *argv[])
{
	cout<<minDiff(2)<<endl;
	
	return 0;
}
/*
5

y+pow(2,1)-pow(2,3)

110

1011010001

*/