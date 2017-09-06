/*
 * File name: lab1p5.c
 * Author: Linyong Nan; Zichang Liu
 * Date: Feb 12, 2017
 * Description: This program reads arguments and store each word in a node in a linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create a structure "Linkedlist" that contains a member "head"
struct Linkedlist{
	struct Node* head;		//a pointer to node structure
};

//create a structure "Node" that contains data and next
struct Node{
	char* data;				//a char pointer
	struct Node* next;		//a pointer to node structure
};

//function prototypes
void insertAtBeginning(struct Linkedlist* LL, char ele[]);
void insertAtTheEnd(struct Linkedlist* LL, char ele[]);
void deleteNode(struct Linkedlist* LL, char ele[]);
int findNode(struct Linkedlist LL, char ele[]);
void displayLinkedList(struct Linkedlist LL);

int main(int argc, char *argv[]){
	//Error handling: when there is no argument
	if(argc == 1){
		printf("ERROR: The program must read at least an argument.");
	}
	else{
		//initialize Linked list and the head
		struct Linkedlist LL;
		struct Linkedlist* ptrLL;
		ptrLL = &LL;
		ptrLL -> head = NULL;


		int index = 1;
		for (index; index < argc; index++){
    		//If the word exist, delete it first before insert.
			if(findNode(LL, argv[index]) == 1){
				deleteNode(ptrLL, argv[index]);
			}else{
				//Insert words that start with upper-case letter at beginning.
				if((argv[index][0] > 64) && (argv[index][0] < 91)){
				    insertAtBeginning(ptrLL, argv[index]);
				}
				//Insert words that start with lower-case letter at the end.
				else{
				    insertAtTheEnd(ptrLL, argv[index]);
				}
			}
		}
		//display the linked list.
		displayLinkedList(*ptrLL);
	}

	return 0;
}



/*
 * insertAtBeginning takes a pointer to Linkedlist LL and string ele.
 * Allocates a node using malloc() then insert at the beginning.
 */
void insertAtBeginning(struct Linkedlist* LL, char ele[]){
	//declare and allocate a node structure
    struct Node *newNode;
   	newNode = malloc(sizeof(struct Node));
   	//allocate the string and store it in data.
   	newNode -> data = malloc(strlen(ele));
   	strcpy(newNode -> data, ele);
   	//when LL is an empty linked list
   	if(LL -> head == NULL){
   		LL -> head = newNode;
   		newNode -> next = NULL;
   	}else{
   		newNode-> next =LL ->head;
   		LL ->head = newNode;
   	}
}


/*
 * insertAtTheEnd takes a pointer to Linkedlist LL and a string ele.
 * Allocates a node using malloc() then insert at the end
 */
void insertAtTheEnd(struct Linkedlist* LL, char ele[]){
	//declare and allocate a node structure
	struct Node *newNode;
	newNode = malloc(sizeof(struct Node));
	//allocate the string and store it in data.
	newNode -> data = malloc(strlen(ele));
	strcpy(newNode -> data, ele);
	//when LL is an empty linked list
	if(LL -> head == NULL){
		LL -> head = newNode;
		newNode -> next = NULL;
	}else{
		//iterate to reach the end of LL
		struct Node* searchPtr = LL -> head;
		while(searchPtr -> next != NULL){
			searchPtr = searchPtr -> next;
		}
		//insert the node
		searchPtr -> next = newNode;
		newNode -> next = NULL;
	}
}


/*
 * deleteNode takes a pointer to Linkedlist LL and a string ele.
 * Removes the node with the string in its data and free its space.
 */
void deleteNode(struct Linkedlist* LL, char ele[]){
	//initialize two pointers point to the head
	struct Node* searchPtr = LL -> head;
	struct Node* prev = LL -> head;
	//when deleteNode is the head
	if(strcmp((searchPtr -> data), ele) == 0){
		LL -> head = searchPtr -> next;
		free(searchPtr);
	}
	//travel through LL to find the node that we want to delete.
	else{
		while(searchPtr != NULL && strcmp((searchPtr -> data), ele) != 0){
			prev = searchPtr;
			searchPtr = searchPtr -> next;
		}
		//when the deleteNode does not exist in the Linkedlist.
		if(searchPtr == NULL){
			printf("No such node exists");
		}
		//delete and free the node.
		prev -> next = searchPtr -> next;
		free(searchPtr);
	}
}


/*
 * findNode takes a Linkedlist and a string ele.
 * Return 1 if ele exists. Otherwise, return 0.
 */
int findNode(struct Linkedlist LL, char ele[]){
	int result = 0;
	struct Node* searchPtr = LL.head;
	//travel through LL. If find, change int result from default 0 to 1.
	while(searchPtr != NULL){
		if(strcmp((searchPtr -> data), ele) == 0){
			result = 1;
			break;		//jump out the while loop after find it.
		}else{
			searchPtr = searchPtr -> next;
		}
	}
	return result;
}


/*
 * displayLinkedList takes a Linkedlist LL and prints all the Linkedlist node,
 * seperated by commas.
 */
void displayLinkedList(struct Linkedlist LL){
	struct Node* searchPtr = LL.head;
	if(searchPtr == NULL){
		printf("The list is empty.");
	}
	else{
		printf("The list:- ");
		//travel through every node and print it.
		while(searchPtr -> next != NULL){
			printf("%s, ", searchPtr -> data);
			searchPtr = searchPtr -> next;
		}
		printf("%s\n", searchPtr -> data);
	}
}

