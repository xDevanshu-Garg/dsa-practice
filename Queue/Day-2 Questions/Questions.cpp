//! Queue Reversal: https://www.geeksforgeeks.org/problems/queue-reversal/1

//? **********************USING STACKS***********************
//uesd commenly
/*
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

*/
//? *********************USING RECURSION***********************
//TLE recursion works but not optimal for large test cases
//Base Case
/*
if(q.size() == 1) return q;

//RR
int ele = q.front();
q.pop();
q = reverseQueue(q);
q.push(ele);

return q;
*/

//! First negative in every window of size k: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1


//************************Two pointers******************************
//Gives TLE, TC= O(n*k), where k is size of window
/*
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
*/

// **********************Using Deque**************************************

/*
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
*/

//!239. Sliding Window Maximum: https://leetcode.com/problems/sliding-window-maximum/?envType=problem-list-v2&envId=queue

/*
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
*/

//! First Non-Repeating character in stream: https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
/*
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
*/

//! Circular tour: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

/*
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
*/

//! Interleave the First Half of the Queue with Second Half: https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1
/*
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
*/