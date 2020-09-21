package main

import "fmt"

func maxHeapify(nums []int, i, lens int) {
	fa := i
	son := 2*fa + 1
	if son > lens {
		return
	}
	if son+1 <= lens && nums[son] < nums[son+1] {
		son++
	}
	if nums[fa] > nums[son] {
		return
	}
	nums[fa], nums[son] = nums[son], nums[fa]
	maxHeapify(nums, son,lens)

}
func heapSort(nums []int) []int {
	lens := len(nums) - 1
	for i := lens/2; i >= 0; i-- {
		maxHeapify(nums, i, lens)
	}
	for i:= lens; i >0; i--{
		nums[i],nums[0]=nums[0],nums[i]
		maxHeapify(nums,0,i-1)

	}
	return nums

}
func sortArray(nums []int) []int {
	return heapSort(nums)
}
func main() {
	nums := []int{5, 2, 3, 1}
	sortArray(nums)
	fmt.Println(nums)
}
