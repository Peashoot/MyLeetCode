/*
 * @lc app=leetcode id=257 lang=c
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (45.47%)
 * Total Accepted:    218.3K
 * Total Submissions: 479.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *convertNumToString(int num)
{
    if (num == 0)
    {
        return "0";
    }
    bool negative = num < 0;
    num = abs(num);
    char *numStr = (char *)malloc(sizeof(char));
    if (numStr == NULL)
    {
        return NULL;
    }
    *numStr = '\0';
    while (num > 0)
    {
        int newLen = strlen(numStr) + 2;
        char *tmp = (char *)malloc(sizeof(char) * newLen);
        if (tmp == NULL)
        {
            return NULL;
        }
        memset(tmp, '\0', sizeof(char) * newLen);
        *tmp = (char)(num % 10 + '0');
        strcat(tmp, numStr);
        numStr = tmp;
        num /= 10;
    }
    if (negative)
    {
        int newLen = strlen(numStr) + 2;
        char *tmp = (char *)malloc(sizeof(char) * newLen);
        if (tmp == NULL)
        {
            return NULL;
        }
        memset(tmp, '\0', sizeof(char) * newLen);
        *tmp = '-';
        strcat(tmp, numStr);
        numStr = tmp;
    }
    return numStr;
}

char **binaryTreePathsWithFather(struct TreeNode *root, char **ret, int *returnSize, char *fatherStr)
{
    if (root == NULL)
    {
        return ret;
    }
    char *valStr = convertNumToString(root->val), *store = fatherStr, *arrow = "->", *oldStr = fatherStr;
    int len = strlen(fatherStr) + strlen(arrow) + strlen(valStr) + 1;
    fatherStr = (char *)malloc(sizeof(char) * len);
    if (fatherStr == NULL)
    {
        free(store);
        return ret;
    }
    memset(fatherStr, '\0', len);
    strcat(fatherStr, oldStr);
    strcat(fatherStr, arrow);
    strcat(fatherStr, valStr);
    if (root->left == NULL && root->right == NULL)
    {
        char **tmp = ret;
        ret = (char **)realloc(ret, sizeof(char *) * (*returnSize + 1));
        if (ret == NULL)
        {
            free(tmp);
            return ret;
        }
        ret[*returnSize] = (char *)malloc(sizeof(char) * (strlen(fatherStr) + 1));
        if (ret[*returnSize] == NULL)
        {
            return ret;
        }
        strcpy(ret[*returnSize], fatherStr);
        (*returnSize)++;
    }
    ret = binaryTreePathsWithFather(root->left, ret, returnSize, fatherStr);
    ret = binaryTreePathsWithFather(root->right, ret, returnSize, fatherStr);
    return ret;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    if (root == NULL)
    {
        returnSize = 0;
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        *returnSize = 1;
        char **ret = (char **)malloc(sizeof(char *));
        if (ret == NULL)
        {
            return NULL;
        }
        *ret = convertNumToString(root->val);
        return ret;
    }
    char **ret = NULL;
    *returnSize = 0;
    char *s = convertNumToString(root->val);
    ret = binaryTreePathsWithFather(root->left, ret, returnSize, s);
    ret = binaryTreePathsWithFather(root->right, ret, returnSize, s);
    return ret;
}

