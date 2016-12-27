#include"linkedlist.h"
#include<iostream>

using namespace std;

void Kth_Node_from_last_util(Node *head){
	int k;
	cout << "Enter the value of K\n" << endl;
	cin >> k;
	Node *result = Kth_Node_from_last(head, k);
	printf("Tte Value of the Kth Node from last is %d\n", result->data);
}

void main(void){
	Node * head = NULL;
	head = createLinkedList();
	printLinkedList(head);
	Kth_Node_from_last_util(head);
}