#include <iostream>
#include <string>

using namespace std;

template <class T>
class MyException {
string msg ;
T v ;
public:
MyException(const string& _msg, T _v=T()) : msg(_msg), v(_v) {}
void print() const { cout << msg << " " << v << endl ; }
} ;
template <class T>
int find(T data[], int size, T v) {
if ( data == '\0' ) throw MyException<T>("The array pointer is null") ;
if ( size <= 0 ) throw new MyException<T>("The array size is invalid") ;
for ( int i = 0 ; i < size ; i ++ ) if ( data[i] == v ) return i ;
throw MyException<T>("Not found", v) ;
}
int main() {
int iValues[] = {10, 20, 30, 40, 50} ;
try {
//int index = find(iValues, 5, 60) ;
//index = find(iValues, 0, 50) ;
int index = find((int*) 0, 5, 50) ;
}
catch (const MyException<int>& e) { e.print() ; }
catch (const MyException<int>* const e) { e->print() ; delete e ; }
}
