#include <bits/stdc++.h>
using namespace std;

// bool chck(std::map< int  , std::map<int, bool> > & graph , vector<int> g1 , vector<int> g2 , int v , int tot)
// {
// 	bool flag1=1,flag2=1;
// 	vector<int>::iterator it;

// 	// cout<<" State : \n";
// 	// cout<<" t1 : \n";

// 	for(it=g1.begin();it!=g1.end();it++)
// 	{
// 		// cout<<*it<<endl;
// 		if(graph[v][*it]==0)
// 		{
// 			flag1=0;
// 			break;
// 		}
// 	}

// 	// cout<<" t2 : \n";

// 	for(it=g2.begin();it!=g2.end();it++)
// 	{
// 		// cout<<*it<<endl;
// 		if(graph[v][*it]==0)
// 		{
// 			flag2=0;
// 			break;
// 		}
// 	}

// 	if(v==tot)
// 	{
// 		// cout<<" final : "<<flag1<<' '<<flag2<<endl;
// 		if(flag1==0&&flag2==0)
// 		{
// 			return 0;
// 		}
// 		else return 1;
// 	}

// 	if(flag1==0 && flag2==0)
// 	{
// 		return 0;
// 	}
// 	if(flag1&&flag2==0)
// 	{
// 		g1.push_back(v);
// 		return chck(graph,g1,g2,v+1,tot);
// 	}
// 	if(flag2&&flag1==0)
// 	{
// 		g2.push_back(v);
// 		return chck(graph,g1,g2,v+1,tot);
// 	}
// 	if(flag2&&flag1)
// 	{
// 		if(g1.empty() && g2.empty())
// 		{
// 			g1.push_back(v);
// 			return chck(graph,g1,g2,v+1,tot);
// 		}
// 		g1.push_back(v);
// 		bool res = chck(graph,g1,g2,v+1,tot);
// 		if(res)return 1;
// 		g1.erase(g1.end()-1);
// 		g2.push_back(v);
// 		return chck(graph,g1,g2,v+1,tot);
// 	}
// }

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long int m,num=0,t1=1,t2=0;
		cin>>n>>m;
		std::map< int  , std::map<int, bool> > graph;
		int tb[n+1][2];
		tb[1][0]=1;
		tb[1][1]=-1;


		for(long int j=0;j<m;j++)
		{
			int a,b;
			cin>>a>>b;
			graph[a][b]=1;
			graph[b][a]=1;
		}
		vector<int> g1;
		vector<int> g2;
		bool flag=0;

		// for(long int i=2;i<=n;i++)
		// {
		// 	tb[i][0]=tb[i][1]=0;
		// 	for(long int j=1;j<i;j++)
		// 	{
		// 		if(tb[j][0]==-1 && tb[j][1]==1 && graph[i][j]==0)
		// 		{
		// 			// cout<<" for "<<i<<' '<<j<<" c1\n";
		// 			tb[i][1]=-1;
		// 		}
		// 		else if(tb[j][0]==1 && tb[j][1]==-1 && graph[i][j]==0)
		// 		{
		// 			// cout<<" for "<<i<<' '<<j<<" c2\n";
		// 			tb[i][0]=-1;
		// 		}
		// 		else if(tb[j][0]==1 && tb[j][1]==1 && graph[i][j]==0)
		// 		{
		// 			t1++;
		// 			t2++;
		// 		}

		// 	}
		// 	if(tb[i][0]==-1 && tb[i][1]==-1)
		// 	{
		// 		num++;
		// 	}
		// 	if(tb[i][0]==0)tb[i][0]=1;
		// 	if(tb[i][1]==0)tb[i][1]=1;
		// 	if(tb[i][0]==1 && tb[i][1]==-1)t1++;
		// 	else if(tb[i][0]==-1 && tb[i][1]==1)t2++;
		// }

		// for(long int i=1;i<=n;i++)
			// cout<<tb[i][0]<<' '<<tb[i][1]<<endl;

		// if(num>1)
		// 	cout<<"NO\n";
		// else if(num==1 && t1!=0 && t2!=0)cout<<"NO\n";
		// else if(num==1 && (t1==0 || t2==0))cout<<"YES\n";
		// else cout<<"YES\n";


		// for(int i=0;i<n;i++)
		// {
		// 	for(long int k=0;k<i;k++)
		// 	{
				
		// 	}
		// }
		
		if(chck(graph,g1,g2,1,n)==1)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}