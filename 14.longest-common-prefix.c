/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.15%)
 * Total Accepted:    428.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        return "";
    }
    char *common = strs[0];
    for (int i = 1; i < strsSize; i++)
    {
        int j = -1;
        do
        {
            j++;
            if (*(common + j) != *(strs[i] + j))
            {
                *(common + j) = '\0';
                if (j == 0)
                {
                    return common;
                }
                break;
            }
        } while (!(*(common + j) == '\0' || *(strs[i] + j) == '\0'));
    }
    return common;
}
