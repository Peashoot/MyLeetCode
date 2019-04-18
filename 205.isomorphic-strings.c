/*
 * @lc app=leetcode id=205 lang=c
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (36.90%)
 * Total Accepted:    194.4K
 * Total Submissions: 525.6K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
bool isIsomorphic(char* s, char* t) {
    if (strlen(s) != strlen(t))
    {
        return false;
    }
    char ascii1[256], ascii2[256];
    memset(ascii1, '\0', sizeof(ascii1));
    memset(ascii2, '\0', sizeof(ascii2));
    while (*s != '\0')
    {
        if (ascii1[*s] == '\0' && ascii2[*t] == '\0')
        {
            ascii1[*s] = *t;
            ascii2[*t] = *s;
        }
        else if (ascii1[*s] != *t || ascii2[*t] != *s)
        {
            return false;
        }
        s++;
        t++;
    }
    return true;
}

