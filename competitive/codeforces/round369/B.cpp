#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int i,j;
	ll rs=0,tot=0,reqd_rs=0,diag=0,diag1=0,col[n],r_col=0;
	for(i=0;i<n;i++)col[i]=0;
	ll n1;
	bool flag=0,m=1,chck_diag=0 , chck_diag1=0;
	for(i=0;i<n;i++)
	{
		ll rs1=0;
		for(j=0;j<n;j++)
		{
			ll k;
			cin>>k;
			if(n==1)n1=k;
			if(k==0)
			{
				if(i+j==n-1)
					chck_diag1=1;
				if(i==j)
					chck_diag=1;
				flag=1;
				r_col=j;
			}
			tot+=k;
			rs1+=k;
			if(i+j==n-1)
				diag1+=k;
			if(i==j)
				diag+=k;

			col[j]+=k;
		}
		if(!flag)
		{
			if(rs!=0)
			{
				if(rs!=rs1)
				{
					m=0;
				}
			}
			else rs=rs1;
		}
		else
		{ 
			reqd_rs=rs1;
			flag=0;
		}
	}
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	if((tot-reqd_rs)%(n-1)!=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(!chck_diag && !chck_diag1)
	{
		if(diag!=(tot-reqd_rs)/(n-1))
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	// cout<<rs<<' '<<reqd_rs<<' '<<chck_diag<<' '<<chck_diag1<<' '<<diag<<' '<<diag1<<endl;
	ll chck_col;
	// cout<<" r "<<r_col<<endl;

	for(i=0;i<n;i++)
	{

		// cout<<col[i]<<'\n';
		if(i!=r_col && i!=0)
		{
			if(col[i]!=chck_col)
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		else if(i==0 && i!=r_col)
			chck_col=col[0];
		else if(i==0 && i==r_col)
			chck_col=col[i+1];
		// cout<<chck_col<<endl;
	}
	
	ll col_sum=(r_col==0)?col[1]:col[0];
	// cout<<col_sum<<endl;
	if(rs!=chck_col)
	{
		cout<<-1<<endl;
		return 0;
	}
	else if(chck_diag && !chck_diag1)
	{
		if(rs!=diag1)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	else if(chck_diag1 && !chck_diag)
	{
		if(rs!=diag)
		{
			cout<<-1<<endl;
			return 0;
		}
	}

	if(m)
	{
		if(chck_diag && !chck_diag1)
			if(diag1-diag==rs-reqd_rs && rs-reqd_rs==col_sum-col[r_col] )
			{
				if(rs-reqd_rs<=0)
				{
					cout<<-1<<endl;
					return 0;
				}
				cout<<rs-reqd_rs<<endl;
			}
			else
			{
				cout<<-1<<endl;
				return 0;
			}
		else if(!chck_diag && chck_diag1)
			if(diag-diag1==rs-reqd_rs && rs-reqd_rs==col_sum-col[r_col])
			{
				if(rs-reqd_rs<=0)
				{
					cout<<-1<<endl;
					return 0;
				}
				cout<<rs-reqd_rs<<endl;
			}
			else
			{ 
				cout<<-1<<endl;
				return 0;
			}
		else if(chck_diag && chck_diag1)
			if(diag==diag1 && rs-reqd_rs==col_sum-col[r_col])
			{
				if(rs-reqd_rs<=0)
				{
					cout<<-1<<endl;
					return 0;
				}
				cout<<rs-reqd_rs<<endl;
			}
			else
			{ 
				cout<<-1<<endl;
				return 0;
			}
		else if(!chck_diag1 && !chck_diag)
			if(diag==diag1 && rs-reqd_rs==col_sum-col[r_col])
			{
				if(rs-reqd_rs<=0)
				{
					cout<<-1<<endl;
					return 0;
				}
				cout<<rs-reqd_rs<<endl;
			}
			else
			{
			 	// cout<<diag<<' '<<diag1<<endl;
				cout<<-1<<endl;
				return 0;
			}

	}
	else cout<<-1<<endl;
	return 0;
}