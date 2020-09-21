#!/usr/bin/env python3
# -*- coding:utf-8 -*-

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        self.s = " "+s
        self.p = " "+p
        self.matrix = [[0]*len(self.p) for x in self.s]
        self.matrix[0][0]=1
        for i in range(len(s)+1):
            for j in range(1,len(p)+1):
                if self.matched(i,j):
                    self.matrix[i][j]=1
        return self.matrix[len(s)][len(p)]

    def matched(self,i:int,j:int)->bool:
        if self.equal(i, j):
            return self.matrix[i-1][j-1]
        elif self.p[j]=='*':
            if self.equal(i,j-1):
                return self.matrix[i][j-2] or self.matrix[i-1][j]
            else:
                return self.matrix[i][j-2]
    def equal(self,i:int,j:int)->bool:
        return i != 0 and self.p[j]== '.' or self.s[i]==self.p[j]

a=Solution()
print(a.isMatch("aa","a*"))
print(a.isMatch("ba","a*"))
print(a.isMatch("","*"))
print(a.isMatch("","."))
