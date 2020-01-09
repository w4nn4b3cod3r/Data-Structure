// Queue Using Linked List

#include <iostream>

typedef struct Queue {
	int data;
	struct Queue* next;
}node;

node* front = nullptr;
node* rear = nullptr;

node* getNode() {
	node* providenode;
	providenode = new node();
	std::cout << "Enter the data: ";
	std::cin >> providenode->data;
	providenode->next = nullptr;
	return providenode;
}

int getMenuChoice() {
	int ch;
	std::cout << "\n1. Insert Element\n2. Delete Element\n3. Display Queue\n4. Quit\n";
	std::cout << "Enter your choice: ";
	std::cin >> ch;
	return ch;
}

void insertQ() {
	node* newNode = getNode();
	if (front == nullptr) {
		front = newNode;
		rear = newNode;
	}
	else if (newNode == nullptr) {
		std::cout << "\nQueue full !\n";
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	std::cout << "\nInserted data into queue successfull.\n";
}
void deleteQ() {
	node* temp;
	if (rear == nullptr) {
		std::cout << "\nQueue is empty !\n";
	}
	else if (rear == front) {
		temp = front;
		std::cout << "\n Deleted element from queue: " << temp->data << "\n";
		delete temp;
		front = nullptr;
		rear = nullptr;
	}
	else {
		temp = front;
		front = front->next;
		std::cout << "\ndeleted element from queue: " << temp->data << "\n";
		delete temp;
	}
}
void displayQ() {
	node* temp = front;
	if (rear == nullptr) {
		std::cout << "\nQueue is empty !\n";
	}
	else {
		std::cout << "\nQueue Elements are: ";
		while(temp != nullptr){
			std::cout << temp->data << "-";
			temp = temp->next;
		}
	}
}
int main(void) {
	std::cout << "Queue Using Linked List\n************************\n";
	int choice;
	do {
		choice = getMenuChoice();
		switch (choice)
		{
		case 1:
			insertQ();
			break;
		case 2:
			deleteQ();
			break;
		case 3:
			displayQ();
			break;
		case 4:
			break;
		default:
			std::cout << "\nInvalid Coice. Try Again.\n";
		}
	} while (choice != 4);

	return 0;
}
