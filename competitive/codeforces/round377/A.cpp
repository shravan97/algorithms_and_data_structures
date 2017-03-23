#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int k,r;
	cin>>k>>r;
	int l=k%10;
	for(int i=1;i<10;i++)
		if((l*i)%10==r||(l*i)%10==0 )
		{
			cout<<i<<endl;
			break;
		}

	return 0;
}