/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (42.53%)
 * Total Accepted:    192.5K
 * Total Submissions: 451.3K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize)
{
    if (rowIndex < 0)
    {
        return NULL;
    }
    rowIndex++;
    *returnSize = rowIndex;
    int *ret = (int *)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < rowIndex; i++)
    {
        ret[0] = 1;
        ret[i] = 1;
        for (int j = 1, store = ret[0]; j < i; j++)
        {
            int temp = store;
            store = ret[j];
            ret[j] += temp;
        }
    }
    return ret;
}
