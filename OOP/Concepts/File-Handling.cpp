//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//char** readStudentsList(const char* filename, int& totalStudents) {
//    ifstream file(filename);
//    if (!file) {
//        cerr << "Error opening file!" << endl;
//        return nullptr;
//    }
//
//    file >> totalStudents; //To Read the total number of students0
//    file.ignore(); 
//
//    char** students = new char* [totalStudents];
//
//    for (int i = 0; i < totalStudents; i++) {
//        string fullName;
//        getline(file, fullName); 
//        students[i] = new char[fullName.length() + 1];
//        for (size_t j = 0; j < fullName.length(); j++) {
//            students[i][j] = fullName[j]; 
//        }
//        students[i][fullName.length()] = '\0'; 
//    }
//
//    file.close();
//    return students;
//}
//void PrintAllNames(char** studentsList, int& size) {
//    for (int i = 0; i < size; i++) {
//        cout << studentsList[i] << endl;
//    }
//}
//
//int main() {
//    int totalStudents;
//   
//    char** students = readStudentsList("StudentsList.txt", totalStudents);
//
//    if (students) {
//        PrintAllNames(students, totalStudents);
//        }
//    if (students) {
//        for (int i = 0; i < totalStudents; i++) {
//            cout << students[i] << endl;
//            delete[] students[i]; 
//        }
//        delete[] students; 
//    }
//
//    return 0;
//}
