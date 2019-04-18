/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (47.93%)
 * Total Accepted:    262.3K
 * Total Submissions: 546.8K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
int missingNumber(int* nums, int numsSize) {
    if (numsSize == 0)
    {
        return 0;
    }
    int max = nums[0], min = nums[0];
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
        }
        else if (min > nums[i])
        {
            min = nums[i];
        }
        sum += nums[i];
    }
    int temp = (max + min) * (max - min + 1) / 2 - sum;
    if (temp == 0)
    {
        if (min == 0)
        {
            return max + 1;
        }
        else
        {
            return 0;
        }
    }
    else {
        return temp;
    }
}

