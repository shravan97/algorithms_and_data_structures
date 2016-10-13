#include <bits/stdc++.h>
#define min(a,b)((a<b)?a:b)
using namespace std;
int main(int argc, char const *argv[])
{
	int t,count=0;
	cin>>t;
	ofstream ofile;
	ofile.open("out.txt",ios::out);
	while(t--)
	{
		long long int l,r,k;
		cin>>l>>r;
		k = min(l,r);
		ofile<<"Case #"<<count+1<<": "<<k*(k+1)/2<<'\n';
		count++;
	}
	return 0;
}