package main

import (
	"github.com/Axect/Numeric/array"
)

type Matrix = [][]float64

func main() {
	A := array.Zeros(2, 2)
	A[0][0] = 1
	A[0][1] = 2
	A[1][0] = 3
	A[1][1] = 4

	array.MatrixForm(array.Inverse(A))
}
