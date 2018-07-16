#include <iostream>
#include <cstring>

using namespace std;

class Complex {
private:
	float r, i;
public:
	Complex(float r = 0.F, float i = 0.F) :r(r), i(i) {

	}
	bool operator == (const Complex& complex1) const {
		return(r == complex1.r && i == complex1.i);
	}
};

class String {
public:
	String() {}
	String(const char *s) {
		str = s;
	}
	friend ostream& operator << (ostream& os, const String& str);
	bool operator == (String s) const {
		return(str == s.str);
	}
protected:
	const char* str;
};
ostream& operator << (ostream& os, const String& str) {
	os << str.str;
	return os;
}

class MyString : public String {
public:
	MyString() {}
	MyString(const char *s) : String(s) {}
};

template <class T, int sz>
class List {
private:
	T * pElems;
	int currentSize;
	const int maxSize;
public:
	List() : maxSize(sz) {
		pElems = new T[sz];
		currentSize = 0;
	}
	template <class T2, int sz2>
	List(List<T2, sz2>& list) : currentSize(list.getCurrentSize()),maxSize(sz2) {
		pElems = new T[sz2];
		for (int i = 0; i < currentSize; i++) {
			pElems[i] = list[i];
		}
	}
	T& operator [] (int i) { return pElems[i]; }
	int getCurrentSize() const { return currentSize; }
	int getMaxSize() const { return maxSize; }
	void operator = (const List& list) {
		delete[] pElems;
		currentSize = list.currentSize;
		copyFrom(list);
	}
	void copyFrom(const List<T, sz>& list) {
		pElems = new T[sz];
		for (int i = 0; i < currentSize; i++) {
			pElems[i] = list.pElems[i];
		}
	}

	int add(T object) {
		pElems[currentSize] = object;
		currentSize++;

		return currentSize;
	}
	void remove(int index) {
		if (index >= 0 && index <= currentSize) {
			for (int i = index; i < currentSize; i++) {
				pElems[index] = pElems[index + 1];
			}
			currentSize--;
		}
	}
	void remove(T object) {
		if (find(object)==true) {
			int index;
			for (index = 0; index < currentSize; index++) {
				if (pElems[index] == object) {
					break;
				}
			}
			for (int i = index; i < currentSize; i++) {
				pElems[index] = pElems[index + 1];
			}
			currentSize--;
		}
	}
	bool find(T object) {
		for (int i = 0; i < currentSize; i++) {
			if (pElems[i] == object) {
				return true;
			}
		}
		return false;
	}
};


int main() {
	List<Complex, 100> cList;
	List<MyString, 200> sList;

	int i1 = cList.add(Complex(0, 0));
	cList.add(Complex(1, 1));
	cout<< cList.getCurrentSize() <<endl;
	MyString s("abc");
	int i2 = sList.add("abc");
	sList.add("def");
	cout << cList.find(Complex(1, 0)) << endl;
	cout << sList.find("def") << endl;
	cList.remove(i1);
	cout << cList.getCurrentSize() << endl;

	sList.remove("abc");
	MyString s3("ddd");
	String s4;
	s4 = s3;
	List<String, 200> s2List(sList);
	cout << s2List.getCurrentSize() << endl;
	List<String, 200> s3List;
	s3List.add("123");
	s3List = s2List;
	s3List.remove("def");
}
