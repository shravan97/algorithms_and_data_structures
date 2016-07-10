#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
bool any_in_vec(vector <long long int> v1 , std::vector<long long int> v2)
{
	std::vector<long long int>::iterator i;
	for (i = v1.begin(); i != v1.end(); ++i)
	{
		if(find(v2.begin(), v2.end() , *i)!=v2.end())
			return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		long long int n,i=0;

		scanf("%lld",&n);
		long long int a[n],b[n];
		set <long long int> equals , b_used;
		pair <long long int , vector <long long int> > gbl[8];
		bool np=0;
		while(i<n)
		{
			scanf("%lld",&b[i]);
			i++;
		}
		i=0;
		while(i<n)
		{
			scanf("%lld",&a[i]);
			i++;
		}
		i=0;
		while(i<n)
		{
			pair <long long int , vector <long long int> > local[8];
			set <long long int> local_eq;

			if(np)break;
			local[0].first = a[i];
			// printf("%lld ",local[0].first );

			local[1].first =a[i];
			if(i>=1)
			{
				local[1].first+=b[i-1];
				local[1].second.push_back(i-1);
			}
			// printf("%lld b",local[1].first );

			local[2].first=a[i]+b[i];
			local[2].second.push_back(i);
			// printf("%lld ",local[2].first );

			local[3].first=a[i];
			if(i<n-1)
			{
				local[3].first += b[i+1];
				local[3].second.push_back(i+1);
			}
			// printf("%lld ",local[3].first );

			local[4].first=a[i]+b[i];
			if(i>=1)
			{
				local[4].first+=b[i-1];
				local[4].second.push_back(i-1);
			}
			local[4].second.push_back(i);
			// printf("%lld ",local[4].first );

			local[5].first = a[i]+b[i];
			local[5].second.push_back(i);
			if(i<n-1)
			{
				local[5].first+=b[i+1];
				local[5].second.push_back(i+1);
			}
			// printf("%lld ",local[5].first );

			local[6].first=a[i];
			if(i>=1)
			{
				local[6].first+=b[i-1];
				local[6].second.push_back(i-1);
			}
			if(i<n-1)
			{
				local[6].first+=b[i+1];
				local[6].second.push_back(i+1);
			}
			// printf("%lld ",local[6].first );

			local[7].first=a[i];
			if(i>=1)
			{
				local[7].first+=b[i-1];
				local[7].second.push_back(i-1);
			}
			local[7].first+=b[i];
			local[7].second.push_back(i);
			if(i<n-1)
			{
				local[7].first+=b[i+1];
				local[7].second.push_back(i+1);
			}
			// printf("%lld\n",local[7].first );

			// printf("one\n");

			if(i>=1)
			{
				int j=0;
				while(j<8)
				{
					int k=0;
					while(k<8)
					{
						if(any_in_vec(local[j].second , gbl[k].second)==0)
						{
							if(local[j].first==gbl[k].first)
								if(find(equals.begin(), equals.end() , local[j].first)!=equals.end())
								{
									local_eq.insert(local[j].first);
									vector <long long int>::iterator itr;
									for(itr=local[j].second.begin();itr!=local[j].second.end();itr++)
									{
										b_used.insert(*itr);
									}
									for(itr=gbl[k].second.begin();itr!=gbl[k].second.end();itr++)
									{
										b_used.insert(*itr);
									}
								}
						}
						k++;
					}
					j++;
				}
				if(local_eq.empty())
				{
					np=1;
				}
			}
			else 
			{
				local_eq.insert(local[0].first);
				local_eq.insert(local[1].first);
				local_eq.insert(local[2].first);
				local_eq.insert(local[3].first);
				local_eq.insert(local[4].first);
				local_eq.insert(local[5].first);
				local_eq.insert(local[6].first);
				local_eq.insert(local[7].first);
			}

			// printf("two\n");

			equals = local_eq;
			for(int z=0;z<8;z++)
				gbl[z]=local[z];

			i++;
		}
		// printf("%lld\n",b_used.size() );

		if(np) printf("-1\n");
		else if(n==1)printf("%lld\n",*max_element(equals.begin(), equals.end()) );
		else if(b_used.size() !=n)printf("-1\n");
		else printf("%lld\n",*max_element(equals.begin(), equals.end()) );
	}
	return 0;
}