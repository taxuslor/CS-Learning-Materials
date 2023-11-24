# CS106B: Using ADTs

## Counting Sort

### Code:

```C++
#include <iostream>
#include <map>
#include <string>

int main() {
    // 初始化一个 map 容器 alpha_number，用于记录字符串中每个字符出现的次数
    std::map<char, int> alpha_number;

    // 待排序的字符串
    std::string theWord = "banana";

    // 遍历字符串，统计字符出现次数
    for (int i = 0; i < theWord.size(); ++i) {
        auto it = alpha_number.find(theWord[i]);
        if (it != alpha_number.end()) {
            alpha_number[theWord[i]]++;
        } else {
            alpha_number.insert(std::make_pair(theWord[i], 1));
        }
    }

    // 对字符按出现次数从少到多排序
    std::string sortedString = "";
    for (const auto& [ch, cnt]: alpha_number) {
        for (int i = 0; i < cnt; ++i) {
            sortedString.push_back(ch);
        }
    }

    // 输出排序结果
    if (sortedString.empty()) {
        std::cout << "字符串为空！" << std::endl;
    } else {
        for (char a: sortedString) {
            std::cout << a;
        }
        std::cout << std::endl;
    }

    return 0;
```

## Breadth-First Search(BFS)

### BFS Example

- Based on "Word Ladder": 
- What's the simplest possible word ladder we could find? 
  If the words are only one letter different from one another (pig and fig), then finding the word ladder is relatively easy – we look at all words that are one letter away from the current word. 
- What's the next simplest possible word ladder we could find? 
  If the word ladder requires two steps, then we can break down the problem into the problem of exploring one step away from all the words that are one step away from the starting word.
- Important observation: In order to keep our search organized, we first explore all word ladders of "length" 1 before we explore any word ladders of "length" 2, and so on.


### Formalizing BFS

We need...

- A data structure to represent (partial word) ladders
  Desired characteristics: We should be able to easily access the most recent word added to the word ladder.
  *** Stack<string>***

- A data structure to store all the partial word ladders that we have generated so far and have yet to explore
  Desired characteristics: We want to maintain an ordering of ladders such that all ladders of a certain length get explored before ladders of longer length get explored.

  ***Queue<Stack<string>>***

- A data structure to keep track of all the words that we've explored so far, so that we avoid getting stuck in loops
  Desired characteristics: We want to be able to quickly decide whether or not a word has been seen before. 
  ***Set<string>***

### Code:

- One possible code

```C++
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

// 函数定义：用于求解从beginWord到endWord的最短路径
vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // 定义哈希表来存储wordList，方便后续查询是否包含某个单词
    unordered_set<string> dict(wordList.begin(), wordList.end());
    // 如果输入的endWord不在dict中，则无法构成路径，返回空vector
    if (!dict.count(endWord)) return {};
    // 定义栈、队列和visited哈希表（访问过的节点）
    stack<string> s;
    Queue<stack<string>> q;
    // 将起点加入栈，并将该栈加入队列，表示从起点开始的路径
    s.push(beginWord);
    q.push(s);
    unordered_set<string> visited;
    // 开始BFS搜索
    while (!q.empty()) {
        // 获取当前队列中所有的元素（即这一层可以到达的所有单词）
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            // 取出队列中的第一个元素（也就是当前路径）
            stack<string> path = q.front();
            q.pop();
            // 获取该路径上的最后一个单词，作为当前要扩展的单词
            string word = path.top();
            // 枚举当前单词的所有相邻单词
            for (int j = 0; j < word.size(); ++j) {
                char tmp = word[j];
                for (char k = 'a'; k <= 'z'; ++k) {
                    if (k == tmp) continue;
                    word[j] = k;
                    // 如果在字典中找到了该相邻单词，且该单词没有被访问过，则将其加入队列进行扩展
                    if (dict.count(word)) {
                        if (!visited.count(word)) {
                            // 复制当前路径，添加新节点
                            stack<string> newPath = path;
                            newPath.push(word);
                            // 如果找到了终点单词，直接返回答案
                            if (word == endWord) {
                                vector<string> result;
                                while (!newPath.empty()) {
                                    result.push_back(newPath.top());
                                    newPath.pop();
                                }
                                return result;
                            }
                            // 记录该单词已被访问过，并将它加入队列等待后续扩展
                            visited.insert(word);
                            q.push(newPath);
                        }
                    }
                }
                word[j] = tmp; // 恢复该位置上原有的字符，以便枚举下一个相邻单词
            }
        }
    }
    // BFS搜索结束后，如果没有找到合法路径，返回空vector
    return {};
}

// 主函数用于测试上面的findLadders函数
int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    auto result = findLadders(beginWord, endWord, wordList);
    if (result.empty()) {
        cout << "Cannot find a path from " << beginWord << " to " << endWord << endl;
    } else {
        cout << "The shortest path from " << beginWord << " to " << endWord << " is:" << endl;
        for (const auto& s : result) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
```

- Another code:

```C++
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// 函数定义：用于求解从beginWord到endWord的最短路径
vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // 定义哈希表来存储wordList，方便后续查询是否包含某个单词
    unordered_set<string> dict(wordList.begin(), wordList.end());
    // 如果输入的endWord不在dict中，则无法构成路径，返回空vector
    if (!dict.count(endWord)) return {};

    // 定义队列和visited哈希表（访问过的节点）
    queue<vector<string>> q;
    // 将起点加入队列，并创建一个只有beginWord的单词列表作为初始路径
    q.push({beginWord});
    // unordered_set记录从起点开始已经遍历过的单词
    unordered_set<string> visited;

    // 开始BFS搜索
    while (!q.empty()) {
        // 获取当前队列中所有的元素（即这一层可以到达的所有单词）
        int size = q.size();
        vefor (int i = 0; i < size; ++i) {
            // 取出队列中的第一个元素（也就是当前路径）
            vector<string> path = q.front();
            q.pop();
            // 获取该路径上的最后一个单词，作为当前要扩展的单词
            cstring word = path.back();
            // 枚举当前单词的所有相邻单词
            for (int j = 0; j < word.size(); ++j) {
                char tmp = word[j];
                infor (char k = 'a'; k <= 'z'; ++k) {
                    if (k == tmp) continue;
                    word[j] = k;
                    // 如果在字典中找到了该相邻单词，且该单词没有被访问过，则将其加入队列进行扩展
                    if (dict.count(word)) {
                        if (!visited.count(word)) {
                            // 复制当前路径，添加新节点
                            vector<string> newPath = path;
                            newPath.push_back(word);
                            // 如果找到了终点单词，直接返回答案
                            if (word == endWord) return newPath;
                            // 记录该单词已被访问过，并将它加入队列等待后续扩展
                            visited.insert(word);
                            q.push(newPath);
                        }
                    }
                }
                word[j] = tmp; // 恢复该位置上原有的字符，以便枚举下一个相邻单词
            }
        }
    }
    // BFS搜索结束后，如果没有找到合法路径，返回空vector
    return {};
}

// 主函数用于测试上面的findLadders函数
int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    auto result = findLadders(beginWord, endWord, wordList);
    if (result.empty()) {
        cout << "Cannot find a path from " << beginWord << " to " << endWord << endl;
    } else {
        cout << "The shortest path from " << beginWord << " to " << endWord << " is:" << endl;
        for (const auto& s : result) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## Nested Data Structures

### Summary

- Powerful
  - Can express highly structured and complex data
  - Used in many real-world systems
- Tricky
  - With increased complexity comes increased cognitive load in differentiating between the levels of information stored at each level of the nesting
  - Specifically in C++, working with nested data structures can be tricky due to the fact that references and copies show up at different points in time. Follow the correct paradigms presented earlier to stay on track!
