#include <bits/stdc++.h>
using namespace std;

struct activity
{
	long long int start,end;
};

struct act_compare
{
	bool operator()(const activity &act1 , const activity &act2)
	{
		return act1.end > act2.end;
	}
};

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		priority_queue< activity , std::vector<activity> , act_compare > act_q;
		long long int n,i;
		cin>>n;

		for(i=0;i<n;i++)
		{
			activity a;
			cin>>a.start>>a.end;
			act_q.push(a);
		}

		long long int max_end=0,num_acts=0;

		while(!act_q.empty())
		{
			activity it = act_q.top();
			act_q.pop();
			if(it.start>=max_end)
			{
				num_acts++;
				max_end = it.end;
			}
		}
		cout<<num_acts<<'\n';

	}
	return 0;
}