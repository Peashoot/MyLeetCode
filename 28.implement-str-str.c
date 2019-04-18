/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.49%)
 * Total Accepted:    398.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
int strStr(char* haystack, char* needle) {
    int ret = -1;
    int len = 0;
    do
    {
        int i = 0;
        do
        {
            if (*(needle + i) == '\0')
            {
                return len;
            }
            else if (*(haystack + len + i) != *(needle + i))
            {
                break;
            }
            i++;
        } while (*(haystack + i - 1) != '\0');
        len++;
    } while (*(haystack + len - 1) != '\0');
    return ret;
}

