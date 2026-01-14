////Recursion
//
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//void printAscending(int num) {
//	if (num == 0) { cout << num << " "; return; }
//	printAscending(num - 1);
//	cout << num << " ";
//}
//void printDecending(int num) {
//	if (num == 0) { cout << num << " "; return; }
//	cout << num << " ";
//	printDecending(num - 1);
//}
//int sum(int n) {
//	if (n == 0) return n;
//	return n + sum(n - 1);
//}
//int factorial(int n) {
//	if (n == 1) return n;
//	return n * factorial(n - 1);
//}
//int power(int a, int b) {
//	if (b == 1) return a;
//	return a * power(a, b - 1);
//}
//int digitsInNumber(int num) {
//	if (num < 0) num = -num;
//	if (num < 10) return 1;
//	return 1 + digitsInNumber(num / 10);
//}
//void reverseString(string& str, int start, int end) {
//	if (start >= end) return;
//	swap(str[start], str[end]);
//	reverseString(str, start + 1, end - 1);
//}
//bool palindrome(string str, int start, int end) {
//	if (start >= end) return true;
//	if (str[start] != str[end]) return false;
//	return palindrome(str, start + 1, end - 1);
//}
//int maximum(int array[], int start, int end) {
//	if (start == end) return array[start];
//	int mid = start + (end - start) / 2;
//	int leftMax = maximum(array, start, mid);
//	int rightMax = maximum(array, mid + 1, end);
//	return max(leftMax, rightMax);
//}
//void print_subsequence(string input, string output) {
//	if (!input.length()) {
//		cout<<" \""<<output<<"\" ";
//		return;
//	}
//	char ch = input[0];
//	string rest = input.substr(1);
//	print_subsequence(rest, output+ch);
//	print_subsequence(rest, output);
//}
//int countways(int n) {
//	if(n==0) return 1;
//	if(n==1) return 1;
//	return countways(n-1) + countways(n-2);
//}
//
//
//int main() {
//	cout << "Question 1\n";printAscending(8);
//
//	cout << "\n\nQuestion 2\n";printDecending(8);
//
//	cout << "\n\nQuestion 3\n";
//	cout << "Sum:\t" << sum(6);
//
//	cout << "\n\nQuestion 4\n";
//	cout << "6!:\t" << factorial(6);
//
//	cout << "\n\nQuestion 5\n";
//	cout << "2^7:\t" << power(2, 7);
//
//	cout << "\n\nQuestion 6\n";
//	cout << "Digits in 764729:\t" << digitsInNumber(764729);
//
//	cout << "\n\nQuestion 7\n";
//	string mystr = "LaiiaL";
//	cout << "Reversed AHMAD:\t";reverseString(mystr, 0, mystr.length() - 1);cout << mystr;
//
//	cout << "\n\nQuestion 8\n";
//	cout << "Is Palindrome:\t" << palindrome(mystr, 0, mystr.length() - 1);
//
//	cout << "\n\nQuestion 9\n";
//	int array[] = { 1,2,43,5,67,54,1,22,43,93,7,8 };int largest = array[0];
//	cout << "Largest:\t" << maximum(array, 0, size(array) - 1);
//
//	cout << "\n\nQuestion 10\n";
//	string str = "abb";
//	cout << "Sustrings:\t["; print_subsequence(str,""); cout<<"]";
//
//	cout << "\n\nQuestion 11\n";
//	cout << "No of ways to reach 5 is:\t"<<countways(5);
//}