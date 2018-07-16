#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
string name ;
float gpa ;
public:
    Student(const string& name, const float gpa = 0){
        this->name = name;
        this->gpa = gpa;
    }
    void setName(const string& name){
        this->name = name;
    }

    void setGPA(const float gpa){
        this->gpa = gpa;
    }

    string getName() const{
        return name;
    }
    float getGPA() const{
        return gpa;
    }
    void print() const{
        cout << "Name: " << getName() << " GPA: " << getGPA() << endl ;
    }
} ;

class School {
private:
string schoolName ;
vector<Student> students ;
public:
    School(const string& name){
        this->schoolName=name;
    }

    void addStudent(const string& name, const float gpa = 0){
        Student student(name, gpa);
        students.push_back(student);
    }

    void print(){
        cout << "Student Count: " << students.size() << endl;
        for( vector<Student>::iterator it = students.begin(); it != students.end(); it++){
            cout<< "\t" ;
            it->print();
        }
    }

    bool isbigger(const Student& student1, const Student& student2){
        return (student1.getGPA() > student2.getGPA());
    }

    void swap(Student& student1, Student& student2){
        const Student temp = student2;
        student2 = student1;
        student1 = temp;
    }

    void sort(){
        for(unsigned int i = 0; i < students.size()-1 ; i++){
            for( unsigned int j = i + 1; j < students.size() ; j++){
                if (students[i].getGPA() < students[j].getGPA()){
                    swap(students[i], students[j]);
                }
            }
        }
    }

    Student& findStudentWithName(const string& name){
        for( vector<Student>::iterator it = students.begin(); it != students.end(); it++){
            Student& student = *it;
            string newName = student.getName();
            if ( newName == name) {
                return student;
            }

        }
    }
} ;


int main() {
School pnu("PNU") ;
pnu.addStudent("Kim", 2.7F) ;
pnu.addStudent("Hong", 3.5F) ;
pnu.addStudent("Lee") ;
pnu.addStudent("Joo", 1.5F) ;
pnu.print() ;
pnu.sort() ; // descending
pnu.print() ;
School knu("KNU") ;
knu.addStudent("Seo", 2.5F) ;
knu.addStudent("Lee", 3.8F) ;
knu.print() ;
Student& lee = pnu.findStudentWithName("Lee") ;
lee.setGPA(3.3F) ;
lee.setName("Yoon") ;
pnu.print() ;
knu.addStudent("Hong", 4.3F) ;
Student& hong = knu.findStudentWithName("Hong") ;
hong.setGPA(3.3F) ;
hong.setName("Joon") ;
knu.print() ;
}

