/*
 * @lc app=leetcode id=400 lang=c
 *
 * [400] Nth Digit
 */


int findNthDigit(int n){
    int len = 0, total = 0, temptotal = 0, zeros = 1;
    if (n > 788888889)
    {
        len = 9;
        zeros = 100000000;
        total = 788888889;
    }
    else
    {
        for (; temptotal < n;)
        {
            len++;
            zeros *= 10;
            total = temptotal;
            temptotal += 9 * len * (zeros / 10);
        }
    }
    int start = (n - total + 1) / len + zeros;
    for (int i = 0; i < len - (n - total) % len; i++)
    {
        start /= 10; // 2147483661
    }
    return start % 10;
}



