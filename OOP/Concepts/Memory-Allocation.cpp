//#include<iostream>
//#include<iomanip>
//using namespace std;
//inline int** AllocateMemory(int& rows, int& columns) {
//	cout << "Enter the number of Rows: ";
//	cin >> rows;
//	cout << "Enter the number of columns: ";
//	cin >> columns;
//	int** arr = new int* [rows];
//	for (int i = 0;i < rows;i++) {
//		*(arr + i) = new int[columns];
//	}
//	return arr;
//}
//inline void InputMatrix(int** arr,const int& rows,const int& columns) {
//	for (int i = 0;i < rows;i++) {
//		for (int j = 0;j < columns;j++) {
//			cout << "Enter the Element for [" << i << "][" << j << "]: ";
//			cin >> *(*(arr + i) + j);
//		}
//	}
//}
//inline void DisplayMatrix(int** arr,const int&rows,const int& columns) {
//	cout << "The Matrix: " << endl;
//	for (int i = 0;i < rows;i++) {
//		for (int j = 0;j < columns;j++) {
//			cout << *(*(arr + i) + j)<<setw(2)<<" ";
//		}
//		cout << endl;
//	}
//}
//void DeAllocateMemory(int** arr,int& rows) {
//	for (int i = 0;i < rows; i++) {
//		delete[] *(arr + i);
//	}
//}
//int* MaxOfColumns(int** arr,const int& rows,const int& columns) {
//	int* max = new int[columns];
//	int largest;
//	for (int i = 0;i < columns;i++) {
//	    largest = *(*(arr + 0) + i); 
//		for (int j = 0;j < rows;j++) {
//			if ((*(*(arr + j) + i)) > largest) {
//				largest = *(*(arr + j) + i);
//			}
//		}
//		*(max + i) = largest;
//	}
//	return max;
//}
//bool IsMatrixUpperTriangular(int** arr, const int& rows, const int& columns) {
//	bool flag = true;
//	for (int i = 0;i < rows; i++) {
//		for (int j = 0;j < columns;j++) {
//			if (i > j) {
//				if (*(*(arr + i) + j) != 0) {
//					flag = false;
//				}
//
//			}
//		}
//	}
//	if (flag == true) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//int main() {
//	int rows = 0, columns = 0;
//	int** arr;
//	arr = AllocateMemory(rows, columns);
//	InputMatrix(arr, rows, columns);
//	DisplayMatrix(arr, rows, columns);
//	cout << "\nArray of Max Column ELements: ";
//	*arr = MaxOfColumns(arr, rows, columns);
//	for (int i = 0;i < columns;i++){
//		cout << *(*(arr)+i) << " ";
//}
//	cout << endl;
//	bool flag = IsMatrixUpperTriangular(arr, rows, columns);
//	if (flag == false) {
//		cout << "The Matrix is not Upper Triangular" << endl;
//	}
//	else {
//		cout << "The Matrix is Upper Triangular" << endl;
//	}
//	DeAllocateMemory(arr, rows);
//}