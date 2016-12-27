#include"linkedlist.h"
#include<iostream>
using namespace std;

//utility method to create a node with specified value
Node *createNode(int data){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//method to create a linked list 
Node *createLinkedList(){
	int n;
	cin >> n;
	int *values = (int *)malloc(sizeof(int)*n);
	for (int iter = 0; iter < n; iter++){
		scanf("%d", &values[iter]);
	}
	Node *head = createNode(values[0]);
	Node *temp = head;
	for (int iter = 1; iter < n; iter++){
		temp->next = createNode(values[iter]);
		temp = temp->next;
	}
	free(values);
	return head;
}

void printLinkedList(Node *head){
	Node *temp = head;
	while (temp){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int medianValue(Node *head){
	Node *slow = head; 
	Node *fast = head;
	if (!head){
		return -1;
	}
	while (fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

Node *medianNode(Node *head){
	if (!head)
		return NULL;
	Node *slow = head;
	Node *fast = head;
	while (fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}