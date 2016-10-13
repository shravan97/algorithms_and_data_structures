#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// std::map<std::vector<ll> , ll> freq;
// ll compute(vector<ll> &v,)

int main(int argc, char const *argv[])
{
	ll x,y;
	cin>>x>>y;
	ll arr[3]={y,y,y},t=0;
	int n=0;

	// if(x==2 && y==1)
	// {
		// cout<<
	// }

	while(arr[0]!=x || arr[1]!=x || arr[2]!=x)
	{
		// arr[n]=arr[!n]-arr[2]+1;
		// if(arr[n]<y)arr[n]=y;
		cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<endl;
		if(n==0)
		{
			arr[0]=arr[1]+arr[2]-1;
			if(arr[0]>x)arr[0]=x;
		}
		else if(n==1)
		{
			arr[1]=arr[2]+arr[0]-1;
			if(arr[1]>x)arr[1]=x;
		}
		else
		{
			arr[2]=arr[1]+arr[0]-1;
			if(arr[2]>x)arr[2]=x;
		}
		t++;
		if(n==2)
			n=0;
		else n++;
	}
	cout<<t<<endl;
	return 0;
}