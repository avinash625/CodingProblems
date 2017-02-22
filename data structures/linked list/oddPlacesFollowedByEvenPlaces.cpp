void rearrange(struct node *head)
{
	struct node *even = NULL, *temp = head, *nextNode,*prev;
    if(!head || !(head->next) || !(head->next->next))
        return;
	while (temp && temp->next){
		if (!even){
			even = temp->next;
			temp->next = temp->next->next;
			temp = temp->next;
			even->next = NULL;
		}
		else{
			nextNode = temp->next;
			prev = temp;
			temp->next = temp->next->next;
			nextNode->next = even;
			even = nextNode;
			temp = temp->next;
		}
	}
	if (temp)
		temp->next = even;
	else
		prev->next = even;
}
