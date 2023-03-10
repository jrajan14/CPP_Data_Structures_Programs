/*
Data Structures C++ Programs
By J RAJAN
For Learners
Title: ARRAYS SORTING ALGORITHMS IN C++
*/

#include <iostream>
# define MAX 100  //Pre-defining Maximim length of array

using namespace std;

int MyArray[MAX]; //Default array

//Sorting Functions Declarations
void DisplayArray(int size);
void InsertionSort(int size);
void SelectionSort(int size);
void BubbleSort(int size);
void MergeSort(int size);
void ShellSort(int size);
void HeapSort(int size);
/*
 
  ADD MORE

*/

int main()
{
    cout << "ARRAY SORTING ALGORITHMS IN C++\n";

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
        DisplayArray(size);
        cout << "\n\nSelect an Option : ";

        cout << "\n1 : Insertion Sort";
        cout << "\n2 : Selection Sort";
        cout << "\n3 : Bubble Sort";
        cout << "\n4 : Merge Sort";
        cout << "\n5 : Shell Sort";
        cout << "\n6 : Heap Sort";
        
        cout << "\nSELECTION : ";
        int option;
        cin >> option;

        switch (option)
        {
            case 1:
            {
                InsertionSort(size);
                break;
            }
            case 2:
            {
                SelectionSort(size);
                break;
            }
            case 3:
            {
                BubbleSort(size);
                break;
            }
            case 4:
            {
                MergeSort(size);
                break;
            }
            case 5:
            {
                ShellSort(size);
                break;
            }
            case 6:
            {
                HeapSort(size);
                break;
            }
            //Out of range case
            default:
            {
                cout << "\nINVALID SELECTION#n";
            }
          

        }

    }
    
}

void DisplayArray(int size)
{
    cout << "Array : ";
    for (int i = 0; i < size; i++)
    {
        cout << MyArray[i] << " ";
    }
}

/*
INSERTION SORT
*/
void InsertionSort(int size) 
{
    cout << "\nINSERTION SORTING \n";
    int i, key, j;
    for (i = 1; i < size; i++) 
    {
        key = MyArray[i];
        j = i - 1;
        while (j >= 0 && MyArray[j] > key) 
        {
            MyArray[j + 1] = MyArray[j];
            j = j - 1;
        }
        MyArray[j + 1] = key;
    }
}

/*
SELECTION SORT
*/
void SelectionSort(int size) 
{
    cout << "\nSELECTION SORTING \n";
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < size; j++) 
        {
            if (MyArray[j] < MyArray[min_idx]) 
            {
                min_idx = j;
            }
        }
        swap(MyArray[i], MyArray[min_idx]); //Built-in Swap function
    }
}

/*
BUBBLE SORT
*/
void BubbleSort(int size) 
{
    cout << "\nBUBBLE SORTING \n";
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) 
    {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) 
        {
            if (MyArray[j] > MyArray[j + 1]) 
            {
                swap(MyArray[j], MyArray[j + 1]);
                swapped = true;
            }
        }
        //If not swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

/*
MERGE SORT
Merge Sort algorithms contains two functions.
One for merging and one for sorting
*/

//We don't need to declare MERGE function above main, because it's used only in MergeSort() function
void Merge(int arr[], int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Merge the two subarrays directly in the original array
    while (n1 > 0 && n2 > 0) 
    {
        if (arr[l] <= arr[m + 1]) 
        {
            l++;
            n1--;
        }
        else 
        {
            int temp = arr[m + 1];
            for (int i = m; i >= l; i--) 
            {
                arr[i + 1] = arr[i];
            }
            arr[l] = temp;
            l++;
            m++;
            n2--;
        }
    }
}
//Merge Sort function
void MergeSort(int size) 
{
    cout << "\nMERGE SORTING\n";
    for (int currentSize = 1; currentSize <= size - 1; currentSize = 2 * currentSize) 
    {
        for (int leftStart = 0; leftStart < size - 1; leftStart += 2 * currentSize) 
        {
            int mid = leftStart + currentSize - 1;
            int rightEnd = min(leftStart + 2 * currentSize - 1, size - 1);
            Merge(MyArray, leftStart, mid, rightEnd);
        }
    }
}


/*
SHELL SORT
*/
void ShellSort(int size) 
{
    cout << "\nSHELL SORTING \n";
    //Start with a large gap, then reduce the gap until it is 1
    for (int gap = size / 2; gap > 0; gap /= 2) 
    {
        //Perform insertion sort on each sublist defined by the gap
        for (int i = gap; i < size; i++) 
        {
            int temp = MyArray[i];
            int j;
            for (j = i; j >= gap && MyArray[j - gap] > temp; j -= gap) 
            {
                MyArray[j] = MyArray[j - gap];
            }
            MyArray[j] = temp;
        }
    }
}

/*
HEAP SORT
In heap Sort, first we create a HEAP then sort each heap one by one
*/
void CreateHeap(int arr[], int n, int i)
{
    int largest = i;   //Initialize largest as root
    int l = 2 * i + 1; //Left 
    int r = 2 * i + 2; //Right

    //If left is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    //If right is larger than largest now
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    //If Largest is not root
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        //Create sub-tree heap
        CreateHeap(arr, n, largest);
    }
}

//HEAP SORT
void HeapSort(int size) 
{
    cout << "\nHEAP SORTING \n";
    //Create Heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        CreateHeap(MyArray, size, i);
    }
    //Get an element from heap
    for (int i = size - 1; i >= 0; i--) 
    {
        //Move current root to the end
        swap(MyArray[0], MyArray[i]);

        //Create Heap on reduced Heap
        CreateHeap(MyArray, i, 0);
    }
}
