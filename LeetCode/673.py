#!/usr/bin/env python3
# -*- coding:utf-8 -*-

class Solution:
    def findNumberOfLIS(self, nums) -> int:
        self.nums = nums
        self.longest=[0]*len(nums)
        self.prev_num=[0]*len(nums)
        self.lens = len(nums)
        self.caculate()
        num = 0
        max = 0
        for k,l in enumerate(self.longest):
            if l > max:
                max = l
                num = self.prev_num[k]
            elif l == max:
                num += self.prev_num[k]
        return num
    def caculate(self):
        for i in range(self.lens):
            max = 0
            prev_num = 1
            for j in range(i):
                if self.nums[j] >= self.nums[i]:
                    continue
                elif max < self.longest[j]:
                    max = self.longest[j]
                    prev_num = self.prev_num[j] 
                elif max == self.longest[j]:
                    prev_num += self.prev_num[j]
            self.longest[i] = max+1
            self.prev_num[i] = prev_num

a=Solution()
print(a.findNumberOfLIS([1,2,4,3,5,4,7,2]))
