//
//  Moorse.cpp
//  
//
//  Created by Amandeep on 16/09/26.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
        //your code goes here
    TreeNode* curr = root;
    if(!root) return {};
    vector<int> inorder;
    while(curr){
        if(curr->left == nullptr){
         inorder.push_back(curr->data);
         curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right == nullptr){
                prev->right = curr;
                curr=curr->left;
            }
            else{
                prev->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
    }
};
