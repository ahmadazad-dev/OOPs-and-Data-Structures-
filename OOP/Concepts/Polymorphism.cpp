//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class Student {
//private:
//	char name[50];
//	char rollNo[8];
//	float cgpa;
//
//public:
//	Student();
//	Student(const char*, const char*, const float);
//	void Print();
//	bool operator!();
//	float getCGPA() { return cgpa; };
//	char* getName() { return name; };
//	Student& operator=(const Student& );
//	bool operator==(const Student&);
//};
//class Society {
//private:
//	char name[50];
//	Student* president;
//	Student* members[5];
//	static int currentMembersCount;
//	
//public:
//	Society();
//	Society(const char*);
//	void PrintInfo();
//	void AppointPresident(Student&);
//	void AddMember(Student*);
//	void SuspendMember(char*);
//};
//int Society::currentMembersCount = 0;
//
//void Student::Print() {
//	cout  << name <<" ("<<rollNo<<")"<< endl;
//}
//void StringCopy(char* arr, const char* temp) {
//	while (*temp) {
//		*arr = *temp;
//		arr++;
//		temp++;
//	}
//	*arr = '\0';
//}
//void Society::PrintInfo() {
//	cout << "Society: " << name << endl;
//	if (!president) {
//		cout << "President: not available" << endl;
//	}
//	else {
//		cout << "President :";
//		president->Print();
//	}
//	for (int i = 0;i < 5;i++) {
//		if (!members[i]) {
//			cout << "Member[" << i + 1 << "] : not available" << endl;
//		}
//		else {
//			members[i]->Print();
//		}
//	}
//}
//void Society::AppointPresident(Student& stu) {
//	if (!president) {
//		if (stu.getCGPA() > 3.00) {
//			president = new Student();
//			*president = stu;
//			cout << stu.getName() << " has been appointed as President" << endl;
//		}
//		else {
//			cout << stu.getName() << " cannot be appointed as President as CGPA criteria not met." << endl;
//		}
//	}
//	else {
//		cout << stu.getName() << " cannot be appointed as President as the seat is not empty." << endl;
//	}
//}
//void Society::AddMember(Student* stu) {
//	
//	bool checkforsamemember = true;
//	bool checkforpresident = true;
//
//	for (int i = 0;i < currentMembersCount;i++) {
//		if (stu == members[i]) {
//			checkforsamemember = false;
//		}
//	}
//	if (*stu == *president) {
//		checkforpresident = false;
//	}
//	
//	if (checkforsamemember && checkforpresident) {
//		if (!members[currentMembersCount]) {
//			members[currentMembersCount] = stu;
//			cout << stu->getName() << "has been added to members list successfully." << endl;
//			currentMembersCount++;
//		}
//		else {
//			cout << "Members are full" << endl;
//		}
//	}
//	if (!checkforsamemember){
//		cout <<stu->getName()<< " is already present" << endl;
//	}
//	if (!checkforpresident) {
//		cout << "President cannot be added in Members list." << endl;
//	}
//}
//void Society::SuspendMember(char* member) {
//
//}
//
//Student::Student() {//default constructor
//	cgpa = 0;
//	memset(name, 0, 50);
//	memset(rollNo, 0, 8);
//}
//Student::Student(const char* rollNo, const char* name, const float cgpa) {
//	StringCopy(this->name, name);
//	StringCopy(this->rollNo, rollNo);
//	this->cgpa = cgpa;
//}
//Student& Student::operator=(const Student& rhs) {
//	if (this != &rhs) {
//		StringCopy(this->name, rhs.name);
//		StringCopy(this->rollNo, rhs.rollNo);
//		this->cgpa = rhs.cgpa;
//	}
//	return *this;
//}
//Society::Society() {
//	memset(name, 0, 50);
//	president = nullptr;
//	for (int i = 0;i < 5;i++) members[i] = nullptr;
//}
//Society::Society(const char* name){
//	StringCopy(this->name, name);
//}
//bool Student::operator!() {
//	if (name && rollNo && cgpa) {
//		return true;
//	}
//	else {
//		false;
//	}
//}
//bool Student::operator==(const Student& rhs) {
//	return (*name == *rhs.name && *rollNo == *rhs.rollNo && cgpa == rhs.cgpa);
//}
//
//
//
//int main() {
//	Student s1("12L1111", "Hashim Amla", 3.99);
//	Student s2("13L1121", "Virat Kohli", 3.45);
//	Student s3("13L1126", "Quinton de Kock", 2.98);
//	Student s4("14L1361", "Joe Root", 2.99);
//	Student s5("14L1124", "Martin Guptil", 3.09);
//	Student s6("15L1314", "Rohit Sharma", 3.19);
//
//	Society sports("Sports");
//	sports.PrintInfo();
//
//	cout << "\n\n";
//	sports.AppointPresident(s3);
//	sports.AppointPresident(s1);
//	sports.AppointPresident(s2);
//
//	cout << endl << endl << endl;
//	Student s7("15L1334", "Robert Elen", 2.19);
//	sports.AddMember(&s3);
//	sports.AddMember(&s2);
//	sports.AddMember(&s3);
//	sports.AddMember(&s1);
//	sports.AddMember(&s4);
//	sports.AddMember(&s5);
//	sports.AddMember(&s6);
//	sports.AddMember(&s7);
//	sports.PrintInfo();
//
//
//}