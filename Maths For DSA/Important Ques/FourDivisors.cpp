#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/four-divisors

/************************************************************
 * LeetCode 1390 - Four Divisors
 *
 * Problem:
 * Given an array nums, for each number x:
 * - If x has exactly 4 positive divisors,
 *   add the sum of those divisors to the answer.
 * - Otherwise, ignore it.
 *
 * Return the total sum.
 ************************************************************/


/************************************************************
 * APPROACH 1: BRUTE FORCE (Direct Divisor Counting)
 *
 * IDEA:
 * For each number x:
 * - Count its divisors by looping from 1 to sqrt(x)
 * - If i divides x:
 *      - i is a divisor
 *      - x/i is also a divisor (if different)
 * - Stop early if divisor count exceeds 4
 * - If count == 4, add their sum
 *
 * WHY THIS WORKS:
 * Constraints are small:
 * nums[i] <= 1e5
 * nums.size() <= 1e4
 ************************************************************/

class SolutionBruteForce {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int cnt = 0;   // number of divisors
            int sum = 0;   // sum of divisors

            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int d1 = i;
                    int d2 = x / i;

                    cnt++;
                    sum += d1;

                    if (d1 != d2) {
                        cnt++;
                        sum += d2;
                    }

                    // More than 4 divisors → invalid
                    if (cnt > 4) break;
                }
            }

            if (cnt == 4)
                ans += sum;
        }

        return ans;
    }
};

/*
TIME COMPLEXITY:
For each number → O(√x)
Overall → O(n * √max(nums[i]))

SPACE COMPLEXITY:
O(1)
*/



/************************************************************
 * APPROACH 2: OPTIMIZED (Math / Number Theory)
 *
 * KEY OBSERVATION:
 * A number has EXACTLY 4 divisors if and only if:
 *
 * 1) x = p^3   (p is prime)
 *    Divisors: 1, p, p^2, p^3
 *
 * 2) x = p * q (p and q are DISTINCT primes)
 *    Divisors: 1, p, q, p*q
 *
 * Any other form gives <4 or >4 divisors.
 ************************************************************/

class SolutionOptimized {
public:
    // Helper function to check primality
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {

            /******** Case 1: x = p^3 ********/
            int p = cbrt(x);
            if (p * p * p == x && isPrime(p)) {
                // divisors: 1 + p + p^2 + p^3
                ans += (1 + p + p * p + x);
                continue;
            }

            /******** Case 2: x = p * q ********/
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;

                    // p and q must be distinct primes
                    if (i != j && isPrime(i) && isPrime(j)) {
                        // divisors: 1 + i + j + x
                        ans += (1 + i + j + x);
                    }
                    break; // only one factorization needed
                }
            }
        }

        return ans;
    }
};

/*
TIME COMPLEXITY:
Worst case → O(n * √x)
But practically faster due to:
- Early factor detection
- Early exits

SPACE COMPLEXITY:
O(1)
*/



/************************************************************
 * FINAL NOTES (REVISION):
 *
 * - Brute force is acceptable due to constraints.
 * - Optimized solution shows number theory insight.
 * - EXACTLY 4 divisors ⇒ only two valid forms:
 *      p^3 or p*q
 *
 * Interview Tip:
 * Always mention the divisor-pattern observation.
 ************************************************************/