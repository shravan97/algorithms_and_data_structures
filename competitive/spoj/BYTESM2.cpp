#include <bits/stdc++.h>
#define max(a,b)((a>b)?a:b)
using namespace std;
typedef long long int ll; 
int a[101][101];
std::map<int , ll > mem[101];
// long long int dp(int r ,int col , int rmax , int colmax)
// {
// 	if(col<0)return 0;
// 	if(col>=colmax) return 0;
// 	if(r==rmax)
// 	{
// 		mem[rmax][col]=a[rmax][col];
// 		return a[rmax][col];
// 	}
// 	long long int s1,s2,s3;
// 	if(mem[r+1][col]!=0)
// 		s1=mem[r+1][col]+a[r][col];
// 	else 
// 	{
// 		s1 = dp(r+1,col,rmax,colmax);
// 		// cout<<" with "<<r<<' '<<col<<" and "<<r+1<<' '<<col<<' '<<s1<<endl;
// 		s1+=a[r][col];
// 		// cout<<" with "<<r<<' '<<col<<" and2 "<<r+1<<' '<<col<<' '<<s1<<endl;
// 	}
// 	if(mem[r+1][col-1]!=0)
// 		s2=mem[r+1][col-1]+a[r][col];
// 	else
// 	{
// 		s2 = dp(r+1,col-1,rmax,colmax);
// 		// cout<<" with "<<r<<' '<<col<<" and "<<r+1<<' '<<col-1<<' '<<s2<<endl;
// 		// m[r+1][col-1]=s2;
// 		s2+=a[r][col];
// 		// cout<<" with "<<r<<' '<<col<<" and2 "<<r+1<<' '<<col-1<<' '<<s2<<endl;
// 	}
// 	if(mem[r+1][col+1]!=0)
// 		s3=mem[r+1][col+1]+a[r][col];
// 	else
// 	{
// 		s3 = dp(r+1,col+1,rmax,colmax);
// 		// cout<<" with "<<r<<' '<<col<<" and "<<r+1<<' '<<col+1<<' '<<s3<<endl;
// 		// m[r+1][col+1]=s3;
// 		s3+=a[r][col];
// 		// cout<<" with "<<r<<' '<<col<<" and2 "<<r+1<<' '<<col+1<<' '<<s3<<endl;
// 	}
	
// 	// cout<<" with "<<r<<' '<<col<<" and "<<r+1<<' '<<col<<' '<<s1<<endl;
// 	// cout<<" with "<<r<<' '<<col<<" and "<<r+1<<' '<<col-1<<' '<<s2<<endl;
// 	// cout<<" with "<<r<<' '<<col<<" and "<<r+1<<' '<<col+1<<' '<<s3<<endl;

// 	// for(i=0;i<c;i++)
// 	// {
// 	// 	long long int itr = dp(r+1,c,s+a[r][i],rmax);
// 	// 	if(itr>max)
// 	// 		max=itr;
// 	// }
// 	mem[r][col] = max(max(s1,s2),s3);
// 	return max(max(s1,s2),s3);
// }

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,i;
		cin>>n>>m;
		for(i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
			}

		// cout<<" max : "<<max_ind<<endl;

		ll val=0;
		for(i=n-2;i>=0;i--)
		{
			// ll k=dp(0,i,n-1,m);
			// if(k>val)
			// 	val=k;
			for(int j=0;j<m;j++)
			{
				if(j==0)
				{
					if(j!=m-1)
						a[i][j]+= max(a[i+1][0],a[i+1][1]);
					else a[i][j]+= a[i+1][0];
				}
				else if(j!=m-1)
					a[i][j]+=max(a[i+1][j+1],max(a[i+1][j-1],a[i+1][j]));
				else a[i][j]+=max(a[i+1][j-1],a[i+1][j]);
			}
		}

		// ll val=0;
		for(i=0;i<m;i++)
			if(val<a[0][i])
				val=a[0][i];

		// std::map<int , ll >::iterator it;
		// for(i=0;i<n;i++)
		// 	for(it=mem[i].begin();it!=mem[i].end();it++)
		// 	{
		// 		cout<<" val of "<<i<<' '<<it->first<<" : "<<it->second<<endl;
		// 	}

		cout<<val<<endl;

	}
	return 0;
}