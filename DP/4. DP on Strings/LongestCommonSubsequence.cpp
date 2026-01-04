#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem types on DP on Strings: Comparisions, replaces/edits

//Subsequence: A sub string with same order of elements that may or may not be contiguious. 
//"abc": "" "a" "b" "c" "ab" "bc" "ac" "abc (2^n)

//! https://leetcode.com/problems/longest-common-subsequence/

// LCS cannot be solved greedily because sometimes you must skip a matching character to allow a longer match later.
// s1 = "abcxyz", s2 = "gbxyzc"
// Output: "bxyz"
// But greedy will give output bc or c or xyz yz z so max is xyz of 3 length not bxyz of len 4, why? because sometimes you must skip a matching character to allow a longer match in future and future can only be seen by DP.
