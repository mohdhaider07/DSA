
// BST class
#include <bits/stdc++.h>
using namespace std;
// BINARY TREE
// Class BTNode

template <typename T>
class BTNode
{
public:
    T val;
    BTNode *left;
    BTNode *right;
    BTNode(T x) : val(x), left(NULL), right(NULL) {}
    ~BTNode()
    {
        delete left;
        delete right;
    }
};

class BST
{
private:
    BTNode<int> *root;
    // inserting the node
    BTNode<int> *insert(BTNode<int> *node, int data)
    {

        if (node == NULL)
        {

            BTNode<int> *newNode = new BTNode<int>(data);
            return newNode;
        }
        if (data < node->val)
        {

            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }
    void printTree(BTNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->val << ":";
        if (root->left != NULL)
        {
            cout << "inside left";
            cout << "L" << node->left->val << " ";
        }
        if (root->right != NULL)
        {
            cout << "R" << node->right->val << " ";
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }

public:
    BST() : root(NULL) {}
    void insert(int data)
    {
        root = insert(root, data);
    }
    void printTree()
    {
        cout << "Printing Tree" << endl;
        printTree(root);
    }
    ~BST()
    {
        delete root;
    };
};

int main()
{
    cout << "BST";
    BST b;
    b.insert(4);
    b.insert(7);
    b.insert(1);
    b.insert(3);
    b.insert(2);
    b.insert(9);
    b.insert(0);
    b.printTree();

    return 0;
}

//   // search in tree recursively
//   TreeNode* searchBST(TreeNode* root, int val) {
//         if(root==NULL){
//             return NULL;
//         }
//         if(root->val==val){

//             return root;
//         }
//         if(root->val>val){

//            return searchBST(root->left,val);
//         }else if(root->val<val){

//            return searchBST(root->right,val);
//         }

//         return NULL;
//     }
//     // iterative meathod
//      TreeNode* searchBST(TreeNode* root, int val) {

//         while(root!=NULL){
//             if(root->val==val)return root;
//             else if(root->val>val){
//                 root=root->left;
//             }else if(root->val<val){
//                 root=root->right;
//             }
//         }
//         return root;
//     }

//     // contructing Tree from sorted array
//      TreeNode* helper(vector<int>&nums,int s,int e){
//         if(s>e){
//             return NULL;
//         }
//         int mid=(s+e)/2;
//         int rootData=nums[mid];
//         TreeNode*root=new TreeNode(rootData);
//         root->left=helper(nums,s,mid-1);
//         root->right=helper(nums,mid+1,e);
//         return root;
//     }
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//        int n =nums.size();
//         return helper(nums,0,n-1);
//     }

//     // contructing Tree from sorted array
