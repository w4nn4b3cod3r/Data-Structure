// Circular Queue Implementation using array

#include <iostream>

const int MAX_SIZE = 5;
int CQ[5];
int front, rear, counter;


int getMainMenu(){
    int choice;
    std::cout << "\n\nCircular Operation using Queue Array\n***************************\n";
    std::cout << "\n1. Insert\n2. Dequeue\n3. Display\n4. Quit\n";
    std:: cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}
void insertCQ(){
    if(counter == MAX_SIZE){
        std::cout << "\nCircular Queue is full.\n";
    }
    else {
        int data;
        std::cout << "Enter data: ";
        std::cin >> data;
        CQ[rear] = data;
        rear = (++rear) % MAX_SIZE;
        counter++;
        std::cout << "\nData pushed enque successfull!\n";
    }

}
void deleteCQ(){
    if(counter == 0){
        std::cout << "\nCircular Queue is empty !\n";
    }
    else {
        std::cout << "\nDeleted element from CQ: " << CQ[front] << "\n";
        front = (++front) % MAX_SIZE;
        counter--;
    }
}
void displayCQ(){
    if(counter == 0){
        std::cout << "\nCircular Queue is empty !\n";
    }
    else {
        int j = counter;
        std::cout << "Elements are: ";
        for(int i = front; j ; j--){
            std::cout << CQ[i] << " ";
            i = (++i) % MAX_SIZE;
        }
    }
}

int main(void){
    int ch;
    do{
        ch = getMainMenu();
        switch (ch)
        {
        case 1:
            insertCQ();
            break;
        case 2:
            deleteCQ();
            break;
        case 3:
            displayCQ();
            break;
        case 4:
            std::cout << "\nThanks for using application.\n";
            break;
        default:
            std::cout << "\nInvalid choice ! Try again.\n";
        }
    }while(ch != 4);

    return 0;
}
