#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		std::vector< std::vector<int> > teams;
		int i,n;
		scanf("%d",&n);
		double lazy=0.0;

		for(i=0;i<n;i++)
		{
			int choice;
			scanf("%d",&choice);
			if(choice==-1)lazy++;

		}

		printf("%f\n",1.0+(lazy-1)/2.0 );
	}
	return 0;
}