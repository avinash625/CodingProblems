void InsertDuplicates(Node *head) {
	Node *temp = head;
	Node *t;
	while (temp) {
		t = newNode(temp->data);
		t->next = temp->next;
		temp->next = t;
		temp = temp->next->next;
	}
}
Node * copyList(Node *head)
{
	Node *temp = head;
	InsertDuplicates(head);
	Node *newHead = temp->next;
	while (temp) {
		if (!temp->next)
			break;
		if (temp->arb)
			temp->next->arb = temp->arb->next;
		else
			temp->next->arb = NULL;
		if (temp->next)
			temp = temp->next->next;
	}
	temp = head;
	Node *t;
	t = temp->next;
	while (temp) {
		if (t->next) {
			temp->next = temp->next->next;
			t->next = temp->next->next;
		}
		else {
			temp->next = NULL;
			t->next = NULL;
			break;
		}
		temp = temp->next;
		t = t->next;
		//temp = temp->next->next;
	}
	return newHead;
}
