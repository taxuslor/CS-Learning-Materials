# CS106B: Sorting

## Sorting

- Given a list of data points, sort those data points into ascending / descending order by some quantity.

## Selection Sort

- Find the smallest element and move it to the first position.
- Find the smallest element of what’s left and move it to the second position.
- Find the smallest element of what’s left and move it to the third position.
- Find the smallest element of what’s left and move it to the fourth position.
- (etc.)

````c++
void selectionSort(Vector<int>& elems) {
    for (int index = 0; index < elems.size(); index++) {
        int smallestIndex = indexOfSmallest(elems, index);
        swap(elems[index], elems[smallestIndex]);
    }
}

int indexOfSmallest(const Vector<int>& elems, int startPoint) {
    int smallestIndex = startPoint;
    for (int i = startPoint + 1; i < elems.size(); i++) {
        if (elems[i] < elems[smallestIndex]) {
            smallestIndex = i;
} }
    return smallestIndex;
}
````

### The complexity of selection sort

## Insertion sort

- Repeatedly insert an element into a sorted sequence at the front of the array.
- To insert an element, swap it backwards until either:
  - it’s bigger than the element before it, or
  - it’s at the front of the array.

```c++
void insertionSort(Vector& v) {
	for (int i = 0; i < v.size(); i++) {
		/* Scan backwards until either (1) the preceding
		* element is no bigger than us or (2) there is
		* no preceding element. */
		for (int j = i - 1; j >= 0; j--) {
			if (v[j] <= v[j + 1]) break;
			/* Swap this element back one step. */ 
      swap(v[j], v[j + 1]);
		} 
  }
}
```

## Divide-and-Conquer Sorting Algorithms

### General Divide-and-Conquer Approach

- Our general approach when designing a divide-and-conquer algorithm is to decide how to make the problem smaller and how to unify the results of these solved, smaller problems.
- Both sorting algorithms we explore today will have both of these components:
  - Divide Step: Make the problem smaller by splitting up the input list
  - Join Step: Unify the newly sorted sublists to build up the overall sorted result

## Merge Sort

- **Base Case:**
  - An empty or single-element list is already sorted.

- **Recursive step:**
  - Break the list in half and recursively sort each part. (easy divide)
  - Use merge to combine them back into a single sorted list (hard join)

```c++
// 合并两个有序数组
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // 创建临时数组
    int L[n1], R[n2];
    
    // 将数据复制到临时数组
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // 合并临时数组，并进行排序
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // 复制剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序主函数
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // 分割数组
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // 合并数组
        merge(arr, left, mid, right);
    }
}
```

## Quick Sort

1. **Partition** the elements into three categories based on a chosen **pivot** element:
   - Elements **smaller** than the pivot
   - Elements **equal** to the pivot
   - Elements **larger** than the pivot
2. **Recursively sort** the two partitions that are not equal to the pivot (smaller and larger elements).

3. **Concatenate** the three now-sorted partitions together.
