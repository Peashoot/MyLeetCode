/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (40.55%)
 * Total Accepted:    305K
 * Total Submissions: 751.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the depth of the two subtrees of every node never
 * differ by more than 1.
 * 
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * Return false.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode *root);

int getDepth(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_depth = getDepth(root->left) + 1;
    int right_depth = getDepth(root->right) + 1;
    return left_depth > right_depth ? left_depth : right_depth;
}

bool isChildBalanced(struct TreeNode *left, struct TreeNode *right)
{
    if (left == NULL && right == NULL)
    {
        return true;
    }
    if (!(abs(getDepth(left) - getDepth(right)) < 2 && isBalanced(left) && isBalanced(right)))
    {
        return false;
    }
    return true;
}

//判断是否二叉平衡树
bool isBalanced(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    return isChildBalanced(root->left, root->right);
}
