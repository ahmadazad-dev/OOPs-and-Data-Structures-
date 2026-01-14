//#include<iostream>
//#include<string>
//using namespace std;
//
//
//struct Node {
//	int data;
//	Node* next;
//};
//
//int gcd(int a, int b) {
//	if (b == 0) return a;
//	return gcd(b, a % b);
//}
//void findsubsets(string str, int index, string current) {
//	if (index == str.length()) {
//		if (current != "") cout << current << endl;
//		return;
//	}
//	findsubsets(str, index + 1, current + str[index]);
//	findsubsets(str, index + 1, current);
//}
//int sum(int num) {
//	if (num == 0) return 0;
//	return num % 10 + sum(num / 10);
//}
//int fibonacci(int num) {
//	if (num == 0) return 0;
//	if (num == 1) return 1;
//	return fibonacci(num - 1) + fibonacci(num - 2);
//}
//int factorial(int num) {
//	if (num == 1)return 1;
//	return num * factorial(num - 1);
//}
//bool search(Node* head, int key) {
//	if (head == nullptr)return false;
//	if (head->data == key)return true;
//	return search(head->next, key);
//}
//
//int main() {
//	cout << "<============= FACTORIAL ==============>\n\n";
//	cout << " 5! : " << factorial(5) << endl;
//	cout << " 7! : " << factorial(7) << endl;
//	cout << " 3! : " << factorial(3) << endl;
//
//	cout << "\n<============= FIBONACCI ==============>\n\n";
//	cout << "Fibonacci 6th term: " << fibonacci(6) << endl;
//
//	cout << "\n<============= SUM ==============>\n\n";
//	cout << "Sum of digits 12345: " << sum(12345) << endl;
//
//	cout << "\n<============= SUBSETS ==============>\n\n";
//	cout << "Subsets:\n"; findsubsets("abcd", 0, "") ;
//
//	cout << "\n<============= SUBSETS ==============>\n\n";
//	cout << "GCD of " << 48 << " and " << 18 << " is: " << gcd(48, 18) << endl;
//
//
//	cout << "\n<============= LINKED LIST ==============>\n\n";
//	Node* head = new Node{ 10, nullptr };
//	head->next = new Node{ 20, nullptr };
//	head->next->next = new Node{ 30, nullptr };
//	int key = 20;
//	if (search(head, key)) cout << key << " found in linked list.\n\n";
//	else cout << key << " not found.\n\n";
//}