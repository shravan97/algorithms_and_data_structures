#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll d;
		cin>>d;

		ll no_9 = d/9;
		ll rem = d-9*no_9;
		cout<<rem+1<<endl;
	}
	return 0;
}