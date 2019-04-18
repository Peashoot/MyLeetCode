/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (41.78%)
 * Total Accepted:    220.2K
 * Total Submissions: 527.1K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true 
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * 
 * Input: 218
 * Output: false
 * 
 */
bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    while (n > 0)
    {
        if (n == 1)
        {
            return true;
        }
        if (n % 2 == 1) {
            return false;
        }
        n /= 2;
    }
    return true;
}

