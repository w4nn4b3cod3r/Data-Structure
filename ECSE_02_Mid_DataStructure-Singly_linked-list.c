/*
* Building a linked-list with all the function used usually in Linked_List
*/
#include <iostream>

using namespace std;

typedef struct Node {
    string name;
    int roll;
    Node* next;
} Node;

Node* head = NULL;
// Each time getNode() get called will create a new node
Node* getNode() {
    Node* newNode;
    newNode = new Node();
    cout << "Enter the name: ";
    cin >> newNode->name;
    cout << "Enter the roll: ";
    cin >> newNode->roll;
    return newNode;
}
// For counting each node created in linked list
int countNode(Node *ptr) {
    int count=0;
    while(ptr != NULL) {
        count++;
        ptr = ptr -> next;
    }
    return count;
}
// If the user want to make multiple List items:
void createList(int x) {
    Node* addNode, *setNode;
    for(int i = 0; i < x; i++) {
        addNode = getNode();
        if(head == NULL)
            head = addNode;
        else {
            setNode = head;
            while(setNode->next != NULL) {
                setNode = setNode->next;
            }
            setNode->next = addNode;
        }
    }
}
// Traversing through the present linked list.
void showList() {
    Node* temp;
    temp = head;
    cout <<"The Built Linked-list is below: \n\n";
    while(temp != NULL) {
        cout <<"Student Name: "<< temp->name << "\tRoll Number: " << temp->roll
             << endl;
        cout << "-----------------------------------------------------" << endl;
        temp = temp->next;
    }
    cout << endl;
}
// For inserting node in the beginning section.
void insertInBegining() {
    cout << "Inserting Node in List in beginning.\n";
    Node* temp = getNode();
    temp->next = head;
    head = temp;
}
//For inserting node in the end section.
void insertInEnd() {
    cout << "Inserting as last node on list.\n";
    Node* add;
    add = getNode();
    if(head == NULL) {
        head = add;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = add;
    }
}
// For inserting the node in nth position selected by the user
void insertNthPos() {
    int ctr = 1, position, nodectr;
    Node *newNode,*temp, *prev;
    newNode = getNode();
    cout << "Enter the position: ";
    cin >>position;
    nodectr = countNode(head);
    if(position > 1 && position < nodectr) {
        temp = prev = head;
        while(ctr < position) {
            prev = temp;
            temp = temp -> next;
            ctr++;
        }
        prev -> next = newNode;
        newNode -> next = temp;
    } else
        cout << "The position " << position << "is invalid !" << endl;
}

// For deleting the node in nth position selected by the user
void deleteNodeNthPos() {
    int ctr = 1, pos, nodectr;
    Node *temp, *prev;
    if(head == NULL) {
        cout << "Empty list !" << endl;
        return ;
    } else {
        cout << "\n Enter position of node to delete: ";
        cin >> pos;
        nodectr = countNode(head);
        if(pos > nodectr) {
            cout << "This node doesn't exist !" << endl;
        }
        if(pos > 1 && pos < nodectr) {
            temp = prev = head;
            while(ctr < pos) {
                prev = temp;
                temp = temp -> next;
                ctr ++;
            }
            prev -> next = temp -> next;
            delete temp;
            cout << "node deleted !" << endl;
        } else {
            cout << "Invalid position entered !" << endl;
        }
    }

}
void reverseList() {
    Node* current, *next, *prev;
    current = head;
    prev = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
// Main section. This program will run from main() function.
int main() {
    int x;
    cout << "Enter the terms for list you want: ";
    cin >> x;
    createList(x);
    showList();
    //insertNthPos(3);
    //showList();
    //deleteNodeNthPos(2);
    //showList();
    cout << "Reversing the list: " << endl;
    reverseList();
    showList();
    return 0;
}
