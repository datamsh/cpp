
#include <iostream>
#include <string>

using namespace std;


int main()
{
	cout << "문자열 2개를 입력하시오" << endl;
	string inputA, inputB;
	cin >> inputA;
	cin >> inputB;

	string output = inputA.append(inputB);
	cout << output << endl;
    return 0;
}
/*
int main()
{
	cout << "문자열을 입력하세요" << endl;
	string input;
	cin >> input;

	string output = "";
	int size = input.length();
	
	for (int i = 0; i < size; i++) {
		output += input[size - i - 1];
	}
	cout << output << endl;
	return 0;
	
}*/