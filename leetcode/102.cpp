void traverse(TreeNode* node, int level, vector<vector<int>> &order) {
     if(node == NULL) return;
     
     if(order.size() <= level) order.push_back(vector<int>{node->val});
     else order[level].push_back(node->val);
     
     traverse(node->left, level+1, order);
     traverse(node->right,level+1, order);
 }
 
 vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>> order;
     
     traverse(root,0,order);
     
     return order;
 }
