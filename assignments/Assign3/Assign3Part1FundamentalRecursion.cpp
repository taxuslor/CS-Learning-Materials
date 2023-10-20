/* CS106B Assign3: Recursive Problem Solving
 * Part1: Fundamental Recursion
 * The first collection of recursive problems walks you through some fundamental recursion problems
 * that increase in difficulty and complexity over time.
 * These problems will serve as the foundational practice for you
 * to begin to grapple with the core tenants of recursive problem-solving.
 */

#include <iostream>
#include <queue>

using namespace std;

// Segment1: Balanced Operators
string operatorsOnly(string str);

bool checkOperators(string ops);

/* The function isBalanced given below takes a string str of text
 * and returns true or false to report whether the bracketing operators in str are balanced.
 * The function first extracts the operator characters from str
 * using the function operatorsOnly and then checks that
 * those operators are balanced using the function checkOperators.
 * */
bool isBalanced(string str) {
    string ops = operatorsOnly(str);
    return checkOperators(ops);
}

/* The operatorsOnly function returns a string consisting of only the bracketing characters from str.
 * You implemented some similar string cleaning code for the first two assignments,
 * but in those situations you processed the string using an iterative loop.
 * This time we want you to take a recursive approach to get practice with recursive problem-solving.
 * In particular, you can think of approaching this problem in a similar way to
 * what we saw in lecture with the reverse function. Processing the string can be divided into two steps:
 * Process the first character of the string and determine how (if at all) it should be kept as part of the output.
 * Recursively process the rest of the string
 */
string operatorsOnly(string str) {
    if (str.empty()) return "";
    if (str.front() == '(' || str.front() == ')' || str.front() == '[' || str.front() == ']' || str.front() == '{' ||
        str.front() == '}') {
        return str.front() + operatorsOnly(str.substr(1));
    } else {
        return operatorsOnly(str.substr(1));
    }
}

/* Next up is the checkOperators function which is also to be implemented recursively.
 * To help get you starter, consider the following recursive insight about how to approach this problem.
 * A string consisting of only bracketing characters is balanced if and only if
 * one of the following conditions holds:
 * The string is empty.
 * The string contains "()", "[]", or "{}" as a substring and
 * the rest of the string is balanced after removing that substring.
 */
bool checkOperators(string ops) {
    if (ops.empty()) return true;
    ::size_t foundParentheses = ops.find("()");
    if (foundParentheses != string::npos) {
        return checkOperators(ops.erase(foundParentheses, 2));
    }
    ::size_t foundBrackets = ops.find("[]");
    if (foundBrackets != string::npos) {
        return checkOperators(ops.erase(foundBrackets, 2));
    }
    ::size_t foundBraces = ops.find("{}");
    if (foundBraces != string::npos) {
        return checkOperators(ops.erase(foundBraces, 2));
    }
    return false;
}

void test1() {
    string testcase;
    while (getline(cin, testcase)) {
        if (isBalanced(testcase)) {
            cout << "Operators Balanced." << endl;
        } else {
            cout << "Operators Unbalanced." << endl;
        }
    }
}

// Segment2: Merge
// Binary Merge
queue<int> merge(queue<int> one, queue<int> two) {
    queue<int> merged;
    while (!one.empty() && !two.empty()) {
        if (one.front() <= two.front()) {
            merged.push(one.front());
            one.pop();
        } else {
            merged.push(two.front());
            two.pop();
        }
    }
    while (!one.empty()) {
        merged.push(one.front());
        one.pop();
    }
    while (!two.empty()) {
        merged.push(two.front());
        two.pop();
    }
    return merged;
}

// Multiway merge (k-way merge)
queue<int> multiMerge(vector<queue<int>> &all) {
    queue<int> result;
    for (queue<int> q: all) {
        result = merge(q, result);
    }
    return result;
}

// Divide and conquer to the rescue
/* The recursive component of the strategy for recMultiMerge has the following important steps:
 * Divide the vector of k sequences (queues) into two halves. The "left" half is the first k/2 sequences (queues) in the vector,
 * and the "right" half is the rest of the sequences (queues).
 * The Vector subList operation can be used to subdivide a Vector, which you may find helpful.
 * Make a recursive call to recMultiMerge on the "left" half of the sequences to generate one combined, sorted sequence.
 * Then, do the same for the "right" half of the sequences, generating a second combined, sorted sequence.
 * Use your binary merge function to join the two combined sequences into the final result sequence,
 * which is then returned.
 */
queue<int> recMultiMerge(vector<queue<int>> &all) {
    if (all.size() > 2) {
        vector<queue<int>> vec1(all.begin(), all.begin() + all.size() / 2);
        vector<queue<int>> vec2(all.begin() + all.size() / 2, all.end());
        return merge(recMultiMerge(vec1), recMultiMerge(vec2));
    } else if (all.size() == 2) {
        return merge(all.front(), all.back());
    } else {
        return all.front();
    }
}

void test2() {
    queue<int> zero, one, two, three, four, five;
    vector<queue<int>> all;
    one.push(1);
    one.push(5);
    two.push(2);
    two.push(6);
    three.push(3);
    three.push(7);
    four.push(4);
    four.push(8);
    all.push_back(zero);
    all.push_back(one);
    all.push_back(two);
    all.push_back(three);
    all.push_back(four);
    five = recMultiMerge(all);
    while (!five.empty()) {
        cout << five.front() << " ";
        five.pop();
    }
    cout << endl;
}

int main() {
    //test1();
    test2();
}
