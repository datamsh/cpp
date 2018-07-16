#include <iostream>
#include <string>

using namespace std;
class MyException {
string msg ;
public:
MyException(const string& _msg) : msg(_msg) {}
void print() const { cout << msg << endl ; }
} ;
int find(int data[], int size, int v) {
if ( data == '\0' ) throw MyException("The array pointer is null") ;
if ( size <= 0 ) throw new MyException("The array size is invalid") ;
for ( int i = 0 ; i < size ; i ++ ) if ( data[i] == v ) return i ;
throw MyException("Not found") ;
}
int main() {
int iValues[] = {10, 20, 30, 40, 50} ;
try {
int index = find(iValues, 5, 50) ;
//index = find(iValues, 5, 60) ;
index = find(iValues, 0, 50) ;
}
catch (const MyException& e) { e.print() ; cout << "hihi" ; }
catch (const MyException* const e) { e->print() ; delete e ; }
}
