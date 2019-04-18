/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.57%)
 * Total Accepted:    375.5K
 * Total Submissions: 925.3K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
int searchInsert(int* nums, int numsSize, int target) {
    int min = 0;
    int max = numsSize - 1;
    int mid = 0;
    do
    {
        mid = (max + min) / 2;
        int v_mid = nums[mid];
        if (v_mid > target)
        {
            max = mid;
        }
        else if (v_mid < target)
        {
            min = mid;
        }
        else
        {
            return mid;
        }
    } while (max > min + 1);
    return target <= nums[min] ? min : target > nums[max] ? max + 1 : min + 1;
}

