//
//  RecoverBST.cpp
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
class Solution {
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    
    void recover(TreeNode* root){
          if(!root) return;
          recover(root->left);
          if(prev!=NULL && (root->val < prev->val)){
            if(first==NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root ;
            }
          }
        prev = root ;
        recover(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
     first = middle = last = NULL;
     prev = new TreeNode(INT_MIN);
     recover(root);
     if(first && last) swap(first->val, last->val);
     else if (first && middle) swap(first->val, middle->val);
    }
};
