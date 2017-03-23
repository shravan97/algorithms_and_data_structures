#include <bits/stdc++.h>
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

node * added(node * head1,node * head2)
{
	ll n1=0,n2=0,c=0;
	while(head1)
	{
		// cout<<"here 1 \n";
		n1=n1+(head1->data)*pow(10,c++);
		head1=head1->next;
	}
	c=0;
	while(head2)
	{
		// cout<<"here 2\n";
		n2=n2+(head2->data)*pow(10,c++);
		head2=head2->next;
	}
	node * head= NULL;
	ll num=n1+n2;
	cout<<n1<<' '<<n2<<endl;

	while(num>0)
	{
		head=insert(head,num%10);
		num/=10;
	}

	return head;

	
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
	
	node * head1=new node;
	head1->data=5;
	head1->next = new node;
	head1->next->data=1;
	head1->next->next = new node;
	head1->next->next->data=1;
	head1->next->next->next = new node;
	head1->next->next->next->data=4;
	head1->next->next->next->next = new node;
	head1->next->next->next->next->data=2;
	head1->next->next->next->next->next = NULL;
	
	display(added(head,head1));

	return 0;
}
