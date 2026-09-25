class solution {
public:
    TreeNode* ceil(TreeNode* root){
        TreeNode* ceil = NULL;
        while(root){
            if(root->data == val){
                ceil = root;
                return ciel;
            }
            if(key > root->data){
                root = root->right;
            }
            else {
                ceil = root->data;
                root = root-left;
            }
        }
        return ceil;
    }
};
