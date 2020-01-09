#include <iostream>

typedef struct Stack {
	int data;
	struct Stack* next;
}Node;
Node* head = nullptr;
Node* top = nullptr;

Node* getNewStackNode(){
	Node* temp = new Node();
	std::cout << "Enter data to push into the stack: ";
	std::cin >> temp->data;
	temp->next = nullptr;
	return temp;
}



void push(Node* makeNode)
{
	Node* temp = head;
	if (makeNode == nullptr) {
		std::cout << "\nStack is overflow.\n";
	}
	else if (head == nullptr) {
		head = makeNode;
		top = makeNode;
	}
	else {
		//temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = makeNode;
		top = makeNode;
	}
	std::cout << "\nPushed data into the stack.\n";
}

void pop() {
	Node* temp = head;
	if (top == nullptr) {
		std::cout << "\nStack Underflow.\n";
	}
	else if (head->next == nullptr) {
		std::cout << "Poped element is : " << top->data << "\n";
		head = nullptr;
		delete top;
		top = nullptr;
	}
	else {
		while (temp->next != top) {
			temp = temp->next;
		}
		temp->next = nullptr;
		std::cout << "Poped element is: " << top->data << "\n";
		delete top;
		top = temp;
	}
}

void displayStack() {
	Node* temp;
	if (top == nullptr) {
		std::cout << "\nStack is empty!" << std::endl;
	}
	else {
		temp = head;
		std::cout << "\nStack is: " << temp->data << " ";
		while (temp != top)
		{
			temp = temp->next;
			std::cout << temp->data << " ";
			
		}
	}
}
int getFromMenu()
{
	int selectMyOption;
	std::cout << "\n Stack Using Linked-List\n************************\n";
	std::cout << "\n1. Push\n2. Pop\n3. Display Stack\n4. Quit\n";
	std::cout << "Enter your choice: ";
	std::cin >> selectMyOption;
	return selectMyOption;
}


int main()
{
	int ch;
	//int loop = 1;
	do {
		ch = getFromMenu();
		switch (ch)
		{
		case 1:
			Node* newNode = getNewStackNode();
			push(newNode);
			break;
		case 2:
			pop();
			break;
		case 3:
			displayStack();
			break;
		case 4:
			//loop = 0;
			break;
		default:
			std::cout << "\nInvalid Choice. Please try again.\n";
			break;
		}
	} while (ch != 4);

	return 0;
}
