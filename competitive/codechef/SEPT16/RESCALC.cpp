#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,score=0,w_ind=0;
		bool istie=0;
		cin>>n;
		std::map<int, bool> pt;

		for(int i=0;i<n;i++)
		{
			int sz,typ=0,pts=0;
			int freq[7];
			for(int b=1;b<7;b++)
				freq[b]=0;
			cin>>sz;
			// cout<<" sz : "<<sz<<endl;
			for(int j=0;j<sz;j++)
			{
				int z;
				cin>>z;
				if(freq[z]==0)typ++;
				freq[z]++;
				// cout<<" freq of  "<<z<<' '<<freq[z]<<endl;
			}
			pts=sz;
			// cout<<" types for "<<i<<' '<<typ<<endl;
			int tot=0;
			if(typ>=4)
			{
				while(typ>=4)
				{
					int min=INT_MAX,m_ind=0,num=0;
					bool flag=0;
					for(int x=1;x<7;x++)
					{
						if(freq[x]-tot>0)num++;
						if(freq[x]-tot<min && freq[x]-tot>0)
						{
							min=freq[x]-tot;
							m_ind=x;
							flag=1;
							// cout<<" here for : "<<x<<' '<<min<<' '<<typ<<endl;
						}
						// else if(freq[x]-tot==0 && tot!=0)
						// {
						// 	flag=0;
						// 	min=0;
						// 	break;
						// }
					}
					// cout<<" freq for "<<i<<' '<<min<<endl;
					if(num<4)break;
					if(!flag) break;
					tot+=min;
					typ=num;
					if(typ==6)
						pts+=min*4;
					else if(typ==5)
						pts+=min*2;
					else pts+=min;
					freq[m_ind]=0;
					typ--;

				}
			}
			// cout<<" pts for "<<i<<' '<<pts<<endl;
			if(pts>score)
			{
				score=pts;
				w_ind=i;
				pt[pts]=1;
				istie=0;
			}
			else if(pts==score && pt[pts]==1)
				istie=1;
			// else pt[pts]=1;

		}
		if(istie)
			cout<<"tie\n";
		else if(w_ind==0)
			cout<<"chef\n";
		else
			cout<<w_ind+1<<'\n';
	}
	return 0;
}