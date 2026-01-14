//#include<iostream>
//#include<string>
//using namespace std;
//
//class HashTable;
//
//class HashItem {
//	friend class HashTable;
//private:
//	int key; // index where your value will be stored
//	string value; //actual value to be stored in HashTable
//	int status; // 0: Empty, 1: Deleted, 2: Occupied
//public:
//	HashItem():key(0), value(""), status(0) {};
//};
//class HashTable {
//private:
//	HashItem* hashArray;
//	int capacity;
//	int currentElements;
//	int getNextCandidateIndex(int key, int i);
//	void doubleCapacity();
//public:
//	HashTable();
//	HashTable(int const capacity);
//	void insert(int const key, string const value);
//	bool deleteKey(int const key);
//	string get(int const key);
//	~HashTable();
//};
//
//HashTable::HashTable() {
//	capacity = 10;
//	currentElements = 0;
//	hashArray = new HashItem[capacity];
//}
//HashTable::HashTable(int const capacity) {
//	if (capacity<=0){
//		cout<<"Error: Capacity must be at least 1\n";
//		return;
//	}
//	else {
//		this->capacity = capacity;
//	}
//	currentElements = 0;
//	hashArray = new HashItem[capacity];
//}
//int HashTable::getNextCandidateIndex(int key, int i) {
//	return (key*i)%capacity;
//}
//void HashTable::doubleCapacity() {
//	capacity *= 2;
//	HashItem* oldHashArray = hashArray;
//	hashArray = new HashItem[capacity];
//	currentElements = 0;
//	for (int i = 0; i < capacity / 2;i++) {
//		if (oldHashArray[i].status == 2) {
//			insert(oldHashArray[i].key,oldHashArray[i].value);
//		}
//	}
//	delete[] oldHashArray;
//}
//void HashTable::insert(int const key, string const value) {
//	if (currentElements >= 0.75 * capacity) {
//		doubleCapacity();
//	}
//	int index = key % capacity;
//	int i=0;
//	while (hashArray[index].status == 2) {
//		i++;
//		index = getNextCandidateIndex(key, i);
//	}
//	hashArray[index].key = key;
//	hashArray[index].value = value;
//	hashArray[index].status = 2;
//	currentElements++;
//}
//bool HashTable::deleteKey(int const key) {
//	int index = key%capacity;
//	int i=0;
//	while (hashArray[index].status != 0) {
//		if (hashArray[index].status == 2 && hashArray[index].key == key) {
//			hashArray[index].status = 1;
//			currentElements--;
//			return true;
//		}
//		i++;
//		index = getNextCandidateIndex(key, i);
//		if (index >= capacity) {
//			break;
//		}
//	}
//	return false;
//}
//string HashTable::get(int const key) {
//	int index = key % capacity;
//	int i = 0;
//	while (hashArray[index].status != 0) {
//		if (hashArray[index].status == 2 && hashArray[index].key == key) {
//			return hashArray[index].value;
//		}
//		i++;
//		index = getNextCandidateIndex(key, i);
//		if (index >= capacity) {
//			break;
//		}
//	}
//	return "";
//}
//
//HashTable::~HashTable() {
//	delete[] hashArray;
//}
//
//
//int main() {
//	HashTable newTabel(5);
//	newTabel.insert(101, "Alice in BorderLand");
//	newTabel.insert(201, "Stranger Things");
//	newTabel.insert(301, "Money Heist");
//	newTabel.insert(401, "Squid Game");
//	newTabel.insert(501, "Stranger Things S5");
//
//	string name = newTabel.get(201);
//	if (name.length() != 0) {
//		cout << "Value at key 201: " << name << endl;
//	}
//	else {
//		cout << "not found" << endl;
//	}
//
//	bool deleted = newTabel.deleteKey(301);
//	if (deleted) {
//		cout << "Key 301 deleted successfully." << endl;
//	}
//	else {
//		cout << "Key 301 not found!" << endl;
//	}
//
//	name = newTabel.get(301);
//	if (name.length() != 0) {
//		cout << "Value at key 301: " << name << endl;
//	}
//	else {
//		cout << "not found" << endl;
//	}
//
//}