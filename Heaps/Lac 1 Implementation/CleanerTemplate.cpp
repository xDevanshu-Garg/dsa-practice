#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! This is a template file for cleaner code. 

class maxHeap {
  private:
    vector<int> heap;

  public:

    void heapify() {
        
    }
    
    void push(int x) {
        // Insert x into the heap
        heap.push_back(x);
        
        int i = heap.size() - 1;
        
        while(i > 0) {
            int parent = (i - 1) / 2;
            
            if(heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void pop() {
        // Remove the top (maximum) element
        // Can remove only from back because a heap is a CBT
        if(heap.empty()) return;
        
        heap[0] = heap.back();
        heap.pop_back();
        
        int n = heap.size();
        int i = 0;
        
        // Swap with largest bw left and right child
        while(true) {
            int largest = i;
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            
            if(left < n && heap[left] > heap[largest]) 
                largest = left;
                
            if(right < n && heap[right] > heap[largest]) 
                largest = right;
                
            if(largest == i) break;
            
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    int peek() {
        // Return the top element or -1 if empty
        return heap.empty() ? -1 : heap[0];
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size();
    }
};