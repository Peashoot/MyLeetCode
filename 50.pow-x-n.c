/*
 * @lc app=leetcode id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start

double fast(double x, long long n)
{
    if (n == 0)
        return 1.0;
    double half = fast(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}
double myPow(double x, int n)
{
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = N * (-1);
    }
    return fast(x, N);
}

// @lc code=end

