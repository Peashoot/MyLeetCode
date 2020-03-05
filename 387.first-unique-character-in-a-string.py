#
# @lc app=leetcode id=387 lang=python
#
# [387] First Unique Character in a String
#
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        arr = [-1] * 256
        for i in range(len(s)):
            if arr[ord(s[i])] == -1:
                arr[ord(s[i])] = i
            elif arr[ord(s[i])] > -1:
                arr[ord(s[i])] = -2
        min = len(s)
        for i in range(256):
            if arr[i] > -1 and arr[i] < min:
                min = arr[i]
        if min == len(s):
            return -1
        else:
            return min
