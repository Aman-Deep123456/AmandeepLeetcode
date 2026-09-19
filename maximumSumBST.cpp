//
//  maximumSumBST.cpp
//  
//
//  Created by Amandeep on 19/09/26.
//
class nodeVal {
public:
    int maxVal;
    int minVal;
    int sum;
    int maxSum;

    nodeVal(int maxVal, int minVal, int sum, int maxSum) {
        this->maxVal = maxVal;
        this->minVal = minVal;
        this->sum = sum;
        this->maxSum = maxSum;
    }
};

class Solution {
private:
    nodeVal findLargest(TreeNode* root) {

        if (root == NULL) {
            return nodeVal(INT_MIN, INT_MAX, 0, 0);
        }

        nodeVal left = findLargest(root->left);
        nodeVal right = findLargest(root->right);

        // Current subtree is a BST
        if (root->val > left.maxVal &&
            root->val < right.minVal) {

            int sum = left.sum + right.sum + root->val;

            int maxSum = max({
                sum,
                left.maxSum,
                right.maxSum
            });

            return nodeVal(
                max(root->val, right.maxVal),
                min(root->val, left.minVal),
                sum,
                maxSum
            );
        }

        // Current subtree is NOT a BST
        return nodeVal(
            INT_MAX,
            INT_MIN,
            0,
            max(left.maxSum, right.maxSum)
        );
    }

public:
    int maxSumBST(TreeNode* root) {
        return findLargest(root).maxSum;
    }
};
