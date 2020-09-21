package main

import "fmt"

func feedMatrix(matrix [][]int, dimension, offset int) {
	begin, end := offset, dimension-offset-1
	nums := 1 + dimension*dimension - (dimension-2*offset)*(dimension-2*offset)
	if begin == end {
		matrix[begin][end] = nums
		return
	}
	for i := begin; i < end; i++ {
		matrix[begin][i] = nums
		nums++
	}
	for i := begin; i < end; i++ {
		matrix[i][end] = nums
		nums++
	}
	for i := end; i > begin; i-- {
		matrix[end][i] = nums
		nums++
	}
	for i := end; i > begin; i-- {
		matrix[i][begin] = nums
		nums++
	}
	offset += 1
	if offset < (dimension+1)/2 {
		feedMatrix(matrix, dimension, offset)
	}
}
func generateMatrix(n int) [][]int {
	result := make([][]int, n)
	for i := 0; i < n; i++ {
		result[i] = make([]int, n)
	}
	feedMatrix(result, n, 0)
	return result
}
func main() {
	fmt.Println(generateMatrix(3))
}
