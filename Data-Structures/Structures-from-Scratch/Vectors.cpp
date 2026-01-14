//#include<iostream>
//#include<vector>
//using namespace std;
////<----------------------------------------------------------------------------------------->
//
////Class LinkedList
//template<class L>
//class LinkedList {
//	struct  Node {
//		L data;
//		Node* next;
//		Node(L const);
//		void Print();
//	};
//	Node* head;
//	Node* tail;
//public:
//	LinkedList();
//	~LinkedList();
//	void insertAtHead(L const);
//	void insertAtTail(L const);
//	void update(int, L const);
//	void printList();
//
//};
////<----------------------------------------------------------------------------------------->
//
////Class DynamicArray
//template<class T>
//class DynamicArray {
//	int capacity;
//	int size;
//	T* array;
//public:
//	DynamicArray();
//	DynamicArray(const int);
//	~DynamicArray();
//	DynamicArray& operator=(const DynamicArray&);
//	DynamicArray(const DynamicArray&);
//	bool isInitialised();
//	void InitializeArray(int);
//	void push_back(const int);
//	int getCapacity();
//	int getSize();
//	void pop_back();
//	void remove_duplicates();
//	void rotate_right(int);
//	vector<vector<int>> find_subarrays_with_sum(int);
//	void print();
//};
////<----------------------------------------------------------------------------------------->
//
////Functions of class Dynamic Array
//template<class T>//Default Constructor
//DynamicArray<T>::DynamicArray() {
//	capacity = 0;
//	size = 0;
//	array = nullptr;
//}
//template<class T>//Overloaded Constructor
//DynamicArray<T>::DynamicArray(const int capacity) {
//	this->capacity = capacity;
//	size = 0;
//	array = new T[capacity];
//}
//template<class T>//Destructor
//DynamicArray<T>::~DynamicArray() {
//	if (array) {
//		delete[] array;
//		array = nullptr;
//	}
//}
//template<class T>//Copy Constructor
//DynamicArray<T>::DynamicArray(const DynamicArray& rhs) {
//	capacity = rhs.size;
//	size = rhs.numberOfValuessize;
//	array = new T[size];
//	for (int i = 0; i < size; i++) {
//		array[i] = rhs.array[i];
//	}
//}
//template<class T>//Assignment Operator
//DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& rhs) {
//	if (this != &rhs) {
//		delete[] array;
//		size = rhs.size;
//		size = rhs.size;
//		array = new T[size];
//		for (int i = 0; i < size; i++) {
//			array[i] = rhs.array[i];
//		}
//	}
//	return *this;
//}
//template<class T>//Returns Capacity of Array
//int DynamicArray<T>::getCapacity() {
//	return capacity;
//}
//template<class T>//Returns Size of Array
//int DynamicArray<T>::getSize() {
//	return size;
//}
//template<class T>//Returns true if Array is initialised
//bool DynamicArray<T>::isInitialised() {
//	if (capacity) return 1;
//	else return 0;
//}
//template<class T>//Initialises the Array
//void DynamicArray<T>::InitializeArray(int capacity) {
//	this->capacity = capacity;
//	array = new T[capacity];
//}
//template<class T>//Adds a value at the end of Array
//void DynamicArray<T>::push_back(const int value) {
//	if (!this->isInitialised()) {
//		this->InitializeArray(1);
//	}
//	if (size == capacity) {//If the array is already filled
//		T* temp = new T[2 * capacity];
//		for (int i = 0; i <= capacity; i++) {
//			if (i == size) {
//				temp[i] = value;
//			}
//			else {
//				temp[i] = array[i];
//			}
//		}
//		delete[] array;
//		array = temp;
//		capacity = 2 * capacity;
//	}
//	else {
//		array[size] = value;
//	}
//	size++;
//}
//template<class T>//Removes an element from the end of the Array
//void DynamicArray<T>::pop_back() {
//	size--;
//}
//template<class T>//Removes all duplicate elements from the Array
//void DynamicArray<T>::remove_duplicates() {
//	int tempSize = size;
//	for (int i = 0; i < tempSize; i++) {
//		int value = array[i];
//		for (int j = i + 1; j < tempSize; j++) {
//			if (array[j] == value) {
//				for (int k = j; k < tempSize; k++) {
//					array[k] = array[k + 1];
//				}
//				tempSize--;
//			}
//		}
//	}
//	size = tempSize;
//}
//template<class T>//Rotates element to the right
//void DynamicArray<T>::rotate_right(int k) {
//	for (int j = 0; j < k; j++) {
//		int lastValue = array[size - 1];
//		for (int i = size - 1; i >= 0; i--) {
//			if (i == 0) {
//				array[i] = lastValue;
//			}
//			else {
//				array[i] = array[i - 1];
//			}
//		}
//	}
//}
//template<class T>//prints the Array
//void DynamicArray<T>::print() {
//	cout << "\n";
//	for (int i = 0; i < size; i++) {
//		cout << " " << array[i] << " ";
//	}
//}
//template<class T>//Finds SubArrays with the sum equal to target
//vector<vector<int>> DynamicArray<T>::find_subarrays_with_sum(int target) {
//	vector<vector<int>> subArrays;
//	for (int i = 0;i < size;i++) {
//		int sum = 0;
//		vector<int> subArray;
//		for (int j = i;j < size;j++) {
//			sum += array[j];
//			subArray.push_back(array[j]);
//			if (sum == target){
//				subArrays.push_back(subArray);
//			}
//		}
//	}
//	return subArrays;
//}
////<----------------------------------------------------------------------------------------->
//
////Functions of LinkedList
//template<class L>//Constructor
//LinkedList<L>::Node::Node(L const value) {
//	data = value;
//	next = nullptr;
//}
//template<class L>//Prints a Node
//void LinkedList<L>::Node::Print() {
//	cout << data << " ";
//	if (this->next) {
//		this->next->Print();
//	}
//}
//template<class L>//Constructor
//LinkedList<L>::LinkedList() {
//	head = nullptr;
//	tail = nullptr;
//}
//template<class L>//Destructor
//LinkedList<L>::~LinkedList() {
//	Node* current = head;
//	while (current) {
//		Node* nextNode = current->next;
//		delete current;
//		current = nextNode;
//	}
//	head = tail = nullptr;
//}
//template<class L>//Inserts element in the place of head
//void LinkedList<L>::insertAtHead(L const element) {
//	Node* newNode = new Node(element);
//	if (head == nullptr) {
//		head = tail = newNode;
//	}
//	else {
//		newNode->next = head;
//		head = newNode;
//	}
//}
//template<class L>//Inserts element at the end of list
//void LinkedList<L>::insertAtTail(L const element) {
//	Node* newNode = new Node(element);
//	if (tail == nullptr) {
//		head = tail = newNode;
//	}
//	else {
//		tail->next = newNode;
//		tail = newNode;
//	}
//}
//template<class L>//Updates any element
//void LinkedList<L>::update(int position, L const value) {
//	if (position <= 0) {
//		throw invalid_argument("The position cannot be lesser than or equal to 0");
//	}
//	Node* current = head;
//	int count = 0;
//	while (current && position > count++) {
//		current = current->next;
//	}
//	if (current) {
//		current->data = value;
//	}
//	else {
//		throw invalid_argument("Position is out of range");
//	}
//}
//template<class L>//Prints the list
//void LinkedList<L>::printList() {
//	if (head) {
//		head->Print();
//	}
//}
////<----------------------------------------------------------------------------------------->
//
////Functions for Vector
//void swapElements(vector<int>& array) {
//	cout << array.size();
//	for (int i = 0, j = array.size() - 1; i < (array.size())/2 && j >= (array.size())/2; i++, j--) {
//		int value = array[i];
//		array[i] = array[j];
//		array[j] = value;
//	}
//}
//vector<int> maximunmProduct(vector<int> array) {
//	vector<int> result;
//	int maxProduct = INT_MIN;
//	for (int i = 0;i < array.size();i++) {
//		int product = 1;
//		for (int j = i ;j < array.size();j++) {
//			product *= array[j];
//			if (product > maxProduct) {
//				maxProduct = product;
//				result.clear();
//				for (int k = i;k <= j;k++) {
//					result.push_back(array[k]);
//				}
//			}
//		}
//	}
//	return result;
//}
////<----------------------------------------------------------------------------------------->
//
//
//int main() {
//	//Question-1
//	{
//		DynamicArray<int> arr;
//		arr.push_back(10);
//		arr.push_back(20);
//		arr.push_back(30);
//		arr.push_back(20);
//		arr.push_back(10);
//		arr.push_back(50);
//		arr.push_back(70);
//		arr.push_back(80);
//		arr.push_back(90);
//		arr.push_back(100);
//		cout << "Initial array: ";
//		arr.print();
//		arr.pop_back();
//		cout << "\n\nArray after Poping Back: ";
//		arr.print();
//		arr.push_back(100);
//
//		cout << "\nArray size: " << arr.getSize() << endl;
//		cout << "Array capacity: " << arr.getCapacity() << endl;
//
//		cout << "\nArray size: " << arr.getSize() << endl;
//		cout << "Array capacity: " << arr.getCapacity() << endl;
//
//		arr.rotate_right(4);
//		cout << "\nArray after Rotation:";
//		arr.print();
//
//		arr.remove_duplicates();
//		cout << "\nArray after removing duplicates:";
//		arr.print();
//
//		cout << "\nSub Arrays are: [ ";
//		vector<vector<int>> subArrays = arr.find_subarrays_with_sum(30);
//		for (int i = 0;i < subArrays.size();i++) {
//			for (int j = 0;j < subArrays[i].size();j++) {
//				cout << subArrays[i][j] << " ";
//			}
//		}
//	}
//
//	//Question-2
//	{
//		vector<int> arr;
//		arr.push_back(2);
//		arr.push_back(3);
//		arr.push_back(-2);
//		arr.push_back(4);
//		arr.push_back(6);
//		swapElements(arr);
//		cout << "\nSwapped Array is: [ ";
//		int product = 1;
//		for (int value : arr) {
//			cout << value << " ";
//			product *= value;
//		}cout << "]";
//		cout << "\nProduct: " << product;
//
//		cout << "\nArray Of Maximum Product: [ ";
//		vector<int> subArray = maximunmProduct(arr); product = 1;
//		for (int value : subArray) {
//			product *= value;
//			cout << value << " ";
//		}cout << "] the Product is: "<<product;
//	}
//
//	//Question-3
//	{
//		LinkedList<int> list;
//		list.insertAtHead(10);
//		list.insertAtHead(20);
//		list.insertAtTail(30);
//		list.insertAtTail(40);
//		cout << "\n\n\nOriginal List: ";
//		list.printList();
//		list.update(2, 99);
//		cout << "\nAfter Update: ";
//		list.printList();
//	}
//}
//
////<----------------------------------------------------------------------------------------->
////		Name: Ahmad Azad
////		Roll Number: 24L-2523