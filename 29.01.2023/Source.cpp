#include <iostream>
using namespace std;

void initArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << "\t";
	}
	cout << endl;
}

//int unite(int* arr1, int* arr2, int size1, int size2) {
//	int size3 = 0;
//	for (int i = 0; i < size1; i++) {
//		for (int j = 0; j < size2; j++) {
//			if (arr1[i] == arr2[j]) {
//				break;
//			}
//
//			for(int j = 0; j < i; j++)
//			{
//				if (arr1[i] == arr1[j]) {
//					break;
//				}
//			}
//			if (arr1[i] != arr2[j]) {
//					size3++;
//			}
//		}
//		int* arr3 = new int[size3];
//		int k = 0;
//		for (int i = 0; i < size1; i++) {
//			for (int j = 0; j < size2; j++) {
//				if (arr1[i] == arr2[j]) {
//					break;
//				}
//			}
//			for (int j = 0; j < i; j++) {
//				if (arr1[i] == arr1[j]) {
//					break;
//				}
//			}
//			for(int j = 0; j < size2; j++)
//			{
//				if (arr1[i] != arr2[j]) {
//					arr3[k++] = arr1[i];
//				}
//			}
//			cout << arr3[k] << '\t'; 
//		}
//	}
//}



int main() {
	setlocale(LC_ALL, "Rus");
	int m = 3;
	int n = 6;
	int* A = new int[m];
	int* B = new int[n];
	initArr(A, m);
	cout << endl;
	initArr(B, n);
	int size3 = 0;
	bool isU;
	for (int i = 0; i < m; i++) {
		isU = true;
		for (int j = 0; j < n; j++) {
			if (A[i] == B[j]) {
				isU = false;
				break;
			}
		}
		for (int j = 0; j < i; j++) {
			if (A[i] == A[j]) {
				isU = false;
				break;
			}
		}
		if (isU) size3++;
	}
	for (int i = 0; i < n; i++) {
		isU = true;
		for (int j = 0; j < m; j++) {
			if (B[i] == A[j]) {
				isU = false;
				break;
			}
		}
		for (int j = 0; j < i; j++) {
			if (B[i] == B[j]) {
				isU = false;
				break;
			}
		}
		if (isU) size3++;
	}
	int* C = new int[size3];
	int k = 0;
	for (int i = 0; i < m; i++) {
		isU = true;
		for (int j = 0; j < n; j++) {
			if (A[i] == B[j]) {
				isU = false;
				break;
			}
			
		}
		for (int j = 0; j < i; j++) {
			if (A[i] == A[j]) {
				isU = false;
				break;
			}
		}
		if (isU) {
			C[k++] = A[i];
		}
	}
	for (int i = 0; i < n; i++) {
		isU = true;
		for (int j = 0; j < m; j++) {
			if (B[i] == A[j]) {
				isU = false;
				break;
			}

		}
		for (int j = 0; j < i; j++) {
			if (B[i] == B[j]) {
				isU = false;
				break;
			}
		}
		if (isU) {
			C[k++] = B[i];
		}
	}

	cout << endl;
	for (int i = 0; i < size3; i++) {
		cout << C[i] << "\t";
	}


	return 0;
}