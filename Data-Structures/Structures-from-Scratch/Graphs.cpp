//#include<iostream>
//#include<vector>
//#include<list>
//#include<queue>
//
//using namespace std;
//
//class Graph {
//	int vertices;
//	list<int>* adjacency_List;
//
//public:
//	Graph(const int);
//	void add_Edge_undirected(int u, int v);
//	void add_Edge_directed(int u, int v);
//	void BFS_traversal();
//	void DFS_traversal(int source, vector<bool>& visited);
//	void call_DFS_traversal();
//	bool cycle_detection_using_DFS(int source, int parent, vector<bool>& visited);
//	void call_cycle_detection_using_DFS();
//	bool cycle_detection_using_BFS(int source, vector<bool>& visited);
//	void call_cycle_detection_using_BFS();
//	bool cycle_detection_using_DFS_directed(int current, vector<bool>& visited, vector<bool>& recursionPath);
//	void call_cycle_detection_using_DFS_directed();
//	void print_Adjacency_List();
//
//};
//
//Graph::Graph(const int vertices) {
//	this->vertices = vertices;
//	adjacency_List = new list<int>[vertices];
//}
//
//void Graph::add_Edge_undirected(int u, int v) {//Assuming each edge exists between two nodes i.e. U and V and this funciton takes both the values and forms an edge between them
//	//This is only for undirected graph where the link is fomred from both ends
//	adjacency_List[u].push_back(v);
//	adjacency_List[v].push_back(u);
//}
//
//void Graph::add_Edge_directed(int u, int v) {//Assuming each edge exists between two nodes i.e. U and V and this funciton takes both the values and forms an edge between them
//	//This is only for directed graph where the link is fomred from one end only
//	adjacency_List[u].push_back(v);
//}
//
////BFS Traversal
//void Graph::BFS_traversal() {//Time Complexity: O (Vertices+edges)
//	queue<int> queue_integers;
//	vector<bool> visited(vertices, false);
//
//	queue_integers.push(0);
//	visited[0] = true;
//
//	while (queue_integers.size() > 0) {
//		int source = queue_integers.front();//source is the current vertex
//		queue_integers.pop();
//
//		cout << source << " ";
//
//		for (int neighbor : adjacency_List[source]) {//neighbor is the immediate neighbor of the source
//			if (!visited[neighbor]) {
//				visited[neighbor] = true;
//				queue_integers.push(neighbor);
//			}
//		}
//	}
//	cout << endl;
//}
//
////DFS-Traversal
//void Graph::DFS_traversal(int source, vector<bool>& visited) {//Time Complexity: O (Vertices+edges)
//	visited[source] = true;
//	cout << source << " ";
//	for (int neighbor : adjacency_List[source]) {
//		if (!visited[neighbor]) {
//			DFS_traversal(neighbor, visited);
//		}
//	}
//}
//void Graph::call_DFS_traversal() {
//	vector<bool> visited(vertices, false);
//	DFS_traversal(0, visited);
//}
//
//bool Graph::cycle_detection_using_DFS(int source, int parent, vector<bool>& visited) {//Time Complexity: O (Vertices+Edges)
//	visited[source] = true;
//	list<int> neighbors = adjacency_List[source];
//
//	for (int neighbor : neighbors) {
//		if (!visited[neighbor]) {
//			if (cycle_detection_using_DFS(neighbor, source, visited)) return true;
//		}
//		else if (neighbor != parent) {
//			return true;
//		}
//	}
//	return false;
//
//}
//void Graph::call_cycle_detection_using_DFS() {
//	int source = 0;
//	vector<bool> visited(vertices, false);
//	bool has_cycle = false;
//
//	for (int i = 0;i < vertices;i++) {
//		if (!visited[i]) {
//			if (cycle_detection_using_DFS(source, -1, visited)) {
//				has_cycle = true;
//				break;
//			}
//		}
//	}
//	if (has_cycle) cout << "true";
//	else cout << "false";
//}
//
//bool Graph::cycle_detection_using_BFS(int source, vector<bool>& visited) {//Time Complexity: O (Vertices+Edges)
//	queue<pair<int, int>> queue_integers;
//
//	queue_integers.push({ source,-1 });
//	visited[source] = true;
//
//	while (queue_integers.size() > 0) {
//		int current = queue_integers.front().first;//source is the current vertex
//		int parent = queue_integers.front().second;
//		queue_integers.pop();
//
//		list<int> neighbors = adjacency_List[current];
//
//		for (int neighbor : neighbors) {//neighbor is the immediate neighbor of the source
//			if (!visited[neighbor]) {
//				queue_integers.push({ neighbor,current });
//				visited[neighbor] = true;
//			}
//			else if (neighbor != parent) {
//				return true;
//			}
//		}
//	}
//	return false;
//}
//void Graph::call_cycle_detection_using_BFS() {
//	int source = 0;
//	vector<bool> visited(vertices, false);
//	bool has_cycle = false;
//	for (int i = 0; i < vertices; i++) {
//		if (!visited[i]) {
//			if (cycle_detection_using_BFS(i, visited)) {
//				has_cycle = true;
//				break;
//			}
//		}
//	}
//	if (has_cycle) cout << "true";
//	else cout << "false";
//}
//
//bool Graph::cycle_detection_using_DFS_directed(int current, vector<bool>& visited, vector<bool>& recursionPath) {
//	visited[current] = true;
//	recursionPath[current] = true;
//
//	for (int neighbor : adjacency_List[current]) {
//		if (!visited[neighbor]) {
//			if (cycle_detection_using_DFS_directed(neighbor, visited, recursionPath)) {
//				return true;
//			}
//		}
//		else if (recursionPath[neighbor]) {
//			return true;
//		}
//	}
//	recursionPath[current] = false;
//	return false;
//}
//void Graph::call_cycle_detection_using_DFS_directed() {
//	vector<bool> visited(vertices, false);
//	vector<bool> recursionPath(vertices, false);
//	bool has_cycle = false;
//
//	for (int i = 0;i < vertices;i++) {
//		if (!visited[i]) {
//			if (cycle_detection_using_DFS_directed(i, visited, recursionPath)) {
//				cout << "true\n";
//				return;
//			}
//		}
//	}
//	cout << "false";
//}
//
//void Graph::print_Adjacency_List() {
//	for (int i = 0;i < vertices;i++) {
//		cout << "Neighbours of " << i << ": ";
//		for (int neighbours : adjacency_List[i]) {
//			cout << neighbours << " ";
//		}
//		cout << endl;
//	}
//}
//
//int main() {
//	Graph myGraph_Undirected(5);
//	myGraph_Undirected.add_Edge_undirected(0, 1);
//	myGraph_Undirected.add_Edge_undirected(0, 2);
//	myGraph_Undirected.add_Edge_undirected(1, 2);
//	myGraph_Undirected.add_Edge_undirected(1, 3);
//	myGraph_Undirected.add_Edge_undirected(2, 4);
//
//	Graph myGraph_Directed(4);
//	myGraph_Directed.add_Edge_directed(1, 0);
//	myGraph_Directed.add_Edge_directed(0, 2);
//	myGraph_Directed.add_Edge_directed(2, 3);
//	myGraph_Directed.add_Edge_directed(3, 1);
//
//	cout<<"<================= Adjacency List =================>\n";
//	myGraph_Undirected.print_Adjacency_List();
//
//	cout << "\n<================= BFS Traversal =================>\n";
//	myGraph_Undirected.BFS_traversal();
//
//	cout << "\n<================= DFS Traversal =================>\n";
//	myGraph_Undirected.call_DFS_traversal();
//
//	cout << "\n\n<================= Cycle Detection DFS =================>\n";
//	myGraph_Undirected.call_cycle_detection_using_DFS();
//
//	cout << "\n\n<================= Cycle Detection BFS =================>\n";
//	myGraph_Undirected.call_cycle_detection_using_BFS();
//
//	cout << "\n\n<================= Cycle Detection DFS Directed =================>\n";
//	myGraph_Directed.call_cycle_detection_using_DFS_directed();
//}