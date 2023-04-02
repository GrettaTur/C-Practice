#include <iostream> 
#include <string>
#include <math.h>

using namespace std;
//Битовые операции

//struct Complex_number {
//	int a;
//	int b;
//	const int i = sqrt(-1);
//};
//
//void plus_(Complex_number a, Complex_number b) {
//	cout << "Сумма комплексных чисел = " << (a.a + b.a*a.i) + (a.b + b.b*b.i) /*<< "i"*/;
//}
//
//void minus_(Complex_number a, Complex_number b) {
//	cout << "Вычитание комплексных чисел = " << (a.a - b.a) + (a.b - b.b) << "i";
//}
//
//void multiply_(Complex_number a, Complex_number b) {
//	cout << "Произведение комплексных чисел = " << (a.a * b.a - a.b * b.b) +(a.a*b.b + a.b*b.a) << "i";
//}
//
//void divide_(Complex_number a, Complex_number b) {
//	cout << "Частное комплексных чисел = " << (a.a * b.a + a.b * b.b) / (b.a * b.a + b.b * b.b) + (a.b*b.a - a.a*b.b ) / (b.a * b.a + b.b * b.b) << "i";
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
	cout << "Введите дату типа дд.мм: ";
	string date;
	cin >> date;
	cout << "Введите задачу: ";
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
		cout << "Не могу записать!";
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
		cout << "Не могу прочитать!";
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
	cout << "Что сделать?\n";
	cout << "1. Добавить задачу\n";
	cout << "2. Прочитать все задачи\n";
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
	//	cout << "Не могу открыть!";
	//}
	//else{
	//	/*fopen_s(&stream, "D:\\text.txt", "w");*/ // открывает файл и возвращает указатель на этот файл;
	//	fprintf(stream, "%s\t%i\n", "Вадим:", 12);
	//	fprintf(stream, "%s\t%i\n", "Егор:", 10);
	//	fclose(stream);
	//}

	//if ((fopen_s(&stream, "D:\\text1.txt", "r")) != NULL) {
	//	cout << "Не могу открыть!";
	//}
	//else {
	//	fscanf_s(stream, "%s\t%i\n", "Вадим", 12);
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