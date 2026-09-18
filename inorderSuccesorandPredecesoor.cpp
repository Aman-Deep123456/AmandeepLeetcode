//
//  inorderSuccesorandPredecesoor.cpp
//  
//
//  Created by Amandeep on 18/09/26.
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

class Solution{
    private :
        int findSucc(TreeNode* root, int key){
            int succ = -1 ;
            while(root){
            if(root->data > key){
              succ = root->data;
              root = root->left;
            }
            else {
                root = root->right;
            }
        }
       return succ;
        }
       
       int findPred(TreeNode* root, int key){
          int pred = -1;
          while(root){
             if(root->data < key){
                pred = root->data;
                root = root->right;
             }
             else {
                root = root->left;
             }
          }
          return pred;
       }
    public:
        vector<int> succPredBST(TreeNode* root,int key){
            //your code goes here
        int succ = findSucc(root, key);
        int pred = findPred(root, key);
        return{pred, succ};
        }
};
