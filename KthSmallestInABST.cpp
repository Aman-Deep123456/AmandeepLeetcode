//
//  KthSmallestInABST.cpp
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentTrack){
        queue<TreeNode*>q;
        q.push({root});
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parentTrack[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parentTrack[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentTrack;
        findParent(root,parentTrack);
        queue<TreeNode *>q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int currentDist = 0 ;
        while(!q.empty()){
            int size = q.size();
            if(currentDist++==k) break ;
            for(int i=0;i<size;i++){
                    TreeNode * node = q.front();
                    q.pop();
                    if(node->left&&!visited[node->left]){
                        q.push(node->left);
                        visited[node->left]=true;
                    }
                    if(node->right&&!visited[node->right]){
                        q.push(node->right);
                        visited[node->right]=true;
                    }
                    if(parentTrack[node]&&!visited[parentTrack[node]]){
                        q.push(parentTrack[node]);
                        visited[parentTrack[node]]=true;
                    }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            int val = node->val;
            result.push_back(node->val);
        }
        return result ;
}
};
