#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    /* int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];  

    This is very dangerous practice. As we know it will allocate memory in stack but in runtime not compile time. and stack usually comes with less memory. So if we give a big number then our program will crash. Because we're demanding very very large memory and ther's not much memory in stack. When we write arr[100000] stack already knows in compile time so it will already we prepared. so this is safe. 
    */ 

   //Dynamic memory: Use new keyword

    new char; //Like this. But we need to access this memory. new returns an address so we can use pointers.
    char* p = new char; //This way we can access this dunamically created memory location. pointer needs 8 bytes and new char allocates 1 byte of memory so this statment uses a total of 9 bytes in memory

    //Dynamic array

    int* arr = new int[5]; //This will allocate 5 int blocks for pointer(not an array) named arr.
    /* 
    as we know 
    arr[i] = *(arr + i) 
    &(arr[i]) = arr + i 
    so,
    */
   arr[0] = 5; //5 assigned to first memory address of arr.
   *(arr + 1) = 6; //6 assigned to 2nd memory address of arr

    cout<<arr[0] <<' ' <<arr[1] <<endl;

    //Dynamic variable array.

    int n;
    cout<<"Enter size of array: ";
    cin>>n; 
    int* array = new int[n]; //This is how we create a Dynamic sized array in heap.
    
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }

    cout<<"Our array is: ";
    for (int i = 0; i < n; i++)
    {
        cout<<array[i] <<' ';
    } cout<<endl;
    
    //Using array in a funciton.

    cout<<"Sum of array is: " << sum(array,n);
    delete[] array; //This is the way to delete the memory allocated for an array.

    //Shaitani

    while(true){
        int a = 5; //allocates 4 bytes of memory but deletes as soon as it reaches end of block(})
    }
    
    while(true){
        int* a = new int; //Allocates 12 bytes of memory but doesn't free so out laptop will crash.

        //prevention
        delete a;
    }
   
    return 0;
}