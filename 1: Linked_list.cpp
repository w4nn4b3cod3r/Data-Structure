/*
*------------------------------------------------------------------------------------------------------------------------------
* P:18_Exercises: 1  -> Write a program that takes a dynamic value from user to input terms & value and make a linked list.
*------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

//Creating Node Structure
struct Node{
	int data;
	Node *link;
};
//creating head pointer and equating to NULL
Node *head=NULL;

//Function to insert at the beginning of linked list
void insertBeg (int d){
	Node *ptr = new Node(); // creating HEAP MEMORY for ptr node
	ptr->data=d;   //set ptr data to assigned d value
	ptr->link=head;
	head=ptr;
}
//Function to insert at the end of linked list
void insertEnd (int d){
	Node *ptr = new Node();
	ptr->data=d;
	ptr->link=NULL;
	
	//If list is empty
	if(head==NULL) head=ptr;
	//else list is not empty
	else{
		Node *temp = head;
		while(temp->link != NULL){
		temp=temp->link;
		}
		temp->link=ptr;
	}
}
//Function to display linked list
void dispLink(){
	Node *temp=head;
 	while(temp!=NULL){
  		cout<<temp->data<<" ";
  	temp=temp->link;
 		}
 	cout<<"\n";
	}
//Main Function
int main(){
    int x, j;
    cout << "Enter the terms your want to do: ";
    cin >> j;
    for(int i = 0; i < j; i++) {
        cout << "Enter the elements: ";
        cin >> x;
        insertBeg(x);
        dispLink();
    }
 return 0;
}

