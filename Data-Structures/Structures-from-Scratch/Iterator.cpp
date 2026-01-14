//#include<iostream>
//using namespace std;
//
//template<class T>
//class DLinkedList {
//	class Node {
//		T data;
//		Node* forwards;
//		Node* backwards;
//	public:
//		Node();
//		Node(const T);
//		T get_data();
//		void set_data(T);
//		Node* get_forwards();
//		void set_forwards(Node*);
//		Node* get_backwards();
//		void set_backwards(Node*);
//		void print_node();
//	};
//	class Iterator {
//		Node* current;
//	public:
//		Iterator(Node*);
//		T& operator*();
//		Iterator& operator++();
//		Iterator& operator++(int);
//		Iterator& operator--();
//		Iterator& operator--(int);
//		bool operator==(const Iterator&);
//		bool operator!=(const Iterator&);
//	};
//	Node* head;
//	Node* tail;
//	int size;
//public:
//
//	typedef Iterator iterator;
//
//
//	DLinkedList();
//	~DLinkedList();
//	DLinkedList(const T&);
//	void insert_head(const T&);
//	void insert_tail(const T&);
//	void insert(const T&, int);
//	void remove_head();
//	void remove_tail();
//	void remove(int);
//	int get_size() const;
//	void print_list();
//	Iterator begin() const;
//	Iterator end() const;
//	Iterator rbegin() const;
//	Iterator rend() const;
//};
//
//
//
//template<class T>
//DLinkedList<T>::Node::Node() {
//	data = 0;
//	forwards = nullptr;
//	backwards = nullptr;
//}
//template<class T>
//T DLinkedList<T>::Node::get_data() {
//	return data;
//}
//template<class T>
//DLinkedList<T>::Node::Node(const T data) {
//	this->data = data;
//	forwards = nullptr;
//	backwards = nullptr;
//}
//template<class T>
//void DLinkedList<T>::Node::set_data(T data) {
//	this->data = data;
//}
//template<class T>
//typename DLinkedList<T>::Node* DLinkedList<T>::Node::get_backwards() {
//	return backwards;
//}
//template<class T>
//typename DLinkedList<T>::Node* DLinkedList<T>::Node::get_forwards() {
//	return forwards;
//}
//template<class T>
//void DLinkedList<T>::Node::set_backwards(Node* backwards) {
//	this->backwards = backwards;
//}
//template<class T>
//void DLinkedList<T>::Node::set_forwards(Node* forwards) {
//	this->forwards = forwards;
//}
//template<class T>
//void DLinkedList<T>::Node::print_node() {
//	cout << " " << data << " ";
//}
//template<class T>
//bool DLinkedList<T>::Iterator::operator==(const Iterator& rhs) {
//	return current == rhs.current;
//}
//template<class T>
//bool DLinkedList<T>::Iterator::operator!=(const Iterator& rhs) {
//	return current != rhs.current;
//}
//
//template<class T>
//DLinkedList<T>::Iterator::Iterator(Node* pointer) : current(pointer) {}
//template<class T>
//typename T& DLinkedList<T>::Iterator::operator*() {
//	return current->get_data();
//}
//template<class T>
//typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() {
//	if (current) {
//		return current->get_forwards();
//	}return *this;
//}
//template<class T>
//typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++(int) {
//	Iterator temp = *this;
//	if (current) {
//		current = current->get_forwards();
//	}return temp;
//}
//template<class T>
//typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator--() {
//	if (current) {
//		return current->get_backwards();
//	}return *this;
//}
//template<class T>
//typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator--(int) {
//	Iterator temp = *this;
//	if (current) {
//		current = current->get_backwards();
//	}return temp;
//}
//
//
//
//template<class T>
//DLinkedList<T>::DLinkedList() {
//	head = nullptr;
//	tail = nullptr;
//	size = 0;
//}
//template<class T>
//DLinkedList<T>::~DLinkedList() {
//	if (!head) return;
//	Node* current = head;
//	while (current) {
//		Node* temp = current->get_forwards();
//		delete current;
//		current = temp;
//	}
//	head = nullptr;
//	tail = nullptr;
//}
//template<class T>
//DLinkedList<T>::DLinkedList(const T& rhs) {
//	Node* current = rhs.head;
//	while (current) {
//		this->insert_tail(current->get_data());
//		current = current->get_forwards();
//	}
//}
//template<class T>
//void DLinkedList<T>::insert_head(const T& value) {
//	Node* new_node = new Node(value);
//	if (head) {
//		new_node->set_forwards(head);
//		head->set_backwards(new_node);
//		head = new_node;
//	}
//	else {
//		head = new_node;
//		tail = new_node;
//	}
//	size++;
//}
//template<class T>
//void DLinkedList<T>::insert_tail(const T& value) {
//	Node* new_node = new Node(value);
//	if (head) {
//		new_node->set_backwards(tail);
//		tail->set_forwards(new_node);
//		tail = new_node;
//	}
//	else {
//		head = new_node;
//		tail = new_node;
//	}
//	size++;
//}
//template<class T>
//void DLinkedList<T>::insert(const T& value, int index) {
//	Node* new_node = new Node(value);
//	if (head) {
//		if (index > size) {
//			cout << "\nindex is out of range\n";
//			return;
//		}
//		int counter = 0;
//		Node* current = head;
//		while (current && counter < index - 1) {
//			current = current->get_forwards();
//			counter++;
//		}
//		if (current == head) { insert_head(value); }
//		else if (current == tail) { insert_tail(value); }
//		else {
//			current->get_forwards()->set_backwards(new_node);
//			new_node->set_backwards(current);
//			new_node->set_forwards(current->get_forwards());
//			current->set_forwards(new_node);
//			size++;
//		}
//	}
//	else {
//		head = new_node;
//		tail = new_node;
//		size++;
//	}
//}
//template<class T>
//void DLinkedList<T>::remove_head() {
//	if (head) {
//		Node* current = head;
//		if (head->get_forwards()) {
//			head = head->get_forwards();
//			delete current;
//		}
//		else {
//			cout << "\n List Deleted\n";
//			delete current;
//		}
//		size--;
//	}
//	else {
//		cout << "\nNo List exists\n";
//	}
//}
//template<class T>
//void DLinkedList<T>::remove_tail() {
//	if (head) {
//		Node* current = tail;
//		if (tail->get_backwards()) {
//			tail = tail->get_backwards();
//			tail->set_forwards(nullptr);
//			delete current;
//		}
//		else {
//			cout << "\n List Deleted\n";
//			delete current;
//		}
//		size--;
//	}
//	else {
//		cout << "\nNo List exists\n";
//	}
//}
//template<class T>
//void DLinkedList<T>::remove(int index) {
//	if (head) {
//		if (index > size) {
//			cout << "\nindex is out of range\n";
//			return;
//		}
//		int counter = 0;
//		Node* current = head;
//		while (current && counter < index) {
//			current = current->get_forwards();
//			counter++;
//		}
//		if (current == head) { remove_head(); }
//		else if (current == tail) { remove_tail(); }
//		else {
//			current->get_backwards()->set_forwards(current->get_forwards());
//			current->get_forwards()->set_backwards(current->get_backwards());
//
//		}
//		size--;
//	}
//	else {
//		cout << "\nNo List exists\n";
//	}
//}
//template<class T>
//int DLinkedList<T>::get_size() const {
//	return size;
//}
//template<class T>
//void DLinkedList<T>::print_list() {
//	if (head) {
//		Node* current = head;
//		while (current) {
//			current->print_node();
//			current = current->get_forwards();
//		}
//	}
//}
//template<class T>
//typename DLinkedList<T>::Iterator DLinkedList<T>::begin() const {
//	return Iterator(head);
//}
//template<class T>
//typename DLinkedList<T>::Iterator DLinkedList<T>::end() const {
//	return Iterator(nullptr);
//}
//template<class T>
//typename DLinkedList<T>::Iterator DLinkedList<T>::rbegin() const {
//	return Iterator(tail);
//}
//template<class T>
//typename DLinkedList<T>::Iterator DLinkedList<T>::rend() const {
//	return Iterator(nullptr);
//}
//
//template<class T>
//void print(DLinkedList<T>& myList) {
//	for (auto it = myList.begin(); it != myList.end(); ++it) {
//		cout << " " << *it << " ";
//	}
//	cout << endl;
//}
//template<class T>
//T max(DLinkedList<T>& myList) {
//	if (myList.begin() == myList.end()) {
//		cout << "\nList is Empty\n";
//	}
//	auto maxIt = myList.begin();
//	for (auto it = myList.begin(); it != myList.end(); ++it) {
//		if (*it > *maxIt) {
//			maxIt = it;
//		}
//	}
//	return *maxIt;
//}
//template<class T>
//void bubble_sort(DLinkedList<T>& myList) {
//
//}
//template<typename T>
//DLinkedList<DLinkedList<T>> calculateTranspose(DLinkedList<DLinkedList<T>>& matrix) {
//
//}
//
//
//
//int main() {
//
//	{
//		DLinkedList<int> myList;
//		myList.insert_head(5);
//		myList.insert_head(6);
//		myList.insert_head(7);
//		myList.insert_head(8);
//		myList.insert_head(9);
//		myList.insert_tail(4);
//		myList.insert_tail(1);
//		myList.insert_tail(12);
//		myList.insert(66, 3);
//		cout << "Original List:\n";
//		myList.print_list();
//
//		myList.remove_head();
//		myList.remove_tail();
//		myList.remove(3);
//		cout << "\nAfter Removal List:\n";
//		myList.print_list();
//
//		cout << "\nMaximun Element: " << max(myList);
//	}
//
//}