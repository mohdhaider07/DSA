#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// trie node
// /***********************************THIS PROGRAM WORKING FILE ISSUE WITH THE COMPILER       *////////////////////

class TrieNode
{
public:
    vector<TrieNode *> children; // A vector to hold pointers to the next TrieNode for each character
    bool isEndOfWord;            // Flag to check if this node marks the end of a word

    TrieNode() : children(26, nullptr), isEndOfWord(false) {} // Constructor initializes 26 children to nullptr and isEndOfWord to false
};

class Trie
{
    TrieNode *root; // Root of the Trie

public:
    Trie()
    {
        root = new TrieNode(); // Initialize the root
    }

    // Insert a word into the Trie
    void insertWord(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a'; // Calculate the index for the character
            if (node->children[index] == NULL)
            { // If the child node doesn't exist, create a new node
                TrieNode *newNode = new TrieNode();
                node->children[index] = newNode;
            }
            node = node->children[index]; // Move to the child node
        }
        node->isEndOfWord = true; // Mark the end of the word
    }

    // Search for a word in the Trie
    bool searchWord(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a'; // Calculate the index for the character
            if (node->children[index] == NULL)
            { // If the child node doesn't exist, return false
                return false;
            }
            node = node->children[index]; // Move to the child node
        }
        return node->isEndOfWord; // Return true if it's the end of a word, otherwise false
    }

    // Check if there is any word in the Trie that starts with the given prefix
    bool startWith(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a'; // Calculate the index for the character
            if (node->children[index] == NULL)
            { // If the child node doesn't exist, return false
                return false;
            }
            node = node->children[index]; // Move to the child node
        }
        return true; // Return true if all characters of the prefix are found
    }

    // Count how many words start with the given prefix
    int countStartWith(string word)
    {
        TrieNode *node = root;
        int count = 0;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';         // Calculate the index for the character
            if (node->children[index] == NULL) // If the child node doesn't exist, return 0
                return 0;
            node = node->children[index]; // Move to the child node
        }
        for (int i = 0; i < node->children.size(); i++)
        {
            if (node->children[i] != NULL)
            {
                count++; // Count non-null children
            }
        }
        return count; // Return the count of words starting with the given prefix
    }

    // Helper function to erase a word from the Trie
    bool eraseHelper(string word, int depth, TrieNode *node)
    {
        if (!node) // If the node is null, return false
            return false;
        if (depth == word.size())
        {                           // If we have reached the end of the word
            if (!node->isEndOfWord) // If it's not the end of a word, return false
                return false;
            node->isEndOfWord = false;                             // Mark it as not the end of a word
            return node->children == vector<TrieNode *>(26, NULL); // Return true if all children are null
        }
        int index = word[depth] - 'a'; // Calculate the index for the character
        if (eraseHelper(word, depth + 1, node->children[index]))
        {                                 // Recursively erase the next character
            delete node->children[index]; // Delete the node if it's safe to delete
            node->children[index] = NULL;
            return !node->isEndOfWord && node->children == vector<TrieNode *>(26, NULL); // Return true if the node has no children and is not the end of a word
        }
        return false;
    }

    // Erase a word from the Trie
    void erase(string word)
    {
        TrieNode *node = root;
        eraseHelper(word, 0, node); // Call the helper function to erase the word
    }

    // Find the longest complete string in the array of strings
    string longestCompleteString(vector<string> str)
    {
        int n = str.size();
        bool flag = false;
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            string word = "";
            for (int j = 0; j < str[i].size(); j++)
            {
                word = word + str[i][j];           // Build the prefix
                bool wordExist = searchWord(word); // Check if the prefix exists in the Trie
                if (!wordExist)
                { // If any prefix doesn't exist, set the flag to true and break
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                flag = false; // Reset the flag and continue to the next word
                continue;
            }
            ans.push_back(word); // If all prefixes exist, add the word to the answer
        }

        return ans.empty() ? "None" : *max_element(ans.begin(), ans.end()); // Return the lexicographically smallest string or "None" if no complete string found
    }

    int countDistinctSubstrings(string word)
    {
        int ans = 0;
        for (int i = 0; i < word.size(); i++)
        {
            TrieNode *node = root;
            // string word = "";
            for (int j = i; j < word.size(); j++)
            {

                int index = word[j] - 'a';
                if (node->children[index] == NULL)
                {
                    TrieNode *newNode = new TrieNode();
                    node->children[index] = newNode;
                }

                node = node->children[index];
                if (!node->isEndOfWord)
                {
                    node->isEndOfWord = true;
                    ans++;
                }
            }
        }
        return ans + 1;
    }
};

int main()
{
    cout << "Trie code \n";

    vector<string> str;

    // creating new Node
    Trie trie;
    // n ni nin ninj ninja ninga
    // str.push_back("n");
    // str.push_back("ni");
    // str.push_back("nin");
    // str.push_back("ninj");
    // str.push_back("ninja");
    // str.push_back("ninga");
    // // str.push_back("n");

    // trie.insertWord("n");
    // trie.insertWord("ni");
    // trie.insertWord("nin");
    // trie.insertWord("ninj");
    // trie.insertWord("ninja");
    // trie.insertWord("abc");

    cout << trie.countDistinctSubstrings("aa") << endl;

    return 0;
}