#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int row, int col) {
	matrix = new int* [row];
	mrow = row;
	mcol = col;
	for (int i = 0; i < mrow; i++) {
		matrix[i] = new int[mcol] {};
	}
}
void Matrix::print() {
	for (int i = 0; i < mrow; i++) {
		for (int j = 0; j < mcol; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}