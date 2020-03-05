#
# @lc app=leetcode id=374 lang=python
#
# [374] Guess Number Higher or Lower
#
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n
        while True:
            mid = (low + high) >> 1
            pre = guess(mid)
            if pre == 0:
                break
            elif pre == 1:
                low = mid + 1
            else:
                high = mid - 1
        return mid

