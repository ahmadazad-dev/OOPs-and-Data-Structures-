//// STACK
//// Last In First Out FIFO
//
//#include<iostream>
//using namespace std;
//
//class SLinkedList {
//	class Node {
//	public:
//		int data;
//		Node* next;
//		Node();
//		Node(const int);
//		void print();
//	};
//	Node* top;
//	int size;
//public:
//	SLinkedList();
//	~SLinkedList();
//	void pop();
//	void push(const int);
//	int get_size() const;
//	bool isEmpty();
//	bool isFull();
//	int peek();
//	void printList();
//};
//
//SLinkedList::Node::Node() {
//	next = nullptr;
//	data = 0;
//}
//SLinkedList::Node::Node(const int data) {
//	next = nullptr;
//	this->data = data;
//}
//void SLinkedList::Node::print() {
//	cout << data << " ";
//}
//
//
//SLinkedList::SLinkedList() {
//	top = nullptr;
//	size = 0;
//}
//SLinkedList::~SLinkedList(){
//
//}
//void SLinkedList::push(const int data) {
//	Node* newNode = new Node(data);
//	if (!top) { top = newNode; size++; return; }
//	if (isEmpty()) { newNode->next = top; top = newNode; size++; return; }
//	if (isFull()) { cout << "\nStack is full\n"; return; }
//	return;
//}
//void SLinkedList::pop() {
//	if (top) {
//		Node* temp = top->next;
//		delete top;
//		top = temp;
//		size--;
//	}
//	else { cout << "\nStack is Empty\n"; }
//}
//int SLinkedList::get_size() const {
//	return size;
//}
//bool SLinkedList::isEmpty() {
//	return size < 5;
//}
//bool SLinkedList::isFull() {
//	return size == 5;
//}
//int SLinkedList::peek() {
//	return top->data;
//}
//void SLinkedList::printList() {
//	Node* current = top;
//	while (current) {
//		current->print();
//		current = current->next;
//	}
//}
//
//int main() {
//	SLinkedList stack;
//	stack.push(4);
//	stack.push(6);
//	stack.push(8);
//	stack.push(11);
//	stack.push(2);
//	stack.printList();
//	stack.push(10);
//	stack.printList();
//	stack.pop();cout << endl;
//	stack.printList();
//	stack.pop();cout << endl;
//	stack.printList();
//}