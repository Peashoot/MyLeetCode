/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.73%)
 * Total Accepted:    521.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
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
    int i, j, k;
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
int** threeSum(int* nums, int numsSize, int* returnSize) {
    Sort_Bubble(nums, numsSize);
    struct LinkedListNode *head = NULL, *move = head;
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = numsSize - 1, k = i + 1, val = 0 - nums[i];
        while (j > k)
        {
            if (nums[j] + nums[k] > val || (j < numsSize - 1 && nums[j] == nums[j + 1]))
            {
                j--;
            }
            else if (nums[j] + nums[k] < val || (k > i + 1 && nums[k] == nums[k - 1]))
            {
                k++;
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
                j--;
                k++;
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
        *(ret + i) = (int *)malloc(sizeof(int) * 3);
        if (*(ret + i) == NULL)
        {
            return NULL;
        }
        *(*(ret + i)) = move->i;
        *(*(ret + i) + 1) = move->j;
        *(*(ret + i) + 2) = move->k;
        move = move->next;
    }
    return ret;
}

