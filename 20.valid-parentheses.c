/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.11%)
 * Total Accepted:    543.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
bool isValid(char *s)
{
    if (*s == '\0')
    {
        return true;
    }
    //char* temp = (char*)malloc(sizeof(s));
    char temp[20000];
    temp[0] = s[0];
    s++;
    int i = 1;
    while (*s != '\0')
    {
        if (*s == ')')
        {
            if (i < 1 || *(temp + i - 1) != '(')
            {
                return false;
            }
            else
            {
                *(temp + i - 1) = '\0';
                i--;
            }
        }
        else if (*s == '}')
        {
            if (i < 1 || *(temp + i - 1) != '{')
            {
                return false;
            }
            else
            {
                *(temp + i - 1) = '\0';
                i--;
            }
        }
        else if (*s == ']')
        {
            if (i < 1 || *(temp + i - 1) != '[')
            {
                return false;
            }
            else
            {
                *(temp + i - 1) = '\0';
                i--;
            }
        }
        else
        {
            *(temp + i) = *s;
            i++;
        }
        s++;
    }
    return *temp == '\0';
}
