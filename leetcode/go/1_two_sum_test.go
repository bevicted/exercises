package main

import (
	"math/rand"
	"testing"

	"github.com/stretchr/testify/assert"
)

const (
	benchmarkNumsLen = 10
	benchmarkTarget  = 6
)

func TestTwoSum(t *testing.T) {
	t.Parallel()

	for _, tc := range []struct {
		name          string
		nums          []int
		target        int
		expectIndices []int
	}{
		{
			name:          "example 1",
			nums:          []int{2, 7, 11, 15},
			target:        9,
			expectIndices: []int{0, 1},
		},
		{
			name:          "example 2",
			nums:          []int{3, 2, 4},
			target:        6,
			expectIndices: []int{1, 2},
		},
		{
			name:          "example 3",
			nums:          []int{3, 3},
			target:        6,
			expectIndices: []int{0, 1},
		},
	} {
		tc := tc
		t.Run(tc.name, func(t *testing.T) {
			t.Parallel()
			for _, f := range []twoSumF{twoSum, twoSumV2} {
				assert.Equal(t, tc.expectIndices, f(tc.nums, tc.target))
			}
		})
	}
}

func FuzzTwoSum(f *testing.F) {
	f.Add(2, 3, 5)
	f.Fuzz(func(t *testing.T, n1, n2, target int) {
		indices := twoSum([]int{n1, n2}, target)
		if n1+n2 == target {
			assert.Equal(t, []int{0, 1}, indices)
			return
		}

		assert.Nil(t, indices)
	})
}

func makeRandIntSlice(n int) []int {
	s := make([]int, n)
	for i := range n {
		s[i] = rand.Intn(100)
	}
	return s
}

func BenchmarkTwoSum(b *testing.B) {
	for i := 0; i < b.N; i++ {
		b.StopTimer()
		nums := makeRandIntSlice(benchmarkNumsLen)

		b.StartTimer()
		twoSum(nums, benchmarkTarget)
	}
}

func BenchmarkTwoSumV2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		b.StopTimer()
		nums := makeRandIntSlice(benchmarkNumsLen)

		b.StartTimer()
		twoSumV2(nums, benchmarkTarget)
	}
}
