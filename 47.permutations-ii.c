/*
 * @lc app=leetcode id=47 lang=c
 *
 * [47] Permutations II
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//冒泡排序
void Sort_Bubble(int *arr, int size, bool desc)
{
    for (int i = 0; i < size; i++)
    {
        bool changed = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if ((!desc && arr[j] > arr[j + 1]) || (desc && arr[j] < arr[j + 1]))
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

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    Sort_Bubble(nums, numsSize, false);
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
    int *reallocColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * tempSize);
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
        int **tempRet = permuteUnique(newArray, numsSize - 1, &tempRetSize, &tempRetColumnSizes);
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


// @lc code=end

