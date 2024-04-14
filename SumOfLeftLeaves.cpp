/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasLeft(TreeNode* node){
        if(node->left != nullptr) return true;
        return false;
    }

    bool hasRight(TreeNode* node){
        if(node->right != nullptr) return true;
        return false;
    }

    bool hasChildren(TreeNode* node){
        if(hasLeft(node) || hasRight(node)) return true;
        return false;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> order;
        int sum = 0;
        order.push(root);
        while(!order.empty()){
            if(hasLeft(order.front())){
                if(!hasChildren(order.front()->left)){
                    sum += order.front()->left->val;
                }
                else {
                    order.push(order.front()->left);
                }
            }

            if(hasRight(order.front())){
                if(hasChildren(order.front()->right)){
                    order.push(order.front()->right);
                }
            }

            order.pop();
        }

        return sum;
    }
};
