//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const long long P = 31;
//const long long M = 1000000009;
//
//struct Node {
//    char* username;
//    int score;
//    Node* next;
//
//    Node(const char* name, int s) {
//        username = new char[strlen(name) + 1];
//        strcpy(username, name);
//        score = s;
//        next = NULL;
//    }
//};
//
//class HashTable {
//private:
//    Node** table;
//    int tableSize;
//
//    long long hashFunction(const char* s) {
//        long long hash = 0;
//        long long power = 1;
//
//        for (int i = 0; s[i] != '\0'; i++) {
//            hash = (hash + (s[i] * power) % M) % M;
//            power = (power * P) % M;
//        }
//        return hash % tableSize;
//    }
//
//public:
//    HashTable(int size) {
//        tableSize = size;
//        table = new Node * [tableSize];
//        for (int i = 0; i < tableSize; i++) {
//            table[i] = NULL;
//        }
//    }
//
//    void insertPlayer(const char* name, int score) {
//        long long idx = hashFunction(name);
//        Node* curr = table[idx];
//
//        while (curr != NULL) {
//            if (strcmp(curr->username, name) == 0) {
//                curr->score = score;
//                return;
//            }
//            curr = curr->next;
//        }
//
//        Node* newNode = new Node(name, score);
//        newNode->next = table[idx];
//        table[idx] = newNode;
//    }
//
//    int searchPlayer(const char* name) {
//        long long idx = hashFunction(name);
//        Node* curr = table[idx];
//
//        while (curr != NULL) {
//            if (strcmp(curr->username, name) == 0) {
//                return curr->score;
//            }
//            curr = curr->next;
//        }
//        return -1;
//    }
//
//    void deletePlayer(const char* name) {
//        long long idx = hashFunction(name);
//        Node* curr = table[idx];
//        Node* prev = NULL;
//
//        while (curr != NULL) {
//            if (strcmp(curr->username, name) == 0) {
//                if (prev == NULL) table[idx] = curr->next;
//                else prev->next = curr->next;
//
//                delete[] curr->username;
//                delete curr;
//                return;
//            }
//            prev = curr;
//            curr = curr->next;
//        }
//    }
//};
//
//int main() {
//
//    cout<<"Enter the size of the Table:\t";
//    int tableSize;
//    cin >> tableSize;
//
//    HashTable ht(tableSize);
//
//    for (int i = 0; i < tableSize; i++) {
//        char name[100];
//        int score;
//        cout<<"Enter name:\t";
//        cin >> name;
//        cout << "Enter score:\t";
//        cin >> score;
//        ht.insertPlayer(name, score);
//        cout<<endl;
//    }
//
//    for (int i = 0; i < tableSize; i++) {
//
//        cout<<"Enter player Name to be found:\t";
//        char query[100];
//        cin >> query;
//
//        int score = ht.searchPlayer(query);
//        if (score == -1)
//            cout << query << " -> Not Found\n";
//        else
//            cout << query << " -> " << score << "\n";
//    }
//
//    return 0;
//}
