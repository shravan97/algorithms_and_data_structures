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

node * del(node * head , int pos)
{
	node * temp = head,* prev=NULL;
	int count=0;

	while(temp!=NULL && count!=pos)
	{
		if(count==pos-1)
		{
			if(count!=0)
			{
				node * next = temp->link;
				prev->link = next;
			}
			else
				head= head->link;
			delete temp;
			return head;
			
		}
		prev = temp;
		temp = temp->link;
		count++;
	}
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
	head=del(head,3);
	print_list(head);
	return 0;
}