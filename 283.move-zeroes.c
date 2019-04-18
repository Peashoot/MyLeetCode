/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.98%)
 * Total Accepted:    446K
 * Total Submissions: 825.8K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
void moveZeroes(int* nums, int numsSize) {
    if (numsSize == 0)
    {
        return;
    }
    int zeroCount = 0;
    int i = 0;
    for (; i < numsSize - zeroCount;)
    {
        if (nums[i + zeroCount] == 0)
        {
            zeroCount++;
            continue;
        }
        nums[i] = nums[i + zeroCount];
        i++;
    }
    for (; i < numsSize; i++)
    {
        nums[i] = 0;
    }
}

