package main

import (
	"log"
)

func spiralOrder(matrix [][]int) []int {
	var r []int
	if len(matrix) == 0 {
		return r
	}

	i, j, di, dj := 0, 0, 0, 1
	count := len(matrix) * len(matrix[0])
	r = make([]int, 0, count)

	log.Println(matrix, count)

	for n := 0; n < count; n++ {
		r = append(r, matrix[i][j])
		matrix[i][j] = 0
		if j+dj < 0 || matrix[(i+di)%len(matrix)][(j+dj)%len(matrix[0])] == 0 {
			di, dj = dj, -di
		}
		i += di
		j += dj
	}

	log.Println(r)
	return r
}

var (
	case1 = [][]int{{1}}
	case2 = [][]int{{1, 2, 3, 4}}
	case3 = [][]int{{1}, {2}, {3}, {4}}
	case4 = [][]int{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}}
	case5 = [][]int{{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}}
	case6 = [][]int{{1, 2, 3, 4}, {8, 7, 6, 5}}
	case7 = [][]int{{1, 2}, {8, 3}, {7, 4}, {6, 5}}
)

func main() {
	spiralOrder(case1)
	spiralOrder(case2)
	spiralOrder(case3)
	spiralOrder(case4)
	spiralOrder(case5)
	spiralOrder(case6)
	spiralOrder(case7)
}
