//#include <iostream>
//
//using namespace std;
//
//const int MAXIMUM_GRID_SIZE = 100;
//
//struct GridCoordinate {
//    int rowIndex;
//    int columnIndex;
//};
//
//char buildingLayout[MAXIMUM_GRID_SIZE][MAXIMUM_GRID_SIZE];
//bool hasBeenVisited[MAXIMUM_GRID_SIZE][MAXIMUM_GRID_SIZE];
//int minimumSteps[MAXIMUM_GRID_SIZE][MAXIMUM_GRID_SIZE];
//GridCoordinate previousLocation[MAXIMUM_GRID_SIZE][MAXIMUM_GRID_SIZE];
//
//GridCoordinate traversalQueue[MAXIMUM_GRID_SIZE * MAXIMUM_GRID_SIZE];
//int queueFrontIndex = 0;
//int queueRearIndex = 0;
//
//void addToQueue(GridCoordinate coordinate) {
//    traversalQueue[queueRearIndex] = coordinate;
//    queueRearIndex++;
//}
//
//GridCoordinate removeFromQueue() {
//    GridCoordinate item = traversalQueue[queueFrontIndex];
//    queueFrontIndex++;
//    return item;
//}
//
//bool isQueueEmpty() {
//    return queueFrontIndex == queueRearIndex;
//}
//
//int main() {
//    int numberOfRows, numberOfColumns;
//
//    cout << "Enter the number of rows and columns: ";
//    if (!(cin >> numberOfRows >> numberOfColumns)) return 0;
//
//    GridCoordinate startPoint, exitPoint;
//
//    cout << "Enter the building matrix (0, 1, F, S, E):" << endl;
//    for (int i = 0; i < numberOfRows; i++) {
//        for (int j = 0; j < numberOfColumns; j++) {
//            cin >> buildingLayout[i][j];
//
//            hasBeenVisited[i][j] = false;
//            minimumSteps[i][j] = 0;
//
//            if (buildingLayout[i][j] == 'S') {
//                startPoint.rowIndex = i;
//                startPoint.columnIndex = j;
//            }
//            else if (buildingLayout[i][j] == 'E') {
//                exitPoint.rowIndex = i;
//                exitPoint.columnIndex = j;
//            }
//        }
//    }
//
//    int rowDirectionChange[] = { -1, 1, 0, 0 };
//    int columnDirectionChange[] = { 0, 0, -1, 1 };
//
//    bool pathFound = false;
//
//    hasBeenVisited[startPoint.rowIndex][startPoint.columnIndex] = true;
//    minimumSteps[startPoint.rowIndex][startPoint.columnIndex] = 0;
//
//    GridCoordinate invalidParent = { -1, -1 };
//    previousLocation[startPoint.rowIndex][startPoint.columnIndex] = invalidParent;
//
//    addToQueue(startPoint);
//
//    while (!isQueueEmpty()) {
//        GridCoordinate currentLocation = removeFromQueue();
//
//        if (currentLocation.rowIndex == exitPoint.rowIndex && currentLocation.columnIndex == exitPoint.columnIndex) {
//            pathFound = true;
//            break;
//        }
//
//        for (int i = 0; i < 4; i++) {
//            int nextRow = currentLocation.rowIndex + rowDirectionChange[i];
//            int nextColumn = currentLocation.columnIndex + columnDirectionChange[i];
//
//            if (nextRow >= 0 && nextRow < numberOfRows && nextColumn >= 0 && nextColumn < numberOfColumns) {
//                char cellValue = buildingLayout[nextRow][nextColumn];
//
//                if (!hasBeenVisited[nextRow][nextColumn] && cellValue != '1' && cellValue != 'F') {
//                    hasBeenVisited[nextRow][nextColumn] = true;
//                    minimumSteps[nextRow][nextColumn] = minimumSteps[currentLocation.rowIndex][currentLocation.columnIndex] + 1;
//
//                    GridCoordinate sourceLocation;
//                    sourceLocation.rowIndex = currentLocation.rowIndex;
//                    sourceLocation.columnIndex = currentLocation.columnIndex;
//                    previousLocation[nextRow][nextColumn] = sourceLocation;
//
//                    GridCoordinate nextStep;
//                    nextStep.rowIndex = nextRow;
//                    nextStep.columnIndex = nextColumn;
//                    addToQueue(nextStep);
//                }
//            }
//        }
//    }
//
//    if (pathFound) {
//        int totalSteps = minimumSteps[exitPoint.rowIndex][exitPoint.columnIndex];
//        cout << "Escape possible in " << totalSteps << " steps" << endl;
//
//        GridCoordinate finalPath[MAXIMUM_GRID_SIZE * MAXIMUM_GRID_SIZE];
//        int pathLength = 0;
//        GridCoordinate pathCrawler = exitPoint;
//
//        while (pathCrawler.rowIndex != -1 && pathCrawler.columnIndex != -1) {
//            finalPath[pathLength] = pathCrawler;
//            pathLength++;
//
//            if (pathCrawler.rowIndex == startPoint.rowIndex && pathCrawler.columnIndex == startPoint.columnIndex) break;
//
//            pathCrawler = previousLocation[pathCrawler.rowIndex][pathCrawler.columnIndex];
//        }
//
//        cout << "Path coordinates: ";
//        for (int i = pathLength - 1; i >= 0; i--) {
//            cout << "(" << finalPath[i].rowIndex << "," << finalPath[i].columnIndex << ")";
//            if (i > 0) cout << " -> ";
//        }
//        cout << endl;
//
//    }
//    else {
//        cout << "No Escape" << endl;
//    }
//
//    return 0;
//}