/*
 * @lc app=leetcode id=303 lang=c
 *
 * [303] Range Sum Query - Immutable
 */

typedef struct
{
    int *sums;
    int sumSize;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return NULL;
    }
    NumArray *head = (NumArray *)malloc(sizeof(NumArray));
    if (head == NULL)
    {
        return NULL;
    }
    head->sums = (int *)malloc(sizeof(int) * numsSize);
    if (head->sums == NULL)
    {
        return NULL;
    }
    head->sumSize = numsSize;
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        head->sums[i] = sum;
    }
    return head;
}

int numArraySumRange(NumArray *obj, int i, int j)
{
    if (obj == NULL)
    {
        return 0;
    }
    if (i >= obj->sumSize || j >= obj->sumSize)
    {
        return 0;
    }
    if (i == 0)
    {
        return obj->sums[j];
    }
    return obj->sums[j] - obj->sums[i - 1];
}

void numArrayFree(NumArray *obj)
{
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/

