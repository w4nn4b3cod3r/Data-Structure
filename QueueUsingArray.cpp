// Queue Using Array

#include <iostream>

const int MaxSize = 5;
int mArray[MaxSize];
int front, rear;

int getMenuChoice() {
	int ch;
	std::cout << "\n1. Insert Element\n2. Delete Element\n3. Display Queue\n4. Quit\n";
	std::cout << "Enter your choice: ";
	std::cin >> ch;
	return ch;
}

void insertQ() {
	int data;
	if (rear == MaxSize) {
		std::cout << "\nLinear Queue is full. \n";
	}
	else {
		std::cout << "Enter the data: ";
		std::cin >> data;
		mArray[rear] = data;
		rear++;
		std::cout << "\nInsertion of data is successful.\n";
	}
}
void deleteQ() {
	if (rear == front) {
		std::cout << "\nQueue is empty !\n";
	}
	else {
		std::cout << "\nQueue element deleted. " << mArray[front];
		front++;
	}
}
void displayQ() {
	if (rear == front) {
		std::cout << "\nQueue is empty !\n";
	}
	else {
		std::cout << "\nQueue elements are: ";
		for (int i = front; i < rear; i++) {
			std::cout << mArray[i] << "-";
		}
	}
}
int main(void) {
	std::cout << "Queue Using Array\n**********************\n";
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
