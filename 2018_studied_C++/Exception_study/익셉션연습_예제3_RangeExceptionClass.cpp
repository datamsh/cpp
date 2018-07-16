# include <iostream>
# include <string>
using namespace std ;
class RangeException {
const int value ;
const string msg ;
public:
RangeException(const string& _msg, int _value) : msg(_msg), value(_value) {}
void print() const { cout << value << " " << msg << endl ; }
} ;

class Date {
int month, day, year ;
public:
Date(int m, int d, int y) {
if ( m <= 0 || m > 12 ) throw RangeException("Invalid Month !", m) ;
if ( d <= 0 || d > 31 ) throw RangeException("Invalid Day!", d) ;
if ( y <= 0 ) throw RangeException("Negative year not allowed!", y) ;
month = m ; day = d ; year = y ;
}
void print() const { cout << month << '.' << day << '.' << year << endl ; }
} ;
int main() {
try {
Date d1(5, 30, 2009) ; // no exception
d1.print();

Date d4(13, 35, 2009) ; // invalid month
}
catch ( const RangeException& e) { e.print() ; }
}
