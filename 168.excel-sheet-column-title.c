/*
 * @lc app=leetcode id=168 lang=c
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (28.64%)
 * Total Accepted:    167.3K
 * Total Submissions: 582.7K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 */
char *convertToTitle(int n)
{
    char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *store = NULL;
    int storeSize = 0;
    while (n > 0)
    {
        n = n - 1;
        int x = n % 26;
        n = n / 26;
        store = (char *)realloc(store, sizeof(char) * (storeSize + 1));
        store[storeSize] = arr[x];
        storeSize++;
    }
    char *ret = (char *)malloc(sizeof(char) * storeSize + 1);
    ret[storeSize] = '\0';
    for (int i = 0; i < storeSize; i++)
    {
        ret[i] = store[storeSize - i - 1];
    }
    return ret;
}
