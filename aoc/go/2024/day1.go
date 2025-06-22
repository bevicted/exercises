package twentytwentyfour

import (
	"fmt"
	"slices"
	"strconv"
	"strings"
)

func SolveDay1(input string) (int, error) {
	a, b, err := parseInput(input)
	if err != nil {
		return 0, err
	}

	a = bSortSlice(a)
	b = bSortSlice(b)

	return calcSliceDistance(a, b), nil
}

func parseInput(input string) ([]int, []int, error) {
	const sep = "   "
	var (
		a = []int{}
		b = []int{}
	)

	for line := range strings.SplitSeq(input, "\n") {
		if line == "" {
			break
		}
		parts := strings.Split(line, sep)
		if len(parts) != 2 {
			return nil, nil, fmt.Errorf("malformed input, expected 2 parts per line, got %d", len(parts))
		}

		i, err := strconv.ParseInt(parts[0], 10, 32)
		if err != nil {
			return nil, nil, err
		}
		a = append(a, int(i))

		i, err = strconv.ParseInt(parts[1], 10, 32)
		if err != nil {
			return nil, nil, err
		}
		b = append(b, int(i))
	}

	return a, b, nil
}

func bSortSlice(s []int) []int {
	var sorted = []int{}
	for _, num := range s {
		idx, _ := slices.BinarySearch(sorted, num)
		sorted = slices.Insert(sorted, idx, num)
	}
	return sorted
}

func calcSliceDistance(a []int, b []int) int {
	var d int
	for idx := range a {
		d += calcDistance(a[idx], b[idx])
	}
	return d
}

func calcDistance(a int, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}
