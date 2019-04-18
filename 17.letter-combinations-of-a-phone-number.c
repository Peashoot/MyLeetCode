/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (41.00%)
 * Total Accepted:    371.2K
 * Total Submissions: 903.7K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    if (*digits == '\0')
    {
        *returnSize = 0;
        return NULL;
    }
    char *store[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = strlen(digits);
    int *nums = (int *)malloc(sizeof(int) * len), *multi = (int *)malloc(sizeof(int) * len), i = 0;
    if (nums == NULL || multi == NULL)
    {
        return NULL;
    }
    while (*digits != '\0')
    {
        *(nums + i++) = (*digits++) - '2';
    }
    *returnSize = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        multi[i] = *returnSize;
        *returnSize *= strlen(store[nums[i]]);
    }
    char **ret = (char **)malloc(sizeof(char *) * (*returnSize));
    if (ret == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < *returnSize; i++)
    {
        *(ret + i) = (char *)malloc(sizeof(char) * (len + 1));
        if (*(ret + i) == NULL)
        {
            return NULL;
        }
        for (int j = 0, tmp = i; j < len; j++)
        {
            *(*(ret + i) + j) = *(*(store + *(nums + j)) + tmp / *(multi + j));
            tmp %= *(multi + j);
        }
        *(*(ret + i) + len) = '\0';
    }
    return ret;
}

