#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum EmployeeLevel{���,�븮,����,����,����};
class Employee {
	string name;
	EmployeeLevel level;
public:
	Employee(string name, EmployeeLevel employee) 
	:name(name), level(employee){
		
	}
	string getName() const {
		return name;
	}
	int getLevel() const {
		return level;
	}
	friend ostream& operator << (ostream& os, const Employee& employee);

};

ostream& operator << (ostream& os, const Employee& employee) {
	os << employee.level << "\t" << employee.name << endl;
	return os;
}
class Manager :public Employee {
	vector<Employee*> group;
public:
	Manager(string name, EmployeeLevel employee) 
	:Employee(name,employee){
		
	}
	void addEmployee(Employee* employee) {
		group.push_back(employee);
	}
	friend ostream& operator << (ostream& os, const Manager& manager);

};

ostream& operator << (ostream& os, const Manager& manager) {
	os << manager.group.size() << "\t" << manager.getName() << endl;
	os << "List of employees managed by me" << endl;
	for (vector<Employee*>::const_iterator it = manager.group.begin();it!=manager.group.end() ;it++) {
		Employee employee = **it;
		os << employee.getLevel() << "\t" << employee.getName() << endl;
	}
	return os;
}

int main() {

	Employee e1("ȫ", ���), e2("��", �븮), e3("��", ���);
	cout << e1 << e2 << e3;

	Manager m1("Tom", ����);
	m1.addEmployee(&e1);
	m1.addEmployee(&e2);
	m1.addEmployee(&e3);
	cout << endl << "Information for Manager" << endl;
	cout << m1;
	
}