//#include<iostream>
//using namespace std;
//
//template<class T>
//class SLinkedList {
//
//public:
//    class Node {
//
//        Node* next;
//        T data;
//
//    public:
//        Node();
//        Node(T data);
//        Node* get_next();
//        T get_data();
//        void set_next(Node*);
//        void print_node();
//    };
//
//    Node* head;
//
//    SLinkedList();
//    ~SLinkedList();
//    SLinkedList(const SLinkedList&);
//    void push_front(const T&);
//    void push_back(const T&);
//    void print_list();
//    void clear();
//    SLinkedList& operator=(const SLinkedList&);
//    SLinkedList<SLinkedList<T>> divide_list(const int);
//};
//
//template<class T>
//SLinkedList<T>::Node::Node() {
//    next = nullptr;
//}
//template<class T>
//SLinkedList<T>::Node::Node(T data) {
//    this->data = data;
//    next = nullptr;
//}
//template<class T>
//typename SLinkedList<T>::Node* SLinkedList<T>::Node::get_next() {
//    return next;
//}
//template<class T>
//void SLinkedList<T>::Node::set_next(Node* next) {
//    this->next = next;
//}
//template<class T>
//void SLinkedList<T>::Node::print_node() {
//    cout << " " << data << " ";
//}
//template<class T>
//T SLinkedList<T>::Node::get_data() {
//    return data;
//}
//
//template<class T>
//SLinkedList<T>::SLinkedList() {
//    head = nullptr;
//}
//template<class T>
//SLinkedList<T>::~SLinkedList() {
//    if (head) {
//        Node* current = head;
//        while (current) {
//            Node* nextNode = current->get_next();
//            delete current;
//            current = nextNode;
//        }
//        head = nullptr;
//    }
//}
//template<class T>
//SLinkedList<T>::SLinkedList(const SLinkedList& rhs) {
//    head = nullptr;
//    Node* current = rhs.head;
//    while (current) {
//        this->push_back(current->get_data());
//        current = current->get_next();
//    }
//}
//template<class T>
//void SLinkedList<T>::clear() {
//    Node* current = head;
//    while (current) {
//        Node* nextNode = current->get_next();
//        delete current;
//        current = nextNode;
//    }
//    head = nullptr;
//}
//template<class T>
//SLinkedList<T>& SLinkedList<T>:: operator=(const SLinkedList& rhs) {
//    if (this == &rhs) { return *this; }
//    this->clear();
//    Node* current = rhs.head;
//    while (current) {
//        this->push_back(current->get_data());
//        current = current->get_next();
//    }
//    return *this;
//}
//template<class T>
//void SLinkedList<T>::push_front(const T& data) {
//    Node* newNode = new Node(data);
//    if (head) {
//        newNode->set_next(head);
//        head = newNode;
//    }
//    else {
//        head = newNode; 
//    }
//}
//template<class T>
//void SLinkedList<T>::push_back(const T& data) {
//    Node* newNode = new Node(data);
//    if (head) {
//        Node* current = head;
//        while (current->get_next()) {
//            current = current->get_next();
//        }
//        current->set_next(newNode);
//    }
//    else {
//        head = newNode;
//    }
//}
//template<class T>
//void SLinkedList<T>::print_list() {
//    if (head) {
//        Node* current = head;
//        while (current) {
//            current->print_node();
//            current = current->get_next();
//            if (current) {
//                cout << " -> ";
//            }
//        }
//    }
//    else {
//        return;
//    }
//}
//template<class T>
//SLinkedList<SLinkedList<T>> SLinkedList<T>::divide_list(const int k) {
//    SLinkedList<SLinkedList<T>> result;
//    Node* current = head;
//    int counter;
//    while (current) {
//        counter = 0;
//        SLinkedList<T> sub_list;
//        while (counter < k && current) {
//            sub_list.push_back(current->get_data());
//            current = current->get_next();
//            counter++;
//        }
//        result.push_back(sub_list);
//    }
//    return result;
//}
//template<>
//void SLinkedList<SLinkedList<int>>::print_list() {
//    Node* current = head;
//    while (current) {
//        cout << "[";
//        current->get_data().print_list();
//        cout << "] ";
//        current = current->get_next();
//        if (current) {
//            cout << " -> ";
//        }
//    }
//}
//
//int main() {
//    SLinkedList<int> myList;
//
//    int size;
//
//    do {
//        cout << "Enter size of list (>=0): ";
//        cin >> size;
//        if (size < 0) {
//            cout << "Invalid input. Size must be non-negative.\n";
//        }
//    } while (size < 0);
//
//    if (size == 0) {
//        cout << "Empty list.\n";
//        return 0;
//    }
//
//    cout << "Enter " << size << " elements:\n";
//    for (int i = 0; i < size; i++) {
//        int value;
//        cout << "Element " << (i + 1) << ": ";
//        cin >> value;
//        myList.push_back(value);
//    }
//
//    cout << "\nOriginal List: ";
//    myList.print_list();
//
//    int k;
//    do {
//        cout << "\nEnter value of k (1 - " << size << "): ";
//        cin >> k;
//        if (k <= 0 || k > size) {
//            cout << "Invalid input. k must be between 1 and " << size << ".\n";
//        }
//    } while (k <= 0 || k > size);
//
//    SLinkedList<SLinkedList<int>> divided_list = myList.divide_list(k);
//
//    cout << "\nDivided List:\n";
//    divided_list.print_list();
//}