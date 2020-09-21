#!/usr/bin/env python
# -*- coding:utf-8 -*-
class Solution:
    def backspaceCompare(self, S, T):
        i,j = len(S)-1,len(T)-1
        while i >= 0 and j >= 0:
            i,j = self.skip(S,i),self.skip(T,j)
            print(i,j)
            if i > 0 and j > 0 and S[i] != T[j]:
                return False
            i,j=i-1,j-1
        return i < 0 and j < 0
    def skip(self,Str,idx):
        back = 1 if Str[idx] == '#' else 0
        while back > 0 and idx >= 0:
            idx = idx - 1
            if Str[idx] == '#':
                back = back+1
            else:
                back = back - 1
        return idx
print("aa")
