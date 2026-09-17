//
//  DeleteingANodeInABST.cpp
//  
//
//  Created by Amandeep on 17/09/26.
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
     private :
          TreeNode* helper(TreeNode* root){
              if(root->left == NULL){
                return root->right;
              }
              if(root->right == NULL){
                return root->left;
              }
              TreeNode* rightNode = root->right;
              TreeNode* lastRight = findRight(root->left);
              lastRight->right = rightNode;
              return root->left;
          }

          TreeNode* findRight(TreeNode* node){
               if(node->right == NULL){
                return node ;
               }
            return findRight(node->right);
          }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root != NULL){
             if(key < root->val){
                if(root->left!=NULL && root->left->val==key){
                  root->left = helper(root->left);
                  break;
                }
                else {
                    root = root->left;
                }
             }
             else{
                if(root->right != NULL && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
             }
        }
        return dummy;
    }
};
