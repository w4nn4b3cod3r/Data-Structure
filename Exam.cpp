/*
* Make a program with Linked list & display the list. Optional : in linked list increment the value of linked list items by 1
*/
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

Node *head = NULL;

/* Making A new node with each call to the getNode() Method */
Node* getNode(){
    Node* makeNode;
    makeNode = (Node*)malloc(sizeof(Node));
    cout << "Enter the data for this node: "; // for c program use printf() instead of cout
    cin >> makeNode->data; // for c program use instead of cin scanf("%d", &makeNode->data)
    makeNode->next = NULL;
    return makeNode;
}

/// Creating the Linked list here
void createList(int range)
{
    Node* createNode, *get_node;
    for(int i = 0; i < range; ++i)
    {
        createNode = getNode();
        if(head == NULL){
            head = createNode;
        }
        else{
            get_node = head;
            while (get_node->next != NULL){
                get_node = get_node->next;
            }
            get_node->next = createNode;
        }
    }
}

/// Displaying the list here
void displayList()
{
    Node* tempNode;
    tempNode = head;
    cout << "Displaying the data of the linked-list: " << endl;
    while(tempNode != NULL){
        cout << tempNode->data << "\t";
        tempNode = tempNode->next;
    }
    cout << endl;
}

/// OPTIONAL >> Please leave this area if you dont want to do something with data
void incrementData()
{
    Node* accessdata;
    accessdata = head;
    while(accessdata != NULL){
        accessdata->data += 1;
        accessdata = accessdata->next;
    }
    cout << endl;
}

/// Calling main function
int main()
{
    int x;
    cout << "Enter the number of length of list: " ;
    cin >> x;
    createList(x);
    displayList();
    incrementData();
    displayList();
}
