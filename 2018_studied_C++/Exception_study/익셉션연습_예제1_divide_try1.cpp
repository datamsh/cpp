#include <iostream>
using namespace std;

int divide(int x, int y) {
	if (y == 0) throw ("bb");
	if (x== 0 ) throw ("hihi");
	return x / y;
}
void f(int x, int y) {
	try { divide(x, y); }
	catch (const char* const e) { cout << e<<"hh" << endl; divide(0,-1);}
}
int main() {
	try { f(10, 0); }
	catch (const char* const e) { cout << e; }
}
