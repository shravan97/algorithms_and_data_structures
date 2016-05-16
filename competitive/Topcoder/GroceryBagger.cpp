#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class 	GroceryBagger
{
public:
	int minimumBags(int strength , string itemType[50])
	{
		int bags=0;
		int no_strings = sizeof(itemType)/sizeof(itemType[0]);
		std::vector<string> v;
		std::vector<int> freq;

		for(int i=0;i<no_strings;i++)
		{
			bool flag=0;
			std::vector<string>::iterator it;
			if(!v.empty())
			{
				for (it = v.begin(); it != v.end(); ++it)
				{
					if(v[*it] == itemType[i])
					{
						flag=1;
						break;
					}
				}
			}		

			if(!flag)
			{
				int fr=0;
				for(int j=i;j<no_strings;j++)
				{
					if(itemType[i]==itemType[j])
						fr++;
				}
				v.push_back(itemType[i]);
				freq.push_back(fr);
			}
		}

		std::vector<int>::iterator it_f;

		for(it_f=freq.begin();it_f!=freq.end();it_f++)
		{
			bags+=(freq[*it_f]/m)+((freq[*it_f]) % m);
		}

		return bags;
	}
};

int main()
{
	return 0;
}