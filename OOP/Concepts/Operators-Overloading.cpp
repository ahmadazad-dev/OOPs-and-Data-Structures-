//#include<iostream>
//using namespace std;
//
//class MyString
//{
//	//You can add your code here
//private:
//	char* str;
//	int lenght;	//not including the null char here
//	//Add GetStringFromBuffer as static private member (helper)
//	//Add Concatenate, CompareString as static private member (helper)
//	//You can add your class members here
//public:
//	//-------------DO_NOT_CHANGE REGION starts below---------------------
//	//Do not change the prototypes given below
//	const MyString operator+(const MyString&) ;
//	const MyString& operator=(const MyString&) ;
//	bool operator<(MyString&);
//		//Comparison on the basis of ascii values
//	//-------------End of DO_NOT_CHANGE REGION---------------------
//	bool operator!();
//	MyString();
//	MyString(const char*);
//	MyString(char*, int);
//	friend ostream& operator<<(ostream& out, const MyString& obj);
//	friend istream& operator>>(istream& in, MyString& obj);
//	char& operator[](int);
//	MyString operator()(int, int);
//	//Add your class members here	
//};
//
//void getStringFromBuffer(char* str,const char* temp) {
//	while (*temp) {
//		*str = *temp;
//		str++;temp++;
//	}
//	*str = '\0';
//}
//void StringConcatinate(char* str, char* arr2) {
//	while (*str){
//		str++;   //Moving the arr1 to the end of the string so that when the new string comes it begins from the end
//	}
//	*str = ' ';
//	str++;
//	while (*arr2){
//		*str = *arr2;//copying the elements of str2 in str1
//		str++;arr2++;
//	}
//	*str = '\0';//adding null terminator
//}
//MyString::MyString() {
//	str = new char[1];
//	str[0] = '\0';
//	lenght = 0;
//}
//MyString::MyString(char* str, int len) {
//	this->str = new char[strlen(str) + 1];
//	getStringFromBuffer(this->str, str);
//	this->lenght = len;
//}
//MyString::MyString(const char* arr) {
//	this->str = new char[strlen(arr) + 1];
//	getStringFromBuffer(this->str, arr);
//}
////--------------------------Add your code here----------------------
//const MyString MyString::operator+(const MyString& rhs) {
//	char* str1 = new char[strlen(str) + strlen(rhs.str) + 2];
//	getStringFromBuffer(str1, str);
//	StringConcatinate(str1, rhs.str);
//	return MyString(str1, (lenght + rhs.lenght));
//}
//const MyString& MyString::operator=(const MyString& rhs)  {
//	if (this != &rhs) {
//		lenght = rhs.lenght;
//		getStringFromBuffer(str, rhs.str);
//		return MyString(str, lenght);
//	}
//	return *this;
//}
//bool MyString::operator!() {
//	if (str || lenght) return true;
//	else false;
//}
//bool MyString::operator<(MyString& rhs) {
//	bool flag = true;
//	while (*str && *rhs.str) {
//		if (*str == *rhs.str) flag = true;
//		else flag = false;
//		if (!flag) return false;
//		str++;
//		rhs.str++;
//	}
//	return true;
//}
//char& MyString::operator[](int index) {
//	return str[index];
//}
//MyString MyString::operator()(int start, int end) {
//	if (start < 0 || end <= start || end < 0) {
//		return MyString();
//	}
//	int length = end - start + 1;
//	char* newstring = new char[length];
//	for (int i = 0;i < start;i++) {
//		str++;
//	}
//	getStringFromBuffer(newstring, str);
//	MyString result(newstring);
//	return result;
//}
//ostream& operator<<(ostream& out, const MyString& obj) {
//	out << obj.str ;
//	if (obj.lenght) {
//		out << obj.lenght;
//	}
//	return out;
//}
//istream& operator>>(istream& in, MyString& obj) {
//	in >> obj.str;
//	return in;
//}
//
////-------------DO_NOT_CHANGE REGION starts below---------------------
//void main()
//{
//	MyString str1, str2, str3, str4;	//Default constructor will make a string of lenght 0 but having null character (only) i.e. empty string
//
//	if (!str1){
//		cout << "String 1 is Empty.\n";
//		cout << "Str 1 = " << str1 << endl << endl << endl;
//	}
//
//	cout << "Enter String 1:\t";
//	cin >> str1;
//
//
//	cout << "Enter String 2:\t";
//	cin >> str2;
//
//
//	cout << "\n\n\nUser Entered:\n";
//	cout << "String 1 = " << str1 << endl;
//	cout << "String 2 = " << str2 << endl << endl << endl;
//
//	//What is following code testing? // Its testing the assignment operator
//	cout << "Before str1 = str1; str1 = " << str1 << endl;
//	str1 = str1;
//	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;
//
//
//	cout << "Before str4 = str3 = str1+str2\n";
//	cout << "str1 = " << str1 << endl;
//	cout << "str2 = " << str2 << endl;
//	cout << "str3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//
//	str4 = str3 = str1 + str2;
//
//
//	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
//	cout << "str1 = " << str1 << endl;
//	cout << "str2 = " << str2 << endl;
//	cout << "str3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//
//	cout << "\n\n\nEnter String 3:\t";
//	cin >> str3;
//
//	cout << "\n\n\nEnter String 4:\t";
//	cin >> str4;
//
//
//	cout << "\n\n\nstr3 = " << str3 << endl;
//	cout << "str4 = " << str4 << endl;
//
//	if (str3 < str4) //Zohaib < Zoraiz <Zuhaib
//		cout << "String 3 is Less than String 4.\n";
//	else
//		cout << "String 3 is NOT Less than String 4.\n";
//
//	MyString str5 = str1 + str2;
//	cout << "\n\n\nStr5:\t" << str5 << endl;
//	cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7).
//	str5[7] = '$';
//
//	cout << "\n\nStr5:\t" << str5 << endl;
//
//	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10 starting from index 5 . Function Call str5.operator()(5,10)
//
//}
////-------------End of DO_NOT_CHANGE REGION---------------------
//
