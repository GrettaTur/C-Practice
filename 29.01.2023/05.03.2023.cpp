#include <iostream> 
#include <string>
#include <math.h>

using namespace std;
//������� ��������

//struct Complex_number {
//	int a;
//	int b;
//	const int i = sqrt(-1);
//};
//
//void plus_(Complex_number a, Complex_number b) {
//	cout << "����� ����������� ����� = " << (a.a + b.a*a.i) + (a.b + b.b*b.i) /*<< "i"*/;
//}
//
//void minus_(Complex_number a, Complex_number b) {
//	cout << "��������� ����������� ����� = " << (a.a - b.a) + (a.b - b.b) << "i";
//}
//
//void multiply_(Complex_number a, Complex_number b) {
//	cout << "������������ ����������� ����� = " << (a.a * b.a - a.b * b.b) +(a.a*b.b + a.b*b.a) << "i";
//}
//
//void divide_(Complex_number a, Complex_number b) {
//	cout << "������� ����������� ����� = " << (a.a * b.a + a.b * b.b) / (b.a * b.a + b.b * b.b) + (a.b*b.a - a.a*b.b ) / (b.a * b.a + b.b * b.b) << "i";
//}
//
//union Number {
//	char c[8];
//	int i;
//};
//
//
//struct Car {
//	char make[20];
//	int year;
//	Number car_number;
//};

struct task {
	string date;
	string text;
};

task create() {
	setlocale(LC_ALL, "Rus");
	cout << "������� ���� ���� ��.��: ";
	string date;
	cin >> date;
	cout << "������� ������: ";
	string text;
	cin >> text;
	task task{ date, text };
	return task;
}

void print(task task) {
	cout << "\t" << task.date << endl;
	cout << "\t" << task.text << endl;
}

const char* path = "D:\\text.txt";

void write(task task) {
	setlocale(LC_ALL, "Rus");
	FILE* stream;
	if (fopen_s(&stream, path, "a") != NULL) {
		cout << "�� ���� ��������!";
		return;
	}
	else {
		const char* date = task.date.c_str();
		const char* text = task.text.c_str();
		fprintf(stream, "\n%s %s", date, text);
		fclose(stream);
	}
}

void read() {
	FILE* stream;
	if (fopen_s(&stream, path, "r") != NULL) {
		cout << "�� ���� ���������!";
		return;
	}
	else {
		while (!feof(stream)) {
			char date [10];
			fscanf_s(stream, "%s", &date, 10);
			char  text[100];
			fscanf_s(stream, "%s", &text, 100);
			task task{ date, text };
			print(task);
		}
		fclose(stream);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "��� �������?\n";
	cout << "1. �������� ������\n";
	cout << "2. ��������� ��� ������\n";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: write(create());
		break;
	case 2: read();
		break;
	}
	//FILE* stream;
	//if ((fopen_s(&stream, "D:\\text1.txt", "w")) != NULL) {
	//	cout << "�� ���� �������!";
	//}
	//else{
	//	/*fopen_s(&stream, "D:\\text.txt", "w");*/ // ��������� ���� � ���������� ��������� �� ���� ����;
	//	fprintf(stream, "%s\t%i\n", "�����:", 12);
	//	fprintf(stream, "%s\t%i\n", "����:", 10);
	//	fclose(stream);
	//}

	//if ((fopen_s(&stream, "D:\\text1.txt", "r")) != NULL) {
	//	cout << "�� ���� �������!";
	//}
	//else {
	//	fscanf_s(stream, "%s\t%i\n", "�����", 12);
	//	fclose(stream);
	//}
	/*Complex_number d{5,3};
	Complex_number s{ 7,3};
	plus_(d,s);
	cout << endl;
	minus_(d, s);
	cout << endl;
	multiply_(d, s);*/
	
	/*Car car1{ "model 2", 2007, "Number" };
	Car car2{ "model 1", 2005};
	car2.car_number.i = 123456;
	Car cars[2]{car1, car2};
	for (int i = 0; i < 2; i++) {
		cout << cars[i].make << " " << cars[i].year << " ";
		if (cars[i].year > 2006) cout << cars[i].car_number.c;
		else cout << cars[i].car_number.i;
		cout << endl;
	}*/


	return 0;
}