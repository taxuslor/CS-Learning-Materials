# CS106B: String

## String Methods

- `size() / length()`: 返回字符串的长度

```C++
string str = "Hello world";
cout << str.size() << endl; // 输出: 11
cout << str.length() << endl; // 输出: 11
```

- `empty()`: 判断字符串是否为空

```C++
string str = "Hello";
if(str.empty()) {
    cout << "String is empty." << endl;
} else {
    cout << "String is not empty." << endl;
}
```

- `clear()`: 清空字符串

```C++
string str = "Hello";
str.clear(); // 清空字符串
cout << str << endl; // 输出一个空字符串
```

- `append() / push_back()`: 将字符串或字符添加到字符串末尾

```C++
string str = "Hello";
str.append(" world"); // 在末尾添加一个字符串
str.push_back('!'); // 在末尾添加一个字符
cout << str << endl; // 输出: "Hello world!"
```

- `insert()`: 在指定位置插入字符串或字符

```C++
string str = "Hello world";
str.insert(6, "C++ "); // 在索引位置6处插入一个字符串
cout << str << endl; // 输出: "Hello C++ world"
```

- `replace()`: 将指定范围内的子串替换为新的字符串

```C++
string str = "Hello world";
str.replace(0, 5, "Hi"); // 将前五个字符替换为"Hi"
cout << str << endl; // 输出: "Hi world"
```

- `substr()`: 截取子串

```C++
string str = "Hello world";
string substr = str.substr(6, 5); // 从索引位置6开始，截取长度为5的子串
cout << substr << endl; // 输出: "world"
```

- `find()` / `rfind()`: 在字符串中查找指定的子串，返回其首次/最后出现的位置

```C++
string str = "Hello world";
size_t pos = str.find("world"); // 在字符串中查找"world"子串的位置
if(pos != string::npos) {
    cout << "Found at position: " << pos << endl; // 输出: "Found at position: 6"
}
```

- `compare()`: 比较两个字符串是否相等，并返回比较结果

```C++
string str1 = "Hello";
string str2 = "hello";
if(str1.compare(str2) == 0) {
    cout << "Strings are equal." << endl;
} else {
    cout << "Strings are not equal." << endl;
}
```

- `c_str()`: 获取C风格字符串表示的字符串（const char *）

```C++
string str = "Hello";
const char *c_str = str.c_str(); // 获取C风格字符串表示的字符串
cout << c_str << endl; // 输出: "Hello"
```

- `at() / operator[]`: 获取指定位置的字符

```C++
string str = "Hello";
char ch1 = str.at(0); // 获取第一个字符
char ch2 = str[1]; // 获取第二个字符
cout << ch1 << ch2 << endl; // 输出: "He"
```

- `resize()`: 改变字符串的长度

```C++
string str = "Hello";
str.resize(3); // 将字符串长度改为3
cout << str << endl; // 输出: "Hel"
```

- `reserve()`: 预先分配字符串的存储空间

```C++
string str;
str.reserve(100); // 提前分配100个字符的存储空间
```

- `shrink_to_fit()`: 缩小字符串的存储空间，使其适应当前大小

```C++
string str = "Hello";
str.resize(3); // 改变字符串长度
str.shrink_to_fit(); // 缩小字符串的存储空间，使其适应当前大小
```

- `erase()`: 删除指定范围内的子串或单个字符

```C++
string str = "Hello world";
str.erase(6, 5); // 删除从索引位置6开始，长度为5的子串
cout << str << endl; // 输出: "Hello"
```



- `front() / back()`: 访问字符串的第一个/最后一个字符

```C++
string str = "Hello";
char ch1 = str.front(); // 获取第一个字符
char ch2 = str.back(); // 获取最后一个字符
cout << ch1 << ch2 << endl; // 输出: "Ho"
```

