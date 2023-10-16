# CS106B: Abstract Data Type

## Ordered Data Structures

## Vectors

### Definition:

At a high level, a vector is an ordered collection of elements of the same type that can grow and shrink in size.

- Each element in the collection has a specific location, or index
- All elements in a vector must be of the same type. Unlike in other programming languages, a single vector cannot contain elements of mixed types.
- Vectors are flexible when it comes to the number of elements they can store. You can easily add and remove elements from a vector. Vectors also know their size, meaning you can query[^](ask a question about something, especially in order to express one's doubts about it or to check its validity or accuracy.) them to see how many elements they currently contain.

### Basic Operations:

- 创建vector对象：

`````C++
vector<int> v; //创建一个空的vector对象
vector<int> v2(10); //创建一个大小为10的vector对象
`````

- 添加元素：

```C++
v.push_back(1); //在v末尾添加元素1
v.push_back(2); //在v末尾添加元素2
v.insert(v.begin(), 0); //在v的开头添加元素0	
```

- 访问元素：

```C++
cout << v[0] << endl; //输出第一个元素
cout << v.at(1) << endl; //输出第二个元素
```

- 获取vector大小：

``` C++
cout << v.size() << endl; //输出v中元素的个数
```

- 删除元素：

```C++
v.pop_back(); //删除末尾的一个元素
v.erase(v.begin()+1); //删除第二个元素
```

- 清空元素：

```C++
v.clear(); //清空v中所有元素
```

- 对元素进行排序：

```C++
sort(v.begin(), v.end()); //升序排序
sort(v.begin(), v.end(), greater<int>()); //降序排序
```

## Grids

### Definition:

A 2D array, defined with a particular width and height. Useful for spreadsheets, game boards, etc.

### Basic Operations:

- 声明矩阵

```C++
// 声明一个3x3的int类型矩阵
int grid[3][3];

// 声明一个5x5的vector<int>类型矩阵
vector<vector<int>> grid(5, vector<int>(5));
```

- 遍历矩阵

```C++
// 遍历一个3x3的int类型矩阵
int grid[3][3] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};
for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        cout << grid[i][j] << " ";
    }
    cout << endl;
}

// 遍历一个vector<vector<int>>类型矩阵
vector<vector<int>> grid(3, vector<int>(3));
for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[i].size(); j++) {
        cout << grid[i][j] << " ";
    }
    cout << endl;
}
```

- 访问矩阵

```C++
// 赋值操作
int grid[3][3];
grid[0][0] = 1;

// 取值操作
int x = grid[0][0];

// 赋值操作
vector<vector<int>> grid(3, vector<int>(3));
grid[0][0] = 1;

// 取值操作
int x = grid[0][0];
```

- 初始矩阵

```C++
// 初始化为0
int grid[3][3] = {0};

// 初始化为指定的值
int grid[3][3] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};

// 使用函数对象初始化
int grid[3][3];
int index = 0;
for_each(begin(grid), end(grid), [&index](auto& row) {
    std::iota(begin(row), end(row), index);
    index += row.size();
});

// 初始化为0
vector<vector<int>> grid(3, vector<int>(3, 0));

// 初始化为指定的值
vector<vector<int>> grid = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

// 使用函数对象初始化
vector<vector<int>> grid(3, vector<int>(3));
int index = 0;
for_each(begin(grid), end(grid), [&index](auto& row) {
    std::iota(begin(row), end(row), index);
    index += row.size();
});
```

- 转置矩阵

```C++
// 将3x3的矩阵按照主对角线进行转置
int grid[3][3] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};
for(int i = 0; i < 3; i++) {
    for(int j = i+1; j < 3; j++) {
        swap(grid[i][j], grid[j][i]);
    }
}

// 将vector<vector<int>>类型的矩阵进行转置
vector<vector<int>> grid(3, vector<int>(3));
for(int i = 0; i < grid.size(); i++) {
    for(int j = i+1; j < grid[i].size(); j++) {
        swap(grid[i][j], grid[j][i]);
    }
}
```

- 翻转矩阵

```C++
// 将3x3的矩阵按照水平方向进行翻转
int grid[3][3] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};
for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 1.5*3; j++) {
        swap(grid[i][j], grid[i][2-j]);
    }
}

// 将vector<vector<int>>类型的矩阵按照垂直方向进行翻转
vector<vector<int>> grid(3, vector<int>(3));
for(int i = 0; i < 1.5*grid.size(); i++) {
    for(int j = 0; j < grid[i].size(); j++) {
        swap(grid[i][j], grid[2-i][j]);
    }
}
```

## Queue

### Definition:

- First person In is the First person Out (FIFO) 
  When you remove (dequeue) people from the queue, you remove them from the front of the line.
- Last person in is the last person served
  When you insert (enqueue) people into a queue, you insert them at the back (the end of the line).

### Basic Operations:

- `push()`: 入队操作，将一个元素添加到队列的尾部

- `pop()`: 出队操作，将队列头的元素移除

- `front()`: 访问队列头的元素

- `back()`: 访问队列尾的元素

- `empty()`: 判断队列是否为空，如果队列为空则返回true，否则返回false

- `size()`: 返回队列中元素的个数

```C++
#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 创建一个空队列
    queue<int> q;

    // 入队操作
    q.push(10);
    q.push(20);
    q.push(30);

    // 访问队列头和尾的元素
    cout << "队列头的元素是：" << q.front() << endl;
    cout << "队列尾的元素是：" << q.back() << endl;

    // 出队操作
    q.pop();

    // 访问队列头的元素
    cout << "出队后，队列头的元素是：" << q.front() << endl;

    // 遍历队列中的元素
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // 测试size()方法
    cout << "队列中元素的个数是：" << q.size() << endl;

    return 0;
}
```

## Stack

### Definiton:

- Only the top element in a stack is accessible. The Last item In is the First one Out. (LIFO)
- The push, pop, and top operations are the only operations allowed by the stack ADT.

### Basic Operations:

- `push()`: 入栈操作，将一个元素添加到栈顶
- `pop()`: 出栈操作，将栈顶的元素移除
- `top()`: 访问栈顶的元素，但并不将其移除
- `empty()`: 判断栈是否为空，如果栈为空则返回true，否则返回false
- `size()`: 返回栈中元素的个数

```C++
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // 创建一个空栈
    stack<int> s;

    // 入栈操作
    s.push(10);
    s.push(20);
    s.push(30);

    // 访问栈顶的元素
    cout << "栈顶的元素是：" << s.top() << endl;

    // 出栈操作
    s.pop();

    // 访问栈顶的元素
    cout << "出栈后，栈顶的元素是：" << s.top() << endl;

    // 遍历栈中的元素
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // 测试size()方法
    cout << "栈中元素的个数是：" << s.size() << endl;

    return 0;
}
```

## Unordered Data Structures

## Sets

### Definition

- A set is a collection of elements with no duplicates.
- Sets are faster than ordered data structures like vectors – since there are no duplicates, it’s faster for them to find things.

### Basic Operations:

- `insert()`: 插入一个元素到set中
- `erase()`: 从set中删除指定元素或范围内的元素
- `find()`: 查找set中是否存在指定元素，如果存在则返回该元素的迭代器，否则返回set::end()
- `empty()`: 判断set是否为空，如果为空则返回true，否则返回false
- `size()`: 返回set中元素的个数
- `clear()`: 清空set中所有元素

```C++
#include <iostream>
#include <set>

using namespace std;

int main() {
    // 创建一个空set
    set<int> s;

    // 插入元素
    s.insert(10);
    s.insert(20);
    s.insert(30);

    // 查找元素
    set<int>::iterator it = s.find(20);
    if(it != s.end()) {
        cout << "元素20在set中" << endl;
    } else {
        cout << "元素20不在set中" << endl;
    }

    // 删除元素
    s.erase(20);

    // 遍历set中的元素
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 测试size()和empty()方法
    cout << "set中元素的个数是：" << s.size() << endl;
    cout << "set是否为空：" << (s.empty() ? "是" : "否") << endl;

    // 清空set
    s.clear();
    cout << "set中元素的个数是：" << s.size() << endl;

    return 0;
}
```

## Maps

### Definition

- A map is a collection of key/value pairs, and the key is used to quickly find the value.
- A map is an alternative to an ordered data structure, where the “indices” no longer need to be integers.

### Basic Operations:

- `insert()`: 插入一个键值对到map中
- `erase()`: 从map中删除指定键或范围内的键值对
- `find()`: 查找map中是否存在指定键，如果存在则返回该键的迭代器，否则返回map::end()
- `operator[]`: 访问map中的值，如果键不存在则会自动添加并设置为默认值
- `size()`: 返回map中键值对的个数
- `empty()`: 判断map是否为空，如果为空则返回true，否则返回false
- `clear()`: 清空map中所有键值对

```C++
#include <iostream>
#include <map>

using namespace std;

int main() {
    // 创建一个空map
    map<string, int> m;

    // 插入元素
    m.insert(make_pair("Alice", 21));
    m.insert(make_pair("Bob", 22));
    m.insert(make_pair("Charlie", 23));

    // 查找元素
    map<string, int>::iterator it = m.find("Bob");
    if(it != m.end()) {
        cout << "Bob的年龄是：" << it->second << endl;
    } else {
        cout << "没有找到Bob" << endl;
    }

    // 访问map中的值
    cout << "Alice的年龄是：" << m["Alice"] << endl;

    // 删除元素
    m.erase("Charlie");

    // 遍历map中的键值对
    for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << "的年龄是：" << it->second << endl;
    }

    // 测试size()和empty()方法
    cout << "map中键值对的个数是：" << m.size() << endl;
    cout << "map是否为空：" << (m.empty() ? "是" : "否") << endl;

    // 清空map
    m.clear();
    cout << "map中键值对的个数是：" << m.size() << endl;

    return 0;
}
```
