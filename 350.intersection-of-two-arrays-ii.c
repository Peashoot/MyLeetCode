/*
 * @lc app=leetcode id=350 lang=c
 *
 * [350] Intersection of Two Arrays II
 */

void Sort_Bubble(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool changed = false;
        int temp;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    Sort_Bubble(nums1, nums1Size);
    Sort_Bubble(nums2, nums2Size);
    int minSize = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *ret = (int *)malloc(minSize * sizeof(int));
    if (ret == NULL)
    {
        return NULL;
    }
    (*returnSize) = 0;
    int j = 0;
    if (nums1Size < nums2Size)
    {
        for (int i = 0; i < nums1Size; i++)
        {
            if (j < nums2Size && nums1[i] < nums2[j])
            {
                continue;
            }
            for (; j < nums2Size; j++)
            {
                if (nums2[j] == nums1[i])
                {
                    ret[(*returnSize)++] = nums1[i];
                    j++;
                    break;
                }
                if (nums2[j] > nums1[i])
                {
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < nums2Size; i++)
        {
            if (j < nums1Size && nums2[i] < nums1[j])
            {
                continue;
            }
            for (; j < nums1Size; j++)
            {
                if (nums1[j] == nums2[i])
                {
                    ret[(*returnSize)++] = nums2[i];
                    j++;
                    break;
                }
                if (nums1[j] > nums2[i])
                {
                    break;
                }
            }
        }
    }

    return ret;
}
