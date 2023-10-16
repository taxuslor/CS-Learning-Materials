# CS106B: Trees

## Tree

- A tree is hierarchical data organization structure composed of a root value linked to zero or more non-empty subtrees.

- A **node** with 0 or more non-empty **subtrees**
- **A** is the **root node** of the tree

- **B, C, D, E,** and **F** are **children** of **A**
- **A i**s the **parent** of **B, C, D, E,** and **F**
- **B** has no children. A node with no children is called a **leaf node**.

- **G, H** and **I** all have the same parent. Nodes with the same parent are **siblings**.

- The **path** from **A** to **L** is **A -> F -> K -> L**
- The **length** of the path is **number of edges it contains**. The path from **A** to **L** has length 3.
- The **depth** of a node is the **length of its path to the root**.
- The **height** of a tree is defined to be **the number of levels that a tree has.**
- The **height** can also be defined as **the number of nodes along the longest path from the root to a leaf.**

## Bianry Tree

- In general, we've seen that nodes in a tree can have variable numbers of children (subtrees) and sometimes very, very many.
- However, when working with trees in computer programs, it is common to work mostly with **binary trees**.
- A **binary tree** is a tree where every node has either 0, 1, or 2 children. No node in a binary tree can have more than 2 children.
- Typically, the two children of a node in a binary tree are referred to as the **left child** and the **right child**.

### Pre-order Traversal

- "Do something" with the current node
- Traverse the left subtree
- Traverse the right subtree

### In-order Traversal

- Traverse the left subtree
- "Do something" with the current node
- Traverse the right subtree

### Post-order Traversal

- Traverse the left subtree
- Traverse the right subtree
- "Do something" with the current node

## Binary Search Tree

- An optimal BST is built by repeatedly choosing the median element as the root node of a given subtree and then separating elements into groups less than and greater than that median.

````c++
#include <iostream>

template <typename T>
class Set {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        explicit Node(const T& value)
            : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    Set() : root(nullptr) {}

    ~Set() {
        clear(root);
    }

    void insert(const T& value) {
        root = insertNode(root, value);
    }

    void remove(const T& value) {
        root = removeNode(root, value);
    }

    bool contains(const T& value) const {
        return findNode(root, value) != nullptr;
    }

    void displayInOrder() const {
        displayInOrder(root);
    }

private:
    Node* insertNode(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    Node* removeNode(Node* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = removeNode(node->left, value);
        } else if (value > node->data) {
            node->right = removeNode(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* minNode = findMinNode(node->right);
                node->data = minNode->data;
                node->right = removeNode(node->right, minNode->data);
            }
        }

        return node;
    }

    Node* findNode(Node* node, const T& value) const {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return findNode(node->left, value);
        } else {
            return findNode(node->right, value);
        }
    }

    Node* findMinNode(Node* node) const {
        if (node == nullptr || node->left == nullptr) {
            return node;
        }

        return findMinNode(node->left);
    }

    void displayInOrder(Node* node) const {
        if (node != nullptr) {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

int main() {
    Set<int> set;
    set.insert(5);
    set.insert(2);
    set.insert(7);
    set.insert(9);

    std::cout << "Set: ";
    set.displayInOrder();
    std::cout << std::endl;

    set.remove(2);

    std::cout << "Set after removing 2: ";
    set.displayInOrder();
    std::cout << std::endl;

    std::cout << "Set contains 7: " << (set.contains(7) ? "true" : "false") << std::endl;
    std::cout << "Set contains 3: " << (set.contains(3) ? "true" : "false") << std::endl;

    return 0;
}
````

## Compression Algorithms

- Compression algorithms are a whole class of real-world algorithms that are have widespread prevalence and importance.

- In particular, we are interested in algorithms that provide **lossless compression**

  on a stream of characters or other data.

  - Lossless compression means that we make the amount of data smaller without losing any of the details, and we can decompress the data to exactly the same as it was before compression.

- Virtually everything that you do online involves data compression.
  - When you visit a website, download a file, or transmit video/audio, the data is **compressed** when sending and **decompressed** when receiving.
- Compression algorithms **identify patterns in data** and take advantage of those patterns to come up with more efficient representations of that data!

## Huffman Coding

- Huffman coding is an algorithm for generating a coding tree for a given piece of data that produces a **provably minimal encoding** for a given pattern of letter frequencies.
- Different data (different text, different images, etc.) will each have their own personalized Huffman coding tree.
- The Huffman coding algorithm is a flexible, powerful, adaptive algorithm for data compression.

```c++
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Huffman树节点
struct Node {
    char data;            // 字符
    int frequency;        // 频率
    Node* left;
    Node* right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// 优先队列中的比较函数
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// 构建Huffman树
Node* buildHuffmanTree(unordered_map<char, int>& frequencies) {
    // 创建优先队列，按照频率进行排序
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    
    // 创建叶子节点并加入优先队列
    for (auto& pair : frequencies) {
        Node* node = new Node(pair.first, pair.second);
        minHeap.push(node);
    }

    // 构建Huffman树
    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* newNode = new Node('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    // 返回根节点
    return minHeap.top();
}

// 生成Huffman编码表
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr)
        return;

    // 叶子节点为编码节点
    if (!root->left && !root->right) {
        codes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

// 使用Huffman编码压缩消息
string compress(string message, unordered_map<char, string>& codes) {
    string compressedMessage = "";
    for (char c : message) {
        compressedMessage += codes[c];
    }
    return compressedMessage;
}

// 使用Huffman编码解压消息
string decompress(string compressedMessage, Node* root) {
    string decompressedMessage = "";
    Node* currentNode = root;
    for (char c : compressedMessage) {
        if (c == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (!currentNode->left && !currentNode->right) {
            decompressedMessage += currentNode->data;
            currentNode = root;
        }
    }
    return decompressedMessage;
}

int main() {
    string message = "Hello, World!";
    unordered_map<char, int> frequencies;
    
    // 统计字符频率
    for (char c : message) {
        frequencies[c]++;
    }

    // 构建Huffman树
    Node* root = buildHuffmanTree(frequencies);

    // 生成Huffman编码表
    unordered_map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    // 压缩消息
    string compressedMessage = compress(message, codes);
    cout << "Compressed Message: " << compressedMessage << endl;

    // 解压消息
    string decompressedMessage = decompress(compressedMessage, root);
    cout << "Decompressed Message: " << decompressedMessage << endl;

    return 0;
}
```

