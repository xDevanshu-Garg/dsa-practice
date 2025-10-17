#include <iostream>
#include <bits/stdc++.h>
using namespace std;


  class Solution {
public:
    int countGoodNumbers(long long n) {
        long long mod = 10e9 + 7;
        int a = n/2;
        int b = n-a;
        return mod % pow(4,a) * mod % pow(5,b);
    }