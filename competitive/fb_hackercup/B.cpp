#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;

	ofstream ofile;
	ofile.open("op.txt",ios::out);

	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int n;

		cin>>n;
		vector<int> w;

		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			w.push_back(k);
		}

		sort(w.begin(), w.end());

		queue<int> q;

		for(auto e:w)
			q.push(e);

		int trips=0;
		int rt=w.size()-1,lt=0;

		while(rt>=lt)
		{
			int cur=w[rt],s=w[rt];

			cout<<w[rt]<<' ';

			while(s<50 && lt<rt)
			{
				s+=w[rt];
				cout<<w[lt]<<' ';
				lt++;
			}

			if(s<50)
			{
				break;
			}

			cout<<endl;

			rt--;
			trips++;

		}

		cout<<"Case #"<<j<<": "<<trips<<endl;
		
	}
	return 0;
}
/*
15
-92
40
-5
-48
-70
-54
-47
-64
-10
35
44
-85
-46
-23
-44

*/