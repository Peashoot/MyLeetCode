/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.85%)
 * Total Accepted:    367.9K
 * Total Submissions: 900K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memset(ret, 0, digitsSize + 1);
    if (ret != NULL)
    {
        int retSize = digitsSize;
        bool carry = false;
        for (int i = digitsSize; i > 0; i--)
        {
            if (i == digitsSize)
            {
                if (digits[i - 1] == 9)
                {
                    ret[i] = 0;
                    carry = true;
                }
                else
                {
                    ret[i] = digits[i - 1] + 1;
                }
            }
            else
            {
                if (carry)
                {
                    if (digits[i - 1] == 9)
                    {
                        ret[i] = 0;
                        carry = true;
                    }
                    else
                    {
                        ret[i] = digits[i - 1] + 1;
                        carry = false;
                    }
                }
                else
                {
                    ret[i] = digits[i - 1];
                    carry = false;
                }
            }
        }
        if (carry)
        {
            ret[0] = 1;
            retSize = digitsSize + 1;
        }
        else
        {
            ret++;
        }
        *returnSize = retSize;
    }
    return ret;
}
