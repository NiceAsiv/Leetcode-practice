# C++与C

## 基础知识

C++源文件后缀名.cc/.cpp，头文件后缀名.hh/.hpp

编译c++源代码命令

```bash
g++ *.cc/.cpp [-o name]
```

### 命名空间

#### **为什么要有命名空间**

命名空间又称为名字空间，是程序员命名的内存区域，程序员根据需要指定一些有名字的空间域，把一些全局实体分别存放到各个命名空间中，从而与其他全局实体分隔开。通俗的说，每个名字空间都是一个名字空间域，存放在名字空间域中的全局实体只在本空间域内有效。名字空间对全局实体加以域的限制，从而合理的解决命名冲突。

在声明一个命名空间时，大括号内不仅可以存放变量，还可以存放以下类型：

变量、常量、函数、结构体、引用、类、对象、模板、命名空间等，它们都称为实体

#### 使用命名空间的三种方式

命名空间一共有三种使用方式，分别是using编译指令、作用域限定符、using声明机制

- using编译指令,其中std代表的是标准命令空间

  ```cpp
  #include <iostream>
  using namespace std;
  
  int main(int argc, char * argv[]){
      cout << "hello,world" << endl;
      return 0;
  }
  ```

  会造成名字冲突的案例,会报错 `error: reference to 'cout' is ambiguous`

  ```cpp
  #include <iostream>
  
  using namespace std;
  
  double cout()
  {
      return 3.14;
  }
  
  int main()
  {
      cout();
      return 0;
  }
  ```

- 作用域限定符

  每次要使用某个命名空间的实体时，都加上作用域限定符`::`，例如

  ```cpp
  #include <iostream>
  
  // using namespace std; 
  /* This line is commented out to avoid conflicts with the cout function defined below.
      If we were to use 'using namespace std;', 
      it would cause ambiguity between the standard 'cout' and our custom 'cout' function. 
  */
  
  double cout()
  {
      return 3.14;
  }
  
  int main()
  {
      std::cout << "The value of pi is: " << cout() << std::endl;
      return 0;
  }
  ```

- using声明机制

  using声明机制的作用域是从using语句开始，到using所在的作用域结束。要注意，在同一作用域内用using声明的不同的命名空间的成员不能有同名的成员，否则会发生重定义。

  ```cpp
  #include <iostream>
  using std::cout;
  using std::endl;
  namespace wd
  {
      int number = 10;
      void display()
      {
          cout << "wd::display()" << endl;
      }
  }//end of namespace wd
  using wd::number;
  using wd::display;
  int main(void)
  {
      cout << "wd::number = " << number << endl;
      wd::display();
  }
  ```

  

#### 匿名命名空间

命名空间还可以不定义名字，不定义名字的命名空间称为匿名命名空间（简称匿名空间），其定义方式如下：

```cpp
namespace {
    int val1 = 10;
    void func();
}//end of anonymous namespace
```

在C++代码中可以直接使用一些C语言的函数，就是通过匿名空间实现（体现了C++对C的兼容性）。

**匿名空间注意事项**：

（1）匿名空间不要定义与全局空间中同名的实体；

（2）匿名空间中支持改写兼容C语言的函数，但是最好不要改写；

（3）匿名空间中的实体不能跨模块调用。

#### 跨模块调用问题

一个*.c/*.cc/*.cpp的文件可以称为一个模块。

**（1）全局变量和函数是可以跨模块调用的**

**（2）有名命名空间中的实体可以跨模块调用**

**（3）静态变量和函数只能在本模块内部使用**

**（4）匿名空间的实体只能在本模块内部使用**

匿名空间中的实体只能在本文件的作用域内有效，它的作用域是从匿名命名空间声明开始到本文件结束。

### const关键字

const修饰的变量称为常量，之后不能修改其值

char/short/int/long/float/double  整型、浮点型数据都可以修饰——const常量

```cpp
const int number1 = 10;
int const number2 = 20;

const int val;//error 常量必须要进行初始化
```

**const常量和宏定义常量的区别**

1. <font color=red>**发生的时机不同**</font>：C语言中的宏定义发生时机在预处理时，做字符串的替换；

   const常量是在编译时（const常量本质还是一个变量，只是用const关键字限定之后，赋予只读属性，使用时依然是以变量的形式去使用）

2. <font color=red>**类型和安全检查不同**</font>：宏定义没有类型，不做任何类型检查；const常量有具体的类型，在编译期会执行类型检查。

   在使用中，应尽量以const替换宏定义，可以减小犯错误的概率。

### 修饰指针类型

三种形式：const int * p      int const * p1      int * const p2

这三个声明的本质区别在于：**const 修饰的是“指针指向的内容”还是“指针本身”**。

1）`const int * p` 或 `int const * p`

- const 修饰的是 `int`
- 说明：p 指向的内容是常量
- 结果：
  - 不能通过 p 修改它指向的值
  - 但可以修改 p 的指向

2）`int * const p`

- const 修饰的是指针 p 本身
- 说明：p 是一个常量指针
- 结果：
  - 可以通过 p 修改它指向的值
  - 但不能修改 p 的指向

3)`const int * const p`

- 前一个 const 修饰值
- 后一个 const 修饰指针
- 结果：
  - 不能改值
  - 不能改指向

举个例子

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;

    cout << "Initial values: a = " << a << ", b = " << b << endl;

    // 1. const int * p  （或 int const * p）
    const int *p = &a;

    // *p = 100;      // 错误：不能通过 p 修改值
    p = &b;           // 正确：可以修改指向

    cout << "p now points to b, *p = " << *p << endl;


    // 2. int * const p2
    int * const p2 = &a;

    *p2 = 300;        // 正确：可以修改值
    // p2 = &b;       // 错误：不能修改指向

    cout << "After modifying through p2, a = " << a << endl;


    // 3. const int * const p3
    const int * const p3 = &b;

    // *p3 = 400;     // 错误：不能修改值
    // p3 = &a;       // 错误：不能修改指向

    cout << "p3 always points to b, *p3 = " << *p3 << endl;

    return 0;
}

//Initial values: a = 10, b = 20
//p now points to b, *p = 20
//After modifying through p2, a = 300
//p3 always points to b, *p3 = 20
```

### 申请释放堆

**C语言中使用malloc/free函数，C++使用new/delete表达式**

new语句中可以不加参数，初始化为各类型默认值；也可加参数，参数代表要初始化的值

```cpp
int * p = new int(1);
cout << *p << endl;
```

区别如下

```cpp
#include <iostream>
using namespace std;

class Test
{
public:
    Test()  { cout << "Constructor\n"; }
    ~Test() { cout << "Destructor\n"; }
};

int main()
{
    Test* p1 = (Test*)malloc(sizeof(Test));
    free(p1);

    cout << "------\n";

    Test* p2 = new Test;
    delete p2;

    return 0;
}

// ------
// Constructor
// Destructor
```



### valgrind工具集

algrind是一种开源工具集，它提供了一系列用于调试和分析程序的工具。其中最为常用和强大的工具就是memcheck。它是valgrind中的一个内存错误检查器，它能够对C/C++程序进行内存泄漏检测、非法内存访问检测等工作。

- <font color=red>**sudo apt install valgrind**</font>

安装完成后即可通过memcheck工具查看内存泄漏情况，编译后输入如下指令

```C++
valgrind --tool=memcheck ./a.out
```

如果想要更详细的泄漏情况，如造成泄漏的代码定位，编译时加上-g

```C++
valgrind --tool=memcheck --leak-check=full ./a.out
```

但是这么长的指令使用起来不方便，每查一次就得输入一次，如果需要查看静态区的情况，还需要

```C++
valgrind --tool=memcheck --leak-check=full --show-reachable=yes ./a.out
```

**malloc**

- 只分配内存

- 不会调用构造函数
- 强制类型转化，不安全
- 返回 void*
- 失败返回 NULL
- 手动 sizeof
- 不支持对象语义

**free**

- 只释放内存

- 不会调用析构函数

**new**

- 分配内存
- 自动调用构造函数
- 自动返回正确类型，类型安全
- 失败抛异常
- 自动计算大小
- 支持类对象

**delete**

- 自动调用析构函数
- 再释放内存