/* CS106B Assign6: Huffman Coding
 */
#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct Bit {
    enum Value {
        Zero, One
    };
    Value value;
};

struct EncodedData {
    queue<Bit> bits;
    queue<char> leaves;
};

struct EncodingTreeNode {
    char data;
    int frequency;
    EncodingTreeNode *left;
    EncodingTreeNode *right;

    EncodingTreeNode(char d, int f) {
        data = d;
        frequency = f;
        left = nullptr;
        right = nullptr;
    }
};

struct CompareNodes {
    bool operator()(const EncodingTreeNode *a, const EncodingTreeNode *b) const {
        return a->frequency > b->frequency;
    }
};

void buildEncodingMap(EncodingTreeNode *tree, string code, map<char, string> &encodingMap) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left == nullptr && tree->right == nullptr) {
        encodingMap[tree->data] = code;
    } else {
        buildEncodingMap(tree->left, code + "0", encodingMap);
        buildEncodingMap(tree->right, code + "1", encodingMap);
    }
}

void flattenTree(EncodingTreeNode *tree, queue<Bit> &treeBits, queue<char> &treeLeaves) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left == nullptr && tree->right == nullptr) {
        treeBits.push(Bit{Bit::One});
        treeLeaves.push(tree->data);
    } else {
        treeBits.push(Bit{Bit::Zero});
        flattenTree(tree->left, treeBits, treeLeaves);
        flattenTree(tree->right, treeBits, treeLeaves);
    }
}

EncodingTreeNode *unflattenTree(queue<Bit> &treeBits, queue<char> &treeLeaves) {
    if (treeBits.empty()) {
        return nullptr;
    }
    Bit bit = treeBits.front();
    treeBits.pop();
    if (bit.value == Bit::One) {
        char leaf = treeLeaves.front();
        treeLeaves.pop();
        return new EncodingTreeNode(leaf, 0);
    } else {
        EncodingTreeNode *node = new EncodingTreeNode('\0', 0);
        node->left = unflattenTree(treeBits, treeLeaves);
        node->right = unflattenTree(treeBits, treeLeaves);
        return node;
    }
}

queue<Bit> encodeText(EncodingTreeNode *tree, string text) {
    map<char, string> encodingMap;
    buildEncodingMap(tree, "", encodingMap);
    queue<Bit> encodedBits;
    for (char c: text) {
        string code = encodingMap[c];
        for (char bitChar: code) {
            Bit bit;
            bit.value = (bitChar == '0') ? Bit::Zero : Bit::One;
            encodedBits.push(bit);
        }
    }
    return encodedBits;
}

EncodingTreeNode *buildHuffmanTree(string text) {
    map<char, int> frequencyMap;
    for (char c: text) {
        frequencyMap[c]++;
    }
    priority_queue<EncodingTreeNode *, vector<EncodingTreeNode *>, CompareNodes> pq;
    for (auto &entry: frequencyMap) {
        pq.push(new EncodingTreeNode(entry.first, entry.second));
    }
    while (pq.size() > 1) {
        EncodingTreeNode *left = pq.top();
        pq.pop();
        EncodingTreeNode *right = pq.top();
        pq.pop();
        EncodingTreeNode *parent = new EncodingTreeNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}

EncodedData compress(string messageText) {
    EncodingTreeNode *huffmanTree = buildHuffmanTree(messageText);
    queue<Bit> encodedBits = encodeText(huffmanTree, messageText);
    EncodedData data;
    flattenTree(huffmanTree, data.bits, data.leaves);
    while (!encodedBits.empty()) {
        data.bits.push(encodedBits.front());
        encodedBits.pop();
    }
    return data;
}

string decodeText(EncodingTreeNode *tree, queue<Bit> &messageBits) {
    string decodedText;
    EncodingTreeNode *currentNode = tree;
    while (!messageBits.empty()) {
        Bit bit = messageBits.front();
        messageBits.pop();
        if (bit.value == Bit::Zero) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decodedText += currentNode->data;
            currentNode = tree;
        }
    }
    return decodedText;
}

string decompress(EncodedData &data) {
    EncodingTreeNode *tree = unflattenTree(data.bits, data.leaves);
    return decodeText(tree, data.bits);
}

int main() {
    string message = "Hello, World!";
    EncodedData compressedData = compress(message);
    string decompressedMessage = decompress(compressedData);
    cout << "Original Message: " << message << endl;
    cout << "Compressed Data: ";
    while (!compressedData.bits.empty()) {
        cout << static_cast<int>(compressedData.bits.front().value) << " ";
        compressedData.bits.pop();
    }
    cout << endl;
    cout << "Decompressed Message: " << decompressedMessage << endl;
    return 0;
}