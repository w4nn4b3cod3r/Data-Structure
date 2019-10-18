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

