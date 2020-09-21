#!/usr/bin/env python
# -*- coding:utf-8 -*-

class Solution:
    def longestPalindrome(self,s):
        dp = [[False for _ in range(len(s))] for _ in range(len(s))]
        l,r = 0,0
        for head in range(len(s)-2,0,-1):
            for tail in range(head,len(s)):
                if s[head] == s[tail] and (tail-head < 3 or dp[head+1][tail-1]):
                    dp[head][tail] = True
                    if r-l < tail-head:
                        l,r=head,tail
        return s[l:r+1]
a=Solution()
print(a.longestPalindrome("babad"))
