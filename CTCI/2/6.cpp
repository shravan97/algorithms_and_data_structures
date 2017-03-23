#include <bits/stdc++.h>
#define nl NULL
using namespace std;
typedef long long int ll;

struct node
{
	int data;
	node * next;
};

void display(node * head)
{
	while(head)
	{
		cout<<head->data<<' ';
		head=head->next;
	}
	cout<<endl;
}

node * insert(node * head,int data)
{
	node * newNode = new node;
	newNode->data=data;
	newNode->next=head;
	return newNode;

}

node * findLoop(node * head)
{
	std::map<node * , bool> chck;
	while(head)
	{
		if(chck[head])
			break;
		chck[head]=1;
		head=head->next;
	}

	return head;
}

node * findLoop1(node * head)
{
	if(head==NULL)
		return NULL;

	node * ptr = head, * ptr2=head->next->next;
	while(ptr!=ptr2)
	{
		// cout<<ptr->data<<' '<<ptr2->data<<endl;
		ptr=ptr->next;
		ptr2=ptr2->next->next;
	}
	// cout<<ptr->data<<endl;
	// return head;
	node * curr=head;
	while(curr!=ptr2)
	{
		cout<<curr->data<<' '<<ptr2->data<<endl;
		curr=curr->next;
		ptr2=ptr2->next;
	}

	return ptr2;

}

node * link (node * head,node * n)
{
	node * curr=head;
	while(head)
	{
		if(head->next==NULL)
			break;
		head=head->next;
	}
	head->next = n;
	return curr;
}

int main(int argc, char const *argv[])
{
	node * head =NULL;
	head= insert(head,5);
	head= insert(head,4);
	head= insert(head,2);
	head= insert(head,4);
	node * loop = head;
	head= insert(head,1);
	head=link(head,loop);
	node * find = findLoop1(head);
	cout<<find->data<<endl;
	// display(head);
	
	/*
	1->4->2->4->5--
		     |_____|
	*/

	return 0;
}
