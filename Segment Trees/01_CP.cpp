/*
============================================================
                SEGMENT TREE TEMPLATE
        (Range Maximum Query + Point Update)
============================================================

HOW TO USE:

1) Create object:
      SegTree st(n);

2) Build:
      st.build(arr);

3) Query:
      st.query(l, r);

4) Update:
      st.update(index, newValue);

Time Complexity:
    Build  : O(n)
    Query  : O(log n)
    Update : O(log n)

Space: O(4n)
============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class SegTree {
public:
    int n;
    vector<int> seg;

    // Constructor
    SegTree(int size) {
        n = size;
        seg.resize(4 * n);
    }

    /*================= BUILD =================*/
    void build(int ind, int low, int high, vector<int>& arr) {

        if(low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid + 1, high, arr);

        seg[ind] = max(seg[2*ind + 1], seg[2*ind + 2]);
    }

    void build(vector<int>& arr) {
        build(0, 0, n-1, arr);
    }

    /*================= QUERY =================*/
    int query(int ind, int low, int high, int l, int r) {

        // Complete overlap
        if(low >= l && high <= r)
            return seg[ind];

        // No overlap
        if(low > r || high < l)
            return INT_MIN;

        int mid = (low + high) / 2;

        int left = query(2*ind + 1, low, mid, l, r);
        int right = query(2*ind + 2, mid + 1, high, l, r);

        return max(left, right);
    }

    int query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    /*================= POINT UPDATE =================*/
    void update(int ind, int low, int high, int idx, int val) {

        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) / 2;

        if(idx <= mid)
            update(2*ind + 1, low, mid, idx, val);
        else
            update(2*ind + 2, mid + 1, high, idx, val);

        seg[ind] = max(seg[2*ind + 1], seg[2*ind + 2]);
    }

    void update(int idx, int val) {
        update(0, 0, n-1, idx, val);
    }
};


/*
==================== EXAMPLE USAGE ====================

int main() {

    vector<int> arr = {8,2,5,1,4,5,3,9,6,10};

    SegTree st(arr.size());
    st.build(arr);

    cout << st.query(3,8) << endl;  // 9

    st.update(3, 100);              // arr[3] = 100

    cout << st.query(3,8) << endl;  // 100

}
=======================================================
*/
