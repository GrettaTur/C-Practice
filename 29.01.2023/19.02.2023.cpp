#include <iostream>
#include <string>

using namespace std;

//struct Movie {
//	string movie_name;
//	string director;
//	string genre;
//	double rating;
//	int price;
//};
//
//void print(Movie movie) {
//	cout << "Name: " << movie.movie_name << endl;
//	cout << "Director: " << movie.director << endl;
//	cout << "Genre: " << movie.genre << endl;
//	cout << "Rating: " << movie.rating << endl;
//	cout << "Price: " << movie.price << endl;
//}
//
//void search_by_name(Movie movies[], int size, string key) {
//	for (int i = 0; i < size; i++) {
//		if (movies[i].movie_name.find(key) != -1)
//			print(movies[i]);
//	}
//}
//
//void search_by_genre(Movie movies[], int size, string key) {
//	for (int i = 0; i < size; i++) {
//		if (movies[i].genre.find(key) != -1)
//			print(movies[i]);
//	}
//}
//
//void search_max_rating(Movie movies[], int size) {
//	int index = 0;
//	double max = movies[0].rating;
//	for (int i = 0; i < size; i++) {
//		if (movies[i].rating > max) {
//			index = i;
//			max = movies[i].rating;
//		}
//	}
//	cout << "The most popular movie is " << movies[index].movie_name;
//}
struct player {
	char symbol;
	int score;
};

char field[3][3];
void print_field(char arr[3][3]) {
	cout << "-\t-\t-\t-\t-" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "|\t";
		for (int j = 0; j < 3; j++){
			cout << arr[i][j] << "\t";
		}
		cout << "|" << endl;
	}
	cout << "-\t-\t-\t-\t-" << endl;
}
	

int main() {
	//setlocale(LC_ALL, "Rus");
	//
	//Movie movies[3]{ { "Home alone", "Chris Columbus", "Comedy", 7.7, 500 },
	//				{ "The Matrix", "The Wachowskis", "Science fiction", 8.7,800 },
	//				{ "Titanic", "James Cameron", "Romance", 7.9,750 }  };

	//cout << "Что ищем? ";
	//string key;
	//cin >> key;
	//search_by_name(movies, 3, key);
	///*search_by_genre(movies, 3, key);*/
	///*search_max_rating(movies, 3);*/
	int k = 49;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = k++;
		}
	}

	player playerX{ 'X', 0 };
	player playerO{ 'O',0 };
	player players[2]{ playerX, playerO };
	/*while (true) {
		for (int i = 0; i < 2; i++) {
			cout << players[0].symbol << " tern" << endl;
		}
	}*/

	print_field(field);

	return 0;
}