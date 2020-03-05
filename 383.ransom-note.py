#
# @lc app=leetcode id=383 lang=python
#
# [383] Ransom Note
#
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        if ransomNote == magazine:
            return True
        if magazine == "":
            return False
        if len(ransomNote) > len(magazine):
            return False
        s = set()
        for i in range(0, len(ransomNote)):
            for j in range(0, len(magazine)):
                if j == len(magazine) - 1 and ransomNote[i] != magazine[j]:
                    return False
                if j in s:
                    continue
                if ransomNote[i] == magazine[j]:
                    s.add(j)
                    break
        return True

