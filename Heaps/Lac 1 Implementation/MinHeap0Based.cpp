//! https://www.naukri.com/code360/problems/build-min-heap_1171167?leftPanelTab=0
#include <iostream>
using namespace std;
#include <bits/stdc++.h> 

void heapify(vector<int> &arr, int n, int i){
    int minimum = i;
    int left = i*2 + 1;
    int right = i*2 + 2;

    //Check whether left child is minimum or right. Whichever is minimum we've to pick for root.
    if(left < n && arr[minimum] > arr[left])
        minimum = left; //minimum is updated here
    //if right is less then minimum then we've new minimum
    if(right < n && arr[minimum] > arr[right])
        minimum = right;
        
    if(minimum != i){
        swap(arr[i], arr[minimum]);
        heapify(arr, n, minimum);
    }
}

vector<int> buildMinHeap(vector<int> &arr){
    int n = arr.size();
    for(int i = n/2-1; i >= 0; i--)
        heapify(arr, n, i);
    return arr;
}