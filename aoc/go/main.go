package main

import (
	"errors"
	"fmt"
	"os"

	twentytwentyfour "github.com/bevicted/exercises/aoc/go/2024"
)

func main() {
	if len(os.Args) != 4 {
		fmt.Println("Exact arguments required: YEAR DAY PATH/TO/INPUT/FILE")
		os.Exit(1)
	}

	var (
		result    any
		year      = os.Args[1]
		day       = os.Args[2]
		inputPath = os.Args[3]
	)

	b, err := os.ReadFile(inputPath)
	if err != nil {
		fmt.Println("can't read input file, please check the path provided")
		os.Exit(1)
	}

	switch {
	case year == "2024" && day == "1":
		result, err = twentytwentyfour.SolveDay1(string(b))
	default:
		err = errors.New("solution doesn't exist yet, get to work")
	}

	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	fmt.Println(result)
}
