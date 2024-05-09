// Reference: https://leetcode.com/problems/design-add-and-search-words-data-structure/



// Design a data structure that supports adding new words and finding if a string matches any 
// previously added string.

// Implement the WordDictionary class:
// - WordDictionary() Initializes the object.
// - void addWord(word) Adds word to the data structure, it can be matched later.
// - bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 


// Example:
// ========
// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
 


// Constraints:
// ============
// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 10^4 calls will be made to addWord and search.





class Node {
public:
    bool isEnd = false;
    unordered_map<char, Node*> child;

    Node() {}
};

class WordDictionary {
public:
    Node* root = new Node();

    WordDictionary() {}
    
    void addWord(string word) {
        Node* itr = root;
        for (char ch: word) {
            if (itr->child.find(ch) == itr->child.end())
                itr->child[ch] = new Node();
            itr = itr->child[ch];
        }
        itr->isEnd = true;
    }

    bool searchUtil(int idx, Node* root, string& word) {
        if (idx == word.size())
            return root->isEnd;
        if (word[idx] == '.') {
            for (auto [ch, node]: root->child) {
                if (searchUtil(idx+1, node, word))
                    return true;
            }
            return false;
        } else {
            if (root->child.find(word[idx]) == root->child.end())
                return false;
            return searchUtil(idx+1, root->child[word[idx]], word);
        }
    }
    
    bool search(string word) {
        return searchUtil(0, root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
