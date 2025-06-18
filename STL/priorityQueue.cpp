#include <iostream>
#include <queue>
using namespace std;

/*
There are two types of priority queue: 
1) Maximum heap: Top element is always maximum i.e. the first element becuase queue follows FIFO.
2) Minimum heap: Top element is always minimum.
*/

int main()
{
    priority_queue<int> maxi; //By default priority queue is maximum heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(3);
    maxi.push(5);
    maxi.push(2);
    maxi.push(0);

    cout<<"maxm heap empty or not: " <<maxi.empty() <<endl;

    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout<<maxi.top() << ' ';
        maxi.pop();
    } cout<<endl;

    cout<<"maxm heap empty or not: " <<maxi.empty() <<endl;
    
    mini.push(7);
    mini.push(3);
    mini.push(4);
    mini.push(2);

    n = mini.size();
    for (int i = 0; i < n; i++)
    {
        cout<<mini.top() << ' ';
        mini.pop();
    } cout<<endl;


    return 0;
}