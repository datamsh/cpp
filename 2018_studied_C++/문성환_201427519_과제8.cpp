#include <iostream>
#include <string>

using namespace std;

class MyString {
	char* str;
	int size;
public:
	MyString() {
		str = '\0';
		size = 0;
	}
	MyString(const string& str)
		: size(str.length()) {
		this->str = new char[size + 1];
		int i = 0;
		while (i < size) {
			this->str[i] = str.at(i);
			i++;
		}
	}
	MyString(const MyString& myString)
		: size(myString.size){
		this->str = new char[size + 1];
		int i = 0;
		for (i; i < size; i++) {
			this->str[i] = myString.at(i);
		}
	}
	~MyString() {
		delete[] str;
		str = NULL;
	}
	int length() const {
		return size;
	}
	char at(int i) const {
		return str[i];
	}
	void print() const {
		int i = 0;
		for (i; i < this->length(); i++) {
			cout << this->at(i);
		}
		cout << endl;
	}
	void set(int i, char d) {
		this->str[i] = d;
	}

};

int main()
{
	MyString str1("ABC");
	str1.print();

	{
		MyString str2(str1);
		str2.set(0, 'D');
		str2.print();
	}
	str1.print();

	for (int i = 0; i < str1.length(); i++) {
		cout << str1.at(i);
	}
    return 0;
}

