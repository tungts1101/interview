enum Direction {
    LEFT,
    RIGHT
};
    
void zigzagTraverse(TreeNode* node, Direction d, int level, vector<vector<int>> &order) {
    if(!node) return;
    if(level == order.size()) order.push_back(vector<int>{node->val});
    else {
        if(d == LEFT) order[level].push_back(node->val);
        else order[level].insert(order[level].begin(), node->val);
    }
    
    Direction _d = (d == LEFT) ? RIGHT : LEFT;
    zigzagTraverse(node->left, _d, level+1, order);
    zigzagTraverse(node->right, _d, level+1, order);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> order;
    zigzagTraverse(root, LEFT, 0, order);
    return order;
}
