#include <iostream>
#include <string.h>

using namespace std;

int times(string s, char symbol, int pos) {
	int n = s.find(symbol, pos);
	if (n == -1) return 0;	
	return times(s, symbol, n + 1)+1;
}

int main() {
	setlocale(LC_ALL, "Rus");
	string line = "Hello world";
	char symbol = 'l';
	cout << line << endl;
	cout << symbol << " встречается " << times(line, symbol, 0) << " раз." << endl;
	return 0;
}