# include <iostream>
# include <string>
using namespace std ;

class StackException {
const string msg ;
public:
StackException(const string& msg):msg(msg){} ;
void print() const { cout << msg << endl ; }
} ;

class CharStack {
int size ;
int top ;
char* s ;
public:
CharStack(int sz) {
    if ( sz <=0 ) throw StackException("size is lower than 1");
    top = 0 ; s = new char[size=sz]; }
// destructor, copy constructor, and assignment operator
void push(char c) {
    if (top==size) throw StackException("stack full");
    s[top++] = c ; }
char pop() {
    if (top==0) throw StackException("stack empty");
    char r = s[--top]; s[top] = '\0' ; return r ; }
void print() const {
for ( int i = 0 ; i < top ; i ++ ) cout << s[i] ;
cout << endl ;
}
} ;

int main () {
    try{
        CharStack charStack(2);
        charStack.push('f');
        charStack.push('g');
        charStack.pop();
        charStack.pop();
        charStack.pop();
        //charStack.push('g');
        charStack.print();
    } catch ( const StackException& e) { e.print();}

}
