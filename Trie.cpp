#include <bits/stdc++.h>
using namespace std;

// Node Structure for Trie
struct Node {
    /* Array to store links to child nodes,
    each index represents a letter */
    Node* links[26] = {nullptr};  // Initialize all to nullptr

    /* Flag indicating if 
    the node marks the end 
    of a word */
    bool flag = false;

    /* Check if the node contains
    a specific key (letter) */
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    /* Insert a new node with a specific
    key (letter) into the Trie */
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    /* Get the node with a specific
    key (letter) from the Trie */
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    /* Set the current node
    as the end of a word */
    void setEnd() {
        flag = true;
    }

    /* Check if the 
    current node marks 
    the end of a word */
    bool isEnd() {
        return flag;
    }

    /* Node destructor to delete all child nodes recursively */
    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (links[i] != nullptr) {
                delete links[i];
                links[i] = nullptr;
            }
        }
    }
};

// Trie class
class Trie {
private:
    Node* root;

public:
    /* Constructor to 
    initialize the
    Trie with an 
    empty root node */
    Trie() {
        root = new Node();
    }

    /* Trie destructor to cleanup the root */
    ~Trie() {
        delete root;
    }

    /* Inserts a word into the Trie
    Time Complexity O(len), where len
    is the length of the word */
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                /* Create a new node for
                the letter if not present */
                node->put(ch, new Node());
            }
            // Move to the next node
            node = node->get(ch);
        }
        // Mark the end of the word
        node->setEnd();
    }

    /* Returns if the word
    is in the trie */
    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                /* If a letter is 
                not found, the word 
                is not in the Trie */
                return false;
            }
            // Move to the next node
            node = node->get(ch);
        }
        /* Check if the last node
        marks the end of a word */
        return node->isEnd();
    }

    /* Returns if there is any word in the
    trie that starts with the given prefix */
    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                /* If a letter is not 
                found, there is
                no word with the 
                given prefix */
                return false;
            }
            // Move to the next node
            node = node->get(ch);
        }
        // Prefix Found
        return true;
    }
};

int main() {
    Trie* trie = new Trie();
    vector<string> operations = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<vector<string>> arguments = { {}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"} };

    vector<string> output;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i] == "Trie") {
            output.push_back("null");
        } else if (operations[i] == "insert") {
            trie->insert(arguments[i][0]);
            output.push_back("null");
        } else if (operations[i] == "search") {
            bool result = trie->search(arguments[i][0]);
            output.push_back(result ? "true" : "false");
        } else if (operations[i] == "startsWith") {
            bool result = trie->startsWith(arguments[i][0]);
            output.push_back(result ? "true" : "false");
        }
    }

    for (string res : output) {
        cout << res << endl;
    }

    delete trie;
    return 0;
}