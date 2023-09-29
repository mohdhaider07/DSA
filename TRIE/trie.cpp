#include <iostream>
#include <vector>
using namespace std;
// trie node
// /***********************************THIS PROGRAM WORKING FILE ISSUE WITH THE COMPILER       *////////////////////
class Node
{
public:
    Node *child[26];
    bool isTerminal;
    Node()
    {
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] == NULL;
        }
    }
};

void insertDir(string word, Node *trie)
{
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        if (trie->child[word[i] - 'A'] == NULL)
        {
            Node *newNode = new Node();
            trie->child[word[i] - 'A'] = newNode;
        }
        trie = trie->child[word[i] - 'A'];
    }
    trie->isTerminal = true;
}

bool searchDir(string word, Node *trie)
{
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        if (trie->child[word[i] - 'A'] == NULL)
            return false;
        trie = trie->child[word[i] - 'A'];
    }
    return trie->isTerminal;
}

int main()
{
    cout << "Haider";
    vector<string> v;
    v.push_back("NEW");
    v.push_back("DOSE");
    v.push_back("HOW");
    v.push_back("THESE");
    // creating new Node

    Node *trie = new Node();
    cout << "\nee";
    for (int i = 0; i < v.size(); i++)
    {
        insertDir(v[i], trie);
    }
    cout << searchDir("DAD", trie) << endl;
    cout << searchDir("DOSE", trie) << endl;
    cout << "Program End";

    return 0;
}