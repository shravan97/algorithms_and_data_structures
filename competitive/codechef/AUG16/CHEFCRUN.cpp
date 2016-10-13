#include <iostream>
#include <vector>
#define min(a,b)((a<b)?a:b)
using namespace std;
typedef long long int ll;

ll max_subarray(vector<ll> &a,ll size)
{
	ll max_so_far=0 ,i, max=a[0] ,max_this=0;
	for(i=0;i<size;i++)
	{
		if(max>a[i])max=a[i];
		if(max_this+a[i]>0)
			max_this=max_this+a[i];
		else max_this=0;

		if(max_this>max_so_far)
			max_so_far=max_this;
	}
	if(max_so_far==0)
		return max;
	return max_so_far;
}
int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,i,st,end;
		cin>>n;

		vector <ll> g(n);
		// cout<<"arr : \n";
		for(i=0;i<n;i++)
		{
			cin>>g[i];
			// cout<<i<<" : "<<g[i]<<'\n';
		}
		cin>>st>>end;

		if(n==2)
		{
			if(st==1)
				cout<<min(min(g[0],g[1]),min((2*g[0]+g[1]),(g[0]+2*g[1])))<<'\n';
			continue;
		}

		std::vector<ll> fwd;
		ll fsize=0,bsize=0;
		std::vector<ll> bwd;
		ll count=0,max1=g[st-1],max_ind1=st-1,max_index1 = 0;
		ll fw=0,fw1=0,fw_min=0,fw_min_index=st-1;
		ll bw=0,bw1=0,bw_min=0,bw_min_index=(st==1)?n-1:(st-2);

		// cout<<"fwd vec : ";
		for(i=st-1;i<end-1;i++)
		{
			if(g[i]>max1)
			{
				max1=g[i];
				max_index1=fsize;
				max_ind1=i;
			}
			fwd.push_back(g[i]);
			fw+=g[i];
			// cout<<g[i]<<' ';
			fsize++;
		}

		// cout<<"\nBwd vec : ";
		count=0;
		ll ind=((st-2)<0)?n-1:st-2,max2=g[ind],max_ind2=ind,max_index2 = 0;
		for(i=st-2;i>=0;i--)
		{
			// cout<<g[i]<<' ';
			
			bwd.push_back(g[i]);
			bw+=g[i];
			bsize++;
			// ind=((i<0)?n+i:i);

		}
		for(i=n-1;i>=end-1;i--)
		{
			bwd.push_back(g[i]);
			// cout<<g[i]<<' ';
			bw+=g[i];
			bsize++;
		}
		
		ll m1 = max_subarray(fwd,fsize), m2= max_subarray(bwd,bsize);

		if(m1<0)
			m1=0;
		if(m2<0)
			m2=0;

		cout<<min(2*fw+bw-2*m1,fw+2*bw-2*m2)<<'\n';
	}
	return 0;
}