//// QUEUE
//// First In First Out FIFO
//
//#include<iostream>
//using namespace std;
//
//class QLinkedList {
//	class Node {
//	public:
//		int data;
//		Node* next;
//		Node();
//		Node(const int);
//		void print();
//	};
//	Node* rear;
//	Node* front;
//	int size;
//public:
//	QLinkedList();
//	~QLinkedList();
//	void dequeue();
//	void enqueue(const int);
//	int get_size() const;
//	bool isEmpty();
//	bool isFull();
//	int peak();
//	void printList();
//};
//
//QLinkedList::Node::Node() {
//	next = nullptr;
//	data = 0;
//}
//QLinkedList::Node::Node(const int data) {
//	next = nullptr;
//	this->data = data;
//}
//void QLinkedList::Node::print() {
//	cout << data << " ";
//}
//
//
//QLinkedList::QLinkedList() {
//	rear = nullptr;
//	front = nullptr;
//	size = 0;
//}
//QLinkedList::~QLinkedList(){
//
//}
//void QLinkedList::enqueue(const int data) {
//	Node* newNode = new Node(data);
//	if (!front) { front = rear = newNode; size++; return; }
//	if (isEmpty()) { rear->next = newNode; rear = newNode; size++; return; }
//	if (isFull()) { cout << "\nQueue is full\n"; size++; return; }
//
//	return;
//}
//void QLinkedList::dequeue() {
//	if (front) {
//		Node* temp = front->next;
//		delete front;
//		front = temp;
//		size--;
//	}
//	else { cout << "\nQueue is Empty\n"; }
//}
//int QLinkedList::get_size() const {
//	return size;
//}
//bool QLinkedList::isEmpty() {
//	return size < 5;
//}
//bool QLinkedList::isFull() {
//	return size == 5;
//}
//int QLinkedList::peak() {
//	return front->data;
//}
//void QLinkedList::printList() {
//	Node* current = front;
//	while (current) {
//		current->print();
//		current = current->next;
//	}
//}
//
//int main() {
//	QLinkedList queue;
//	queue.enqueue(4);
//	queue.enqueue(6);
//	queue.enqueue(8);
//	queue.enqueue(11);
//	queue.enqueue(2);
//	queue.printList();
//	queue.enqueue(10);
//	queue.printList();
//}