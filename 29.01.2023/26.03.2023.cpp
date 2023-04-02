#include <iostream>
#include <string>

using namespace std;

class Array {
public:
	int* pa;
	int size;
	void r_init() {
		for (int i = 0; i < size; i++) {
			pa[i] = rand() % 10;
		} 
	}
	
	void print() {
		for (int i = 0; i < size; i++) {
			cout << pa[i] << " ";
		}
	}

	void add_item(int item) {
		int* npa = new int[size + 1];
		for (int i = 0; i < size; i++) {
			npa[i] = pa[i];
		}
		npa[size] = item;
		size++;
		delete[]pa;
		pa = npa;
	}

	int pop() { //возвращает последний элемент массива и удаляет его
		int item = pa[size - 1];
		int* npa = new int[--size];
		for (int i = 0; i < size; i++) {
			npa[i] = pa[i];
		}
		delete[]pa;
		pa = npa;
		return item;
	}
};

int main() {
	Array arr;
	arr.size = 5;
	arr.pa = new int[arr.size];
	arr.r_init();
	arr.print();
	cout << endl;
	int number = arr.pop();
	arr.print();
	cout << endl << number;
	return 0;
}