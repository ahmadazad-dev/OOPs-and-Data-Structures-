////Doubly Circular Linked List
//
//#include<iostream>
//using namespace std;
//
//template<class T>//Doubly Circular Linked List
//class DCLinkedList {
//	//Class Node
//	class Node {
//		T data;
//		Node* forwards;
//		Node* backwards;
//	public:
//		Node();
//		Node(T);
//		Node* getForwards();
//		Node* getBackwards();
//		T getData();
//		void setForwards(Node*);
//		void setBackwards(Node*);
//		void printNode();
//	};
//
//	Node* head;
//
//public:
//	DCLinkedList();
//	~DCLinkedList();
//	void insert(T data);
//	void deleteNode(T data);
//	void printList();
//};
//
//
//template<class T>//Constructor Default
//DCLinkedList<T>::Node::Node() {
//	data = 0;
//	forwards = nullptr;
//	backwards = nullptr;
//}
//template<class T>//Parameterized Constructor
//DCLinkedList<T>::Node::Node(T data) {
//	this->data = data;
//	forwards = nullptr;
//	backwards = nullptr;
//}
//template<class T>//get next node
//typename DCLinkedList<T>::Node* DCLinkedList<T>::Node::getForwards() {
//	return forwards;
//}
//template<class T>//get previous node
//typename DCLinkedList<T>::Node* DCLinkedList<T>::Node::getBackwards() {
//	return backwards;
//}
//template<class T>//set next node
//void DCLinkedList<T>::Node::setForwards(Node* forwards) {
//	this->forwards = forwards;
//}
//template<class T>//set previous node
//void DCLinkedList<T>::Node::setBackwards(Node* backwards) {
//	this->backwards = backwards;
//}
//template<class T>//print node
//void DCLinkedList<T>::Node::printNode() {
//	cout << "\nData: " << data;
//}
//template<class T>//get data of node
//T DCLinkedList<T>::Node::getData() {
//	return data;
//}
//
//
//template<class T>//Constructor
//DCLinkedList<T>::DCLinkedList() {
//	head = nullptr;
//}
//template<class T>//Destructor
//DCLinkedList<T>::~DCLinkedList() {
//	if (!head) return;
//	Node* current = head->getForwards();
//	while (current != head) {
//		Node* nextNode = current->getForwards();
//		delete current;
//		current = nextNode;
//		if (current == nullptr) break;
//	}
//	delete head;
//	head = nullptr;
//}
//template<class T>//Insert Randomly
//void DCLinkedList<T>::insert(T data) {
//	Node* newNode = new Node(data);
//	if (head) {
//		if (newNode->getData() >= head->getData()) {
//			head->getBackwards()->setForwards(newNode);
//			newNode->setBackwards(head->getBackwards());
//			head->setBackwards(newNode);
//			newNode->setForwards(head);
//			head = newNode;
//		}
//		else if (newNode->getData() < head->getData() && newNode->getData() > head->getBackwards()->getData()) {
//			Node* current = head;
//			Node* beforeCurrent = current->getBackwards();
//			while (newNode->getData() < current->getData()) {
//				beforeCurrent = current;
//				current = current->getForwards();
//			}
//			beforeCurrent->setForwards(newNode);
//			current->setBackwards(newNode);
//			newNode->setForwards(current);
//			newNode->setBackwards(beforeCurrent);
//		}
//		else {
//			head->getBackwards()->setForwards(newNode);
//			newNode->setBackwards(head->getBackwards());
//			newNode->setForwards(head);
//			head->setBackwards(newNode);
//		}
//	}
//	else {
//		head = newNode;
//		head->setBackwards(head);
//		head->setForwards(head);
//	}
//}
//template<class T>//Delete with data
//void DCLinkedList<T>::deleteNode(T data) {
//	if (head) {
//		if (data == head->getData()) {
//			if (head->getForwards() == head && head->getBackwards() == head) {
//				delete head;
//				head = nullptr;
//			}
//			else {
//				head->getBackwards()->setForwards(head->getForwards());
//				head->getForwards()->setBackwards(head->getBackwards());
//				Node* temp = head;
//				head = head->getForwards();
//				delete temp;
//				temp = nullptr;
//			}
//
//		}
//		else if (data < head->getData() && data> head->getBackwards()->getData()) {
//			Node* current = head->getForwards();
//			while (data != current->getData() && current!=head) {
//				current = current->getForwards();
//			}
//			if (current != head) {
//				current->getBackwards()->setForwards(current->getForwards());
//				current->getForwards()->setBackwards(current->getBackwards());
//				delete current;
//				current = nullptr;
//			}
//			else {
//				cout << "Value not found\n";
//			}
//		}
//		else {
//			if (data == head->getBackwards()->getData()) {
//				Node* tail = head->getBackwards();   
//				tail->getBackwards()->setForwards(head);
//				head->setBackwards(tail->getBackwards());
//				delete tail;
//			}
//			else {
//				cout << "Value not found\n";
//			}
//		}
//	}
//	else {
//		cout << "Linked List does not exist";
//	}
//}
//template<class T>//Print list
//void DCLinkedList<T>::printList() {
//	Node* current = head;
//	do{
//		current->printNode();
//		current = current->getForwards();
//	} while (current != head);
//}
//
//int main() {
//	DCLinkedList<int> list;
//
//	cout << "Inserting values into Doubly Circular Linked List (descending order)...\n";
//
//	list.insert(30);
//	list.insert(10);
//	list.insert(50);
//	list.insert(20);
//	list.insert(40);
//	list.printList();
//
//	// Now delete different cases
//	cout << "\nDeleting head (50)...";
//	list.deleteNode(50);
//
//	cout << "\nDeleting middle (30)...";
//	list.deleteNode(30);
//
//	cout << "\nDeleting tail (10)...";
//	list.deleteNode(10);
//
//	cout << "\nTrying to delete non-existent value (100)...";
//	list.deleteNode(100);
//
//	cout << "\nDeleting last nodes (40, 20)...";
//	list.deleteNode(40);
//	list.deleteNode(20);
//
//	cout << "\nDeleting from empty list...";
//	list.deleteNode(5);
//
//	cout << "\n\nAll test cases done.\n";
//	return 0;
//}