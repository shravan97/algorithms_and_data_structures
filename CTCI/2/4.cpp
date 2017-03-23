#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
	int data;
	node * next;
};
node * partition(node * head, int x)
{
	node * plow=NULL, * phigh=NULL, * hstart=NULL;
	node * curr=head,*prev=NULL;

	// 5 6 2 1 7 

	while(curr!=NULL)
	{
		if(curr->data<x)
		{
			if(plow==NULL)
			{
				plow=curr;
				prev=curr;
				curr=curr->next;
			}
			else if(prev!=plow)
			{
				prev->next = curr->next;
				curr->next=plow->next;
				plow->next=curr;
				plow=curr;
				curr=prev->next;
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}
		else if(curr->data > x)
		{
			if(phigh==NULL)
			{
				phigh=curr;
				prev=curr;
				curr=curr->next;
				hstart=phigh;
			}
			else if(prev!=phigh)
			{
				prev->next = curr->next;
				curr->next=phigh->next;
				phigh->next=curr;
				phigh=curr;
				curr=prev->next;
			}
			else
			{
				phigh=curr;
				prev=curr;
				curr=curr->next;
			}
		}
		else
		{
			prev=curr;
			curr=curr->next;
		}


	}

	// plow->next=hstart;

	return head;
}

void display(node * head)
{
	while(head)
	{
		cout<<head->data<<' ';
		head=head->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	node * head=new node;
	head->data=4;
	head->next = new node;
	head->next->data=5;
	head->next->next = new node;
	head->next->next->data=1;
	head->next->next->next = new node;
	head->next->next->next->data=4;
	head->next->next->next->next = new node;
	head->next->next->next->next->data=2;
	head->next->next->next->next->next = NULL;
	// head->next->next->next->next->data=7;
	
	// head->next = new node;
	// head->next->data=6;
	display(head);
	
	head = partition(head,4);

	display(head);
	return 0;
}
