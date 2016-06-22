#include <iostream>
#include <cstdio>
using namespace std;

struct node
{
	int data;
	node * link;
};

node * insert(node * head)
{
	int num;
	node * temp = new node;
	cout<<"Enter the data : ";
	cin>>num;

	temp->data = num;

	temp->link = head;
	head=temp;

	return head;

}

node * reverse(node * head)
{// 1 -> 2 -> 3 -> 4
	node * prev=NULL ,* next=head,* temp=head; 
	while(next!=NULL)
	{
		next = temp->link;
		temp->link = prev;
		prev = temp;
		temp = next;
	}

	return prev;
}

void print_list(node * head)
{
	node * temp = head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<' ';
		temp= temp->link;
	}
	delete temp;
}

int main(int argc, char const *argv[])
{
	int num;
	node * head = NULL;
	head=insert(head);
	head=insert(head);
	head=insert(head);
	head=insert(head);
	head=reverse(head);
	print_list(head);
	return 0;
}