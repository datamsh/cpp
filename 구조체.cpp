# 2018. 03. 29 학교 수업 실습
# 학생수와 각 학생의 이름, 3가지 과목의 성적을 입력 받아 각 학생의 번호, 이름, 성적, 성적 합, 평균성적을 출력하는 프로그램

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int SUBJECT_NO = 3;

struct StudentInfo {
	string name ;
	int scores[SUBJECT_NO] ;
	int sum ;
	float average ;
	static int indexOfStudent ;


	void setSum() {
		sum = scores[0] + scores[1] + scores[2] ;
	}
	void setAverage() {
		average = (scores[0] + scores[1] + scores[2]) / static_cast<float>(3) ;
	}
	void print() {
		cout << indexOfStudent << "\t" << name << "\t" << scores[0] << "\t" << scores[1] << "\t" <<
			scores[2] << "\t" << sum << "\t" << average << endl ;
		indexOfStudent++;
	}
};

int StudentInfo::indexOfStudent;

StudentInfo input() {
	StudentInfo newStudent ;

	cin >> newStudent.name ;
	cin >> newStudent.scores[0] ;
	cin >> newStudent.scores[1] ;
	cin >> newStudent.scores[2] ;

	newStudent.setSum() ;
	newStudent.setAverage() ;

	return newStudent ;
}

int main(void) {

	int numberOfStudent ;
	StudentInfo studentStruct ;
	vector<StudentInfo> inputStudent ;
	vector<StudentInfo>::iterator iteratorStudent ;

	cin >> numberOfStudent ;

	for (int i = 0; i < numberOfStudent; i++) {
		StudentInfo newStudent = input() ;
		inputStudent.push_back(newStudent) ;
	}

	for (iteratorStudent = inputStudent.begin(); iteratorStudent != inputStudent.end(); ++iteratorStudent) {
		studentStruct = *iteratorStudent ;
		studentStruct.print() ;
	}

	system("pause") ;
	return 0 ;
}
