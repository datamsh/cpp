# include <string>
# include <iostream>
# include <map>
using namespace std;
const string STR_QUIT = "QUIT";

inline const int getDistanceinASCII() {
	return ('a' - 'A');
}

string toUpper(string str) {
	string upperString(str);

	for (unsigned int i = 0; i < str.length(); i++) {
		const char theChar = str[i];
		char theConvertedChar;

		if ((theChar >= 'a') && (theChar <= 'z'))
			theConvertedChar = theChar - getDistanceinASCII();
		else
			theConvertedChar = theChar;

		upperString[i] = theConvertedChar;
	}
	return upperString;
}
void main() {
	int intCounter = 0;
	int floatCounter = 0;
	int charCounter = 0;
	//int counter[3] = {0, 0, 0} ; // int, float, char

	// map<key, value>
	map<string, int> counter;

	while (true) {
		string type;
		cin >> type;

		if (toUpper(type) == STR_QUIT) break;

		string strTypes[3] = { "int", "float", "char" };

		for (unsigned int strIndex = 0; strIndex < 3; strIndex++) {
			if (type == strTypes[strIndex])
				counter[type] ++;
		}
		if (type == "int") {
			intCounter++;

			counter["int"] ++;

			cout << numeric_limits<int>::min() << endl;
			cout << numeric_limits<int>::max() << endl;
		}
		else if (type == "float") {
			floatCounter++;

			counter["float"] ++;
			cout << numeric_limits<float>::min() << endl;
			cout << numeric_limits<float>::max() << endl;
		}
		else if (type == "char") {
			charCounter++;
			counter["char"] ++;

			cout << static_cast<int>(numeric_limits<char>::min()) << endl;
			cout << static_cast<int>(numeric_limits<char>::max()) << endl;
		}
	}
	cout << "int: " << intCounter << endl;
	cout << "float: " << floatCounter << endl;
	cout << "char: " << charCounter << endl;
	int value;
	cin >> value;
}