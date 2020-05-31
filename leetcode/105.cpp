int preIdx;

TreeNode* construct(const vector<int>& preorder, 
                    const vector<int>& inorder,
                    int inIdxStart,
                    int inIdxStop) {
    
    if(inIdxStart > inIdxStop) return NULL;
    
    TreeNode *node = new TreeNode(preorder[preIdx++]);
    
    if(inIdxStart == inIdxStop) return node;

    int inIdx = inIdxStart;
    while(inIdx <= inIdxStop && inorder[inIdx] != node->val) inIdx++;
    
    node->left = construct(preorder,inorder,inIdxStart,inIdx-1);
    node->right = construct(preorder,inorder,inIdx+1,inIdxStop);
    
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    preIdx = 0;
    TreeNode *root = construct(preorder,inorder,0,inorder.size()-1);
    
    return root;
}
