/*
 * @lc app=leetcode id=46 lang=c
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.31%)
 * Total Accepted:    363.7K
 * Total Submissions: 667.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    if (numsSize == 0)
    {
        return NULL;
    }
    int tempSize = 1;
    for (int i = 1; i <= numsSize; i++)
    {
        tempSize *= i;
    }
    int **ret = (int **)malloc(sizeof(int *) * tempSize);
    int *reallocColumnSizes = (int *)malloc(sizeof(int) * tempSize);
    if (reallocColumnSizes == NULL)
    {
        return NULL;
    }
    *returnColumnSizes = reallocColumnSizes;
    // returnColumnSizes = (int**)malloc(sizeof(int*));
    if (ret == NULL || returnColumnSizes == NULL)
    {
        return NULL;
    }
    int m = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int *newArray = (int *)malloc(sizeof(int) * (numsSize - 1));
        if (newArray == NULL)
        {
            return NULL;
        }
        for (int j = 0, k = 0; j < numsSize; j++)
        {
            if (j != i)
            {
                newArray[k++] = nums[j];
            }
        }
        int tempRetSize = 0;
        int *tempRetColumnSizes = (int *)malloc(sizeof(int));
        if (tempRetColumnSizes == NULL)
        {
            return NULL;
        }
        int **tempRet = permute(newArray, numsSize - 1, &tempRetSize, &tempRetColumnSizes);
        if (tempRetSize == 0)
        {
            *(ret + m) = (int *)malloc(sizeof(int) * numsSize);
            if (*(ret + m) == NULL)
            {
                return NULL;
            }
            *(*returnColumnSizes + m) = 1;
            *(ret + m++)[0] = nums[i];
        }
        else
        {
            for (int k = 0; k < tempRetSize; k++)
            {
                *(ret + m) = (int *)malloc(sizeof(int) * numsSize);
                if (*(ret + m) == NULL)
                {
                    return NULL;
                }
                *(ret + m)[0] = nums[i];
                memcpy(*(ret + m) + 1, tempRet[k], sizeof(int) * (numsSize - 1));
                *(*returnColumnSizes + m) = tempRetColumnSizes[k] + 1;
                m++;
            }
        }
    }
    *returnSize = m;
    return ret;
}

