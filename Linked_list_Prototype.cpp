/*
* Building a linked-list with all the function used usually in Linked_List
*/
#include <iostream>

using namespace std;

typedef struct Node{
	string name;
	int roll;
	Node* next;
}Node;

Node* head = NULL;
// Each time getNode() get called will create a new node
Node* getNode(){
	Node* newNode;
	newNode = new Node();
	cout << "Enter the name: ";
	cin >> newNode->name;
	cout << "Enter the roll: ";
	cin >> newNode->roll;
	return newNode;
}
// If the user want to make multiple List items: 
void createList(int x){
	Node* addNode, *setNode;
	for(int i = 0; i < x; i++){
		addNode = getNode();
		if(head == NULL)
			head = addNode;
		else {
			setNode = head;
			while(setNode->next != NULL){
				setNode = setNode->next;
			}
			setNode->next = addNode;
		}
	}
}
// Treversing through the present linked list.
void showList(){
	Node* temp;
	temp = head;
	cout <<"The Built Linked-list is below: \n";
	while(temp != NULL){
		cout << "Student Name: "<< temp->name << "\tRoll Number: " << temp->roll 
		<< endl;
		temp = temp->next;	
	}
	cout << endl;
}
// For inserting node in the begining section.
void insertInBegining(){
	cout << "Inserting Node in List in begining.\n";
	Node* temp = getNode();
	temp->next = head;
	head = temp;
}
//For inserting node in the end section.
void insertInEnd(){
	cout << "Intserting as last node on list.\n";
	Node* add;
	add = getNode();
	if(head == NULL){
		head = add;
	}
	else{
		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = add;
	}
}
// For inserting the node in nth position selected by the user
void insertNthPos(int position){
	//Body
}
// For deleteing the node in nth position selected by the user
void deleteNodeNthPos(){
	//Body
}
void reverseList(){
	//Body
}
// Main section. This program will run from main() function.
int main(){
	int x;
	cout << "Enter the terms for list you want: ";
	cin >> x;
	createList(x);
	showList();
	insertInBegining();
	showList();
	insertInEnd();
	showList();
	
	return 0;
}
