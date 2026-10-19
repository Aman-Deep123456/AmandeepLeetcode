#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    // FIX: Constructor added to initialize pointers to nullptr
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix(); // Tracks words sharing this prefix
        }
        node->increaseEnd(); // Tracks the exact word completion
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void erase(string word) {
        // Prevents reducing prefix counts if the word doesn't actually exist
        if (countWordsEqualTo(word) == 0) return; 

        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            } else {
                return;
            }
        }
        node->deleteEnd();
    }
};
