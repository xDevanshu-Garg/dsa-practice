#include <iostream>
using namespace std;
class heap{
public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size++;
        int index = size; //We have to insert at end
        arr[index] = val;

        while (index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }

    void deleteFromHeap(){ //Always deleted the root node
        if(size == 0){
            cout << "Nothing to delete!" << endl;
            return;
        }
        //Step1: copy last node with root
        arr[1] = arr[size];
        //Step2: Delete last node
        size--;
        //Step3: Take root node to it's correct position
        int i = 1;
        heapify(arr, size, i);
    }

    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = i*2;
        int right = i*2 + 1;

        //Check whether left child is largest or right. Whichever is largest we've to pick for root.
        if(left <= n && arr[largest] < arr[left])
            largest = left; //Largest is updated here
        //if right is greator then largest i.e. then we've new largest
        if(right <= n && arr[largest] < arr[right])
            largest = right;
            
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n){
        while(n > 1){
            //Step 1: Swap first element with last element and now last element is in right place so decrement the size
            swap(arr[1], arr[n--]);
            //Step 2: Call heapify function for the first ele to maintain max heap.
            heapify(arr, n, 1);
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){ //Start from 1 till size
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    heap h;
    h.insert(52);
    h.insert(55);
    h.insert(53);
    h.insert(51);
    h.insert(50);

    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    //O(n) not O(nlogn)
    //We'll start from n/2 because after n/2 (n/2 + 1 to n) there are only leaf nodes so they're already max heaps so no need to change.
    for(int i = n/2; i > 0; i--) h.heapify(arr, n, i);
    
    cout << "Array after heapify: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Array After sorting: ";
    h.heapSort(arr, n);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}