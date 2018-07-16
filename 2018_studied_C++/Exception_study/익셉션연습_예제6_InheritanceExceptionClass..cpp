# include <iostream>
# include <string>
using namespace std ;
class MyException {
const string msg ;
public:
MyException(const string& _msg) : msg(_msg) {
cout << "MyException created! " << msg << endl ;
}
void print() const { cout << msg << endl ; }
} ;

class Base {
protected: int value ;
public:
Base(int n) : value(n) {
cout << "Base constructor for " << value << endl ;
if ( value < 0 ) throw MyException("Negative") ;
}
~Base() { cout << "Base destructor for " << value << endl ; }
} ;
class Derived: public Base {
public:
Derived(int n) : Base(n) {
cout << "Derived constructor for " << value << endl ;
if ( value > 100 ) throw MyException("Too Big") ;
}
~Derived() { cout << "Derived destructor for " << value << endl ; }
} ;
int main() {
try {
Derived one(999) ;
} catch (const MyException& e) { e.print() ; }
try {
Derived two(-1) ;
} catch (const MyException& e) { e.print() ; }
}
