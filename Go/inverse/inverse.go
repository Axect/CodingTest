package main

import (
	"fmt"
	"log"
)

// =============================================================================
// Type Alias
// =============================================================================
type Vector = []float64
type Matrix = []Vector
type Generator = func(int, int) Matrix

// =============================================================================
// Main Function
// =============================================================================
func main() {
	A := Zeros(2, 2)
	A[0][0] = 1
	A[0][1] = 2
	A[1][0] = 3
	A[1][1] = 4
	M := Minor(A)
	fmt.Println(M(0, 1))
	B := Inverse(A)
	fmt.Println(Det(A))
	fmt.Println(B)
}

// =============================================================================
// Sub Functions
// =============================================================================
// Inverse calc inverse
func Inverse(M Matrix) Matrix {
	rows := len(M)
	cols := len(M[0])

	Inv := Zeros(rows, cols)
	D := Det(M)
	N := Minor(M)

	for i := range Inv {
		for j := range Inv[i] {
			Inv[i][j] = Det(N(j, i)) / D
		}
	}
	return Inv
}

// Zeros generates zero matrix
func Zeros(M, N int) Matrix {
	Temp := make(Matrix, M, M)
	for i := range Temp {
		Temp[i] = make(Vector, N, N)
	}
	return Temp
}

// Minor generates Minor
func Minor(M Matrix) Generator {
	rows := len(M) - 1
	cols := len(M[0]) - 1

	return func(p, q int) Matrix {
		Temp := Zeros(rows, cols)

		if p > rows || q > cols {
			log.Fatal("Exceed indices : Please input properly.")
		}

		for i := range Temp {
			for j := range Temp[i] {
				switch i < p {
				case true:
					if j < q {
						Temp[i][j] = M[i][j]
					} else {
						Temp[i][j] = M[i][j+1]
					}
				case false:
					if j < q {
						Temp[i][j] = M[i+1][j]
					} else {
						Temp[i][j] = M[i+1][j+1]
					}
				}
			}
		}
		return Temp
	}
}

// Det calculates Determinant
func Det(M Matrix) float64 {
	s := 0.
	N := Minor(M)

	CheckSquare(M)

	if len(M) == 1 {
		return M[0][0]
	}

	for i := range M[0] {
		switch i % 2 {
		case 0:
			s += M[0][i] * Det(N(0, i))
		default:
			s -= M[0][i] * Det(N(0, i))
		}
	}
	return s
}

//CheckSquare check square matrix
func CheckSquare(M Matrix) {
	if len(M) != len(M[0]) {
		log.Fatal("This Matrix is not square!")
	}
}
