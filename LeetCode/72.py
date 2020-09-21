#!/usr/bin/env python3
# -*- coding:utf-8 -*-
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        l1 = len(word1)+1
        l2 = len(word2)+1
        dp = [[x+y for y in range(l2)] for x in range(l1)]
        for i in range(1,l1):
            for j in range(1,l2):
                dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+ (0 if word1[i-1] == word2[j-1] else 1))
        return dp[l1-1][l2-1]


a = Solution()
print(a.minDistance("horse","ros"))
print(a.minDistance("intention","execution"))
print(a.minDistance("",""))

