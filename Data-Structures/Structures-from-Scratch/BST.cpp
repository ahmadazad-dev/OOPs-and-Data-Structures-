//#include <iostream>
//#include <queue>
//#include <stack>
//#include <functional>
//#include <cassert>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* left;
//    Node* right;
//    Node(int v) : data(v), left(nullptr), right(nullptr) {}
//};
//
//class BST {
//private:
//    Node* root;
//
//    Node* insertRec(Node* node, int v, bool& inserted) {
//        if (!node) {
//            inserted = true;
//            return new Node(v);
//        }
//        if (v == node->data) {
//            inserted = false;
//            return node;
//        }
//        if (v < node->data) node->left = insertRec(node->left, v, inserted);
//        else node->right = insertRec(node->right, v, inserted);
//        return node;
//    }
//
//    Node* searchRec(Node* node, int key) const {
//        if (!node) return nullptr;
//        if (key == node->data) return node;
//        if (key < node->data) return searchRec(node->left, key);
//        return searchRec(node->right, key);
//    }
//
//    void inorderRec(Node* node) const {
//        if (!node) return;
//        inorderRec(node->left);
//        cout << node->data << " ";
//        inorderRec(node->right);
//    }
//
//    Node* cloneRec(Node* node) {
//        if (!node) return nullptr;
//        Node* newNode = new Node(node->data);
//        newNode->left = cloneRec(node->left);
//        newNode->right = cloneRec(node->right);
//        return newNode;
//    }
//
//    void printSideways(Node* node, int indent = 0) const {
//        if (!node) return;
//        printSideways(node->right, indent + 4);
//        for (int i = 0; i < indent; ++i) cout << ' ';
//        cout << node->data << "\n";
//        printSideways(node->left, indent + 4);
//    }
//
//    void kthLargestRec(Node* node, int k, int& count, int& result, bool& found) const {
//        if (!node || found) return;
//        kthLargestRec(node->right, k, count, result, found);
//        if (found) return;
//        ++count;
//        if (count == k) {
//            result = node->data;
//            found = true;
//            return;
//        }
//        kthLargestRec(node->left, k, count, result, found);
//    }
//
//public:
//    BST() : root(nullptr) {}
//
//    BST(const BST& other) {
//        root = cloneRec(other.root);
//    }
//
//    ~BST() {
//        deletePostorder(root);
//        root = nullptr;
//    }
//
//    void deletePostorder(Node* node) {
//        if (!node) return;
//        stack<Node*> s1, s2;
//        s1.push(node);
//        while (!s1.empty()) {
//            Node* cur = s1.top();
//            s1.pop();
//            s2.push(cur);
//            if (cur->left) s1.push(cur->left);
//            if (cur->right) s1.push(cur->right);
//        }
//        while (!s2.empty()) {
//            Node* toDelete = s2.top();
//            s2.pop();
//            delete toDelete;
//        }
//    }
//
//    bool insert(int v) {
//        bool inserted = false;
//        root = insertRec(root, v, inserted);
//        return inserted;
//    }
//
//    Node* search(int key) const {
//        return searchRec(root, key);
//    }
//
//    void inorderPrint() const {
//        inorderRec(root);
//        cout << "\n";
//    }
//
//    void levelorderPrint() const {
//        if (!root) { cout << "(empty)\n"; return; }
//        queue<Node*> q;
//        q.push(root);
//        while (!q.empty()) {
//            int sz = (int)q.size();
//            for (int i = 0; i < sz; ++i) {
//                Node* cur = q.front(); q.pop();
//                cout << cur->data << " ";
//                if (cur->left) q.push(cur->left);
//                if (cur->right) q.push(cur->right);
//            }
//            cout << "\n";
//        }
//    }
//
//    void printTree() const {
//        if (!root) { cout << "(empty tree)\n"; return; }
//        printSideways(root);
//    }
//
//    Node* bstToDoublyLinkedListClone() const {
//        Node* head = nullptr;
//        Node* tail = nullptr;
//        stack<Node*> st;
//        Node* cur = root;
//        while (!st.empty() || cur) {
//            while (cur) {
//                st.push(cur);
//                cur = cur->left;
//            }
//            cur = st.top(); st.pop();
//            Node* n = new Node(cur->data);
//            if (!head) {
//                head = tail = n;
//            }
//            else {
//                tail->right = n;
//                n->left = tail;
//                tail = n;
//            }
//            cur = cur->right;
//        }
//        if (head) head->left = nullptr;
//        return head;
//    }
//
//    int countPairsWithSum(const BST& other, int target) const {
//        if (!root) return 0;
//        return countPairsRec(root, other, target);
//    }
//
//private:
//    int countPairsRec(Node* node, const BST& other, int target) const {
//        if (!node) return 0;
//        int cnt = 0;
//        cnt += countPairsRec(node->left, other, target);
//        int need = target - node->data;
//        if (other.search(need) != nullptr) ++cnt;
//        cnt += countPairsRec(node->right, other, target);
//        return cnt;
//    }
//
//public:
//    pair<bool, int> kthLargest(int k) const {
//        int count = 0;
//        int result = -1;
//        bool found = false;
//        kthLargestRec(root, k, count, result, found);
//        return make_pair(found, result);
//    }
//
//    Node* getRoot() const { return root; }
//};
//
//void printDLL(Node* head) {
//    Node* cur = head;
//    cout << "DLL forward: ";
//    while (cur) {
//        cout << cur->data;
//        if (cur->right) cout << " <-> ";
//        cur = cur->right;
//    }
//    cout << "\n";
//}
//
//void deleteDLL(Node* head) {
//    while (head) {
//        Node* nxt = head->right;
//        delete head;
//        head = nxt;
//    }
//}
//
//int main() {
//    BST a;
//    int valsA[] = { 50, 30, 70, 20, 40, 60, 80 };
//    for (int v : valsA) a.insert(v);
//
//    cout << "Inorder A: ";
//    a.inorderPrint();
//
//    cout << "Level order A:\n";
//    a.levelorderPrint();
//
//    cout << "Visual print A:\n";
//    a.printTree();
//
//    Node* found = a.search(60);
//    cout << "Search 60: " << (found ? "found" : "not found") << "\n";
//
//    BST b = a;
//    cout << "Inorder B (copied): ";
//    b.inorderPrint();
//
//    Node* head = a.bstToDoublyLinkedListClone();
//    printDLL(head);
//
//    BST c;
//    int valsC[] = { 15, 30, 45, 60, 75 };
//    for (int v : valsC) c.insert(v);
//
//    int target = 90;
//    int pairs = b.countPairsWithSum(c, target);
//    cout << "Pairs between B and C that sum to " << target << " = " << pairs << "\n";
//
//    int k = 3;
//    auto res = b.kthLargest(k);
//    if (res.first) cout << k << "rd largest in B is " << res.second << "\n";
//    else cout << "k is too large\n";
//
//    deleteDLL(head);
//    return 0;
//}
