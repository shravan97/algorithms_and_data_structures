#include <iostream>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		
		ll s=(c/3)*5+((c%3)==2)?2:0;
		ll tot=(r/3)*s+((r%5)==1)?s/2:;

	}
	return 0;
}