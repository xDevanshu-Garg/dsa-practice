#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // ✅ Max Heap (Default in C++)
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);

    cout << "Max Heap Top: " << maxHeap.top() << "\n"; // 20

    cout << "Max Heap Elements: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";  // 20 10 5
        maxHeap.pop();
    }
    cout << "\n";

    // ✅ Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);

    cout << "Min Heap Top: " << minHeap.top() << "\n"; // 5

    cout << "Min Heap Elements: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";  // 5 10 20
        minHeap.pop();
    }
    cout << "\n";

    // ✅ Custom Comparator (pair - sort by 2nd element)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({2, 100});
    pq.push({1, 300});
    pq.push({3, 50});

    cout << "Custom Min Heap on pair.first:\n";
    while (!pq.empty()) {
        cout << "(" << pq.top().first << ", " << pq.top().second << ") ";
        pq.pop();
    }
    cout << "\n";

    // ✅ Custom comparator for class or struct
    struct Comp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;  // Min-heap by second value
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> customHeap;
    customHeap.push({1, 40});
    customHeap.push({2, 30});
    customHeap.push({3, 20});

    cout << "Custom Struct Comparator (Min-heap on .second):\n";
    while (!customHeap.empty()) {
        cout << "(" << customHeap.top().first << ", " << customHeap.top().second << ") ";
        customHeap.pop();
    }

    return 0;
}
