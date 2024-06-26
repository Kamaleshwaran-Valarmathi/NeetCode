// Reference: https://leetcode.com/problems/implement-trie-prefix-tree/



// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently 
// store and retrieve keys in a dataset of strings. There are various applications of this 
// data structure, such as autocomplete and spellchecker.

// Implement the Trie class:
// - Trie() Initializes the trie object.
// - void insert(String word) Inserts the string word into the trie.
// - boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// - boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 


// Example 1:
// ==========
// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
 


// Constraints:
// ============
// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.





class Node {
public:
    bool isEnd;
    vector<Node*> child;

    Node() {
        isEnd = false;
        child.resize(26, NULL);
    }
};

class Trie {
public:
    Node* root = new Node();

    Trie() {}
    
    void insert(string word) {
        Node* itr = root;
        for (char ch: word) {
            if (itr->child[ch - 'a'] == NULL)
                itr->child[ch - 'a'] = new Node();
            itr = itr->child[ch - 'a'];
        }
        itr->isEnd = true;
    }
    
    bool search(string word) {
        Node* itr = root;
        for (char ch: word) {
            if (itr->child[ch - 'a'] == NULL)
                return false;
            itr = itr->child[ch - 'a'];
        }
        return itr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* itr = root;
        for (char ch: prefix) {
            if (itr->child[ch - 'a'] == NULL)
                return false;
            itr = itr->child[ch - 'a'];
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
