/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.07%)
 * Total Accepted:    489.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
int maxSubArray(int *nums, int numsSize)
{
    if (numsSize <= 0)
    {
        return 0;
    }
    int max = nums[0], sum = 0;
    int i;
    for (i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        max = max > sum ? max : sum;
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max;
}
