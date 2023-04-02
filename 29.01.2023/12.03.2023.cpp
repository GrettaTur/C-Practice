#include <iostream>
#include "GettingArr.h"
#include "PrintArr.h"
#include <string>
using namespace std;
//Препроцессор
//#define PI 3.14159 - в программе PI будет определяться как заданнное число
//#define begin (

struct Song {
	string name;
	string singer;
	string lyrics;
	int released_year;
};

void print(Song Song) {
	cout << "\t" << Song.name << endl;
	cout << "     " << "(" << Song.singer << ", " << Song.released_year << ")" << endl;
	cout << Song.lyrics << endl;

}

void search(Song* songs, string key) {
	for (int i = 0; i<4 ; i++) {
		if (songs[i].name.find(key)) {
			print(songs[i]);
		}
	}
}
void print0() {
	cout << "Нет такой песни";
}

int main() {
	setlocale(LC_ALL, "RUS");
	Song songs[]{ {"Last Christmas", "George Michael", "Last Christmas I gave you my heart...",1984},
					{"Careless Whisper", "George Michael", "I'm never gonna dance again...", 1984},
					{"All I want for Christmas is you", "Mariah Carey", "I don't want a lot for Christmas...", 1994},
					{"Beautiful", "Mariah Carey", "...", 1994} };
	search(songs, "Christmas");
}