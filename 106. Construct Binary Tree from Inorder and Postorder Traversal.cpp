//
//  106. Construct Binary Tree from Inorder and Postorder Traversal.cpp
//  
//
//  Created by Amandeep on 16/09/26.
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
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& hashMap){
         if(postStart > postEnd || inStart > inEnd) return NULL;
         
         TreeNode* root = new TreeNode(postorder[postEnd]);
         int inRoot = hashMap[postorder[postEnd]];
         int numsLeft = inRoot-inStart;
         root->left = buildTree(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, hashMap);
         root->right = buildTree(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, hashMap);
         return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int>hashMap;
        for(int i=0;i<inorder.size();i++){
            hashMap[inorder[i]]=i;
        }
        TreeNode* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, hashMap);
        return root;
    }
};
