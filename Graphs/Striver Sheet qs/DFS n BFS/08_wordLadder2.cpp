#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

void DFS(string node, string beginWord, unordered_map<string, unordered_set<string>> &parentMap,
         vector<string> &seq, vector<vector<string>> &ans) {
    
    seq.push_back(node); // include current word
    
    if(node == beginWord) {
        ans.push_back(seq);
    } else {
        for(auto &nei: parentMap[node]) {
            DFS(nei, beginWord, parentMap, seq, ans);
        }
    }
    
    seq.pop_back(); // backtrack
}

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        
        //Step1: Convert wordList to set so we can find and erase it
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        //Edge Case if: if endWord are not in wordList
        if(wordSet.find(endWord) == wordSet.end()) return ans;

        unordered_map<string, unordered_set<string>> parentMap; //To create a child parent mapping

        //BFS TIME!! in world ladder 2 erase only when level is completed
        queue<string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);
        unordered_set<string> toBeDeleted; //To not store dups
        bool found = false;

        while(!q.empty()) {

            int size = q.size();
            for (int s = 0; s < size; s++) { // To track levels

                string word = q.front();
                string parent = word;
                q.pop();

                if(word == endWord){
                    found = true;
                    break;
                }

                for (int i = 0; i < word.length(); i++) {
                    char original = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if(wordSet.find(word) != wordSet.end()) { //word found
                            q.push(word);
                            parentMap[word].insert(parent);
                            toBeDeleted.insert(word);
                        }
                    }
                    word[i] = original; // restore original char
                }
            }

            if(found) break;
            for(auto& word: toBeDeleted){
                wordSet.erase(word); //Delete the entry after level
            }
            toBeDeleted.clear();
        }

        //Backtrack endWord to beginWord
        vector<string> seq;
        DFS(endWord, beginWord, parentMap, seq, ans);

        for(auto &seq: ans) {
            reverse(seq.begin(), seq.end());
        }
        return ans;
    }
};