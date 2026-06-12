#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
========================================
MODULAR EXPONENTIATION (Binary Exponentiation)
========================================

When to use:
- Compute (a^b) % MOD efficiently.
- Fermat's Little Theorem.
- Modular inverse.
- Large powers (b up to 1e18).

Complexity:
O(log b)
*/

long long modPow(long long base, long long exp, long long MOD) {
    long long ans = 1;

    while (exp) {
        if (exp & 1)
            ans = (ans * base) % MOD;

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return ans;
}