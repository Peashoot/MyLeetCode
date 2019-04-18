/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.19%)
 * Total Accepted:    254.3K
 * Total Submissions: 790K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
int lengthOfLastWord(char *s)
{
    if (*s == '\0')
    {
        return 0;
    }
    int i = 0;
    while (*(s + ++i) != '\0')
    {
    }
    while (--i >= 0 && *(s + i) == ' ')
    {
    }
    int len = 0;
    while (i >= 0 && *(s + i--) != ' ')
    {
        len++;
    }
    return len;
}
