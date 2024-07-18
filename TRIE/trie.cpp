#include <iostream>
#include <vector>
using namespace std;
// trie node
// /***********************************THIS PROGRAM WORKING FILE ISSUE WITH THE COMPILER       *////////////////////

class TrieNode
{
public:
    vector<TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : children(26, nullptr), isEndOfWord(false) {}
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    // Insert Word
    void insertWord(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            cout << "index is " << index << endl;
            if (node->children[index] == NULL)
            {
                TrieNode *newNode = new TrieNode();
                node->children[index] = newNode;
            }
            node = node->children[index];
        }

        node->isEndOfWord = true;
    }

    bool searchWord(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {

            int index = word[i] - 'a';
            if (node->children[index] == NULL)
            {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    bool startWith(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (node->children[index] == NULL)
            {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
    int countStartWith(string word)
    {
        TrieNode *node = root;
        int count = 0;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (node->children[index] == NULL)
                return 0;

            node = node->children[index];
        }

        for (int i = 0; i < node->children.size(); i++)
        {
            if (node->children[i] != NULL)
            {
                count++;
            }
        }
        return count;
    }

    bool eraseHelper(string word, int depth, TrieNode *node)
    {
        if (!node)
            return false;
        if (depth == word.size())
        {
            if (!node->isEndOfWord)
                return false;

            node->isEndOfWord = false;
            return node->children == vector<TrieNode *>(26, NULL);
        }

        int index = word[depth] - 'a';

        if (eraseHelper(word, depth + 1, node->children[index]))
        {
            delete node->children[index];
            node->children[index] = NULL;

            return !node->isEndOfWord && node->children == vector<TrieNode *>(26, NULL);
        }
        return false;
    }
    void erase(string word)
    {
        TrieNode *node = root;
        cout << "deleted or not " << eraseHelper(word, 0, node);
    }
};

int main()
{
    cout << "Haider";
    vector<string> v;
    v.push_back("NEW");
    v.push_back("DOSE");
    v.push_back("HOW");
    v.push_back("THESE");
    // creating new Node
    Trie trie;
    trie.insertWord("haider");
    trie.insertWord("sadiq");
    trie.insertWord("saif");
    trie.insertWord("tauseef");

    cout << "is the haider exist in the word " << trie.searchWord("haiderd") << endl;
    cout << "is the hai start word exist " << trie.startWith("haider") << endl;
    cout << "count the sa start word " << trie.countStartWith("sa") << endl;

    cout << "eraseing the word haider ";
    trie.erase("haider");
    cout << "is the hai start word exist " << trie.startWith("haider") << endl;

    return 0;
}