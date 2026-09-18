//
//  TwoSumInABST.cpp
//  
//
//  Created by Amandeep on 19/09/26.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class BSTIterator{
      private :
          stack<TreeNode *>st;
          bool reverse;
      public :
         BSTIterator(TreeNode* root, bool reverse){
            this->reverse = reverse;
            pushAll(root);
         }

        int next(){
            TreeNode* node = st.top();
            st.pop();
            if(!reverse) pushAll(node->right);
            else pushAll(node->left);
            return node->val;
        }
     
       void pushAll(TreeNode* node ){
           for(;node!=NULL;){
           st.push(node);
              if(!reverse){
                node = node->left;
              }
              else{
                node = node->right;
              }
           }
       }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
           if(!root) return false;
           BSTIterator l(root,false);
           BSTIterator r(root,true);
           int i = l.next();
           int j = r.next();
           while(i<j){
             if(i+j == k) return true ;
             else if(i+j<k) i = l.next();
             else j =r.next();
           }
           return false ;
    }
};
