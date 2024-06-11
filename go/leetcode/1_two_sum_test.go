package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
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
			assert.Equal(t, tc.expectIndices, twoSum(tc.nums, tc.target))
		})
	}
}
