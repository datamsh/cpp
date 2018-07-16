# include <iostream>

using namespace std;

class Matrix {
	int ** values;
	int row, column;

public:
	Matrix(const int row = 1, const int column = 1)
		: row(row), column(column) {

		values = new int*[row];

		for (int i = 0; i < row; i++) {
			*(values + i) = new int[column];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				values[i][j] = 0;
			}
		}
	}

	Matrix(const Matrix& matrix)
		:row(matrix.row), column(matrix.column) {
	
		values = new int*[row];
		for (int i = 0; i < row; i++) {
			*(values + i) = new int[column];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				values[i][j] = matrix.values[i][j];
			}
		}
	}
	~Matrix() {
		for (int i = 0; i < row; i++) {
			delete[] * (values + i);
		}
		delete[] values;
	}

	Matrix operator + (const Matrix& matrix) const{
		Matrix tempMatrix(row, column);	

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				tempMatrix.values[i][j] = values[i][j] + matrix.values[i][j];
			}
		}
		return tempMatrix;
	}

	Matrix& operator = (const Matrix& matrix) {
		for (int i = 0; i < row; i++) {
			delete[] * (values + i);
		}

		delete[] values;
		values = new int*[row];

		for (int i = 0; i < row; i++) {
			*(values + i) = new int[column];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				values[i][j] = values[i][j] + matrix.values[i][j];
			}
		}
		return *this;
	}

	Matrix operator * (const int number) const {
		Matrix tempMatrix(row, column);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				tempMatrix.values[i][j] = values[i][j] * number;
			}
		}
		return tempMatrix;
	}
	friend void operator >> (istream& is, Matrix& matrix1);
	friend ostream& operator << (ostream& os, const Matrix& matrix1);
};

void operator >> (istream& is, Matrix& matrix1) {
	for (int i = 0; i < matrix1.row; i++) {
		for (int j = 0; j < matrix1.column; j++) {
			cin >> matrix1.values[i][j];
		}
	}
}

ostream& operator << (ostream& os, const Matrix& matrix1) {
	for (int i = 0; i < matrix1.row; i++) {
		for (int j = 0; j < matrix1.column; j++) {
			os << matrix1.values[i][j];
			if (j != matrix1.column - 1)
				os << "\t";
		}
		os << endl;
	}
	return os;
}

int main() {
	Matrix m1(2, 2), m2(2, 2);
	cin >> m1;
	cin >> m2;

	Matrix m3 = m1 + m2;
	Matrix m4 = m3 * 10;

	cout << m3 << endl;
	cout << m4 << endl;
}
