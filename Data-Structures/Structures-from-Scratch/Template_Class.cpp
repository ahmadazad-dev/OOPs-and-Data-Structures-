//#include<iostream>
//using namespace std;
////<------------------------------------------------------------------------------>
//
////Class Matrix
//template<class T>
//class Matrix {
//	T** matrix;
//	int rows;
//	int columns;
//public:
//	Matrix(const int, const int);
//	Matrix(Matrix const&);
//	~Matrix();
//	void insertElement(T const&, const int, const int);
//	const Matrix operator+(const Matrix<T>&);
//	void print();
//	void transposeOfMatrix();
//
//};
////<------------------------------------------------------------------------------>
//
////Functions of Class Matrix
//template<class T>//Parameterized Constructor
//Matrix<T>::Matrix(const int row, const int column) :rows(row), columns(column) {
//	if (row <= 0 || column <= 0) {
//		throw invalid_argument("Rows and Columns must be grater than 0");
//	}
//	for (int i = 0; i < rows; i++) {
//		if (i == 0) matrix = new T * [rows];
//		for (int j = 0; j < columns; j++) {
//			if (j == 0)matrix[i] = new T[columns];
//			matrix[i][j] = 0;
//		}
//	}
//}
//template<class T>//Copy Constructor
//Matrix<T>::Matrix(Matrix const& object) {
//	rows = object.rows;
//	columns = object.columns;
//	for (int i = 0; i < rows; i++) {
//		if (i == 0) matrix = new T * [rows];
//		for (int j = 0; j < columns; j++) {
//			if (j == 0)matrix[i] = new T[columns];
//			matrix[i][j] = object.matrix[i][j];
//		}
//	}
//}
//template<class T>//Destructor
//Matrix<T>::~Matrix() {
//	for (int i = 0; i < columns; i++) delete matrix[i];
//	delete matrix;
//}
//template<class T>//Function to Insert an Element
//void Matrix<T>::insertElement(T const& element, const int rowNumber, const int columnNumber) {
//	if (rowNumber >= this->rows || columnNumber >= this->columns) {
//		throw invalid_argument("Row Number and Column Number must be within the matrix Boundaries");
//	}
//	this->matrix[rowNumber][columnNumber] = element;
//}
//template<class T>//Addition Operator
//const Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
//	if (rows == rhs.rows && columns == rhs.columns) {
//		Matrix<T> temp(*this);
//		for (int i = 0; i < rows; i++) {
//			for (int j = 0; j < columns; j++) {
//				temp.matrix[i][j] += rhs.matrix[i][j];
//			}
//		}
//		return temp;
//	}
//	else {
//		throw invalid_argument("Operation cannot be performed");
//	}
//}
//template<class T>//Function to print Matrix
//void Matrix<T>::print() {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < columns; j++) {
//			cout << matrix[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//template<class T>//Transpose of Matrix
//void Matrix<T>::transposeOfMatrix() {
//	T** temp;
//	temp = new T * [columns];
//	for (int i = 0; i < columns; i++)
//	{
//		temp[i] = new T[rows];
//	}
//	for (int i = 0; i < columns; i++)
//	{
//		for (int j = 0; j < rows; j++)
//		{
//			temp[i][j] = matrix[j][i];
//		}
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		delete matrix[i];
//	}
//	delete matrix;
//	matrix = temp;
//	rows = rows + columns;
//	columns = rows - columns;
//	rows = rows - columns;
//}
////<------------------------------------------------------------------------------>
//
////Sorting Functions
//template <typename T>//Sorting Function
//void sort(T* array, int size, int type) {
//	switch (type) {
//	case 1: //Bubble Sort Time COmpelxity: n^2
//		for (int i = 0; i < size - 1; ++i) {
//			bool swapped = false;
//			for (int j = 0; j < size - i - 1; ++j) {
//				if (array[j] > array[j + 1]) {
//					T temp = array[j];
//					array[j] = array[j + 1];
//					array[j + 1] = temp;
//					swapped = true;
//				}
//			}
//			if (!swapped) break;
//		}
//	case 2: //Insertion Sort Time Complexity: n^2
//		for (int i = 1; i < size; ++i) {
//			T key = array[i];
//			int j = i - 1;
//			while (j >= 0 && array[j] > key) {
//				array[j + 1] = array[j];
//				j--;
//			}
//			array[j + 1] = key;
//		}
//	case 3: // Selection Sort Time Complexity: n^2
//		for (int i = 0; i < size - 1; ++i) {
//			int minimumIndex = i;
//			for (int j = i + 1; j < size; ++j) {
//				if (array[j] < array[minimumIndex]) {
//					minimumIndex = j;
//				}
//			}
//			if (minimumIndex != i) {
//				T temp = array[i];
//				array[i] = array[minimumIndex];
//				array[minimumIndex] = temp;
//			}
//		}
//	default:
//		break;
//	}
//}
//template <typename T>//Print Sorted Array
//void printArray(T* array, int size) {
//	for (int i = 0; i < size; ++i) {
//		cout << array[i] << " ";
//	}
//	cout << endl;
//}
////<------------------------------------------------------------------------------>
//
//
//
//int main() {
//
//	//Question-1
//	Matrix<int> m1(2, 3);
//	m1.insertElement(1, 0, 0);
//	m1.insertElement(1, 0, 1);
//	m1.insertElement(1, 0, 2);
//	m1.insertElement(0, 1, 0);
//	m1.insertElement(0, 1, 1);
//	m1.insertElement(0, 1, 2);
//	m1.transposeOfMatrix();
//	Matrix<int> m2(2, 3);
//	m2.insertElement(-1, 0, 0);
//	m2.insertElement(-1, 0, 1);
//	m2.insertElement(-1, 0, 2);
//	m2.insertElement(10, 1, 0);
//	m2.insertElement(5, 1, 1);
//	m2.insertElement(1, 1, 2);
//	m2.transposeOfMatrix();
//	Matrix<int> m3(m2);
//	Matrix<int> m4(m1 + m3);
//	m4.transposeOfMatrix();
//
//	cout << "Matix: \n";
//	m4.print();
//
//	//Question-2
//	char charArray3[] = { 'z', 'a', 'k', 'm', 'b' };
//	sort(charArray3, sizeof(charArray3), 1);
//	cout << "\nSorted Array: ";
//	printArray(charArray3, sizeof(charArray3));
//}
//
////<----------------------------------------------------------------------------------------->
////		Name: Ahmad Azad
////		Roll Number: 24L-2523