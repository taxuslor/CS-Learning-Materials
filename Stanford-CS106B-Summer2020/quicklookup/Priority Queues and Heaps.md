# CS106B: Priority Queues and Heaps

## Priority Queues

- A queue that orders its elements based on a provided "priority"
- Like regular queues, you cannot index into them to get an item at a particular position
- Useful for maintaining data sorted on priorities 

### Three fundamental operations

````c++
1.enqueue(priority,elem):inserts elem with given priority
2.dequeue():removes the element with the highest priority from the queue
3.peek():returns the element with the highest priority in the queue without removing it
````

### Less fundamental operations

```c++
1.size():returns the number of elements in the queue
2.isEmpty():returns true if there are no elements in the queue ,false otherwise 
3.clear():empties the queue
```

## Binary Heaps

- A heap is a tree-based structure that satisfies the heap property that parents have a higher priority than any of their children
- Additional properties
  - Binary: Two children per parent( but no implied orderings between siblings)
  - Completely filled( each parents must have 2 children) except for the bottom level, which gets populated from left to right
- Two types depends on what we define as a "higher" priority
  - Min-heap: smaller numbers = higher priority( closer to the root)
  - Max-heap: larger numbers = higher priority( closer to the root)

## Example

````C++
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class BinaryHeap {
private:
    vector<int> heap;
    unordered_map<int, int> indexMap;

    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index) {
        return 2 * index + 1;
    }

    int getRightChildIndex(int index) {
        return 2 * index + 2;
    }

    void heapifyUp(int index) {
        if (index == 0)
            return;

        int parentIndex = getParentIndex(index);
        if (heap[parentIndex] > heap[index]) {
            swap(heap[parentIndex], heap[index]);
            updateIndexMap(parentIndex, index);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);

        int smallestIndex = index;
        if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallestIndex])
            smallestIndex = leftChildIndex;

        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallestIndex])
            smallestIndex = rightChildIndex;

        if (smallestIndex != index) {
            swap(heap[index], heap[smallestIndex]);
            updateIndexMap(index, smallestIndex);
            heapifyDown(smallestIndex);
        }
    }

    void updateIndexMap(int oldIndex, int newIndex) {
        indexMap[heap[oldIndex]] = newIndex;
        indexMap[heap[newIndex]] = oldIndex;
    }

public:
    void insert(int value) {
        heap.push_back(value);

        int index = heap.size() - 1;
        indexMap[value] = index;

        heapifyUp(index);
    }

    void remove(int value) {
        if (indexMap.find(value) == indexMap.end()) {
            cerr << "Element not found!" << endl;
            return;
        }

        int index = indexMap[value];
        heap[index] = INT_MIN;

        heapifyUp(index);
        extractMin();
    }

    void updatePriority(int value, int newPriority) {
        if (indexMap.find(value) == indexMap.end()) {
            cerr << "Element not found!" << endl;
            return;
        }

        int index = indexMap[value];
        heap[index] = newPriority;

        if (newPriority < value)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    int extractMin() {
        if (heap.empty()) {
            cerr << "Heap is empty!" << endl;
            return -1; // or throw an exception
        }

        int min = heap[0];

        indexMap.erase(heap[0]);

        heap[0] = heap.back();
        heap.pop_back();

        indexMap[heap[0]] = 0;

        heapifyDown(0);

        return min;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    BinaryHeap heap;

    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);
    heap.insert(8);

    cout << "Extracting elements in ascending order: ";
    while (!heap.isEmpty()) {
        int min = heap.extractMin();
        cout << min << " ";
    }
    cout << endl;

    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);
    heap.insert(8);

    heap.remove(7);

    cout << "Modified heap: ";
    while (!heap.isEmpty()) {
        int min = heap.extractMin();
        cout << min << " ";
    }
    cout << endl;

    return 0;
}
````

