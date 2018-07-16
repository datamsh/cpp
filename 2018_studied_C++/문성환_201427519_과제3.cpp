#include <iostream>
#include <string>
#include <locale>

using namespace std ;

int main() {
	cout << "Enter the score count: " ;
	int maxSize ;
	cin >> maxSize ;

	if (maxSize == 0) {
		cout << "1개 이상의 점수가 입력되어야 한다." << endl ;
	}
	int* const scores = new int[maxSize] ;
	int sum = 0 ;
	double average = 0 ;
	int count = 0 ;
	while (true) {
		string command ;
		cout << "Enter command: (add, sum, average, quit) " ;
		cin >> command ; 
		for (int i = 0; i < command.length(); i++) {
			command[i] = tolower(command[i]) ;
		}

		if (command == "add" && count != maxSize) {
			cout << "Enter score: " ;
			cin >> scores[count] ;
			cout << scores[count] << " added" << endl ;
			sum += scores[count] ;
			count ++ ;		
			average = (double) sum / count ;
			continue ;
		}

		if (command == "add" && count == maxSize) {
			cout << "Too many scores" << endl ;
			continue ;
		}

		if (command == "sum") {
			cout << "Sum: " << sum << endl ;
			continue ;
		}

		if (command == "average") {
			cout << "Average: " << average << endl ;
			continue ;
		}

		if (command == "quit") {
			cout << "Bye" << endl ;
			break ;
		}

		else {
			cout << "잘못된 값을 입력했습니다." ;
		}

	}
	delete[] scores ;

	return 0 ; 
}