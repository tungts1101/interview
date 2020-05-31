int postIdx;
    
TreeNode* construct(const vector<int>& inorder,
                    const vector<int>& postorder,
                    int inIdxStart,
                    int inIdxStop) {
    if(inIdxStart > inIdxStop) return NULL;
    
    TreeNode* node = new TreeNode(postorder[postIdx--]);
    if(inIdxStart == inIdxStop) return node;
    
    int inIdx = inIdxStart;
    while(inIdx <= inIdxStop && node->val != inorder[inIdx]) inIdx++;
    node->right = construct(inorder,postorder,inIdx+1,inIdxStop);
    node->left = construct(inorder,postorder,inIdxStart,inIdx-1);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    postIdx = postorder.size()-1;
    TreeNode* root = construct(inorder,postorder,0,inorder.size()-1);
    
    return root;
}
