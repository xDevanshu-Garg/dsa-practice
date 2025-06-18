#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 3;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    
    for(int i = 0; i<m; i++){
        nums1.pop_back();
    }
    for(int i:nums2){
        nums1.push_back(i);
    }
    sort(nums1.begin(), nums1.end());

    for(int i:nums1){
        cout<<i<<' ';
    }

    return 0;
}