#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k){
	int n = arr.size();
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i+1; j < n; j++){
			sum += arr[i];
		}

		if(minHeap.size() < k) minHeap.push(sum);
		else{
			if(minHeap.top() < sum){
				minHeap.push(sum);
				minHeap.pop();
			}
		}
	}

	for(int i = 0; i < minHeap.size(); i++){
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	return minHeap.top();
}

int main()
{   
    vector<int> arr = {1, 2, 3, 4, 5};
    getKthLargest(arr, 2);

    return 0;
}