//#include <iostream>
//
//using namespace std;
//
//int myStrLen(const char* str) {
//    int len = 0;
//    while (str[len] != '\0') {
//        len++;
//    }
//    return len;
//}
//
//void myStrCpy(char* dest, const char* src) {
//    int i = 0;
//    while (src[i] != '\0') {
//        dest[i] = src[i];
//        i++;
//    }
//    dest[i] = '\0';
//}
//
//int myStrCmp(const char* s1, const char* s2) {
//    while (*s1 && (*s1 == *s2)) {
//        s1++;
//        s2++;
//    }
//    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
//}
//
//struct Edge {
//    int destination;
//    int weight;
//    Edge* next;
//};
//
//const int INF = 1000000000;
//
//class CityNetwork {
//private:
//    int numVertices;
//    int maxCapacity;
//
//    char** vertexNames;
//
//    Edge** adjList;
//
//    int getIndex(const char* name) {
//        for (int i = 0; i < numVertices; i++) {
//            if (myStrCmp(vertexNames[i], name) == 0) {
//                return i;
//            }
//        }
//        return -1;
//    }
//
//    bool dfsCycle(int v, bool visited[], int parent) {
//        visited[v] = true;
//
//        Edge* temp = adjList[v];
//        while (temp != nullptr) {
//            int neighbor = temp->destination;
//
//            if (!visited[neighbor]) {
//                if (dfsCycle(neighbor, visited, v))
//                    return true;
//            }
//            else if (neighbor != parent) {
//                return true;
//            }
//            temp = temp->next;
//        }
//        return false;
//    }
//
//    void dfsConnectivity(int v, bool visited[]) {
//        visited[v] = true;
//        Edge* temp = adjList[v];
//        while (temp != nullptr) {
//            if (!visited[temp->destination]) {
//                dfsConnectivity(temp->destination, visited);
//            }
//            temp = temp->next;
//        }
//    }
//
//    void dfsBridge(int u, bool visited[], int disc[], int low[], int parent[], int& timer) {
//        visited[u] = true;
//        disc[u] = low[u] = ++timer;
//
//        Edge* temp = adjList[u];
//        while (temp != nullptr) {
//            int v = temp->destination;
//
//            if (v == parent[u]) {
//                temp = temp->next;
//                continue;
//            }
//
//            if (visited[v]) {
//                if (disc[v] < low[u])
//                    low[u] = disc[v];
//            }
//            else {
//                parent[v] = u;
//                dfsBridge(v, visited, disc, low, parent, timer);
//
//                if (low[v] < low[u])
//                    low[u] = low[v];
//
//                if (low[v] > disc[u]) {
//                    cout << "  Bridge found: " << vertexNames[u] << " -- " << vertexNames[v] << endl;
//                }
//            }
//            temp = temp->next;
//        }
//    }
//
//public:
//    CityNetwork(int capacity) {
//        maxCapacity = capacity;
//        numVertices = 0;
//
//        vertexNames = new char* [maxCapacity];
//        adjList = new Edge * [maxCapacity];
//
//        for (int i = 0; i < maxCapacity; i++) {
//            adjList[i] = nullptr;
//            vertexNames[i] = nullptr;
//        }
//    }
//
//    ~CityNetwork() {
//        for (int i = 0; i < numVertices; i++) {
//            delete[] vertexNames[i];
//            Edge* current = adjList[i];
//            while (current != nullptr) {
//                Edge* next = current->next;
//                delete current;
//                current = next;
//            }
//        }
//        delete[] vertexNames;
//        delete[] adjList;
//    }
//
//    void addIntersection(const char* name) {
//        if (getIndex(name) != -1) return;
//        if (numVertices >= maxCapacity) {
//            cout << "Capacity full!" << endl;
//            return;
//        }
//
//        int len = myStrLen(name);
//        vertexNames[numVertices] = new char[len + 1];
//        myStrCpy(vertexNames[numVertices], name);
//
//        numVertices++;
//    }
//
//    void addRoad(const char* srcName, const char* destName, int time) {
//        int u = getIndex(srcName);
//        int v = getIndex(destName);
//
//        if (u == -1 || v == -1) {
//            cout << "Invalid intersection names." << endl;
//            return;
//        }
//
//        Edge* newEdge1 = new Edge;
//        newEdge1->destination = v;
//        newEdge1->weight = time;
//        newEdge1->next = adjList[u];
//        adjList[u] = newEdge1;
//
//        Edge* newEdge2 = new Edge;
//        newEdge2->destination = u;
//        newEdge2->weight = time;
//        newEdge2->next = adjList[v];
//        adjList[v] = newEdge2;
//    }
//
//    void findShortestPath(const char* startName, const char* endName) {
//        int startNode = getIndex(startName);
//        int endNode = getIndex(endName);
//
//        if (startNode == -1 || endNode == -1) {
//            cout << "Invalid nodes." << endl;
//            return;
//        }
//
//        int* dist = new int[numVertices];
//        bool* visited = new bool[numVertices];
//        int* parent = new int[numVertices];
//
//        for (int i = 0; i < numVertices; i++) {
//            dist[i] = INF;
//            visited[i] = false;
//            parent[i] = -1;
//        }
//
//        dist[startNode] = 0;
//
//        for (int count = 0; count < numVertices - 1; count++) {
//            int minVal = INF;
//            int u = -1;
//
//            for (int v = 0; v < numVertices; v++) {
//                if (!visited[v] && dist[v] <= minVal) {
//                    minVal = dist[v];
//                    u = v;
//                }
//            }
//
//            if (u == -1 || dist[u] == INF) break;
//
//            visited[u] = true;
//
//            Edge* temp = adjList[u];
//            while (temp != nullptr) {
//                int v = temp->destination;
//                int weight = temp->weight;
//                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
//                    dist[v] = dist[u] + weight;
//                    parent[v] = u;
//                }
//                temp = temp->next;
//            }
//        }
//
//        if (dist[endNode] == INF) {
//            cout << "No path exists between " << startName << " and " << endName << endl;
//        }
//        else {
//            cout << "Shortest Time from " << startName << " to " << endName << ": " << dist[endNode] << " mins" << endl;
//        }
//
//        delete[] dist;
//        delete[] visited;
//        delete[] parent;
//    }
//
//    void detectCycles() {
//        bool* visited = new bool[numVertices];
//        for (int i = 0; i < numVertices; i++) visited[i] = false;
//
//        bool hasCycle = false;
//        for (int i = 0; i < numVertices; i++) {
//            if (!visited[i]) {
//                if (dfsCycle(i, visited, -1)) {
//                    hasCycle = true;
//                    break;
//                }
//            }
//        }
//
//        if (hasCycle)
//            cout << "Cycle Detected: Yes (Potential traffic loops exist)" << endl;
//        else
//            cout << "Cycle Detected: No" << endl;
//
//        delete[] visited;
//    }
//
//    void checkConnectivity() {
//        bool* visited = new bool[numVertices];
//        for (int i = 0; i < numVertices; i++) visited[i] = false;
//
//        int components = 0;
//        for (int i = 0; i < numVertices; i++) {
//            if (!visited[i]) {
//                dfsConnectivity(i, visited);
//                components++;
//            }
//        }
//
//        if (components == 1) {
//            cout << "Graph is Connected (All intersections reachable)." << endl;
//        }
//        else {
//            cout << "Graph is NOT Connected." << endl;
//            cout << "Number of Connected Components: " << components << endl;
//        }
//
//        delete[] visited;
//    }
//
//    void findCriticalRoads() {
//        bool* visited = new bool[numVertices];
//        int* disc = new int[numVertices];
//        int* low = new int[numVertices];
//        int* parent = new int[numVertices];
//        int timer = 0;
//
//        for (int i = 0; i < numVertices; i++) {
//            visited[i] = false;
//            parent[i] = -1;
//            disc[i] = 0;
//            low[i] = 0;
//        }
//
//        cout << "Critical Roads (Bridges):" << endl;
//        for (int i = 0; i < numVertices; i++) {
//            if (!visited[i]) {
//                dfsBridge(i, visited, disc, low, parent, timer);
//            }
//        }
//        cout << "(If no roads listed above, network has no single point of failure)" << endl;
//
//        delete[] visited;
//        delete[] disc;
//        delete[] low;
//        delete[] parent;
//    }
//};
//
//int main() {
//    CityNetwork city(20);
//
//    city.addIntersection("A");
//    city.addIntersection("B");
//    city.addIntersection("C");
//    city.addIntersection("D");
//    city.addIntersection("E");
//    city.addIntersection("F");
//
//    city.addRoad("A", "B", 10);
//    city.addRoad("B", "C", 15);
//    city.addRoad("A", "C", 30);
//    city.addRoad("C", "D", 50);
//    city.addRoad("D", "E", 10);
//
//    cout << "--- 2. Shortest Path Analysis ---" << endl;
//    city.findShortestPath("A", "C");
//    city.findShortestPath("A", "F");
//
//    cout << "\n--- 3. Cycle Detection ---" << endl;
//    city.detectCycles();
//
//    cout << "\n--- 4. Connectivity Check ---" << endl;
//    city.checkConnectivity();
//
//    cout << "\n--- 5. Critical Road Analysis ---" << endl;
//    city.findCriticalRoads();
//
//    return 0;
//}