//
//  LCAinBST.cpp
//  
//
//  Created by Amandeep on 18/09/26.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      TreeNode* curr = root;
       if (curr->val > p->val && curr->val > q->val){
            return lowestCommonAncestor(curr->left, p, q);
        }
       if(curr->val < p->val && curr->val < q->val){
            return lowestCommonAncestor(curr->right, p, q);
       }
       return curr;
    }
};
