package main

// 1. Two Sum
//
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

type twoSumF func(nums []int, target int) []int

// original submission
// BenchmarkTwoSum-8       12280203                91.72 ns/op
func twoSum(nums []int, target int) []int {
	for i := range nums {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}

	return nil
}

// performance + readability
// based on the editorial and other submissions
// local benchmarking seems to disagree though
// BenchmarkTwoSumV2-8      1964156               644.5 ns/op
func twoSumV2(nums []int, target int) []int {
	complements := make(map[int]int, len(nums))
	for i, num := range nums {
		if j, ok := complements[target-num]; ok {
			return []int{j, i}
		}
		complements[num] = i
	}

	return nil
}
