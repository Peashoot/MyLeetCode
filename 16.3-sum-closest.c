/*
 * @lc app=leetcode id=16 lang=c
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (43.07%)
 * Total Accepted:    319.7K
 * Total Submissions: 733.4K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
void Sort_Bubble(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool changed = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                changed = true;
            }
        }
        if (!changed)
        {
            return;
        }
    }
}
int threeSumClosest(int* nums, int numsSize, int target) {
    if (numsSize < 3)
    {
        return target;
    }
    int ret = nums[0] + nums[1] + nums[2], val = abs(target - ret);
    Sort_Bubble(nums, numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        int j = numsSize - 1, k = i + 1;
        while (j > k)
        {
            int temp = nums[j] + nums[k] + nums[i];
            if (temp >= target + val)
            {
                j--;
            }
            else if (temp <= target - val)
            {
                k++;
            }
            else
            {
                val = abs(target - temp);
                ret = temp;
                if (ret == target)
                {
                    return ret;
                }
            }
        }
    }
    return ret;
}

