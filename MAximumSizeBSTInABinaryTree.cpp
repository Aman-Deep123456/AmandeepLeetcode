//
//  MAximumSizeBSTInABinaryTree.cpp
//  
//
//  Created by Amandeep on 19/09/26.
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
class nodeVal{
    public :
         int maxVal;
         int minVal;
         int maxSize;
    public :
       nodeVal(int maxVal, int minVal, int maxSize){
         this->maxVal = maxVal;
         this->minVal = minVal;
         this->maxSize = maxSize;
       }
};

class Solution{
    private :
        nodeVal findLargest(TreeNode* root){
            if(!root){
                return nodeVal(INT_MIN, INT_MAX, 0);
            }
            nodeVal left = findLargest(root->left);
            nodeVal right = findLargest(root->right);

            if(root->data > left.maxVal && root->data < right.minVal){
                return nodeVal(max(root->data, right.maxVal), min(root->data, left.minVal),left.maxSize+right.maxSize+1);
            }
            return nodeVal(INT_MAX, INT_MIN,max(left.maxSize, right.maxSize));
        }
    public:
        int largestBST(TreeNode* root){
            //your code goes here
        return findLargest(root).maxSize;
        }
};
