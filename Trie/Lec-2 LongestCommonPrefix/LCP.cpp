// ! ✏️ Longest Common Prefix in Array of Strings
// !  Problem: https://leetcode.com/problems/longest-common-prefix/

/*
   ✅ Brute Force Approach (O(N*M)):
   - For every adjacent pair of strings, compare character by character
   - Track the **minimum match length** across all pairs
   - Return the prefix from the first string with this length

   Steps:
   1. Loop from i = 0 to n-2
   2. For strs[i] and strs[i+1], count matching prefix characters
   3. Track min(count) → result length
   4. Return strs[0].substr(0, minLen)

   🔸 Time Complexity: O(N*M) where:
       N = number of strings
       M = average length of each string
   🔸 Space Complexity: O(1)
*/

////////////////////////////////////////////////////

/* ✅ Trie Approach (Efficient & Structured)

   🎯 Idea:
   - Insert all strings into Trie
   - Traverse Trie from root and collect characters **until**:
     1. Node has more than one child
     2. OR current node is end of a word

   🔧 TrieNode:
   - `char data`
   - `children[26]` → for lowercase letters
   - `isEndOfWord`
   - `childCount` → to know if branching occurred

   🪜 Steps:
   1. Insert all strings into Trie
   2. Traverse from root using first word as guide
   3. Stop when:
      - `childCount > 1` → branching
      - OR `isEndOfWord == true`

   📦 Variables:
   - `TrieNode` → for each character
   - `insert()` → to build the Trie
   - `LCP()` → to extract longest common prefix

   🕒 Time Complexity: O(N*M)
       N = number of strings
       M = average length of strings
   💾 Space Complexity: O(N*M)
       - For Trie node storage

   ✨ Use Cases:
   - Great for problems involving prefix search
   - Scales well when used in autocomplete, dictionary queries, etc.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ************BRUTE FORCE*************** TC O(N*M)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini = INT_MAX;
        if(strs.size() == 1) return strs[0];
        for(int i = 0; i < strs.size()-1; i++){
            int count = 0;
            for(int j = 0; (j < strs[i].length()) && (j < strs[i+1].length()); j++){
                if (strs[i][j] == strs[i+1][j]){
                    count++;
                }
                else break;
            }
            mini = min(mini, count);
        }
        return strs[0].substr(0,mini);
    }
};

// ***************USING TRIE*****************
class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isEndOfWord;
    int childCount = 0; //Added this to count how many childs are there

    TrieNode(char data){
        this->data = data;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr; // Initialize all children to nullptr
        
        isEndOfWord = false;
    }
};

class Trie{
  public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');  // root with null character
    }

    void insertUtil(TrieNode* node, const string& word, int i){
        //Base Case
        if(i == word.length()){
            node->isEndOfWord = true;
            return;
        }

        int index = word[i] - 'a';
        TrieNode* child;
        //Present
        if(node->children[index]){
            child = node->children[index];
        }
        //Absent
        else{
            child = new TrieNode(word[i]);
            node->children[index] = child;
            node->childCount++;
        }
        insertUtil(child, word, i+1);
    }

    void insert(string word){
        insertUtil(root, word, 0);
    }

    void LCP(const string& word, string &ans) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->childCount == 1 && !curr->isEndOfWord) {
                int index = word[i] - 'a';
                ans += word[i];
                curr = curr->children[index];
            } else {
                break;
            }
        }
    }
    
    
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        //Insert all strings into Trie
        for(auto &str: strs){
            t.insert(str);
        }
        
        //if a node has more then 1 children then break otherwise add to ans;
        string ans;
        t.LCP(strs[0], ans);
        return ans;
    }
};