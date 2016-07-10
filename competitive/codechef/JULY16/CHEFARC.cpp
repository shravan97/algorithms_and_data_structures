#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,m,k1,k2,i,j,min=INT_MAX;
		scanf("%d %d %d %d",&n,&m,&k1,&k2);
		bool done=0;
		std::map<int, std::vector<int> > zeroes;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				int b;
				scanf("%d",&b);
				if(!b)
					zeroes[i].push_back(j);
			}
		}

		std::vector< pair< pair<int , int> , int> > r1 , r2;
		pair< pair<int , int> , int> tem;
		pair<int,int> tem1;
		tem1.first=0;
		tem1.second=0;
		tem.first = tem1;
		tem.second=0;
		r1.push_back(tem);

		tem1.second = m-1;
		tem.first = tem1;
		r2.push_back(tem);
		
		i=0;
		while(i<n && i>=0)
		{
			int pts1=0,pts2=0;
			std::vector<int> sums;
			// printf("Iterating through row : %d\n",i );
			int count=0;
			for(vector<int>::iterator it=zeroes[i].begin();it!=zeroes[i].end();++it)
			{
				vector< pair< pair<int , int> , int> >::iterator itr;
				for(itr=r1.begin();itr!=r1.end();itr++)
				{
					int temp = abs(i- (*itr).first.first)+abs(*it - (*itr).first.second);
					if( temp<=k1 && temp!=0)
					{
						// printf("Match found : %d %d \n",i,*it );
						pair< pair<int , int> , int> tr;
						pair<int,int> tr1;
						tr1.first=i;
						tr1.second= *it;
						tr.first=tr1;
						tr.second= (*itr).second+1;
						r1.push_back(tr);
						sums.push_back(i+(*it));
						pts1++;
						// printf("%d %d %d\n",i,*it , (*itr).second+1 );
						break;
					}
				}
			}

				vector< pair< pair<int , int> , int> >::iterator r_itr;
			for(vector<int>::iterator it=zeroes[i].begin();it!=zeroes[i].end();++it)	
			{	for(r_itr=r2.begin();r_itr!=r2.end();r_itr++)
				{
					vector<int>::iterator ir = zeroes[i].end()-1-count;
					printf("%d %d %d %d\n",(*r_itr).first.first,(*r_itr).first.second,*ir,i );
					int temp = abs(i- (*r_itr).first.first)+abs(*(ir) - (*r_itr).first.second);
					// printf("%d\n",temp );
					if(temp<=k2 && temp!=0)
					{
						pair< pair<int , int> , int> tr;
						pair<int,int> tr1;
						tr1.first=i;
						tr1.second= *(ir);
						tr.first=tr1;
						tr.second= (*r_itr).second+1;
						r2.push_back(tr);
						// printf("%d\n", (*r_itr).second+1 );
						if(find(sums.begin(), sums.end() , i+ *(ir))!=sums.end())
						{
							printf("sat\n");
							if(min>(tr.second))
							{
								min=tr.second;
								done=1;
							}
						}
						pts2++;
						break;
					}
				}
				count++;
			}
			
			}

			if(done)
			{
				break;

			}
			i++;
		
		if(done)
			printf("%d\n",min );
		else
		{
			vector< pair< pair<int , int> , int> > target;
			if(k1==0 && k2!=0)
				target=r2;
			else if(k2==0 && k1!=0)
				target=r1;
			else if(k1==0 && k2==0)
				printf("-1\n");
			else printf("-1\n");

			int req_val=0;
			bool done1=0;
			if((k1==0 || k2==0) && !(k1==0 && k2==0))
			{
				int km = (k1==0)?k2:k1;
				for(i=n-1;i>=0;i--)
				{
					int count=0;
					// printf("%d\n",i );
					for(vector<int>::iterator k=zeroes[i].begin();k!=zeroes[i].end();k++)
					{
						vector< pair< pair<int , int> , int> >::iterator itr;
						vector<int>::iterator ir = (k1==0)?(zeroes[i].end()-1-count):k;
						// printf("H\n");
						for(itr=target.begin();itr!=target.end();itr++)
						{
							// printf("%d\n",target.size() );
							// printf("%d %d\n",(*itr).first.first,(*itr).first.second );
							int temp= abs(i- (*itr).first.first)+abs((*ir) - (*itr).first.second);
							// printf("%d %d %d \n",*ir , temp , (*itr).second );
							if(temp<=km && temp!=0)
							{
								pair< pair<int , int> , int> tr;
								pair<int,int> tr1;
								tr1.first=i;
								tr1.second= *(ir);
								tr.first=tr1;
								tr.second= (*itr).second+1;
								target.push_back(tr);
								// printf("sat\n");
								// printf("%d %d\n",tr1.first==0 , tr1.second );
								int sec = (k1==0)?0:m-1;
								if((tr1.first==0) && (tr1.second==sec))
								{
									done1=1;
									// printf("Here\n");
									req_val=tr.second;

								}
								break;
							}
						}
						count++;
						if(done1)break;
					}
					if(done1)break;
				}
				if(done1)printf("%d\n",req_val );
				else printf("-1\n");
			}
		}
	}
	return 0;
}