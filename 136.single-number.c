/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (59.36%)
 * Total Accepted:    436K
 * Total Submissions: 733.3K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */
int singleNumber(int *nums, int numsSize)
{
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    return ret;
}
