//////Single Linked List
//#include<iostream>
//using namespace std;
//
//class Node {
//	int data;
//	Node* next; //Address of Next Node
//public:
//	Node();
//	~Node();
//	Node(const int);
//	Node* getNext();
//	void setNext(Node*);
//	void printNode();
//	void printAllNodes();
//	int getData();
//	Node& operator=(const Node&);
//};
//class LinkedList {
//	int numberOfNodes;
//public:
//	Node* head; //Address of Head Node
//	LinkedList();
//	void insertAtEnd(const int);
//	void printLinkedList();
//	void middleNode();
//	void reverseList();
//	void removeNode(Node*);
//	void insertRandomly(Node*);
//	Node* mergeNodes(Node*, Node*);
//	Node* getMiddle(Node*);
//	Node* mergeSort(Node*);
//	void sortList();
//};
//
////Functions of class Node
//Node::Node() {//Default constructor
//	data = 0;
//	next = nullptr;
//}
//Node::Node(const int data) {//Overloaded Constructor
//	this->data = data;
//	this->next = nullptr;
//}
//Node::~Node() {
//	next = nullptr;
//}
//int Node::getData() { // Getter
//	return data;
//}
//void Node::printAllNodes() {//Print all nodes of a List
//	cout << this->data <<" ";
//	if (this->next) {
//		this->next->printAllNodes();
//	}
//}
//void Node::printNode() {//Print single Node
//	cout << this->data;
//}
//void Node::setNext(Node* next) {//Sets the address of the next Node
//	this->next = next;
//}
//Node* Node::getNext() {//Returns the address of the next Node
//	return this->next;
//}
//Node& Node::operator=(const Node& rhs) {
//	data = rhs.data;
//	next = rhs.next;
//	return *this;
//}
//
////Functions of class LinkedList
//LinkedList::LinkedList() {//Default Constructor
//	numberOfNodes = 0;
//	head = nullptr;
//}
//void LinkedList::insertAtEnd(const int data) {//Insert new Node at the end of the List
//	Node* newNode = new Node(data);
//	if (head == nullptr) {
//		head = newNode;
//	}
//	else {
//		Node* temp = head;
//		while (temp->getNext() != nullptr) {
//			temp = temp->getNext();
//		}
//		temp->setNext(newNode);
//	}
//	numberOfNodes++;
//}
//void LinkedList::printLinkedList() {//Print whole Linked List
//	if (head)
//		head->printAllNodes();
//}
//void LinkedList::middleNode() {//Finding the middle node in a Linked List
//	Node* temp = head;
//	int currentNodeIndex = 0;
//	while (temp->getNext()) {
//		if (numberOfNodes % 2 == 0) {
//			if (currentNodeIndex == numberOfNodes / 2 -1) {
//				cout << "Since there are even number of Nodes therefore there are two middle nodes \nMiddle Node is: ";
//				temp->printNode();
//			}
//		}
//		if (currentNodeIndex == numberOfNodes / 2) {
//			cout << "\nMiddle Node is: ";
//			temp->printNode();
//		}
//		temp = temp->getNext();
//		currentNodeIndex++;
//	}
//}
//void LinkedList::reverseList() {//Reversing a LinkedList
//	Node* previous = nullptr;
//	Node* current = head;
//	Node* next = nullptr;
//	while (current != nullptr) {
//		next = current->getNext();
//		current->setNext(previous);
//		previous = current;
//		current = next;
//	}
//	head = previous;
//}
//void LinkedList::insertRandomly(Node* newNode) {
//	if (head == nullptr || newNode->getData() > head->getData()) {
//		newNode->setNext(head);
//		head = newNode;
//	}
//	else if (head) {
//		Node* current = head;
//		while (current && current->getNext()->getData() > newNode->getData()) {
//			current = current->getNext();
//		}
//		newNode->setNext(current->getNext());
//		current->setNext(newNode);
//	}
//}
//void LinkedList::removeNode(Node* node) {//Removing a Node
//	if (head) {
//		Node* current = head;
//		Node* previous = nullptr;
//		while (current) {
//			if (current == node) {
//				if (current == head) {
//					head = current->getNext();
//				}
//				else {
//					previous->setNext(current->getNext());
//				}
//				delete current;
//				return;
//			}
//			previous = current;
//			current = current->getNext();
//		}
//	}
//	else {
//		throw invalid_argument("List is Empty");
//	}
//	throw invalid_argument("Node not found");
//}
//Node* LinkedList::mergeNodes(Node* left, Node* right) {
//	if (!left) return right;
//	if (!right) return left;
//	Node* result = nullptr;
//	if (left->getData() <= right->getData()) {
//		result = left;
//		result->setNext(mergeNodes(left->getNext(), right));
//	}
//	else {
//		result = right;
//		result->setNext(mergeNodes(left, right->getNext()));
//	}
//}
//Node* LinkedList::getMiddle(Node* head) {
//	if (!head) return head;
//	Node* slow = head;
//	Node* fast = head;
//	while (slow && fast->getNext()->getNext()) {
//		slow = slow->getNext();
//		fast = fast->getNext()->getNext();
//	}
//	return slow;
//}
//Node* LinkedList::mergeSort(Node* head) {
//	if (!head || !head->getNext()) return head;
//	Node* middleNode = getMiddle(head);
//	Node* nextToMiddle = middleNode->getNext();
//	middleNode->setNext(nullptr);
//	Node* left = mergeSort(head);
//	Node* right = mergeSort(head);
//	return mergeNodes(left, right);
//}
//void LinkedList::sortList() {
//	head = mergeSort(head);
//}
//
//void main() {
//	LinkedList list;
//	list.insertAtEnd(3);
//	list.insertAtEnd(8);
//	list.insertAtEnd(9);
//	list.insertAtEnd(10);
//	list.insertAtEnd(4);
//	list.insertAtEnd(5);
//	list.insertAtEnd(6);
//	list.insertAtEnd(7);
//
//	cout << "Linked List 1: ";
//	list.printLinkedList();
//
//	cout << "\nMiddle Nodes: ";
//	list.middleNode();
//
//	cout << "\nReversed List: ";
//	list.reverseList();
//	list.printLinkedList();
//
//	cout << "\nSorted List: ";
//	list.sortList();
//	list.printLinkedList();
//
//	LinkedList list2;
//	list2.insertAtEnd(12);
//	list2.insertAtEnd(24);
//	list2.insertAtEnd(61);
//	list2.insertAtEnd(81);
//	list2.insertAtEnd(81);
//	list2.insertAtEnd(81);
//	list2.insertAtEnd(81);
//
//
//
//}