//#include<iostream>
//#include<fstream>
//#include<string>
//#include<iomanip>
//using namespace std;
//
//class LinkedList {
//	class Node {
//		int data;
//		Node* up;
//		Node* down;
//		Node* left;
//		Node* right;
//		bool visited;
//	public:
//		Node();
//		Node(const int);
//		~Node();
//		int get_data();
//		void set_data(const int);
//		void set_up(Node*);
//		void set_down(Node*);
//		void set_left(Node*);
//		void set_right(Node*);
//		void set_visited(bool);
//		Node* get_up();
//		Node* get_down();
//		Node* get_left();
//		Node* get_right();
//		bool get_visited();
//		void print_node();
//	};
//	Node* head;
//	int rows;
//	int columns;
//public:
//	LinkedList();
//	~LinkedList();
//	void print_list();
//	void push_tail(const int);
//	void read(string);
//	void print(Node* );
//	void play_maze();
//	int clue_row(int data);
//	int clue_column(int data);
//	void visited(Node* current);
//	void elite_node(Node* elite);
//};
//
//LinkedList::Node::Node() {
//	data = 0;
//	up = nullptr;
//	down = nullptr;
//	left = nullptr;
//	right = nullptr;
//	visited = false;
//}
//LinkedList::Node::Node(const int data) {
//	this->data = data;
//	up = nullptr;
//	down = nullptr;
//	left = nullptr;
//	right = nullptr;
//	visited = false;
//}
//LinkedList::Node::~Node() {
//	 
//}
//void LinkedList::Node::set_data(const int data) {this->data = data;}
//void LinkedList::Node::set_up(Node* up) {this->up = up;}
//void LinkedList::Node::set_down(Node* down) {this->down = down;}
//void LinkedList::Node::set_left(Node* left) {this->left = left;}
//void LinkedList::Node::set_right(Node* right) { this->right = right; }
//void LinkedList::Node::set_visited(bool visited) { this->visited = visited; }
//int LinkedList::Node::get_data() {return data;}
//LinkedList::Node* LinkedList::Node::get_up() {return up;}
//LinkedList::Node* LinkedList::Node::get_down() {return down;}
//LinkedList::Node* LinkedList::Node::get_left() {return left;}
//LinkedList::Node* LinkedList::Node::get_right() { return right; }
//bool LinkedList::Node::get_visited() {return visited;}
//void LinkedList::Node::print_node() {
//	cout << this->data<<"   ";
//}
//
//LinkedList::LinkedList() {
//	head = nullptr;
//	rows = 0;
//	columns = 0;
//}
//LinkedList::~LinkedList() {
//	if (head) {
//		Node* row_ptr = head;
//		while (row_ptr) {
//			Node* column_ptr = row_ptr;
//			while (column_ptr) {
//				Node* temp = column_ptr->get_right();
//				delete column_ptr;
//				column_ptr = temp;
//			}
//			row_ptr = row_ptr->get_down();
//		}
//	}
//}
//void LinkedList::print_list() {
//	cout << rows << endl;
//	cout << columns << endl;
//	if (head) {
//		Node* current = head;
//		while (current) {
//			current->print_node();
//			current = current->get_right();
//		}
//	}
//}
//void LinkedList::push_tail(const int data) {
//	Node* new_node = new Node(data);
//	if (head) {
//		Node* current = head;
//		while (current->get_right()) {
//			current = current->get_right();
//		}
//		current->set_right(new_node);
//		new_node->set_left(current);
//	}
//	else {
//		head = new_node;
//	}
//}
//void LinkedList::read(string file_name) {//reads and format data from the file
//	ifstream input(file_name);
//	if (!input) {
//		cerr << "Error: File could not be opened\n";
//	}
//	char temp[100];
//	int matrix[10] = { 0 };
//	int k = 0;
//	while (input.getline(temp, 100)) {
//		char num_char[10];
//		int j = 0;
//		k = 0;
//		for (int i = 0;temp[i] != '\0';i++) {
//			if (temp[i] == ',') {
//				num_char[j] = '\0';
//				matrix[k++] = stoi(string(num_char));
//				j = 0;
//			}
//			else {
//				num_char[j++] = temp[i];
//			}
//		}
//		if (j > 0) {
//			num_char[j] = '\0';
//			matrix[k++] = stoi(string(num_char));
//		}
//		for (int l = 0;l < k;l++) {
//			if (rows == 0) {
//				columns++;
//			}
//			this->push_tail(matrix[l]);
//		}
//		rows++;
//	}
//	Node* row_start = nullptr;
//	Node* current = nullptr;
//	Node* new_row_start = nullptr;
//	for (int i = 0;i < rows - 1;i++) {
//		if (i == 0) {
//			row_start = head;
//			current = head;
//			new_row_start = head;
//		}
//		else {
//			row_start = current;
//		}
//		for (int j = 0;j < columns;j++) {
//			if (j < columns - 1) {
//				current = current->get_right();
//			}
//			if (new_row_start->get_right() && i==0){
//				new_row_start = new_row_start->get_right();
//			}
//		}
//
//		Node* temp = current->get_right();
//		temp->set_left(nullptr);
//		current->set_right(nullptr);
//
//		do {
//			row_start->set_down(new_row_start);
//			new_row_start->set_up(row_start);
//			row_start = row_start->get_right();
//			new_row_start = new_row_start->get_right();
//		} while (row_start);
//		current = temp;
//	}
//	this->print(head);
//}
//int LinkedList::clue_row(int data){//returns row number
//	int clue = 0;
//	while (data > 0) {
//		clue += data % 10;
//		data /= 10;
//	}
//	clue %= rows;
//	clue += 1;
//	return clue;
//}
//int LinkedList::clue_column(int data) {//returns column number
//	int clue = 0;
//	while (data > 0) {
//		clue += 1;
//		data /= 10;
//	}
//	return clue;
//}
//void LinkedList::visited(Node* current) {//sets visitied true if it is false
//	if (current->get_visited()) {
//		elite_node(current);
//		return;
//	}
//	else {
//		current->set_visited(true);
//		current->print_node();
//	}
//}
//void LinkedList::elite_node(Node* elite) {//print elite node and exit the program
//	cout << "\nElite Node Found: ";
//	elite->print_node();
//	exit(0);
//}
//void LinkedList::print(Node* head) {//print the maze
//	if (head) {
//		Node* row = head;
//		int row_count = 0;
//		while (row) {
//			for (int i = 0;i < columns;i++) {
//				cout << "----------      ";
//			}
//			cout << endl;
//			for (int i = 0;i < columns;i++) {
//				if (i == columns - 1) {
//					cout << "|        |";
//				}
//				else {
//					cout << "|        |  ->  ";
//				}
//			}
//			cout << endl;
//			Node* column = row;
//			while (column) {
//				int data = column->get_data();
//				const int width = 6;
//				string s = to_string(data);
//
//				int padding = width - s.length();
//				int left = padding / 2;
//				int right = padding - left;
//
//				cout << "| " << string(left, ' ') << s << string(right, ' ') << " |      ";
//				column = column->get_right();
//			}
//			cout << endl;
//			for (int i = 0;i < columns;i++) {
//				if (i == columns - 1) {
//					cout << "|        |";
//				}
//				else {
//					cout << "|        |  <-  ";
//				}
//			}
//			cout << endl;
//			for (int i = 0;i < columns;i++) {
//				cout << "----------      ";
//			}
//			cout << endl << endl;
//			if (row_count < rows-1) {
//				for (int i = 0;i < columns;i++) {
//					cout << " /\\    \\/       ";
//				}
//				cout << endl;
//			}
//			cout << endl ;
//			row_count++;
//			row = row->get_down();
//		}
//	}
//}
//
//void LinkedList::play_maze() {
//	Node* move = head;
//	int row_index = 1, column_index = 1;
//	int data = 0;
//	cout << "\nPath: \t";
//	visited(move);
//	while (true) {
//		data = move->get_data();
//		while (clue_column(data) < column_index) {
//			if (move->get_left() == nullptr) break;
//			move = move->get_left();
//			column_index--;
//		}
//		while (clue_column(data) > column_index) {
//			if (move->get_right() == nullptr) break;
//			move = move->get_right();
//			column_index++;
//		}
//		while (clue_row(data) < row_index) {
//			if (move->get_up() == nullptr) break;
//			move = move->get_up();
//			row_index--;
//		}
//		while (clue_row(data) > row_index) {
//			if (move->get_down() == nullptr) break;
//			move = move->get_down();
//			row_index++;
//		}
//		if (move) {
//			visited(move);
//		}
//	}
//}
// 
//int main() {
//	LinkedList maze;
//	maze.read("Maze.txt");
//	maze.play_maze();
//} 