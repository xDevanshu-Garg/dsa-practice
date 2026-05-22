#include <iostream>
#include <string>
using namespace std;

class TrieNode {
    // TrieNode class represents a single node in the Trie
public:
    char data;
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr; // Initialize all children to nullptr
        
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

     void insertUtil(TrieNode* node, const string &word, int i) {
    if (i == word.size()) {
        node->isEndOfWord = true;
        return;
    }

    int index = word[i] - 'a';
    TrieNode* child;

        //Present
        if(node->children[index] != nullptr) { 
            child = node->children[index]; // Move to the child node
        }
        //Absent
        else{
            child = new TrieNode(word[i]); // Create a new TrieNode
            node->children[index] = child;
        }

    insertUtil(child, word, i + 1);
}


    void insert(string word) {
        insertUtil(root, word, 0);
    }
    
    bool searchUtil(TrieNode* root, const string &word, int i){
        //Base Case
        if(i == word.size())
            return root->isEndOfWord;

        int index = word[i] - 'a'; // what happend if i type '0'
        TrieNode* child;

        //Present
        if(root->children[index])
            child = root->children[index];
        //absent
        else
            return false;

        //RR
        return searchUtil(child, word, i+1);
    }

    bool search(string word) {
        return searchUtil(root, word, 0);
    }

    bool startsWithUtil(TrieNode* root, const string &word, int i){
        //Base Case
        if(i == word.size())
            return true;

        int index = word[i] - 'a'; // what happend if i type '0'
        TrieNode* child;

        //Present
        if(root->children[index])
            child = root->children[index];
        //absent
        else
            return false;

        //RR
        return startsWithUtil(child, word, i+1);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix, 0);
    }
    
    //Delete: go to terminal node and set isEndOfWord to false
    bool deleteWordUtil(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        // BASE CASE: end of word
        if (depth == word.length()) {
            if (!node->isEndOfWord) return false; // word doesn't exist
            node->isEndOfWord = false;

            // If this node has no children → deletable
            for (int i = 0; i < 26; ++i)
                if (node->children[i]) return false;
            return true;
        }

        int index = word[depth] - 'a';
        TrieNode* child = node->children[index];
        if (!child) return false; // character not found

        // RECURSE: try deleting child
        bool shouldDeleteChild = deleteWordUtil(child, word, depth + 1);

        // If child can be deleted, free memory
        if (shouldDeleteChild) {
            delete child;
            node->children[index] = nullptr;

            // Check if this node can also be deleted
            if (!node->isEndOfWord) {
                for (int i = 0; i < 26; ++i)
                    if (node->children[i]) return false;
                return true;
            }
        }

        return false;
    }


    void deleteWord(string word){
        if(search(word))
            deleteWordUtil(root, word, 0);
        else cout << "Word doesn't exist!" << endl;
    }

    void freeNode(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i])
                freeNode(node->children[i]);
        }
        delete node;
    }

    ~Trie() {
        freeNode(root);
    }

};

int main() {
    // TC = O(l) where l is len of word
    Trie t;
    t.insert("abcd");
    cout << "abcd is " << (t.search("abcd") ? "Present" : "Absent") << endl;
    cout << "abc is " << (t.search("abc") ? "Present" : "Absent");
}