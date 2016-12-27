#include"linkedlist.h"

Node * Kth_Node_from_last(Node *head, int k){
	Node *temp = head;
	for (int iter = 0; iter < k; iter++){
		temp = temp->next;
	}
	Node *result = head;
	while (temp){
		result = result->next;
		temp = temp->next;
	}
	return result;
}