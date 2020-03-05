/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int low1 = 0,high1 = nums1Size, low2 = 0, high2 = nums2Size;
    if (nums1Size == 0)
    {
        return (nums2[(nums2Size + 1)/ 2] + nums2[(nums2Size + 2) / 2]) / 2.0;
    }
    if (nums2Size == 0)
    {
        return (nums1[(nums1Size + 1) / 2] + nums1[(nums1Size + 2) / 2]) / 2.0;
    }
    if (nums1Size == 1 || nums2Size == 1)
    {
        return (nums1[0] + nums2[0]) / 2.0;
    }
    int mid1 = (low1 + high1 + 1) / 2, mid2 = (low2 + high2 - 1) / 2;
    if (nums1[mid1] == nums2[mid2]) 
    {
        return nums1[mid1];
    }
    if (nums1[mid1] < nums2[mid2])
    {
        low1 = mid1;
        high2 = mid2;
    }
    else if (nums1[mid1] > nums2[mid2])
    {
        high1 = mid1;
        low2 = mid2;
    }
}



