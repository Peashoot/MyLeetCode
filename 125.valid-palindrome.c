/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.49%)
 * Total Accepted:    335.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
bool isPalindrome(char *s)
{
    if (*s == '\0')
    {
        return true;
    }
    int len = strlen(s);
    char *e = s + len - 1;
    while (s < e)
    {
        if (!((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z') || (*s >= '0' && *s <= '9')))
        {
            s++;
            continue;
        }
        if (!((*e >= 'a' && *e <= 'z') || (*e >= 'A' && *e <= 'Z') || (*e >= '0' && *e <= '9')))
        {
            e--;
            continue;
        }
        if (((*s >= '0' && *s <= '9') || (*e >= '0' && *e <= '9')) && *s != *e)
        {
            return false;
        }
        if (*s != *e && abs(*s - *e) != 32)
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}
