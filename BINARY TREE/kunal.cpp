// ============================
// TO DO
        // 1.  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
        // 2.  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
        // 3.  https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
        // 4.  https://leetcode.com/problems/path-sum-iii/
/*
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if(!root){
       return {};
     }
     vector<vector<int>>ans;
     deque<TreeNode*>q;
     q.push_back(root);
     bool isLTR=true;
     while(!q.empty()){
         int len=q.size();
         vector<int>temp;
         for(int i=0;i<len;i++){
                 TreeNode* f=NULL;
                 if(isLTR){
                      f =q.front();
                       q.pop_front();
                 }else{
                     f=q.back();
                     q.pop_back();
                 }

                 temp.push_back(f->val);

                     if(isLTR){
                         if(f->left){
                             q.push_back(f->left);
                         }
                         if(f->right ){
                             q.push_back(f->right);
                         }
                     }else{
                         if(f->right ){
                             q.push_front(f->right);
                         }
                         if(f->left){
                             q.push_front(f->left);
                         }

                     }
             }
         isLTR=!isLTR;
         ans.push_back(temp);
     }

     return ans;
*/


/*

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/

// best solution is this 
===================     ===================
 void connectLevel(Node* curr){
        if(!curr->left){
            return ;
        }
        curr->left->next=curr->right;
        if(curr->next){
        curr->right->next=curr->next->left;
        }
        connectLevel(curr->left);
        connectLevel(curr->right);


        

    }
==========    ===================

Node* connect(Node* root) {

        if(!root){
        return root;
        }
 
     queue<Node*>q;
     q.push(root);

     while(!q.empty()){
        int len=q.size();

         for(int i=0;i<len;i++){
                Node* f=q.front();
                q.pop();
                f->next= i==len-1 ? NULL :  q.front() ;

                if(f->left){
                    q.push(f->left);
                }
                if(f->right ){
                    q.push(f->right);
                }
                    
             }
 
        }
     return root;
    }

*/

// right view of Binary Tree
/*
  vector<int> rightSideView(TreeNode* root) {
        if(!root){
        return {};
        }
        vector<int>ans;
     queue<TreeNode*>q;
     q.push(root);

     while(!q.empty()){
        int len=q.size();

         for(int i=0;i<len;i++){
                TreeNode* f=q.front();
                q.pop();
                if(i==len-1){
                    ans.push_back(f->val);
                }

                if(f->left){
                    q.push(f->left);
                }
                if(f->right ){
                    q.push(f->right);
                }
                    
             }
 
        }
     return ans;
    }
*/

// =======================================
/*

   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }

        if(root==p||root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left && right){
            return root;
        }

        return !left ? right: left;
        
    }

*/


/*

// Path sum

 bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        
        if( targetSum-(root->val)==0 && (!root->left && !root->right)){
            return true;
        }
        bool left=hasPathSum(root->left,targetSum-(root->val));
        bool right=hasPathSum(root->right,targetSum-(root->val));
        return left||right;
    }


*/

/*
MAx sum important question
//https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/

    int helper(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }
        int left =helper(root->left,ans);
        int right =helper(root->right,ans);
        
        left=max(0,left);
        right=max(0,right);

        int localMax = left+right+root->val;
        ans=max(ans,localMax);
        return max(left,right)+root->val;
      
    }

    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
       
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
    }

*/