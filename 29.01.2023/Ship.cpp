#include <iostream>

using namespace std;

struct player {
	char self_field[10][10];
	char enemy_field[10][10];
	string name;
};

void InitField(char field[10][10], char s) {
	for(int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = s;
		}
	}
}

void print_field(char field[10][10]) {
	cout << "  ";
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
		for (int j = 0; j < 10; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

bool check(char field[10][10], int x, int y) {
	if (field[x][y] == 'X') return false;
	if (field[x+1][y] == 'X') return false;
	if (field[x-1][y] == 'X') return false;
	if (field[x][y-1] == 'X') return false;
	if (field[x][y+1] == 'X') return false;
	if (field[x+1][y+1] == 'X') return false;
	if (field[x-1][y-1] == 'X') return false;
	if (field[x-1][y+1] == 'X') return false;
	if (field[x+1][y-1] == 'X') return false;
}

//void ship_1(char field[10][10]) {
//	for (int i = 0; i < 4; i++) {
//		for (;;) {
//			cout << "������� ����������(������� �������): ";
//			int x, y;
//			cin >> x >> y;
//			cout << "������� �����������: ";
//			if (check(field, x, y) {
//				field[x][y] = 'X';
//				break;
//			}
//			else {
//				cout << "������ ������!";
//			}
//		}
//	 }
//}

void shipa(char field[10][10], int cl, int ck) {
	for (int i = 0; i < 4; i++) {
		cout << "���� ����: " << endl;
		print_field(field);
		for (;;) {
			cout << "������� ����������(������� �������): ";
			int x, y;
			cin >> x >> y;
			cout << "������� �����������: ";
			int n;
			cin >> n;
			bool isAllow = true;
			if (n == 0) {
				for (int i = 0; i < cl; i++) {
					if (!check(field, x + 1, y)) {
						isAllow = false;
					}
				}
			}
			if (n == 1) {
				for (int i = 0; i < cl; i++) {
					 {
						isAllow = false;
					}
				}
			}
			if (isAllow) {
				if (n == 0) {
					for (int i = 0; i < cl; i++) {
						field[x][y + i] = 'X';
						
					}break;
				}
			}
			else {
				cout << "������ ������!";
			}
		}
	}
}
void set_field(char field[10][10]) {
	int ck = 4;
	for (int i = 1; i <= 4; i++, ck--) {
		shipa(field, i, ck);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	player players[2]{ {}, {} };
	cout << "���� ���? ";
	cin >> players[0].name;
	players[1].name = "���������";
	for (int i = 0; i < 2; i++) {
		InitField(players[i].self_field, ' ');
		InitField(players[i].enemy_field, ' ');
	}
	cout << "���� ����: " << endl;
	print_field(players[0].self_field);
	set_field(players[0].self_field);

}
