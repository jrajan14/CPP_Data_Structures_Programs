/*
Data Structures C++ Programs
By J RAJAN
For Learners
Title: ARRAYS AND FUNCTIONS
*/

#include <iostream>
# define MAX 100  //Pre-defining Maximim length of array

using namespace std;

int MyArray[MAX]; //Default array

//Functions for given Array
void DisplayArray(int size);
void DisplayArrayItem(int n, int size);
int SmallestNumber(int size);
int LargestNumber(int size);
/*

ADD MORE FUNCTIONS FOR SINGLE ARRAY

*/

int main()
{
    cout << "ARRAY AND FUNCTIONS\n";

    cout << "\n\nEnter size of array : ";
    int size;    //Here we define the size we want to play with
    cin >> size;

    cout << "\nEnter elements in Array : ";

    //Adding elements to array
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        MyArray[i] = temp;
    }

    //Infinite loop to keep showing options
    while (true)
    {
        cout << "\n\nSelect an Option : ";

        cout << "\n1. Display the Array";
        cout << "\n2. Display N'th item in array";
        cout << "\n3. Smallest number in array";
        cout << "\n4. Largest element in array";

        cout << "\nSELETION: ";
        int option;
        cin >> option;
        switch (option)
        {
            case 1:
            {
                //Display complete array
                DisplayArray(size);
                break;
            }
            case 2:
            {
                //Display Array element in N'th position
                cout << "\nEnter Position : ";
                int position;
                cin >> position;
                DisplayArrayItem(position, size);
                break;
            }
            case 3:
            {
                //Find smallest number in Array
                int smallest;
                smallest = SmallestNumber(size);
                cout << "\nSmallest item in Array is : " << smallest;
                break;
            }
            case 4:
            {
                //Find largest number in Array
                int largest;
                largest = LargestNumber(size);
                cout << "\nLargest item in Array : " << largest;
                break;
            }
            default:
            {
                cout << "\nINVALID SELECTION";
            }
        }
    }

}

//Display complete array function definition
void DisplayArray(int size)
{
    cout << "\n\nDisplaying Complete Array : ";
    for (int i = 0; i < size; i++)
    {
        cout << MyArray[i] << " ";
    }
}

//Display N'th item function definition
void DisplayArrayItem(int n, int size)
{
    if (n <= size && n > 0)
    {
        cout << "\nNumber at position " << n << " is: " << MyArray[n - 1];
    }
    else
    {
        cout << "\nPosition out of range ";
    }
}

//Smallest number in Array function definition
int SmallestNumber(int size)
{
    int smallest = MyArray[0];
    int i = 0;
    while(i < size)
    {
        if (smallest > MyArray[i])
        {
            smallest = MyArray[i];
        }
        i++;
    }

    return smallest;
}

//Largest number in Function Definition
int LargestNumber(int size)
{
    int largest = MyArray[0];
    int i = 0;
    while (i < size)
    {
        if (largest < MyArray[i])
        {
            largest = MyArray[i];
        }
        i++;
    }
    return largest;
}
