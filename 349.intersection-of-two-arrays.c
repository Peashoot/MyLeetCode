/*
 * @lc app=leetcode id=349 lang=c
 *
 * [349] Intersection of Two Arrays
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

int BinarySearch(int *arr, int size, int target)
{
    int left = 0, right = size - 1, mid;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    Sort_Bubble(nums1, nums1Size);
    Sort_Bubble(nums2, nums2Size);
    int minSize = nums1Size > nums2Size ? nums2Size : nums1Size;
    int* ret = (int*)malloc(minSize * sizeof(int));
    if (ret == NULL) {return NULL;}
    (*returnSize) = 0;
    if (nums1Size < nums2Size)
    {
    for (int i = 0; i < nums1Size; i++)
    {
        if (i > 0 && nums1[i] == nums1[i - 1]) {continue;}
        if (BinarySearch(nums2, nums2Size, nums1[i]) > -1)
        {
            ret[(*returnSize)++] = nums1[i];
        }
    }
    }
    else
    {
        for (int i = 0; i < nums2Size; i++)
        {
            if (i > 0 && nums2[i] == nums2[i - 1])
            {
                continue;
            }
            if (BinarySearch(nums1, nums1Size, nums2[i]) > -1)
            {
                ret[(*returnSize)++] = nums2[i];
            }
        }
    }
    
    return ret;
}
