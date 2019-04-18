/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (46.56%)
 * Total Accepted:    462.8K
 * Total Submissions: 992.1K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */
int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize <= 1)
    {
        return 0;
    }
    int sum = 0;
    int min_index = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[min_index] > prices[i])
        {
            min_index = i;
        }
        else
        {
            int temp = prices[i] - prices[min_index];
            sum = sum < temp ? temp : sum;
        }
    }
    return sum < 0 ? 0 : sum;
}
