/*
 * @lc app=leetcode id=172 lang=c
 *
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (37.28%)
 * Total Accepted:    151.5K
 * Total Submissions: 406K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 */
int trailingZeroes(int n) {
    return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125 + n / 15625 + n / 78125 + n / 390625 + n / 1953125 + n / 9765625 + n / 48828125 + n / 244140625 + n / 1220703125;
}

