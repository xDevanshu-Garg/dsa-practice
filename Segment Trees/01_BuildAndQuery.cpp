// EXAMPLE: arr = [8 2 5 1 4 5 3 9 6 10], n = 10, query ex: l=3, r=8, ans = 9

/*
============================================================
                SEGMENT TREE (RANGE MAX QUERY)
============================================================

WHY DO WE USE SEGMENT TREE?
------------------------------------------------------------
Suppose:
- We have an array of size n.
- We need to answer multiple range queries like:
    -> Maximum in range [l, r]
    -> Sum in range [l, r]
- Brute force takes O(n) per query.
- If we have q queries → O(n*q) (Too slow for large n)

Segment Tree helps:
    Build Time  : O(n)
    Query Time  : O(log n)
    Update Time : O(log n)

It divides array into segments and stores useful info
(max, sum, min etc.) for each segment.

------------------------------------------------------------
HOW MANY NODES DOES SEGMENT TREE HAVE?
------------------------------------------------------------
For an array of size n:

Worst case number of nodes < 4*n

Why?
Because:
- A complete binary tree with n leaves
- Total nodes ≈ 2*n - 1
- To be safe (for uneven splits), we allocate 4*n

So we declare:
    int seg[4*n];

------------------------------------------------------------
TREE REPRESENTATION (0-BASED INDEXING)
------------------------------------------------------------

For node at index i:

Left Child  → 2*i + 1
Right Child → 2*i + 2

Root index = 0

------------------------------------------------------------
WHAT DOES EACH NODE STORE?
------------------------------------------------------------
Each node stores:
    Maximum value of its segment.

If node represents range [low, high],
seg[ind] = max value in that range.

------------------------------------------------------------
RANGE REPRESENTATION
------------------------------------------------------------
Every recursive call maintains:

ind  → current node index
low  → start of segment
high → end of segment

------------------------------------------------------------
QUERY LOGIC (3 CASES)
------------------------------------------------------------
Given query range [l, r]:

1) Complete Overlap:
    If current segment fully inside query range:
        return seg[ind]

2) No Overlap:
    If current segment completely outside:
        return INT_MIN (identity for max)

3) Partial Overlap:
    Divide into left and right
    Return max(leftResult, rightResult)

------------------------------------------------------------
TIME COMPLEXITY
------------------------------------------------------------
Build  : O(n)
Query  : O(log n)
Space  : O(4n)

============================================================
*/

#include <bits/stdc++.h>
using namespace std;

int a[100005];          // Original array
int seg[4 * 100005];    // Segment tree array

/*
============================================================
BUILD FUNCTION
------------------------------------------------------------
Purpose:
    Builds the segment tree.

Parameters:
    ind  → current node index
    low  → start index of segment
    high → end index of segment
============================================================
*/
void build(int ind, int low, int high) {

    // Base Case: Leaf Node
    if(low == high) {
        seg[ind] = a[low];
        return;
    }

    int mid = low + (high - low) / 2;

    // Build left subtree
    build(2*ind + 1, low, mid);

    // Build right subtree
    build(2*ind + 2, mid + 1, high);

    // Internal node stores max of children
    seg[ind] = max(seg[2*ind + 1], seg[2*ind + 2]);
}


/*
============================================================
QUERY FUNCTION (Range Maximum Query)
------------------------------------------------------------
Returns maximum value in range [l, r]

Parameters:
    ind  → current node index
    low  → segment start
    high → segment end
    l    → query left
    r    → query right
============================================================
*/
int query(int ind, int low, int high, int l, int r) {

    // 1️⃣ Complete Overlap
    if(low >= l && high <= r)
        return seg[ind];

    // 2️⃣ No Overlap
    if(low > r || high < l)
        return INT_MIN;

    // 3️⃣ Partial Overlap
    int mid = low + (high - low) / 2;

    int left = query(2*ind + 1, low, mid, l, r);
    int right = query(2*ind + 2, mid + 1, high, l, r);

    return max(left, right);
}


int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // Build segment tree
    build(0, 0, n - 1);

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while(q--) {
        int l, r;
        cout << "Enter query range l r: ";
        cin >> l >> r;

        cout << "Maximum in range [" << l << ", " << r << "] = "
             << query(0, 0, n - 1, l, r) << endl;
    }

    return 0;
}


/*
============================================================
                    REVISION NOTES
============================================================

1) Segment Tree is used when:
   - Multiple range queries
   - Frequent updates
   - Need faster than O(n) per query

2) Node Count:
   - Allocate 4*n space

3) Indexing:
   - Root = 0
   - Left = 2*i + 1
   - Right = 2*i + 2

4) Query Cases:
   - Complete Overlap → return seg[ind]
   - No Overlap → return identity (INT_MIN here)
   - Partial → split and combine

5) Identity Element:
   - For Max → INT_MIN
   - For Min → INT_MAX
   - For Sum → 0

6) Complexity:
   - Build  → O(n)
   - Query  → O(log n)
   - Update → O(log n)

7) Very Important:
   Segment Tree depth = O(log n)
   So recursion stack also O(log n)

Next Step to Learn:
   → Point Update
   → Range Update
   → Lazy Propagation

============================================================
*/