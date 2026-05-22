#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public: 
    TrieNode* children[26];
    bool isTerminal;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie {
private: 
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for(auto ch: word) {
            int ind = ch - 'a';

            if(!node->children[ind])
                node->children[ind] = new TrieNode();

            node = node->children[ind];
        }

        node->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;

        for(auto ch: word) {
            int ind = ch - 'a';

            if(!node->children[ind]) return false;

            node = node->children[ind];
        }

        return node->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for(auto ch: prefix) {
            int ind = ch - 'a';

            if(!node->children[ind]) return false;

            node = node->children[ind];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 int main() {
    Trie* obj = new Trie();
    obj->insert("cat");
    obj->insert("car");
    obj->insert("dog");

    if(obj->startsWith("do")) cout << "YES do exists" << endl;

    if(obj->search("cat")) cout << "YES cat exists" << endl;

    if(obj->search("ca")) cout << " YES ca exists" << endl; 
    else cout << "ca not exists" << endl;
    
    return 0;
 }