/*
Data Structures C++ Programs
By J RAJAN
For Learners
Title: STACK and IT'S OPERATIONS IN C++
*/

#include <iostream>

using namespace std;

#define MAX 100

class Stack 
{
    private:
        
        int top;            //Top of the Stack
        int MyArray[MAX];   //MAX length of Stack defined
    
    public:
        
        //Initialize
        Stack() 
        {
            top = -1;
        }

        //Empty check
        bool isEmpty() 
        {
            return top == -1;
        }

        //Overflow check
        bool isFull() 
        {
            return top == MAX - 1;
        }

        //Push Function
        void Push(int x) 
        {
            if (isFull()) 
            {
                std::cout << "Error: Stack is full!" << std::endl;
                return;
            }
            MyArray[++top] = x;
        }

        //Pop Function
        int Pop() 
        {
            if (isEmpty()) 
            {
                std::cout << "Error: Stack is empty!" << std::endl;
                return -1;
            }
            return MyArray[top--];
        }


};

void main() 
{
    Stack MyStack; //Stack defined
    
    int num = 1;

    //Push numbers into stack
    while (num != 0)
    {
        cout << "\nEnter number to add in stack (Enter 0 to exit)";
        cout << "\nPUSH : ";
        cin >> num;
        MyStack.Push(num);
    }
    //Removing 0 from stack
    MyStack.Pop();

    std::cout << "Pop elements from stack \n";

    //Pop out everything
    while (!MyStack.isEmpty()) 
    {
        cout << "Popped number : " << MyStack.Pop() << "\n";
    }
    cout << "\n";
}
