package main

import "fmt"

func max(x,y int) int{
	if x>y{
		return x
	}else{
		return y
	}
}
func findNumberOfLIS(nums []int) int {
	dp := make([]int,len(nums)+1)
	res := 0
	dp[0]=0
	for i := 1;i<=len(nums);i++{
		for j:=1;j<=i;j++{
			if nums[i-1] > nums[j-1]{
				dp[i] = max(dp[i],dp[j])
			}
		}
		dp[i] = dp[i]+1
		res=max(res,dp[i])

	}
	return res
}
func main(){
	nums := []int {1,3,5,4,7}
	fmt.Print(findNumberOfLIS(nums))
}
