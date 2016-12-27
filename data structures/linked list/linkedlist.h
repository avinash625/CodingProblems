 //linked list structure definition
typedef struct LinkedList{
	int data;
	struct LinkedList *next;
}Node;

//linked list methods signatures
Node *createLinkedList();
Node *createNode(int data);
void printLinkedList(Node *head);
int medianValue(Node *head);
Node *medianNode(Node *head);
