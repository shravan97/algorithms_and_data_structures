int kthFromLast(node * head, int k)
{
	// 2->4->56->6->NULL
	/*
		> Initialize a pointer and make it traverse first k+1 elements
		> Initialize another pointer and make it point to the first element
		> Traverse elements one by one with each of the node pointers and the just print 	
   Element that the first pointer is pointing to 
	*/
	int count=0;
	node * p1=head; 
	while(count!=k+1 && p1!=NULL)
	{
		p1=p1->next;
		count++;
	}

	if(count!=k+1)
		return -1;
	
	node * p2=head;


	while(p1)
	{
		p1=p1->next;
		p2=p2->next;
	}
	
	return p2->data;
}
