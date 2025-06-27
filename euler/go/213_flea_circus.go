package main

import (
	"iter"
	"math/rand"
)

// A 30x30 grid of squares contains 900 fleas, initially one flea per square.
// When a bell is rung, each flea jumps to an adjacent square at random
// (usually 4 possibilities, except for fleas on the edge of the grid or at the
// corners).
//
// What is the expected number of unoccupied squares after 50 rings of the bell?
// Give your answer rounded to six decimal places.

type Grid [][]uint16

func NewGrid(cols int, rows int) Grid {
	g := make(Grid, cols)
	for i := range g {
		g[i] = make([]uint16, rows)
	}
	return g
}

func (g Grid) ColCount() int {
	return len(g)
}

func (g Grid) RowCount() int {
	if g.ColCount() == 0 {
		return 0
	}
	return len(g[0])
}

func (g Grid) Reset() {
	for x, y := range g.Iter() {
		g[x][y] = 1
	}
}

func (g Grid) CountEmpty() uint16 {
	var count uint16
	for x, y := range g.Iter() {
		if g[x][y] == 0 {
			count++
		}
	}
	return count
}

func (g Grid) Iter() iter.Seq2[int, int] {
	return func(yield func(int, int) bool) {
		for x := range g {
			for y := range g[x] {
				if !yield(x, y) {
					return
				}
			}
		}
	}
}

func Solve213Monte() float32 {
	const (
		size            = 30
		ringCount       = 50
		simulationCount = 100
	)

	var result float32
	grid := NewGrid(size, size)

	for range simulationCount {
		grid.Reset()

		for range ringCount {
			grid = ringBell(grid)
		}

		result += float32(grid.CountEmpty())
	}

	return result / float32(simulationCount)
}

func ringBell(grid Grid) Grid {
	cc := grid.ColCount()
	rc := grid.RowCount()
	g := NewGrid(cc, rc)

	for x, y := range grid.Iter() {
		var moveset [][2]int
		if x > 0 {
			moveset = append(moveset, [2]int{-1, 0})
		}
		if x < cc-1 {
			moveset = append(moveset, [2]int{1, 0})
		}
		if y > 0 {
			moveset = append(moveset, [2]int{0, -1})
		}
		if y < rc-1 {
			moveset = append(moveset, [2]int{0, 1})
		}

		for range grid[x][y] {
			move := moveset[rand.Intn(len(moveset))]
			g[x+move[0]][y+move[1]]++
		}
	}

	return g
}
