package main

// 1. Two Sum
//
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// performance + readability, O(n) complexity
// BenchmarkTwoSum-16             2884608               418.4 ns/op
func twoSum(nums []int, target int) []int {
	complements := make(map[int]int, len(nums))
	for i, num := range nums {
		if j, ok := complements[target-num]; ok {
			return []int{j, i}
		}
		complements[num] = i
	}

	return nil
}
