/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.96%)
 * Total Accepted:    523.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

int min(int num1, int num2)
{
    return num1 > num2 ? num2 : num1;
}
char* longestPalindrome(char* s)
{
    int len = (strlen(s) << 1) + 3;
    char *fillStr = (char *)malloc(sizeof(char) * len), *tmp = s, *fillTmp = fillStr;
    if (fillStr == NULL)
    {
        return NULL;
    }
    memset(fillStr, '\0', sizeof(char) * len);
    *fillTmp++ = '$';
    *fillTmp++ = '#';
    while (*tmp != '\0')
    {
        *fillTmp++ = *tmp++;
        *fillTmp++ = '#';
    }
    //len = 5;
    int *radius = (int *)malloc(sizeof(int) * (len - 1)), mx = 0, id = 0, resLen = 0, resCenter = 0;
    if (radius == NULL)
    {
        return NULL;
    }
    memset(radius, 0, sizeof(int) * (len - 1));
    for (int i = 1; i < len - 1; i++)
    {
        *(radius + i) = mx > i ? min(radius[(id << 1) - i], mx - i) : 1;
        while (*(fillStr + i + radius[i]) == *(fillStr + i - radius[i]))
        {
            radius[i]++;
        }
        if (mx < i + radius[i])
        {
            mx = i + radius[i];
            id = i;
        }
        if (resLen < radius[i])
        {
            resLen = radius[i];
            resCenter = i;
        }
    }
    char *ret = (char *)malloc(sizeof(char) * resLen);
    if (ret == NULL)
    {
        return NULL;
    }
    memset(ret, '\0', sizeof(char) * resLen);
    s = s + ((resCenter - resLen) >> 1);
    memcpy(ret, s, sizeof(char) * (resLen - 1));
    return ret;
}

