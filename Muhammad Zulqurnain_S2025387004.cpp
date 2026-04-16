#include <iostream>
using namespace std;

/* =========================================================
   DSA Assignment 1
   Name: Muhammad Zulqurnain
   ID: S2025387004
   ========================================================= */

/* =========================================================
   Q1 – Arrays and Searching
   ========================================================= */

/*
Q1.A.1
Contiguous memory allocation means array elements are stored
in consecutive memory locations. Arrays use contiguous memory
so elements can be accessed quickly using their index.

Q1.A.2
A memory leak occurs when memory allocated dynamically using
new is not released using delete. Example: creating a dynamic
array using new int[10] but forgetting delete[].

Q1.A.3
A fixed-size array has size defined at compile time.
A dynamic array is created during runtime using new.

Q1.A.4
Array access is O(1) because the address of any element
is calculated directly using base address + index.
Linked lists require traversal so they are slower.
*/

// Linear Search
int linearSearch(int arr[], int size, int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}

// Find Min and Max
void findMinMax(int arr[], int size, int &minVal, int &maxVal)
{
    minVal=arr[0];
    maxVal=arr[0];

    for(int i=1;i<size;i++)
    {
        if(arr[i]<minVal)
            minVal=arr[i];

        if(arr[i]>maxVal)
            maxVal=arr[i];
    }
}

/* =========================================================
   Q2 – Bubble Sort
   ========================================================= */

/*
Bubble sort compares adjacent elements and swaps them if
they are in the wrong order. After each pass, the largest
element moves to the end.

Best Case: O(n)
Average Case: O(n^2)
Worst Case: O(n^2)

Selection sort performs fewer swaps but bubble sort is
easier to understand.
*/

void bubbleSort(int arr[], int size, int &swapCount)
{
    swapCount=0;
    bool swapped;

    for(int i=0;i<size-1;i++)
    {
        swapped=false;

        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                swapCount++;
                swapped=true;
            }
        }

        cout<<"Pass "<<i+1<<": ";
        for(int k=0;k<size;k++)
            cout<<arr[k]<<" ";
        cout<<endl;

        if(!swapped)
            break;
    }
}

/* =========================================================
   Q3 – Binary Search
   ========================================================= */

/*
Binary search requires a sorted array.

Example Dry Run for key=23
Array: {2,5,8,12,16,23,38,45}

Step1: low=0 high=7 mid=3 value=12
Step2: low=4 high=7 mid=5 value=23 found

Linear search = O(n)
Binary search = O(log n)
*/

int binarySearch(int arr[], int size, int key, int &iterations)
{
    int low=0;
    int high=size-1;

    while(low<=high)
    {
        iterations++;

        int mid=(low+high)/2;

        if(arr[mid]==key)
            return mid;

        else if(arr[mid]<key)
            low=mid+1;

        else
            high=mid-1;
    }

    return -1;
}

/* =========================================================
   Q4 – Complexity Analysis
   ========================================================= */

/*
Big O describes algorithm growth as input size increases.

Big O = worst case
Big Omega = best case
Big Theta = exact bound

Ranking fastest to slowest:
O(1)
O(log n)
O(n)
O(n log n)
O(n^2)

Space complexity measures extra memory used.
*/

/*
Nested loop complexity:
O(n^2)
*/
void nestedLoopExample(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;
        }
    }
}

/*
Single loop complexity:
O(n)
*/
void singleLoopExample(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
}

/*
Check if every element in A exists in B
Time Complexity = O(n^2)

Better approach: use hash table
*/
bool checkArrays(int A[], int B[], int n)
{
    for(int i=0;i<n;i++)
    {
        bool found=false;

        for(int j=0;j<n;j++)
        {
            if(A[i]==B[j])
            {
                found=true;
                break;
            }
        }

        if(!found)
            return false;
    }

    return true;
}

/* =========================================================
   Q5 – Singly Linked List
   ========================================================= */

/*
A singly linked list stores nodes with data and a pointer
to the next node.

Insertion at head = O(1)
Insertion at tail = O(n)
Deletion by value = O(n)

If delete is not used when removing a node,
it causes a memory leak.
*/

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
public:

    Node* head;

    LinkedList()
    {
        head=NULL;
    }

    void insertAtHead(int val)
    {
        Node* newNode=new Node;
        newNode->data=val;
        newNode->next=head;
        head=newNode;
    }

    void insertAtTail(int val)
    {
        Node* newNode=new Node;
        newNode->data=val;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
            return;
        }

        Node* temp=head;

        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newNode;
    }

    void display()
    {
        Node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }

        cout<<"NULL"<<endl;
    }

    void deleteByValue(int val)
    {
        if(head==NULL)
            return;

        if(head->data==val)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            return;
        }

        Node* current=head;

        while(current->next!=NULL && current->next->data!=val)
            current=current->next;

        if(current->next==NULL)
        {
            cout<<"Value not found"<<endl;
            return;
        }

        Node* temp=current->next;
        current->next=current->next->next;
        delete temp;
    }
};

/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main()
{
    cout<<"===== Q1 ====="<<endl;

    int arr1[10]={4,15,7,23,1,9,42,18,6,30};

    int index=linearSearch(arr1,10,42);

    if(index!=-1)
        cout<<"42 found at index "<<index<<endl;
    else
        cout<<"42 not found"<<endl;

    int minVal,maxVal;
    findMinMax(arr1,10,minVal,maxVal);

    cout<<"Min = "<<minVal<<endl;
    cout<<"Max = "<<maxVal<<endl;


    cout<<"\n===== Q2 ====="<<endl;

    int arr2[]={64,34,25,12,22,11,90};
    int size2=7;
    int swaps;

    cout<<"Before Sorting: ";
    for(int i=0;i<size2;i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    bubbleSort(arr2,size2,swaps);

    cout<<"Total swaps = "<<swaps<<endl;


    cout<<"\n===== Q3 ====="<<endl;

    int arr3[]={2,5,8,12,16,23,38,45,56,72};
    int size3=10;

    int iterations=0;

    int result=binarySearch(arr3,size3,56,iterations);

    cout<<"Index of 56 = "<<result<<endl;
    cout<<"Iterations = "<<iterations<<endl;

    iterations=0;

    result=binarySearch(arr3,size3,100,iterations);

    cout<<"Search for 100 result = "<<result<<endl;
    cout<<"Iterations = "<<iterations<<endl;


    cout<<"\n===== Q5 ====="<<endl;

    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout<<"Initial List: ";
    list.display();

    list.deleteByValue(20);

    cout<<"After deleting 20: ";
    list.display();

    list.deleteByValue(100);

    cout<<"Final List: ";
    list.display();

    return 0;
}

