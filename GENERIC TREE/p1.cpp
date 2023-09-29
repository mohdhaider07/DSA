
#include <bits/stdc++.h>

using namespace std;

template <typename T>

class TreeNode
{
public:
    int data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
// print function
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";

    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ,";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
// input Recursive function
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter No of Children You Want : ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

// take inpur level wise
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(1);
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        int n;
        cout << "Enter the no of children of " << f->data << " : ";
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int childData;
            cout << "Enter child Data of " << f->data << " of position " << i + 1
                 << " : ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

// printlevel wise
void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        cout << f->data << " : ";
        q.pop();
        for (int i = 0; i < f->children.size(); i++)
        {
            cout << f->children[i]->data << " ,";
            q.push(f->children[i]);
        }
        cout << endl;
    }
}

// cout no ofnodes
int countNode(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); ++i)
    {
        ans += countNode(root->children[i]);
    }
    return ans;
}

// Height of Tree
int heightOfTree(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    for (int i = 0; i < root->children.size(); ++i)
    {
        ans = max(ans, heightOfTree(root->children[i])) + 1;
    }

    return ans;
}

// print all node which has depth of k
void printDepth_K(TreeNode<int> *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->data << " , ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printDepth_K(root->children[i], k - 1);
    }
}

// countleaf nodes
int count_Leaf_Node(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    if (!root->children.size())
        return 1;
    for (int i = 0; i < root->children.size(); ++i)
    {
        ans += count_Leaf_Node(root->children[i]);
    }
    return ans;
}

// PreOrder traverse
void preOrderPrint(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ",";
    for (int i = 0; i < root->children.size(); ++i)
    {
        preOrderPrint(root->children[i]);
    }
}

int main()
{
    cout << "";
    TreeNode<int> *root = takeInputLevelWise();
    // printLevelWise(root);
    printTree(root);
    cout << endl;
    preOrderPrint(root);

    return 0;
}