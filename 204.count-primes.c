/*
 * @lc app=leetcode id=204 lang=c
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (28.49%)
 * Total Accepted:    224.3K
 * Total Submissions: 784.3K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
bool isPrimies(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if ((n % i) == 0)
        {
            return false;
        }
    }
    return true;
}
int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        count += isPrimies(i);
    }
    return count;
}

