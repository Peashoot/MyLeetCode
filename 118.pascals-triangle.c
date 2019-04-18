/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (45.00%)
 * Total Accepted:    237.9K
 * Total Submissions: 527.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int **columnSizes)
{
    if (numRows <= 0)
    {
        return NULL;
    }
    columnSizes[0] = (int *)malloc(sizeof(int) * numRows);
    int **ret = (int **)malloc(sizeof(int *) * numRows);
    for (int i = 0; i < numRows; i++)
    {
        columnSizes[0][i] = i + 1;
        ret[i] = (int *)malloc(sizeof(int) * (i + 1));
        ret[i][0] = 1;
        ret[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }
    return ret;
}
