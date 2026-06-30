#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
SLIDING WINDOW TEMPLATES (C++)
===============================================================================

1. AT LEAST K / MINIMUM VALID WINDOW
------------------------------------
Question Pattern:
- at least K
- contains all required characters
- every required element present
- minimum valid window

Examples:
- LC 1358 Number of Substrings Containing All Three Characters
- LC 76 Minimum Window Substring
- Count substrings with at least K distinct

Template:

int i = 0;
int ans = 0;

for (int j = 0; j < n; j++) {

    add(s[j]);

    while (window_is_valid()) {

        // Count or update answer
        ans += ...;

        remove(s[i]);
        i++;
    }
}

===============================================================================

2. AT MOST K (Longest Valid Window)
-----------------------------------
Question Pattern:
- at most K
- longest valid window
- maximum length
- no more than K

Examples:
- Longest substring with at most K distinct
- Fruits Into Baskets
- Longest Repeating Character Replacement
- Max Consecutive Ones III

Template:

int i = 0;
int ans = 0;

for (int j = 0; j < n; j++) {

    add(s[j]);

    while (window_is_invalid()) {

        remove(s[i]);
        i++;
    }

    ans = max(ans, j - i + 1);
}

===============================================================================

3. COUNT SUBARRAYS WITH AT MOST K
---------------------------------
Question Pattern:
- Count valid subarrays
- Count substrings
- Count windows satisfying some constraint

Observation:
If window [i...j] is valid,
then every subarray ending at j and starting from i...j is also valid.

Number of such subarrays = (j - i + 1)

Examples:
- Count subarrays with at most K distinct
- Count subarrays with sum <= K

Template:

int i = 0;
long long ans = 0;

for (int j = 0; j < n; j++) {

    add(nums[j]);

    while (window_is_invalid()) {

        remove(nums[i]);
        i++;
    }

    ans += (j - i + 1);
}

===============================================================================

4. COUNT SUBARRAYS WITH AT LEAST K
----------------------------------
Question Pattern:
- Count substrings having at least...
- Count windows containing all required elements

Observation:
Once [i...j] becomes valid,
every extension to the right is also valid.

Count = (n - j)

Examples:
- LC 1358

Template:

int i = 0;
long long ans = 0;

for (int j = 0; j < n; j++) {

    add(s[j]);

    while (window_is_valid()) {

        ans += (n - j);

        remove(s[i]);
        i++;
    }
}

===============================================================================

5. EXACTLY K
------------
Almost never solved directly.

Formula:

Exactly(K) = AtMost(K) - AtMost(K-1)

Examples:
- LC 992 Subarrays with K Different Integers
- Binary Subarrays With Sum K

Template:

answer = atMost(k) - atMost(k - 1);

===============================================================================

6. FIXED SIZE WINDOW
--------------------
Question Pattern:
- Window size is exactly K

Examples:
- Maximum Sum of Size K
- Maximum Average Subarray
- Sliding Window Maximum

Template:

int i = 0;

for (int j = 0; j < n; j++) {

    add(nums[j]);

    if (j - i + 1 > k) {

        remove(nums[i]);
        i++;
    }

    if (j - i + 1 == k) {

        update_answer();
    }
}

===============================================================================

7. MINIMUM WINDOW
-----------------
Question Pattern:
- Smallest valid window
- Minimum length satisfying condition

Example:
- LC 76 Minimum Window Substring

Template:

int i = 0;
int ans = INT_MAX;

for (int j = 0; j < n; j++) {

    add(s[j]);

    while (window_is_valid()) {

        ans = min(ans, j - i + 1);

        remove(s[i]);
        i++;
    }
}

===============================================================================

MENTAL DECISION TREE
--------------------

Need LONGEST valid window?
    -> Expand
    -> Shrink while INVALID
    -> ans = max(ans, window_size)

Need SHORTEST valid window?
    -> Expand
    -> Shrink while VALID
    -> ans = min(ans, window_size)

Need COUNT of valid subarrays?

    At Most K?
        ans += (j - i + 1)

    At Least K?
        ans += (n - j)

Need EXACTLY K?
    AtMost(K) - AtMost(K - 1)

Need FIXED SIZE?
    Keep window size == K

===============================================================================

Quick Recognition:

Longest  ----------> Shrink while INVALID
Shortest ----------> Shrink while VALID

Count At Most -----> ans += (j - i + 1)
Count At Least ----> ans += (n - j)

Exactly K ---------> AtMost(K) - AtMost(K-1)

Fixed Size --------> No while loop, maintain size K

===============================================================================
*/