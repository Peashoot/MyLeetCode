/*
 * @lc app=leetcode id=43 lang=c
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (30.29%)
 * Total Accepted:    194.2K
 * Total Submissions: 639.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1), len2 = strlen(num2), tempSize = len1 + len2 + 1;
    char *temp = (char *)malloc(sizeof(char) * tempSize);
    if (temp == NULL)
    {
        return NULL;
    }
    memset(temp, '\0', sizeof(char) * tempSize);
    bool negative = (*num1 == '-' && *num2 != '-') || (*num1 != '-' && *num2 == '-');
    for (int i = len1 - 1; i >= 0 && *(num1 + i) >= '0' && *(num1 + i) <= '9'; i--)
    {
        int carry = 0;
        char *move = temp + len1 - i - 1;
        for (int j = len2 - 1; j >= 0 && *(num2 + j) >= '0' && *(num2 + j) <= '9'; j--)
        {
            int cal = (*(num1 + i) - '0') * (*(num2 + j) - '0') + carry + (*move == '\0' ? 0 : (*move - '0'));
            carry = cal / 10;
            *move = cal % 10 + '0';
            move++;
        }
        if (carry > 0)
        {
            *move = carry + '0';
        }
    }
    int retlen = strlen(temp) + negative + 1;
    char *ret = (char *)malloc(sizeof(char) * retlen);
    if (ret == NULL)
    {
        return NULL;
    }
    char *resver = ret + retlen - 2;
    while (*temp != '\0')
    {
        *resver-- = *temp++;
    }
    if (negative)
    {
        *ret = '-';
    }
    *(ret + retlen - 1) = '\0';
    if (*ret == '0')
    {
        *(ret + 1) = '\0';
    }
    return ret;
}

