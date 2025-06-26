//! ***************************************Using STL ****************************************************************
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Queue Questions";

    return 0;
}
//! Queue Reversal: https://www.geeksforgeeks.org/problems/queue-reversal/1
class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        //? **********************USING STACKS***********************
        //uesd commenly
        
        stack<int> s;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            s.push(ele);
        }
        while(!s.empty()){
            int ele = s.top();
            s.pop();
            q.push(ele);
        }
        return q;
        
        
        //? **********************USING RECURSION***********************
        //TLE recursion works but not optimal for large test cases
        //Base Case
        
        if(q.size() == 1) return q;
        
        //RR
        int ele = q.front();
        q.pop();
        q = reverseQueue(q);
        q.push(ele);
        
        return q;
        
    }
};


//! 🔍 First Negative Integer in Every Window of Size K
//!    Link: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

/* 
   Idea:
   - Use a deque to store indices of negative numbers in the current window.
   - Front of deque → first negative in window
   - Remove indices that go out of the current window

   Steps:
   1. Process first window: store indices of negatives
   2. For each new element:
      - Remove indices outside the window via i - dq.front() >= k which means dq ke front me jo pada h uski distance k se jayada h to hata do. 
      - Add current index if value is negative
      - Append result: arr[dq.front()] or 0

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(k) (worst-case: all negative)

   🧠 Pattern:
   - Sliding Window + Condition-based Deque
   - Applies to: Sliding Window Maximum, First Non-Repeating Char, Min/Max of Subarrays
*/


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        //? /************************Two pointers******************************
        //Gives TLE, TC= O(n*k), where k is size of window
        
        vector<int> ans;
        bool found = false;
        int first = 0, last = k-1;
        while(last < arr.size()){
            found = false;
            for(int i = first; i <= last; i++){
                if(arr[i] < 0) {
                    ans.push_back(arr[i]);
                    found = true;
                    break;
                }
            }
            if(!found) ans.push_back(0);
            first++,last++;
        }
        return ans;
        
        
        //? **********************Using Deque**************************************
        
        deque<int> dq; // stores indices of negative numbers
        vector<int> ans;
        // Step1: Process first window
        for(int i = 0; i< k; i++){
            if(arr[i] < 0) dq.push_back(i);
        }
        
        //Step2: Store ans of first k size window
        if(dq.size() > 0) ans.push_back(arr[dq.front()]);
        else ans.push_back(0);
        
        //Step3: Process remaining windows
        for(int i = k; i < arr.size(); i++){
            //Step4: Remove indices out of this window
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            //Step5: Add current element if negative
            if(arr[i] < 0) dq.push_back(i);
            
            //Step6: Append result
            if(dq.size() > 0) ans.push_back(arr[dq.front()]);
            else ans.push_back(0);
        }
        
        return ans;
    }
};

//! 🔍 239. Sliding Window Maximum
//!  Link: https://leetcode.com/problems/sliding-window-maximum/
/*
   Idea:
   - Use a deque to maintain **indices** of useful elements in **decreasing order of values**.
   - The front of deque always contains the index of the **maximum element** in the current window.
   - While inserting new elements:
     - Remove indices from the back where their corresponding values are less than the current element.(while loop)
     - Remove front if it's out of the window.

   🔹 Steps:
   1. Process the first `k` elements:
      - Maintain decreasing order in deque by poping elemenets which is smaller than current.
   2. For each remaining element from index `k` onward:
      - Remove out-of-window indices from front.
      - Remove all smaller elements from back (they are useless now).
      - Add current index to deque.
      - Push `nums[dq.front()]` to result.

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(k) (worst-case: all elements decreasing)

   🧠 Pattern:
   - Sliding Window + Monotonic Deque
   - Also used in problems like:
     - First Negative Integer in Window
     - Sum/Min/Max of Subarrays
     - Stock Span (variation of maintaining monotonic stack/deque)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices of elements in decreasing order of values
        vector<int> ans; // result vector to store max of each window

        // Step 1: Process the first window of size k
        for (int i = 0; i < k; i++) {
            // Remove indices from back while current element is greater than
            // elements at back
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back(); // these elements can't be maximum if current one is bigger because we always store from front of deque in ans
            }
            dq.push_back(i); // add current index
        }

        // Store the maximum for the first window
        ans.push_back(nums[dq.front()]);

        // Step 2: Process the remaining elements
        for (int i = k; i < nums.size(); i++) {
            // Step 2.1: Remove indices from front if they are out of the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Step 2.2: Maintain decreasing order in deque by removing smallerelements from back and TC will remain o(n) because we are only adding and removing element atmost 1 time
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            // Step 2.3: Add current index to deque
            dq.push_back(i);

            // Step 2.4: The front of deque is the max element of current window
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};


//! 🔍 First Non-Repeating Character in a Stream
//!   Link: https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
/* 

   Idea:
   - Use a hash map to **count frequencies** of each character.
   - Use a queue to maintain the **order of characters** as they arrive in the stream.
   - For every new character:
     - Increment its count.
     - Push it into the queue.
     - While queue is not empty and front has count > 1, pop it.
     - Append front of queue to result, or '#' if no non-repeating character.

   🔹 Steps:
   1. For each char in the stream:
      - count[ch]++
      - q.push(ch)
      - While (q.front() is repeating), q.pop()
      - Append q.front() or '#' to answer

   🕒 Time Complexity: O(n) — Each char enters and exits queue once
   💾 Space Complexity: O(1) — 26 characters max (assuming lowercase)

   🧠 Pattern:
   - Queue for **order maintenance**
   - Map for **frequency tracking**
   - Also applies to problems like:
     - First Negative Integer in Window (window-wise tracking)
     - LRU Cache (tracking recency and frequency)
*/

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Hash map to store frequency count of each character
        unordered_map<char, int> count;
        
        // Queue to store characters in the order they appear
        queue<int> q;

        // String to build the result with first non-repeating character at each step
        string ans = "";

        // Traverse each character in the input string
        for (int ch : s) {
            // Increment the count of the character
            count[ch]++;
            q.push(ch);
            
            // Check and remove characters from front of queue that have frequency > 1
            while (!q.empty()) {
                if (count[q.front()] > 1) {
                    // Repeating character, not a candidate
                    q.pop();
                } else {
                    // Found first non-repeating character
                    ans += q.front();
                    break;
                }
            }

            // If queue becomes empty, there is no non-repeating character
            if (q.empty()) ans += '#';
        }

        return ans;
    }
};

//!  🔍 Circular Tour (Gas Station Problem)
//!   Link: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

   /*
   Idea:
   - We need to find a starting petrol pump index from where a truck can complete the tour without running out of fuel.
   - Use two variables:
     - `balance` → current fuel balance while traversing stations.
     - `deficit` → total shortage whenever balance drops below 0.
   - If balance < 0 at any point, reset start to next station and accumulate the deficit.

   🔹 Steps:
   1. Traverse all stations once:
      - balance += gas[i] - cost[i]
      - if balance < 0:
          - deficit += balance
          - start = i + 1
          - balance = 0
   2. After traversal:
      - If (balance + deficit >= 0), return start
      - Else return -1

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(1)

   🧠 Pattern:
   - Greedy + Single Pass
   - Similar to problems like:
     - Jump Game (greedy with early resets)
     - Minimum platforms (greedy scheduling)
     - Interval merging (local decisions for global solution)
*/


class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int deficit = 0;  // total shortfall when fuel is not enough
        int balance = 0;  // current fuel balance
        int start = 0;    // current start station

        // Traverse each station once
        for(int i = 0; i < gas.size(); i++) {
            balance += gas[i] - cost[i];  // update balance at each station

            if(balance < 0) {
                // Can't reach the next station from current start
                // Accumulate the fuel deficit
                deficit += balance;

                // Reset start to the next station
                start = i + 1;

                // Reset balance since we're restarting the tour
                balance = 0;
            }
        }

        // After the loop:
        // If total fuel (balance + deficit) is non-negative, the journey is possible
        if(deficit + balance >= 0) return start;

        // Otherwise, no valid starting point exists
        return -1;
    }
};



//!  🔍 Interleave the First Half of the Queue with the Second Half
//!    Link: https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

   /*
   Idea:
   - Given a queue of even length, interleave its two halves.
   - Example: 
     Input  = {1, 2, 3, 4}
     Output = {1, 3, 2, 4}

   🔹 Steps:
   1. Push the first half of the queue into a temporary queue `nq`.
   2. While `nq` is not empty:
      - Push one element from `nq` (first half).
      - Push one element from the remaining original queue (second half).

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(n) for temporary queue

   🧠 Pattern:
   - Queue manipulation & interleaving
   - Similar techniques used in:
     - Stack ↔ Queue reversal
     - Simulating interleaved merges (like perfect shuffle)
*/

class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // Step1: Store first half into new queue
        queue<int> nq;
        int n = q.size();
        for(int i = 0; i < n/2; i++){
            nq.push(q.front());
            q.pop();
        }
        
        //Step2: Now append 1st half with second half into the queue while poping both the queues.
        // Poping orignal queue because second half is there and also for traversal
        
        while(!nq.empty()){
            q.push(nq.front());
            nq.pop();
            q.push(q.front());
            q.pop();
            
        }
        
        return q;
    }
};
