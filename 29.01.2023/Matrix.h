#pragma once
class Matrix
{
public:
	int** matrix = nullptr;
	int mrow = 0;
	int mcol = 0;
	void print();
	Matrix(int col, int row);
};

