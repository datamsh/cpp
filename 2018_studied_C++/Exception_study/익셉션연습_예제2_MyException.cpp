# include <iostream>
using namespace std ;
class MyException {
public:
void print() const { cout << "Error: divide by zero\n" ; }
} ;
int divide(int x, int y) {
if ( y == 0 ) throw MyException() ;
return x / y ;
}
int main() {
try {
int r = divide(10, 0) ;
cout << r << endl ;
} catch (const MyException& e) { e.print() ; }
}
