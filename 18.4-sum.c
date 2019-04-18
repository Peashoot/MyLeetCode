/*
 * @lc app=leetcode id=18 lang=c
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.11%)
 * Total Accepted:    224.1K
 * Total Submissions: 743.2K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct LinkedListNode
{
    int i, j, k, l;
    struct LinkedListNode *next;
};
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
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    Sort_Bubble(nums, numsSize);
    struct LinkedListNode *head = NULL, *move = head;
    *returnSize = 0;
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < numsSize - 1; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int k = numsSize - 1, l = j + 1, val = target - nums[i] - nums[j];
            while (k > l)
            {
                if (nums[k] + nums[l] > val || (k < numsSize - 1 && nums[k] == nums[k + 1]))
                {
                    k--;
                }
                else if (nums[k] + nums[l] < val || (l > j + 1 && nums[l] == nums[l - 1]))
                {
                    l++;
                }
                else
                {
                    (*returnSize)++;
                    struct LinkedListNode *new_node = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
                    if (new_node == NULL)
                    {
                        return NULL;
                    }
                    new_node->i = nums[i];
                    new_node->j = nums[j];
                    new_node->k = nums[k];
                    new_node->l = nums[l];
                    new_node->next = NULL;
                    if (move == NULL)
                    {
                        head = move = new_node;
                    }
                    else
                    {
                        move->next = new_node;
                        move = move->next;
                    }
                    k--;
                    l++;
                }
            }
        }
    }
    int **ret = (int **)malloc(sizeof(int *) * *returnSize);
    if (ret == NULL)
    {
        return NULL;
    }
    move = head;
    for (int i = 0; i < *returnSize && move != NULL; i++)
    {
        *(ret + i) = (int *)malloc(sizeof(int) * 4);
        if (*(ret + i) == NULL)
        {
            return NULL;
        }
        *(*(ret + i)) = move->i;
        *(*(ret + i) + 1) = move->j;
        *(*(ret + i) + 2) = move->k;
        *(*(ret + i) + 3) = move->l;
        move = move->next;
    }
    return ret;
}

