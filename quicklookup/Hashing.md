# CS106B: Hashing

## Hash functions

- A function that takes in arbitrary inputs and maps them to a fixed set of outputs.

- Given an input of a particular type (e.g. string), returns a corresponding **hash** **value** (usually a number).

  - The values returned by a hash function are called “hash values,” “hash codes,” or “hashes.”

- Two important properties

  1. If given the same input, the hash function must return the same output. (This is also

     called a **deterministic** function.)

  2. Two different inputs will (usually) produce different outputs, even if the inputs are

     very similar.

## Example

````c++
#include <iostream>

class HashNode {
public:
    int value;
    HashNode* next;

    HashNode(int val) : value(val), next(nullptr) {}
};

class HashSet {
public:
    HashSet() {
        capacity = 10; // 初始容量设为10
        mysize = 0;
        elements = new HashNode*[capacity](); // 创建一个指针数组，并将每个元素初始化为nullptr
    }

    ~HashSet() {
        clear(); // 销毁时清空集合
        delete[] elements;
    }

    void add(int value) {
        int index = getIndexOf(value); // 获取元素对应的索引

        if (contains(value)) {
            std::cout << "Value already exists in the set." << std::endl;
            return;
        }

        HashNode* newNode = new HashNode(value); // 创建新节点

        if (elements[index] == nullptr) {
            elements[index] = newNode; // 若索引位置为空，则直接插入新节点
        } else {
            HashNode* currentNode = elements[index];
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next; // 找到链表的最后一个节点
            }
            currentNode->next = newNode; // 将新节点连接到链表的末尾
        }
        
        mysize++; // 更新集合大小

        if (static_cast<double>(mysize) / capacity > 0.7) {
            rehash(); // 若负载因子超过阈值(0.7)，则进行重新哈希
        }
    }

    void clear() {
        for (int i = 0; i < capacity; i++) {
            HashNode* currentNode = elements[i];
            while (currentNode != nullptr) {
                HashNode* temp = currentNode;
                currentNode = currentNode->next;
                delete temp; // 释放链表的每个节点的内存
            }
            elements[i] = nullptr; // 将数组中的每个元素置为空指针
        }

        mysize = 0; // 更新集合大小
    }

    bool contains(int value) const {
        int index = getIndexOf(value); // 获取元素对应的索引

        HashNode* currentNode = elements[index];
        while (currentNode != nullptr) {
            if (currentNode->value == value) {
                return true; // 若找到值，则返回true
            }
            currentNode = currentNode->next;
        }

        return false; // 若未找到值，则返回false
    }

private:
    HashNode** elements; // 指向指针的指针
    int mysize;
    int capacity;

    int getIndexOf(int value) const {
        return value % capacity; // 使用取余运算得到索引
    }

    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2; // 扩大容量为原来的两倍

        HashNode** newElements = new HashNode*[capacity](); // 创建新的指针数组，并将每个元素初始化为nullptr

        for (int i = 0; i < oldCapacity; i++) {
            HashNode* currentNode = elements[i];
            while (currentNode != nullptr) {
                HashNode* nextNode = currentNode->next;
                int newIndex = getIndexOf(currentNode->value); // 重新计算元素的索引
                currentNode->next = newElements[newIndex]; // 将节点连接到新的索引位置
                newElements[newIndex] = currentNode;
                currentNode = nextNode;
            }
        }

        delete[] elements; // 删除旧的指针数组
        elements = newElements; // 更新指针数组
    }
};

````

```c++
class HashSet {
public:
    HashSet();

    ~HashSet();

    void add(int value);

    void clear();

    bool contains(int value) const;

private:
    HashNode **elements; // an array of HashNode* (an array of pointers!) int mysize;
    int capacity;

    int getIndexOf(int value) const;

    void rehash();
};

// Initialize our member variables in the constructor
HashSet::HashSet() {
    capacity = 10;
    mysize = 0;
    elements = new HashNode *[capacity](); // all are initialized to nullptr using ()
}

// Private helper for calculating the bucket of a given a value
int HashSet::getIndexOf(int value) const {
    return hash(value) % capacity;
}

// Check if a value is inside our set
bool HashSet::contains(int value) const {
    HashNode *curr = elements[getIndexOf(value)];
    while (curr != nullptr) {
        if (curr->data == value) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

HashSet::~HashSet() {
    clear(); // Remove all elements delete[] elements; // Also delete the array itself
}

// Remove all elements in our set so all buckets in our array are nullptr
void HashSet::clear() {
    for (int i = 0; i < capacity; i++) {
        // free list in bucket i
        while (elements[i] != nullptr) {
            HashNode *curListNode = elements[i];
            elements[i] = elements[i]->next;
            delete curListNode;
        }
    }
    mysize = 0;
}

void HashSet::rehash() {
    HashNode **oldElements = elements;
    int oldCapacity = capacity;
    capacity *= 2;
    elements = new HashNode *[capacity]();
    for (int i = 0; i < oldCapacity; i++) {
        HashNode *curr = oldElements[i];
        while (curr != nullptr) { // iterate over old bucket
            HashNode *prev = curr;
            curr = curr->next; // don’t lose access to rest of old bucket
            int newBucket = getIndexOf(prev->data);
            prev->next = elements[newBucket]; // put prev node at front of new bucket elements[newBucket] = prev; // update new bucket pointer
        }
    }
    delete[] oldElements;
}

// Add a given value to our set
void HashSet::add(int value) {
    if (!contains(value)) {
        int bucket = getIndexOf(value);
// insert at the front of the list in that bucket elements[bucket] = new HashNode(value, elements[bucket]); mysize++;
    }
    if (mysize / capacity >= 2) {
        rehash();
    }
}
```

