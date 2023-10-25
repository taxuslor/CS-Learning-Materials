/* CS106B Assign5: Linked Lists
 * Part2: Sorting Linked Lists
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode *getTail(ListNode *list) {
        while (list && list->next) {
            list = list->next;
        }
        return list;
    }
};

// Segment1: MergeSort
/* Work on mergeSort:
 * First write and thoroughly test the split helper function.
 * Then write and thoroughly test the merge helper function.
 * Put everything together in mergeSort, and write a comprehensive set of test cases for your overall function.
 */
void split(ListNode *&list, ListNode *&left, ListNode *&right) {
    int num = 0, cnt = 0;
    ListNode *node = list, *temp;
    while (node != nullptr) {
        num++;
        node = node->next;
    }
    node = list;
    left = list;
    temp = left;
    while (cnt < (num + 1) / 2) {
        temp->next = node->next;
        temp = temp->next;
        if (cnt == (num + 1) / 2) {
            right = node;
            temp->next = nullptr;
        }
        node = node->next;
        cnt++;
    }
}

void merge(ListNode *&list, ListNode *&left, ListNode *&right) {
    ListNode *temp, *cur;
    int cnt_l = 0, cnt_r = 0;
    temp = left;
    while (temp != nullptr) {
        cnt_l++;
        temp = temp->next;
    }
    temp = right;
    while (temp != nullptr) {
        cnt_r++;
        temp = temp->next;
    }
    int i = 0, j = 0;
    while (i < cnt_l && j < cnt_r) {
        if (left->val <= right->val) {
            if (list == nullptr) {
                list = left;
                cur = left;
            } else {
                cur->next = left;
                cur = cur->next;
            }
            left = left->next;
            i++;
        } else {
            if (list == nullptr) {
                list = right;
                cur = right;
            } else {
                cur->next = right;
                cur = cur->next;
            }
            right = right->next;
            j++;
        }
    }
    while (i < cnt_l) {
        cur->next = left;
        cur = cur->next;
        left = left->next;
        i++;
    }
    while (j < cnt_r) {
        cur->next = right;
        cur = cur->next;
        right = right->next;
        j++;
    }
}

void mergeSort(ListNode *&list) {
    if (list == nullptr || list->next == nullptr) {
        return;
    }
    ListNode *left, *right;
    split(list, left, right);
    mergeSort(left);
    mergeSort(right);
    list = nullptr;
    merge(list, left, right);
}

void test1() {
    ListNode *list = new ListNode(3);
    list->next = new ListNode(2);
    list->next->next = new ListNode(4);
    list->next->next->next = new ListNode(1);
    list->next->next->next->next = new ListNode(5);
    cout << "Before sorting: ";
    ListNode *temp = list;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    mergeSort(list);
    cout << "After sorting: ";
    temp = list;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Segment2: QuickSort
/* Work on quickSort:
 * First write and thoroughly test the partition helper function.
 * Then write and thoroughly test the concatenate helper function.
 * Put everything together in quickSort, and write a comprehensive set of test cases for your overall function.
 */
void partition(ListNode *&list, ListNode *&pivot, ListNode *&small, ListNode *&large) {
    ListNode *cur = list->next;
    ListNode *tailSmall = nullptr;
    ListNode *tailLarge = nullptr;
    while (cur) {
        ListNode *next = cur->next;
        if (cur->val < pivot->val) {
            if (!small) {
                small = cur;
                tailSmall = cur;
            } else {
                tailSmall->next = cur;
                tailSmall = cur;
            }
        } else {
            if (!large) {
                large = cur;
                tailLarge = cur;
            } else {
                tailLarge->next = cur;
                tailLarge = cur;
            }
        }
        cur->next = nullptr;
        cur = next;
    }
}

void concatenate(ListNode *&list, ListNode *pivot, ListNode *small, ListNode *large) {
    ListNode *tail = nullptr;
    if (small) {
        list = small;
        tail = small->getTail(small);
        tail->next = pivot;
    } else {
        list = pivot;
    }
    if (large) {
        if (tail) {
            tail->next = large;
        } else {
            list = large;
        }
    }
}

void quickSort(ListNode *&list) {
    if (!list || !list->next) {
        return;
    }
    ListNode *pivot = list;
    ListNode *small = nullptr;
    ListNode *large = nullptr;
    partition(list, pivot, small, large);
    quickSort(small);
    quickSort(large);
    concatenate(list, pivot, small, large);
}

void test2() {
    ListNode *list = new ListNode(3);
    list->next = new ListNode(2);
    list->next->next = new ListNode(4);
    list->next->next->next = new ListNode(1);
    list->next->next->next->next = new ListNode(5);
    cout << "Before sorting: ";
    ListNode *temp = list;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    quickSort(list);
    cout << "After sorting: ";
    temp = list;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    //test1();
    test2();
    return 0;
}
