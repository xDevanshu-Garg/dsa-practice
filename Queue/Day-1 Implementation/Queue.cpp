#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    queue<int> q;

    // Constructor - Already used when declaring `q`
    
    // push() - insert element at the end
    q.push(10);
    q.push(20);

    // emplace() - constructs element in-place at the end (C++11+)
    q.emplace(30);

    // front() - access the first element
    cout << "Front: " << q.front() << endl;

    // back() - access the last element
    cout << "Back: " << q.back() << endl;

    // size() - number of elements
    cout << "Size: " << q.size() << endl;

    // empty() - check if queue is empty
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    // pop() - remove front element
    q.pop();
    cout << "Front after pop: " << q.front() << endl;

    // swap() - swap contents of two queues
    queue<int> q2;
    q2.push(100);
    q2.push(200);

    q.swap(q2); // Now q has 100 and 200
    cout << "After swap, front of q: " << q.front() << endl;

    return 0;
}
