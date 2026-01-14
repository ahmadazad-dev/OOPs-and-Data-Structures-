//#include <iostream>
//
//using namespace std;
//
//const int MAX_CHARACTERS = 256;
//const int MAX_TREE_NODES = 512;
//const int MAX_CODE_LENGTH = 100;
//const int MAX_TEXT_LENGTH = 1000;
//const int MAX_ENCODED_LENGTH = 10000;
//
//struct HuffmanNode {
//    char character;
//    int frequency;
//    HuffmanNode* leftChild;
//    HuffmanNode* rightChild;
//};
//
//HuffmanNode* priorityQueue[MAX_TREE_NODES];
//int heapSize = 0;
//
//char huffmanCodes[MAX_CHARACTERS][MAX_CODE_LENGTH];
//int characterFrequencies[MAX_CHARACTERS];
//
//int stringLength(const char* str) {
//    int length = 0;
//    while (str[length] != '\0') {
//        length++;
//    }
//    return length;
//}
//
//void stringCopy(char* destination, const char* source) {
//    int i = 0;
//    while (source[i] != '\0') {
//        destination[i] = source[i];
//        i++;
//    }
//    destination[i] = '\0';
//}
//
//void stringAppend(char* destination, const char* source) {
//    int destLen = stringLength(destination);
//    int i = 0;
//    while (source[i] != '\0') {
//        destination[destLen + i] = source[i];
//        i++;
//    }
//    destination[destLen + i] = '\0';
//}
//
//HuffmanNode* createNode(char character, int frequency) {
//    HuffmanNode* newNode = new HuffmanNode;
//    newNode->character = character;
//    newNode->frequency = frequency;
//    newNode->leftChild = NULL;
//    newNode->rightChild = NULL;
//    return newNode;
//}
//
//void swapNodes(int indexA, int indexB) {
//    HuffmanNode* temp = priorityQueue[indexA];
//    priorityQueue[indexA] = priorityQueue[indexB];
//    priorityQueue[indexB] = temp;
//}
//
//void minHeapify(int index) {
//    int smallest = index;
//    int left = 2 * index + 1;
//    int right = 2 * index + 2;
//
//    if (left < heapSize && priorityQueue[left]->frequency < priorityQueue[smallest]->frequency)
//        smallest = left;
//
//    if (right < heapSize && priorityQueue[right]->frequency < priorityQueue[smallest]->frequency)
//        smallest = right;
//
//    if (smallest != index) {
//        swapNodes(smallest, index);
//        minHeapify(smallest);
//    }
//}
//
//void insertIntoHeap(HuffmanNode* node) {
//    int currentIndex = heapSize;
//    heapSize++;
//    priorityQueue[currentIndex] = node;
//
//    while (currentIndex != 0 && priorityQueue[(currentIndex - 1) / 2]->frequency > priorityQueue[currentIndex]->frequency) {
//        swapNodes(currentIndex, (currentIndex - 1) / 2);
//        currentIndex = (currentIndex - 1) / 2;
//    }
//}
//
//HuffmanNode* extractMinFromHeap() {
//    if (heapSize <= 0) return NULL;
//    if (heapSize == 1) {
//        heapSize--;
//        return priorityQueue[0];
//    }
//
//    HuffmanNode* root = priorityQueue[0];
//    priorityQueue[0] = priorityQueue[heapSize - 1];
//    heapSize--;
//    minHeapify(0);
//
//    return root;
//}
//
//void generateCodes(HuffmanNode* root, char* currentCode, int depth) {
//    if (!root) return;
//
//    if (!root->leftChild && !root->rightChild) {
//        currentCode[depth] = '\0';
//        stringCopy(huffmanCodes[(unsigned char)root->character], currentCode);
//        return;
//    }
//
//    currentCode[depth] = '0';
//    generateCodes(root->leftChild, currentCode, depth + 1);
//
//    currentCode[depth] = '1';
//    generateCodes(root->rightChild, currentCode, depth + 1);
//}
//
//int main() {
//    char inputText[MAX_TEXT_LENGTH];
//
//    cout << "Enter the text to be compressed: ";
//    cin.getline(inputText, MAX_TEXT_LENGTH);
//
//    for (int i = 0; i < MAX_CHARACTERS; i++) {
//        characterFrequencies[i] = 0;
//    }
//
//    for (int i = 0; inputText[i] != '\0'; i++) {
//        characterFrequencies[(unsigned char)inputText[i]]++;
//    }
//
//    cout << "\n1. Frequency Analysis:" << endl;
//    for (int i = 0; i < MAX_CHARACTERS; i++) {
//        if (characterFrequencies[i] > 0) {
//            insertIntoHeap(createNode((char)i, characterFrequencies[i]));
//            cout << "'" << (char)i << "': " << characterFrequencies[i] << endl;
//        }
//    }
//
//    while (heapSize > 1) {
//        HuffmanNode* leftNode = extractMinFromHeap();
//        HuffmanNode* rightNode = extractMinFromHeap();
//
//        HuffmanNode* topNode = createNode('$', leftNode->frequency + rightNode->frequency);
//        topNode->leftChild = leftNode;
//        topNode->rightChild = rightNode;
//
//        insertIntoHeap(topNode);
//    }
//
//    HuffmanNode* rootNode = extractMinFromHeap();
//
//    char codeBuffer[MAX_CODE_LENGTH];
//    generateCodes(rootNode, codeBuffer, 0);
//
//    cout << "\n2. Huffman Codes:" << endl;
//    for (int i = 0; i < MAX_CHARACTERS; i++) {
//        if (characterFrequencies[i] > 0) {
//            cout << "'" << (char)i << "': " << huffmanCodes[i] << endl;
//        }
//    }
//
//    char encodedString[MAX_ENCODED_LENGTH];
//    encodedString[0] = '\0';
//
//    for (int i = 0; inputText[i] != '\0'; i++) {
//        stringAppend(encodedString, huffmanCodes[(unsigned char)inputText[i]]);
//    }
//
//    cout << "\n3. Encoded Binary String:" << endl;
//    cout << encodedString << endl;
//
//    cout << "\n4. Decoded Text:" << endl;
//    HuffmanNode* currentNode = rootNode;
//
//    for (int i = 0; encodedString[i] != '\0'; i++) {
//        if (encodedString[i] == '0') {
//            currentNode = currentNode->leftChild;
//        }
//        else {
//            currentNode = currentNode->rightChild;
//        }
//
//        if (!currentNode->leftChild && !currentNode->rightChild) {
//            cout << currentNode->character;
//            currentNode = rootNode;
//        }
//    }
//    cout << endl;
//
//    return 0;
//}