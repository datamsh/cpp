#include <iostream>
#include <string>
#include <limits>

using namespace std ;

int main() {
	string dataType= "" ;
	int numberOfCharCall = 0 ;
	int numberOfIntCall = 0 ;
	int numberOfLongCall = 0 ;
	int numberOfFloatCall = 0 ;
	int numberOfDoubleCall = 0 ;

	while (dataType.compare("quit") != 0) {
		cin >> dataType ;
		
		if (dataType.compare("char") == 0) {
			cout << static_cast<int> (numeric_limits<char>::min()) << "\t" ;
			cout << static_cast<int> (numeric_limits<char>::max()) << endl ;
			numberOfCharCall ++ ;
		}

		else if (dataType.compare("int") == 0) {
			cout << numeric_limits<int>::min() << "\t" ;
			cout << numeric_limits<int>::max() << endl ;
			numberOfIntCall ++ ;
		}

		else if (dataType.compare("long") == 0) {
			cout << numeric_limits<long>::min() << "\t" ;
			cout << numeric_limits<long>::max() << endl ;
			numberOfLongCall ++ ;
		}

		else if (dataType.compare("float") == 0) {
			cout << numeric_limits<float>::min() << "\t" ;
			cout << numeric_limits<float>::max() << endl ;
			numberOfFloatCall ++ ;
		}

		else if (dataType.compare("double") == 0) {
			cout << numeric_limits<double>::min() << "\t" ;
			cout << numeric_limits<double>::max() << endl ;
			numberOfDoubleCall ++ ;
		}

		else {
			cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요" << endl ;
		}
	}

	cout << "\=\=\= A List of \# of types \=\=\=" << endl ;
	cout << "int: " << numberOfIntCall << endl ;
	cout << "long: " << numberOfLongCall << endl ;
	cout << "float: " << numberOfFloatCall << endl ;
	cout << "double: " << numberOfDoubleCall << endl ;
	cout << "char: " << numberOfCharCall << endl ;

	return 0 ;
}
