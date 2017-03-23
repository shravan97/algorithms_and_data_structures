#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void remove_duplicates(node *  &head)
{
	map <int,bool> chck;
	
	//Checking for the corner cases
	if(head==NULL || head->next==NULL)
		return;


	chck[head->data]=1;
	chck[head->next->data]=1;
	head=head->next->next;


	while(head)
	{
		if(chck[head->data])
		{
			prev->next = head->next;
		}
		else
			prev=head;
head=head->next;
	}
}


int main(int argc, char const *argv[])
{
	
	return 0;
}
