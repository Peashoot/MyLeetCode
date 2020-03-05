/*
 * @lc app=leetcode id=34 lang=c
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.26%)
 * Total Accepted:    286.9K
 * Total Submissions: 861K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binarySearch(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, mid;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int binaryInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, mid = 0;
    do
    {
        mid = (right + left) / 2;
        int v_mid = nums[mid];
        if (v_mid > target)
        {
            right = mid;
        }
        else if (v_mid < target)
        {
            left = mid;
        }
        else
        {
            return mid;
        }
    } while (right > left + 1);
    return target <= nums[left] ? left : target > nums[right] ? right + 1 : left + 1;
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *ret = (int *)malloc(sizeof(int) * *returnSize);
    if (ret == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int pos = binarySearch(nums, numsSize, target);
    if (pos == -1)
    {
        *ret = -1;
        *(ret + 1) = -1;
        return ret;
    }
    int left = binaryInsert(nums, numsSize, target - 1);
    int right = binaryInsert(nums, numsSize, target + 1);
    for (int i = left; i <= pos; i++)
    {
        if (nums[i] == target)
        {
            left = i;
            break;
        }
    }
    for (int j = right - 1; j >= pos; j--)
    {
        if (nums[j] == target)
        {
            right = j;
            break;
        }
    }
    *ret = left;
    *(ret + 1) = right;
    return ret;
}
