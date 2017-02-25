#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
using namespace std;

typedef struct TrieNode{
	char data;
	bool isEnd;
	struct TrieNode *children[26];
}Trie;
bool searchNode(Trie *head , char *input){
	int length = strlen(input);
	Trie *temp = head;
	int iter;
	for (iter = 0; iter < length; iter++){
		if (temp->children[input[iter] - 'a'] == NULL)
			return false;
		temp = temp->children[input[iter] - 'a'];
	}
	if (temp->isEnd == true)
		return true;
	return false;
}
Trie *createNode(){
	Trie *newNode = NULL;
	newNode = (Trie *)malloc(sizeof(Trie));
	if (newNode){
		newNode->isEnd = false;
		for (int iter = 0; iter < 26; iter++){
			newNode->children[iter] = NULL;
		}
	}
	return newNode;
}
void TrieInsert(Trie *trieHead, char *input){
	int length = strlen(input);

	Trie *temp = trieHead;
	int iter;
	for ( iter = 0; iter < length; iter++){
		if (temp->children[input[iter] - 'a'] == NULL){
			temp->children[input[iter] - 'a'] = createNode();
		}
		temp = temp->children[input[iter] - 'a'];
	}
	temp->isEnd = true;
}


int main(void){
	int t;
	cin >> t;
	char inputString[100];
	Trie *TrieHead = createNode();
	while (t--){
		int n;
		cin >> n;
		for (int iter = 0; iter < n; iter++){
			cin >> inputString;
			TrieInsert(TrieHead, inputString);
		}
		cin>>inputString;
		if(searchNode(TrieHead,inputString))
		    cout<<1<<endl;
		else
		    cout<<0<<endl;
	}
	
}