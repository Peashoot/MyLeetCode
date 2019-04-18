/*
 * @lc app=leetcode id=107 lang=c
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.97%)
 * Total Accepted:    215.5K
 * Total Submissions: 468.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **ChildrenOrderBottom(struct TreeNode *root, int **ori, int **columnSizes, int *returnSize, int depth)
{
    if (root == NULL)
    {
        return ori;
    }
    if (depth + 1 > *returnSize)
    {
        ori = (int **)realloc(ori, sizeof(int *) * (depth + 1));
        columnSizes[0] = depth == 0 ? (int *)malloc(sizeof(int)) : (int *)realloc(columnSizes[0], sizeof(int) * (depth + 1));
        columnSizes[0][depth] = 0;
        *returnSize += 1;
    }
    if (columnSizes[0][depth] == 0)
    {
        ori[depth] = (int *)malloc(sizeof(int));
    }
    else
    {
        ori[depth] = (int *)realloc(ori[depth], sizeof(int) * (columnSizes[0][depth] + 1));
    }
    ori[depth][columnSizes[0][depth]] = root->val;
    columnSizes[0][depth]++;
    depth++;
    ori = ChildrenOrderBottom(root->left, ori, columnSizes, returnSize, depth);
    ori = ChildrenOrderBottom(root->right, ori, columnSizes, returnSize, depth);
    return ori;
}

//逆层序遍历树
int **levelOrderBottom(struct TreeNode *root, int **columnSizes, int *returnSize)
{
    if (root == NULL)
    {
        return NULL;
    }
    int depth = 0;
    int **ori = (int **)malloc(sizeof(int *));
    int **tempColumnSizes = (int **)malloc(sizeof(int *));
    ori = ChildrenOrderBottom(root, ori, tempColumnSizes, returnSize, 0);
    int **ret = (int **)malloc(sizeof(int *) * (*returnSize));
    columnSizes[0] = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++)
    {
        int columnSize = tempColumnSizes[0][i];
        ret[*returnSize - i - 1] = (int *)malloc(sizeof(int) * tempColumnSizes[0][i]);
        columnSizes[0][*returnSize - i - 1] = columnSize;
        for (int j = 0; j < columnSize; j++)
        {
            ret[*returnSize - i - 1][j] = ori[i][j];
        }
    }
    free(ori);
    free(tempColumnSizes);
    return ret;
}
