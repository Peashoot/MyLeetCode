/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.97%)
 * Total Accepted:    375.7K
 * Total Submissions: 873.7K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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

bool isTwoSymmetric(struct TreeNode *one, struct TreeNode *another)
{
    if (one == NULL && another == NULL)
    {
        return true;
    }
    if (!(one != NULL && another != NULL && one->val == another->val && isTwoSymmetric(one->left, another->right) && isTwoSymmetric(one->right, another->left)))
    {
        return false;
    }
    return true;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    return isTwoSymmetric(root->left, root->right);
}

