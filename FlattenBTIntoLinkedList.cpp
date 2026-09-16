//
//  FlattenBTIntoLinkedList.cpp
//  
//
//  Created by Amandeep on 16/09/26.
//
using recursion
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
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(!root) return ;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};

using Stack
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
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
       stack<TreeNode*> st ;
       st.push(root);
       while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(root->right) st.push(root->right);
        if(root->left)  st.push(root->left);
        if(!st.empty()){
            node->right = st.top();
            node->left = NULL;
        }
       }
    }
};
using morse
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
public:
    void flatten(TreeNode* root) {
       TreeNode* curr = root;
       while(curr!=NULL){
        if(curr->left!=NULL){
        TreeNode* prev = curr->left ;
        while(prev->right!=NULL){
            prev = prev->right;
        }
        prev->right=curr->right;
        curr->right=curr->left;
        curr->left=NULL;
        }
        curr=curr->right;
       }
    }
};
