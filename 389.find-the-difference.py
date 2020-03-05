#
# @lc app=leetcode id=389 lang=python
#
# [389] Find the Difference
#
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        arr1 = [0] * 256
        arr2 = [0] * 256
        for c in s:
            arr1[ord(c)] += 1
        for c in t:
            arr2[ord(c)] += 1
        for i in range(256):
            if arr1[i] != arr2[i]:
                return chr(i)
        return '\0'

