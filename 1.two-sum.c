/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (42.75%)
 * Total Accepted:    1.6M
 * Total Submissions: 3.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* result = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize ;i++) 
    {
        int intSerach = target - *(nums + i);
        for (int j = i + 1; j < numsSize; j++)
        {
            if (*(nums + j) == intSerach)
            {
                *result = i;
                *(result + 1) = j;
                return result;
            }
        }
    }
    return result;
}

