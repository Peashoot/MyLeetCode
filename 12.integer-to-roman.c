/*
 * @lc app=leetcode id=12 lang=c
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (50.39%)
 * Total Accepted:    218.7K
 * Total Submissions: 433.2K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * 
 * 
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
char* intToRoman(int num) {
    if (num > 3999 || num <= 0)
    {
        return "";
    }
    char signal[] = "  MDCLXVI";
    char *ret = (char *)malloc(sizeof(char));
    if (ret == NULL)
    {
        return NULL;
    }
    int quotient = num / 1000, len = 1, divisor = 10000, round = 0, index = 0;
    do
    {
        num %= divisor;
        divisor /= 10;
        quotient = num / divisor;
        if (quotient == 9)
        {
            ret = (char *)realloc(ret, sizeof(char) * (2 + len));
            if (ret == NULL)
            {
                return NULL;
            }
            *(ret + index++) = signal[round * 2 + 2];
            *(ret + index++) = signal[round * 2];
            len += 2;
        }
        else if (quotient >= 5)
        {
            ret = (char *)realloc(ret, sizeof(char) * (quotient - 4 + len));
            if (ret == NULL)
            {
                return NULL;
            }
            *(ret + index++) = signal[round * 2 + 1];
            for (int i = 0; i < quotient - 5; i++)
            {
                *(ret + index++) = signal[round * 2 + 2];
            }
            len += quotient - 4;
        }
        else if (quotient == 4)
        {
            ret = (char *)realloc(ret, sizeof(char) * (2 + len));
            if (ret == NULL)
            {
                return NULL;
            }
            *(ret + index++) = signal[round * 2 + 2];
            *(ret + index++) = signal[round * 2 + 1];
            len += 2;
        }
        else if (quotient > 0)
        {
            ret = (char *)realloc(ret, sizeof(char) * (quotient + len));
            if (ret == NULL)
            {
                return NULL;
            }
            for (int i = 0; i < quotient; i++)
            {
                *(ret + index++) = signal[round * 2 + 2];
            }
            len += quotient;
        }
        round++;
    } while (divisor > 1);
    *(ret + index) = '\0';
    return ret;
}

