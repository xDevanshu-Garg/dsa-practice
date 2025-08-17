#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Step1: Convert wordList to set so we can find and erase it
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        //Edge Case if: if endWord are not in wordList

        if(wordSet.find(endWord) == wordSet.end()) return 0;

        //BFS TIME!!
        int step = 1;
        queue<string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);

        while(!q.empty()) {

            int size = q.size();
            for (int s = 0; s < size; s++) { // Tp track levels

                string word = q.front();
                q.pop();

                if(word == endWord) return step; //Early return

                for (int i = 0; i < word.length(); i++) {
                    char original = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if(wordSet.find(word) != wordSet.end()) { //word found
                            q.push(word);
                            wordSet.erase(word); //Delete the entry
                        }
                    }
                    word[i] = original; // restore original char
                }
            }
            step++;
        }
        return 0;
    }
};