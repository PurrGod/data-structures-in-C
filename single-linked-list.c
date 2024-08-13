#include <stdio.h>
#include <stdlib.h>

// Single linked list, a Struct named Node contains data types and variables.
// In this case, int data hold the value of the element in a list
// struct Node* next holds a pointer to the next Node or element in the list


// struct that holds information about the node such as data and pointer to enxt
struct NodeOBJ{
    int data;
    struct NodeOBJ* next;
}NodeOBJ;

typedef struct NodeOBJ * NodePtr;

// another struct that holds informatin regarding length of list and pointer to head

struct ListOBJ{
	int length;
	struct NodeOBJ * head;
}ListOBJ;

typedef struct ListOBJ * ListPtr;


// Create a node and then turn it into a list and assign null values
ListPtr create_list(int numNodes){
	ListPtr newList = (ListPtr)malloc(sizeof(ListPtr));
	if (newList != NULL){
		newList->head = NULL;
		newList->length = 0;
	}

	return newList;
}

//destroy memory of List object
void destroyList(ListPtr * List){
	if (List != NULL && (*List) != NULL){
		NodePtr curr = (*List)->head;
		while (curr != NULL){
			NodePtr temp = curr;
			temp->data = NULL;

			curr = curr->next;
			free(temp);
		}
		free(curr);
		free(*List);
		(*List) = NULL;
	}


}

//make a new node with the given data and list pointer
ListPtr AppendNode(ListPtr List, void * Data){
	//make a new node
	if(List != NULL){
		NodePtr newNode = (NodePtr)malloc(sizeof(NodeOBJ));
		newNode->data = Data;
		newNode->next = NULL;

		if(List->head == NULL){
			List->head = newNode;
			List->length = 1;
		}
		else{
			NodePtr curr = List->head;
			// keep iterating until u reach null, then stop and add the new node
			while(curr->next != NULL){
				curr = curr->next;
			}
			//add newnode
			curr->next = newNode;
			List->length += 1;
		}
	}
	return List;

}

int getListLength(ListPtr L){
	if(L == NULL){
		return 0;
	}else{
		return L->length;
	}
}

void * getNodeDataIndex(ListPtr List, int i){
	if (List != NULL){
		NodePtr curr = List->head;
		int count = 0;
		// iterate until u reach the index value of the node
		while(count <= i){
			curr = curr->next;
		}

		return curr->data;
	}
	return NULL;
}

//Deletes the entry at the specified index and returns the data from that entry.

void * popNodeIndex(ListPtr List, int i){
	if(List != NULL && i >= 0 && i < List->length){
		void * returnData;
		NodePtr curr = List->head;
		NodePtr prev = NULL;

		// if deleting the head
		if(i == 0){
			List->head = curr->next;
			returnData = curr->data;
			curr->next = NULL;
			free(curr);
			List->length--;
			return  returnData;
		}

		for (int m = 0; m < i; m++){
			prev = curr;
			curr = curr->next;
		}

		prev->next = curr->next;
		curr->next = NULL;
		returnData = curr->data;
		free(curr);
		List->length--;
	}
	return NULL;
}

