 //linked list structure definition
typedef struct LinkedList{
	int data;
	struct LinkedList *next;
}Node;

//all the methods signatures
bool pair_with_sum_k(int *values, int n, int sum);
bool tuple_with_sum_k(int *values, int n, int sum);
int comparator(const void *a, const void *b);//util method used for the default qsort.
int number_repeated_odd_number_of_times(int *values, int n);

//linked list methods signatures
Node *createLinkedList();
Node *createNode(int data);
void printLinkedList(Node *head);
int medianValue(Node *head);
Node *medianNode(Node *head);