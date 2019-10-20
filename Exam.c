/*
* Make a program with Linked list & display the list. Optional : in linked list increment the value of linked list items by 1
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *head = NULL;

/* Making A new node with each call to the getNode() Method */
Node* getNode(){
    Node* makeNode;
    makeNode = (Node*)malloc(sizeof(Node));
    printf("Enter the data for this node: ");
    scanf("%d", &makeNode->data);
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
    printf("Displaying the data of the linked-list:\n");
    while(tempNode != NULL){
        printf("%d\t", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

/// OPTIONAL >> Please leave this area if you don't want to do something with data
void incrementData()
{
    Node* accessdata;
    accessdata = head;
    while(accessdata != NULL){
        accessdata->data += 1;
        accessdata = accessdata->next;
    }
}

/// Calling main function
int main()
{
    int x;
    printf("Enter the number of list item: ");
    scanf("%d", &x);
    createList(x);
    displayList();
    incrementData();
    displayList();
}

/*
* With data validation & C++
*/
#include <iostream>
#include <string>
using namespace std;

typedef struct Node
{
    string getName;
    int age;
    Node* next;
}Node;

Node* head = NULL;

Node* getNode()
{
    Node* makeNode;
    makeNode = new Node();
    cout << "Enter the name: ";
    cin.clear(); // this will clear any cin.(string) error
    cin.sync(); // this will clear any character and \n
    getline(cin, makeNode->getName);
    cout << "Enter the age: ";
    do {
        cin >> makeNode->age;

        if(makeNode->age <= 0) {
            cout << "Invalid Input ! Enter a non zero Integer Value: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }while (makeNode->age <= 0);

    return makeNode;
}

void createlist(int y)
{
    Node* newNode;
    for(int i = 0; i < y; ++i)
    {
        newNode = getNode();
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void displayList()
{
    Node* temp;
    temp = head;
    while(temp != NULL)
    {
        cout << "Name of Student: " << temp->getName << "\tAge is: " << temp->age;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int x;
    cout << "Enter the length of the list: ";
    cin >> x;
    while (x <= 0) {
        cout << "Invalid input ! Enter a Positive Non zero value: " ;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> x;
    }
    createlist(x);
    displayList();
}
