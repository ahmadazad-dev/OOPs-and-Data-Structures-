//#include<iostream>
//#include<stack>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* right;
//	Node* left;
//	Node(int);
//};
//class BinaryTree {
//	Node* root;
//public:
//	BinaryTree();
//	void insert_I(const int);
//	void insert_R(const int);
//	void insert_R(Node*, Node*&);
//	bool search(const int);
//	Node* getroot();
//	void inOrderTraversal_I();//Left Node Right
//	void preOrderTraversal_I();//Node Left Right
//	void postOrderTraversal_I();//Left Right Node
//	void inOrderTraversal_R();
//	void preOrderTraversal_R();
//	void postOrderTraversal_R();
//	void inOrderTraversal_R(Node*);//Left Node Right
//	void preOrderTraversal_R(Node*);//Node Left Right
//	void postOrderTraversal_R(Node*);//Left Right Node
//	void deletion(const int);
//};
//
//Node::Node(int data) {
//	this->data = data;
//	right = nullptr;
//	left = nullptr;
//}
//BinaryTree::BinaryTree() {
//	root = nullptr;
//}
//
//void BinaryTree::insert_I(const int key) {
//	Node* newNode = new Node(key);
//	if (!root) { root = newNode; return; }
//	Node* current = root;
//	Node* previous = nullptr;
//	while (current) {
//		previous = current;
//		if (current->data > key) current = current->left;
//		else if (current->data < key) current = current->right;
//	}
//	if (key > previous->data) previous->right = newNode;
//	else if (key < previous->data) previous->left = newNode;
//}
//void BinaryTree::insert_R(Node* newNode, Node*& root) {
//	if(!root) {root = newNode; return;}
//	if (root->data > newNode->data) insert_R(newNode, root->left);
//	if(root->data < newNode->data) insert_R(newNode, root->right);
//}
//void BinaryTree::insert_R(const int data) {
//	Node* newNode = new Node(data);
//	insert_R(newNode, root);
//}
//
//bool BinaryTree::search(const int key) {
//	if (!root) return false;
//	Node* current = root;
//	bool flag = false;
//	while (!flag && current) {
//		if (current->data == key) flag = true;
//		else if (current->data > key) current = current->left;
//		else current = current->right;
//	}
//	return flag;
//}
//Node* BinaryTree::getroot() {
//	return root;
//}
//
//void BinaryTree::inOrderTraversal_I() {//Left Node Right
//	stack<Node*> myStack;
//	Node* current = root;
//
//	while (!myStack.empty() || current) {
//		while (current) {
//			myStack.push(current);
//			current = current->left;
//		}
//		current = myStack.top();
//		myStack.pop();
//		cout << current->data << " ";
//		current = current->right;
//	}
//}
//void BinaryTree::preOrderTraversal_I() {//Node Left Right
//	stack<Node*> myStack;
//	Node* current = root;
//	myStack.push(current);
//	while (!myStack.empty()) {
//		current = myStack.top();
//		myStack.pop();
//		cout<<current->data<<" ";
//		if (current->right) myStack.push(current->right);
//		if (current->left) myStack.push(current->left);
//	}
//}
//void BinaryTree::postOrderTraversal_I() {//Left Right Node
//	stack<Node*> myStack;
//	Node* current = root;
//	Node* last = nullptr;
//	
//	if(!current) return;
//	while (!myStack.empty() || current) {
//		while (current) {
//			myStack.push(current);
//			current = current->left;
//		}
//		Node* top = myStack.top();
//		if (!top->right || top->right==last) {
//			cout<<top->data<<" ";
//			myStack.pop();
//			last = top;
//		}
//		else {
//			current = top->right;
//		}
//	}
//}
//void BinaryTree::inOrderTraversal_R(){
//	inOrderTraversal_R(root);
//}
//void BinaryTree::postOrderTraversal_R(){
//	postOrderTraversal_R(root);
//}
//void BinaryTree::preOrderTraversal_R(){
//	preOrderTraversal_R(root);
//}
//void BinaryTree::inOrderTraversal_R(Node* root) {
//	if(!root) return;
//	if (root->left) inOrderTraversal_R(root->left);
//	cout<<root->data<<" ";
//	if(root->right) inOrderTraversal_R(root->right);
//}
//void BinaryTree::postOrderTraversal_R(Node* root) {
//	if (!root) return;
//	if (root->left) postOrderTraversal_R(root->left);
//	if (root->right) postOrderTraversal_R(root->right);
//	cout << root->data << " ";
//}
//void BinaryTree::preOrderTraversal_R(Node* root) {
//	if (!root) return;
//	cout << root->data << " ";
//	if (root->left) preOrderTraversal_R(root->left);
//	if (root->right) preOrderTraversal_R(root->right);
//}
//
//void BinaryTree::deletion(const int key) {
//	if (!root) return;
//	Node* current = root;
//	while (current) {
//		if (current->data == key) {
//
//		}
//		else if (current->data > key) current = current->left;
//		else current = current->right;
//	}
//}
//
//int sum(Node* root) {
//	if(!root) return 0;
//	return sum(root->left) + sum(root->right) + root->data;
//}
//
//
//
//int main() {
//	BinaryTree Tree;
//	Tree.insert_I(9);
//	Tree.insert_R(4);
//	Tree.insert_I(3);
//	Tree.insert_R(10);
//	Tree.insert_I(11);
//	Tree.insert_R(24);
//	Tree.insert_I(8);
//	Tree.insert_I(14);
//	Tree.insert_R(1);
//	Tree.insert_I(2);
//	Tree.insert_I(5);
//	Tree.insert_I(7);
//	Tree.insert_R(18);
//	Tree.insert_I(15);
//	Tree.insert_R(25);
//	Tree.insert_I(0);
//
//	cout << "Searching for Node 10: " << Tree.search(10);
//	cout << "\nSearching for Node 20: " << Tree.search(20);
//	cout << "\nSearching for Node 5: " << Tree.search(5);
//	cout << "\nSum of All nodes: " << sum(Tree.getroot());
//
//	cout << "\n\nBinary Tree in Left Node Right (InOrder) Iterative:\n";
//	Tree.inOrderTraversal_I();
//
//	cout << "\n\nBinary Tree in Left Node Right (InOrder) Recursive:\n";
//	Tree.inOrderTraversal_R();
//
//	cout << "\n\nBinary Tree in Left Right Node (PostOrder) Iterative:\n";
//	Tree.postOrderTraversal_I();
//
//	cout << "\n\nBinary Tree in Left Right Node (PostOrder) Recursive:\n";
//	Tree.postOrderTraversal_R();
//
//	cout << "\n\nBinary Tree in Node Left Right (PreOrder) Iterative:\n";
//	Tree.preOrderTraversal_I();
//
//	cout << "\n\nBinary Tree in Node Left Right (PreOrder) Recursive:\n";
//	Tree.preOrderTraversal_R();
//}