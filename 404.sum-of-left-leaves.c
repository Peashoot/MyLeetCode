/*
 * @lc app=leetcode id=404 lang=c
 *
 * [404] Sum of Left Leaves
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void leftLeavesWithSum(struct TreeNode *root, int *sum)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        struct TreeNode *next = root->left;
        if (next->left == NULL && next->right == NULL)
        {
            *sum += next->val;
        }
        else
        {
            leftLeavesWithSum(next, sum);
        }
    }
    if (root->right != NULL)
    {
        leftLeavesWithSum(root->right, sum);
    }
}

int sumOfLeftLeaves(struct TreeNode* root){
    int sum = 0;
    leftLeavesWithSum(root, &sum);
    return sum;
}


// @lc code=end

