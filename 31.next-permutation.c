/*
 * @lc app=leetcode id=31 lang=c
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.25%)
 * Total Accepted:    227.1K
 * Total Submissions: 749.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
#define swap(a, b) {int temp = a; a = b; b = temp;}
void Sort_Bubble(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool changed = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                changed = true;
            }
        }
        if (!changed)
        {
            return;
        }
    }
}
void nextPermutation(int* nums, int numsSize) {
    if (numsSize < 2)
    {
        return;
    }
    if (nums[numsSize - 1] > nums[numsSize - 2])
    {
        swap(nums[numsSize - 1],nums[numsSize - 2]);
    }
    else
    {
        int i = numsSize - 1;
        for (; i > 0 && nums[i] <= nums[i - 1]; i--)
        {
        }
        if (i != 0)
        {
            int j = numsSize - 1;
            for (; nums[j] <= nums[i - 1]; j--)
            {
            }
            swap(nums[i - 1], nums[j]);
        }
        Sort_Bubble(nums + i, numsSize - i);
    }
}

