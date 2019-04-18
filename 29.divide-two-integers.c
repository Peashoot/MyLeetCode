/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.15%)
 * Total Accepted:    189.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */
int divide(int dividend, int divisor) {
    int ori_dividend = dividend;
    if (dividend == divisor) {
        return 1;
    }
    if (divisor == INT_MIN)
    {
        return 0;
    }
    bool negative = (dividend < 0 && divisor >= 0) || (dividend > 0 && divisor <= 0);
    int offset = 0;
    if (dividend == INT_MIN)
    {
        dividend = INT_MIN + 1;
        offset = 1;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);
    if (dividend < divisor)
    {
        return 0;
    }
    int ret = 1, temp = divisor, signal = 1;
    while (dividend >= temp)
    {
        if (temp >= 1073741824)
        {
            signal = 0;
            break;
        }
        temp <<= 1;
        ret <<= 1;
    }
    int halfret = divide(dividend - (temp >> signal) + offset, divisor);
    ret = INT_MAX - (ret >> signal) > halfret ? (ret >> signal) + halfret : INT_MAX;
    if (negative)
    {
        return ori_dividend == INT_MIN && ret == INT_MAX ? INT_MIN : 0 - ret;
    }
    return ret;
}

