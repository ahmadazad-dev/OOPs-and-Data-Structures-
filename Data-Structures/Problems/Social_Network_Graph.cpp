//#include <iostream>
//#include <string>
//
//using namespace std;
//
//const int MAX_USERS = 100;
//
//struct Node {
//    int userId;
//    Node* next;
//
//    Node(int id) {
//        userId = id;
//        next = NULL;
//    }
//};
//
//struct User {
//    int id;
//    string name;
//    bool isActive;
//};
//
//class Graph {
//private:
//    User users[MAX_USERS];
//    Node* adjList[MAX_USERS];
//    int userCount;
//
//    int getIndexById(int id) {
//        for (int i = 0; i < MAX_USERS; i++) {
//            if (users[i].isActive && users[i].id == id) {
//                return i;
//            }
//        }
//        return -1;
//    }
//
//    void dfsHelper(int u_idx, bool visited[]) {
//        visited[u_idx] = true;
//        cout << users[u_idx].name << " (" << users[u_idx].id << ") ";
//
//        Node* temp = adjList[u_idx];
//        while (temp != NULL) {
//            int neighborIndex = getIndexById(temp->userId);
//            if (neighborIndex != -1 && !visited[neighborIndex]) {
//                dfsHelper(neighborIndex, visited);
//            }
//            temp = temp->next;
//        }
//    }
//
//    bool areFriends(int u_idx, int friendId) {
//        Node* temp = adjList[u_idx];
//        while (temp != NULL) {
//            if (temp->userId == friendId) return true;
//            temp = temp->next;
//        }
//        return false;
//    }
//
//    void deleteFromList(Node*& head, int val) {
//        if (head == NULL) return;
//
//        if (head->userId == val) {
//            Node* toDelete = head;
//            head = head->next;
//            delete toDelete;
//            return;
//        }
//
//        Node* curr = head;
//        while (curr->next != NULL) {
//            if (curr->next->userId == val) {
//                Node* toDelete = curr->next;
//                curr->next = curr->next->next;
//                delete toDelete;
//                return;
//            }
//            curr = curr->next;
//        }
//    }
//
//    void clearList(Node*& head) {
//        while (head != NULL) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//public:
//    Graph() {
//        userCount = 0;
//        for (int i = 0; i < MAX_USERS; i++) {
//            users[i].isActive = false;
//            adjList[i] = NULL;
//        }
//    }
//
//    void addUser(int id, string name) {
//        if (getIndexById(id) != -1) {
//            cout << "Error: User ID " << id << " already exists.\n";
//            return;
//        }
//
//        int freeSlot = -1;
//        for (int i = 0; i < MAX_USERS; i++) {
//            if (!users[i].isActive) {
//                freeSlot = i;
//                break;
//            }
//        }
//
//        if (freeSlot == -1) {
//            cout << "Error: Network full (Max users reached).\n";
//            return;
//        }
//
//        users[freeSlot].id = id;
//        users[freeSlot].name = name;
//        users[freeSlot].isActive = true;
//        adjList[freeSlot] = NULL;
//        userCount++;
//        cout << "User added successfully.\n";
//    }
//
//    void addFriendship(int id1, int id2) {
//        int idx1 = getIndexById(id1);
//        int idx2 = getIndexById(id2);
//
//        if (idx1 == -1 || idx2 == -1) {
//            cout << "Error: One or both users not found.\n";
//            return;
//        }
//        if (id1 == id2) {
//            cout << "Error: Cannot friend self.\n";
//            return;
//        }
//        if (areFriends(idx1, id2)) {
//            cout << "Already friends.\n";
//            return;
//        }
//
//        Node* newNode1 = new Node(id2);
//        newNode1->next = adjList[idx1];
//        adjList[idx1] = newNode1;
//
//        Node* newNode2 = new Node(id1);
//        newNode2->next = adjList[idx2];
//        adjList[idx2] = newNode2;
//
//        cout << "Friendship added.\n";
//    }
//
//    void displayFriends(int id) {
//        int idx = getIndexById(id);
//        if (idx == -1) {
//            cout << "User not found.\n";
//            return;
//        }
//
//        cout << "Friends of " << users[idx].name << ": ";
//        Node* temp = adjList[idx];
//        bool hasFriends = false;
//        while (temp != NULL) {
//            int friendIdx = getIndexById(temp->userId);
//            if (friendIdx != -1) {
//                cout << users[friendIdx].name << " (" << temp->userId << "), ";
//                hasFriends = true;
//            }
//            temp = temp->next;
//        }
//        if (!hasFriends) cout << "None";
//        cout << endl;
//    }
//
//    void dfsTraversal(int startId) {
//        int startIdx = getIndexById(startId);
//        if (startIdx == -1) {
//            cout << "User not found.\n";
//            return;
//        }
//
//        bool visited[MAX_USERS];
//        for (int i = 0; i < MAX_USERS; i++) visited[i] = false;
//
//        cout << "DFS Traversal: ";
//        dfsHelper(startIdx, visited);
//        cout << endl;
//    }
//
//    void countFriendCircles() {
//        bool visited[MAX_USERS];
//        for (int i = 0; i < MAX_USERS; i++) visited[i] = false;
//
//        int circles = 0;
//        for (int i = 0; i < MAX_USERS; i++) {
//            if (users[i].isActive && !visited[i]) {
//                circles++;
//                dfsHelper(i, visited);
//                cout << "(Circle " << circles << ")\n";
//            }
//        }
//        cout << "Total Friend Circles: " << circles << endl;
//    }
//
//    void findPopularUsers() {
//        int maxDegree = -1;
//
//        for (int i = 0; i < MAX_USERS; i++) {
//            if (users[i].isActive) {
//                int count = 0;
//                Node* temp = adjList[i];
//                while (temp != NULL) { count++; temp = temp->next; }
//                if (count > maxDegree) maxDegree = count;
//            }
//        }
//
//        if (maxDegree <= 0) {
//            cout << "No friendships yet.\n";
//            return;
//        }
//
//        cout << "Popular User(s) with " << maxDegree << " friends:\n";
//        for (int i = 0; i < MAX_USERS; i++) {
//            if (users[i].isActive) {
//                int count = 0;
//                Node* temp = adjList[i];
//                while (temp != NULL) { count++; temp = temp->next; }
//                if (count == maxDegree) {
//                    cout << "- " << users[i].name << endl;
//                }
//            }
//        }
//    }
//
//    void detectIsolatedUsers() {
//        bool found = false;
//        cout << "Isolated Users:\n";
//        for (int i = 0; i < MAX_USERS; i++) {
//            if (users[i].isActive && adjList[i] == NULL) {
//                cout << "- " << users[i].name << endl;
//                found = true;
//            }
//        }
//        if (!found) cout << "None.\n";
//    }
//
//    void showMutualFriends(int id1, int id2) {
//        int idx1 = getIndexById(id1);
//        int idx2 = getIndexById(id2);
//
//        if (idx1 == -1 || idx2 == -1) {
//            cout << "Users not found.\n";
//            return;
//        }
//
//        cout << "Mutual Friends: \n";
//        bool found = false;
//
//        Node* t1 = adjList[idx1];
//        while (t1 != NULL) {
//            Node* t2 = adjList[idx2];
//            while (t2 != NULL) {
//                if (t1->userId == t2->userId) {
//                    int commonIdx = getIndexById(t1->userId);
//                    cout << "- " << users[commonIdx].name << endl;
//                    found = true;
//                    break;
//                }
//                t2 = t2->next;
//            }
//            t1 = t1->next;
//        }
//        if (!found) cout << "No mutual friends.\n";
//    }
//
//    void suggestFriends(int id) {
//        int idx = getIndexById(id);
//        if (idx == -1) {
//            cout << "User not found.\n";
//            return;
//        }
//
//        cout << "Suggestions for " << users[idx].name << ":\n";
//        bool foundAny = false;
//
//        bool seen[MAX_USERS];
//        for (int i = 0; i < MAX_USERS; i++) seen[i] = false;
//
//        seen[idx] = true;
//        Node* direct = adjList[idx];
//        while (direct != NULL) {
//            int friendIdx = getIndexById(direct->userId);
//            if (friendIdx != -1) seen[friendIdx] = true;
//            direct = direct->next;
//        }
//
//        Node* t1 = adjList[idx];
//        while (t1 != NULL) {
//            int fIdx = getIndexById(t1->userId);
//            if (fIdx != -1) {
//                Node* t2 = adjList[fIdx];
//                while (t2 != NULL) {
//                    int suggestionId = t2->userId;
//                    int suggIdx = getIndexById(suggestionId);
//
//                    if (suggIdx != -1 && !seen[suggIdx]) {
//                        cout << "- " << users[suggIdx].name << endl;
//                        seen[suggIdx] = true;
//                        foundAny = true;
//                    }
//                    t2 = t2->next;
//                }
//            }
//            t1 = t1->next;
//        }
//        if (!foundAny) cout << "No new suggestions.\n";
//    }
//
//    void removeUser(int id) {
//        int idx = getIndexById(id);
//        if (idx == -1) {
//            cout << "User not found.\n";
//            return;
//        }
//
//        for (int i = 0; i < MAX_USERS; i++) {
//            if (users[i].isActive && i != idx) {
//                deleteFromList(adjList[i], id);
//            }
//        }
//
//        clearList(adjList[idx]);
//
//        cout << "User " << users[idx].name << " removed.\n";
//        users[idx].isActive = false;
//        userCount--;
//    }
//
//    ~Graph() {
//        for (int i = 0; i < MAX_USERS; i++) {
//            clearList(adjList[i]);
//        }
//    }
//};
//
//int main() {
//    Graph g;
//    int choice;
//    int id, id1, id2;
//    string name;
//
//    do {
//        cout << "\n--- Social Network Menu ---\n";
//        cout << "1. Add User\n";
//        cout << "2. Add Friendship\n";
//        cout << "3. Display Friends\n";
//        cout << "4. DFS Traversal\n";
//        cout << "5. Count Friend Circles\n";
//        cout << "6. Find Popular Users\n";
//        cout << "7. Detect Isolated Users\n";
//        cout << "8. Mutual Friends\n";
//        cout << "9. Suggest Friends\n";
//        cout << "10. Remove User\n";
//        cout << "11. Exit\n";
//        cout << "Enter choice: ";
//        if (!(cin >> choice)) {
//            cin.clear(); cin.ignore(1000, '\n');
//            choice = 0;
//        }
//
//        switch (choice) {
//        case 1:
//            cout << "Enter ID: "; cin >> id;
//            cout << "Enter Name: "; cin >> name;
//            g.addUser(id, name);
//            break;
//        case 2:
//            cout << "Enter ID 1: "; cin >> id1;
//            cout << "Enter ID 2: "; cin >> id2;
//            g.addFriendship(id1, id2);
//            break;
//        case 3:
//            cout << "Enter ID: "; cin >> id;
//            g.displayFriends(id);
//            break;
//        case 4:
//            cout << "Enter Start ID: "; cin >> id;
//            g.dfsTraversal(id);
//            break;
//        case 5:
//            g.countFriendCircles();
//            break;
//        case 6:
//            g.findPopularUsers();
//            break;
//        case 7:
//            g.detectIsolatedUsers();
//            break;
//        case 8:
//            cout << "Enter ID 1: "; cin >> id1;
//            cout << "Enter ID 2: "; cin >> id2;
//            g.showMutualFriends(id1, id2);
//            break;
//        case 9:
//            cout << "Enter ID: "; cin >> id;
//            g.suggestFriends(id);
//            break;
//        case 10:
//            cout << "Enter ID: "; cin >> id;
//            g.removeUser(id);
//            break;
//        case 11:
//            cout << "Exiting...\n";
//            break;
//        default:
//            cout << "Invalid choice.\n";
//        }
//    } while (choice != 11);
//
//    return 0;
//}
//