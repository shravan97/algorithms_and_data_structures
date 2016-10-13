#include <bits/stdc++.h>
#define min(a,b)((a<b)?a:b)
#define max(a,b)((a>b)?a:b)

using namespace std;
int main(int argc, char const *argv[])
{
	long long int l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	if(r1<l2 || r2<l1)
	{
		cout<<0<<endl;
		return 0;
	}

	long long int  ans = min(r1,r2)-max(l1,l2);
	if(k>=max(l1,l2) &&k<=min(r1,r2))
		ans--;
	cout<<ans+1<<endl;
	return 0;
}