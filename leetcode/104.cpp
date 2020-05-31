void maxDepth(TreeNode* node, int depth, int &maxDep) {
    if(!node) return;
    maxDep = max(maxDep, depth);
    maxDepth(node->left,depth+1,maxDep);
    maxDepth(node->right,depth+1,maxDep);
}

int maxDepth(TreeNode* root) {
    int maxDep = 0;
    maxDepth(root,1,maxDep);
    return maxDep;
}
