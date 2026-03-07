# vector

## 基础概念

### 什么是 vector

`vector` 是 C++ STL（标准模板库）中的 **动态数组**。
 它和普通数组类似，但有一个重要特点：**可以自动扩容**。

特点：

- 支持 **随机访问 O(1)**
- 尾部插入删除 **O(1)**
- 中间插入删除 **O(n)**
- 自动管理内存

```cpp
#include <vector>
using namespace std;
```

### vector常见初始化

#### 空 vector

```cpp
vector<int> v;
```

#### 指定大小

```cpp
vector<int> v(5);
```

结果：

```cpp
[0,0,0,0,0]
```

#### 指定大小和初始值

```cpp
vector<int> v(5, 10);
```

结果：

```cpp
[10,10,10,10,10]
```

#### 用数组初始化

```cpp
int arr[] = {1,2,3,4};
vector<int> v(arr, arr + 4);
```

#### 用列表初始化

LeetCode中非常常见

```cpp
vector<int> v = {1,2,3,4};
```

二维 vector：

```cpp
vector<vector<int>> grid(3, vector<int>(4, 0));
```

表示

```cpp
3行4列
全部初始化为0
```

### vector 的基本操作

#### 插入元素

尾部插入

```cpp
v.push_back(5);
```

例：

```cpp
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
```

结果：

```cpp
[1,2,3]
```

#### 删除尾部元素

```cpp
v.pop_back();
```

例：

```cpp
[1,2,3]
pop_back()
```

结果

```cpp
[1,2]
```

#### 插入指定位置

```cpp
v.insert(v.begin()+1, 100);
```

例：

```cpp
[1,2,3]
```

插入后

```cpp
[1,100,2,3]
```

###  访问元素

#### 下标访问

```
v[i]
```

例：

```
cout << v[0];
```

时间复杂度 **O(1)**

#### at()

```
v.at(i)
```

区别：

- `at()` 会进行 **越界检查**
- `[]` 不会

#### 第一个元素

```
v.front()
```

#### 最后一个元素

```
v.back()
```

### vector 的大小和状态

#### 获取大小

```
v.size()
```

#### 判断是否为空

```
v.empty()
```

例：

```
if(v.empty())
```

#### 改变大小

```
v.resize(10);
```

如果变大，会补0。

指定值：

```
v.resize(10, 5);
```

### vector 遍历方式

#### 下标遍历（最常见）

```cpp
for(int i = 0; i < v.size(); i++)
{
    cout << v[i];
}
```

LeetCode最常用写法。

#### range-based for

```cpp
for(int x : v)
{
    cout << x;
}
```

如果需要修改：

```cpp
for(int &x : v)
{
    x += 1;
}
```

#### 迭代器

```cpp
for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
{
    cout << *it;
}
```

简写：

```cpp
for(auto it = v.begin(); it != v.end(); it++)
{
    cout << *it;
}
```

### vector 排序

需要：

```
#include <algorithm>
```

#### 升序排序

```cpp
sort(v.begin(), v.end());
```

例：

```
[3,1,5,2]
```

排序后：

```
[1,2,3,5]
```

#### 降序排序

```
sort(v.begin(), v.end(), greater<int>());
```

结果：

```
[5,3,2,1]
```

### vector 查找

#### 查找某个元素

```
find(v.begin(), v.end(), 3);
```

例：

```
auto it = find(v.begin(), v.end(), 3);
```

如果找到：

```
it != v.end()
```

获取下标：

```
int index = it - v.begin();
```

### vector 反转

```
reverse(v.begin(), v.end());
```

例：

```
[1,2,3,4]
```

变成

```
[4,3,2,1]
```

### 技巧

#### 技巧1：二维 vector

LeetCode常见：

```
vector<vector<int>> ans;
```

插入一行：

```
ans.push_back({1,2,3});
```

或

```
vector<int> row = {1,2,3};
ans.push_back(row);
```

#### 技巧2：vector 当作栈

```cpp
vector<int> stack;
```

入栈

```cpp
stack.push_back(x);
```

出栈

```cpp
stack.pop_back();
```

栈顶

```cpp
stack.back();
```

#### 技巧3：vector 统计频率

```cpp
vector<int> count(26,0);
```

统计字符：

```cpp
count[c - 'a']++
```