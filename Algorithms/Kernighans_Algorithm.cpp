//Brian Kernighan’s Algorithm is used to count set bits of a number in limited operations i.e. op = no. of set bits in case of num = 53 only 4 operations, otherwise in 32 bit system it would take us 32 operations and in 64 bit system 64 operation  
// 53 = 1 1 0 1 0 1

//How it works: This algo jumps to set bits like it'll first see rightmost 1 
// 1) using rightmost set bit mask(rsbm) (num & -num) 
// 2) count it and make that 1 -> 0 by doing num - rsbm or taking xor b/w num ^ rsbm
// 3) repeat 1 and 2 till number become 0


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countSetBits (int num) {
    int count = 0;

    while(num != 0) {
        int rsbm = num & -num;
        count++;
        num -= rsbm;
    }
    return count;
}

int main() {
    
    int num = 53;

    cout << "No of set bits in " << num << " are: " << countSetBits (num) << endl;
    return 0;
}