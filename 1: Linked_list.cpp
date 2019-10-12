/*
*------------------------------------------------------------------------------------------------------------------------------
* P:18_Exercises: 1  -> Write a program that takes a dynamic value from user to input terms & value and make a linked list.
*------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

typedef struct Node{
	int data;
	Node* next;
}Node;
Node* head = NULL;

Node* getNode(){
	Node* newNode;
	newNode = new Node(); // Or we can write newNode = (Node*)malloc(sizeof(Node))
	cout << "Enter data: ";
	cin >> newNode->data;
	newNode->next = NULL;
	return newNode;
}

void createList(int n);
void insertAtEnd();
void insertAtBeg();
void displayList();

int main(){
	createList(3);
	displayList();
	insertAtEnd();
	displayList();
	insertAtBeg();
	displayList();
	return 0;
}

void createList(int n){
	Node* newNode; Node* temp;
	for (int i = 0; i < n; ++i){
		newNode = getNode();
		if (head == NULL){
			head = newNode;
		}
		else{
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;	
			}
			temp->next = newNode;
		}
	}
}
void insertAtEnd(){
//	First of all creating a new Node
	Node* newAdd = getNode();
	newAdd->next = NULL;
//	checking if the node is empty or not then taking decisions
	if(head == NULL){
		head = newAdd;
	}
	else{
		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newAdd;
	}
}
void insertAtBeg(){
	Node* temp = getNode();
	temp->next = head;
	head = temp;
}
void displayList(){
	Node* temp = head;
	cout << "The data of linkedList is: ";
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
