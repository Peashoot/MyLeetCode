/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.32%)
 * Total Accepted:    286.3K
 * Total Submissions: 745.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
char *addBinary(char *a, char *b)
{
    int len_of_a = 1;
    int len_of_b = 1;
    while (*a != '\0')
    {
        a++;
        len_of_a++;
    }
    while (*b != '\0')
    {
        b++;
        len_of_b++;
    }
    int max_len = len_of_a > len_of_b ? len_of_a : len_of_b;
    char *ret = (char *)malloc(sizeof(char) * (max_len + 1));
    if (ret != NULL)
    {
        memset(ret, '0', max_len + 1);
        ret[max_len] = '\0';
        bool carry = false;
        for (int i = max_len - 1; i > 0; i--)
        {
            char ca = (i <= max_len - len_of_a) ? '0' : *(--a);
            char cb = i <= max_len - len_of_b ? '0' : *(--b);
            if (ca == '1' && cb == '1')
            {
                ret[i] = carry ? '1' : '0';
                carry = true;
            }
            else if (ca == '0' && cb == '0')
            {
                ret[i] = carry ? '1' : '0';
                carry = false;
            }
            else if (carry)
            {
                ret[i] = '0';
                carry = true;
            }
            else
            {
                ret[i] = '1';
                carry = false;
            }
        }
        if (carry)
        {
            ret[0] = '1';
        }
        else
        {
            ret++;
        }
    }
    return ret;
}
