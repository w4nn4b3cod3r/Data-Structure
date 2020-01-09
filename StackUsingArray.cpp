#include <iostream>

void displayStack();
void pop();
void push();
void displayStack();
int choice_menu();

const int MAX = 6;
int myStack[MAX];
int top = 0;

int main() {
	int ch, loop = 1;
	do {
		ch = choice_menu();
		switch (ch)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			displayStack();
			break;
		case 4:
			loop= 0;
			break;
		default:
			std::cout << "Invalid option selected. Please try again.\n";
			break;
		}
	} while (loop);
}

int choice_menu() {
	int ch;
	std::cout << "\nStack operation using array. \n************************";
	std::cout << "\n1. Push\n2. Pop\n3. Show Stack\n4. Quit !\n";
	std::cout << "Enter your choice: ";
	std::cin >> ch;
	return ch;
}
void push() {
	int takeData;
	if (top == MAX) {
		std::cout << "\nStack Overflow\n";
	}
	else {
		std::cout << "Enter the data to push into the stack: ";
		std::cin >> takeData;
		myStack[top] = takeData;
		++top;
		std::cout << "\nPushed successfully.\n";
	}
}
void pop() {
	if (top == 0) {
		std::cout << "\nStack Underflow\n";
	}
	else {
		std::cout << "Poped elemet: " << myStack[--top];
	}
}
void displayStack() {
	if (top == 0) {
		std::cout << "\nStack is Empty.\n";
	}
	else {
		std::cout << "\nElements in the stacks are: ";
		for (int i = 0; i < top; i++)
		{
			std::cout << myStack[i] << " ";
		}
	}
}