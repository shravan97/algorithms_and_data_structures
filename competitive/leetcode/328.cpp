#include <cstdio>
struct node
{
	int x;
	node * link;
};
void print_list(node * head)
{
	node * curr = head;
	while(curr!=NULL)
	{
		printf("%d ",curr->x );
		curr = curr->link;
	}

}

node * odd_even(node * head)
{
	if(head->link==NULL || head==NULL) return head;

	node * curr = head;
	node * odd_ptr = head;
	node * even_ptr = head->link;
	curr = even_ptr->link;
	bool val=1;
	node * prev = even_ptr;

	while(curr!=NULL)
	{
		node * temp = curr;
		curr = curr->link;
		if(val)
		{
			prev->link = temp->link;
			temp->link = odd_ptr->link;
			odd_ptr->link = temp;
			odd_ptr = temp;
		}
		else
		{
			even_ptr = even_ptr->link;
			prev = even_ptr;
		}

		val=!val;
	}

	return head;
}

int main(int argc, char const *argv[])
{
	node * head=new node;
	head->x=1;
	head->link=NULL;
	node * prev = head;
	for(int i=2;i<=12;i++)
	{
		node * temp = new node;
		temp -> x = i;
		temp -> link = NULL;
		prev->link = temp;
		prev = temp;
	}

	head = odd_even(head);
	print_list(head);

	return 0;
}