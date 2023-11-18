# 基本语法 The Basics
## 

C++ is a compiled language;

A nonzero value from main() indicates failure;

+x // unary plus;

−x // unary minus;

const   
// "I promise not to change this value"

constexpr   
// "to be evaluated at compile time" 主要用于指定常量、将数据放置在内存中不易损坏的位置以及提高性能。

for (auto x : v) // for each x in v
// 另一种 for 循环

auto& x = a;    // x 指代了 a, 改变x及改变a。

auto* p = &a;   // p 指向了 a, 改变p即改变指向的地址，改变*p即改变a。

nullptr
// using nullptr eliminates potential confusion between integers (such as 0 or NULL) and pointers (such as nullptr).
// 使用 nullptr 可以消除整数（如 0 或 NULL）和指针（如 nullptr）之间可能存在的混淆。

### **Structures**
```c++
struct Vector {
    int sz; // number of elements 
    double∗ elem; // pointer to elements
};
Vector v;

void vector_init(Vector& v, int s) 
{
    v.elem = new double[s]; // allocate an array of s doubles
    v.sz = s; 
}

double read_and_sum(int s)
    // read s integers from cin and return their sum; s is assumed to be positive
{
    Vector v;
    vector_init(v,s); // allocate s elements 
    for v for (int i=0; i!=s; ++i)
        cin>>v.elem[i]; // read into elements
    double sum = 0;
    for (int i=0; i!=s; ++i)
        sum+=v.elem[i]; // take the sum of the elements
    return sum;
}

```

```c++
void f(Vector v, Vector& rv, Vector∗ pv)
{
    int i1 = v.sz;      // access through name
    int i2 = rv.sz;     // access through reference
    int i4 = pv−>sz;    // access through pointer
}
```


### **Classes**

- **class Vector**      一个类定义，Vector 是类的名字
- 定义了两个私有成员变量
- Vector(int s) :elem{new double[s]}, sz{s} { } 构造函数，用于创建 Vector 对象
- 其中，Vector(int s) : 声明构造函数；
- :elem{new double[s]}, sz{s}  初始化列表，依次初始化成员变量；
- { }     构造函数的函数体；

```c++
class Vector { 
public:
    Vector(int s) :elem{new double[s]}, sz{s} { } // construct a Vector 构造函数
    double& operator[](int i) { return elem[i]; } // element access: subscripting
    int size() { return sz; }
private:
    double∗ elem; // pointer to the elements 
    int sz; // the number of elements
};

```

## **Enumerations**    枚举

```c++
enum class ErrorCode : unsigned int {
    None,
    Minor,
    Critical
};
```
- enum 创建枚举类型；
- enum class 创建一个带作用域的枚举类型   ErrorCode heading = **ErrorCode::** Minor;；
-  : unsigned int     为枚举指定底层类型，用于控制枚举值的大小和表示；
- 枚举是创建清晰可读代码的强大工具，尤其是在处理一组密切相关的命名常量时。它们增强了代码的类型安全性，防止错误，并使代码更加自文档化。
- 

## **Modularity**      模块化

指将软件系统划分为单独的、可互换的组件的概念，每个组件封装一个特定的功能或一组相关的功能。这一设计原则是创建可管理、可扩展和可维护的软件的基础。

在C++中，:: 是一个作用域解析运算符（Scope Resolution Operator），它用于指定一个成员（如函数、变量或类）属于特定的类或命名空间。




### **Namespaces**      命名空间

一种组织代码的方式，用于防止名称冲突。命名空间允许将全局变量、函数、类等封装在一个独立的作用域内，这样即使不同的命名空间也有同名的成员，他们也不会相互冲突。

```c++
// 创建
namespace MyNamespace {
    int value;
    void myFunction() {
        // ...
    }
    class MyClass {
        // ...
    };
}

// 使用
int x = MyNamespace::value;
MyNamespace::myFunction();
MyNamespace::MyClass obj;


// 嵌套
namespace Outer {
    namespace Inner {
        void innerFunction() {
            // ...
        }
    }
}

Outer::Inner::innerFunction();

// 匿名命名空间
namespace {
    int internalValue;  // 只在本文件内可见
}

void someFunction() {
    internalValue = 5;  // 直接访问匿名命名空间中的变量
}

// 声明使用空间中特定变量
using MyNamespace::MyClass;

MyClass obj; // 不需要再写 MyNamespace::MyClass

// 声明使用空间中所有变量
using namespace MyNamespace;

myFunction();  // 直接调用，不需要 MyNamespace:: 前缀
```


### **Error Handling**      错误处理
- 错误码    return 1;
- 异常处理
```c++
int divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero.");  // 抛出异常
    }
    return numerator / denominator;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
```
在这个例子中，如果 denominator 为零，divide 函数抛出一个 std::invalid_argument 异常。main 函数中的 try-catch 块用于捕获和处理这个异常。
- 资源获取即初始化（RAII）

RAII是一种利用对象生命周期管理资源的技术。通常涉及在构造函数中获取资源，在析构函数中释放资源。这种模式特别适用于异常安全和资源泄漏的防护。

```c++
class FileHandle {
    FILE* handle;
public:
    FileHandle(const char* filename, const char* mode) {
        handle = fopen(filename, mode);
        if (!handle) {
            throw std::runtime_error("Failed to open file.");
        }
    }
    ~FileHandle() {
        fclose(handle);
    }
    // ... 其他成员函数 ...
};

int main() {
    try {
        FileHandle file("example.txt", "r");
        // 使用文件句柄进行操作
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
```

**析构函数的特点**

在C++中，波浪符号 ~ 用作析构函数的标志。析构函数是一个特殊的类成员函数，它在对象生命周期结束时自动被调用，用于执行清理操作。这些操作通常包括释放对象在生命周期内分配的资源，如内存、文件句柄、网络连接等。

- 名称：析构函数的名称由波浪符号 ~ 后跟类名构成。例如，一个名为 MyClass 的类的析构函数将命名为 ~MyClass。
- 无返回值和参数：析构函数不接受任何参数，也不返回任何值。
- 自动调用：当对象的生命周期结束时（例如，当对象离开其作用域、被删除，或程序结束时），析构函数会被自动调用。
- 不可重载：每个类只能有一个析构函数。
- 继承和多态：如果一个类是基类，它的析构函数应该是虚拟的，以确保派生类对象的正确析构。

#### Exceptions 异常处理 

异常处理是一种处理运行时错误的机制。在C++中，可以通过 throw 语句抛出异常，并使用 try 和 catch 块来捕获和处理它们。

#### Invariants 维护不变量

不变量是在程序执行过程中始终保持为真的条件。在面向对象编程中，不变量通常用于确保对象始终处于有效状态。

类不变量：这些是在类的整个生命周期中应始终为真的条件。例如，一个表示日期的类可能要求其年、月和日属性始终代表有效的日期。

维护不变量：通过构造函数、析构函数和其他方法来维护这些不变量。如果检测到不变量被破坏，可以抛出异常或以其他方式报告错误。

```c++
class Date {
public:
    Date(int year, int month, int day) {
        // 检查日期有效性
        if (!isValidDate(year, month, day)) {
            throw std::invalid_argument("Invalid date");
        }
        // 设置日期
    }

    // 其他方法...
};
```

#### Static Assertions 静态断言

静态断言是编译时进行的检查，用于验证程序的某些方面。这是通过 static_assert 关键字实现的，它在编译时评估一个常量表达式。

使用场景：静态断言可用于检查类型大小、模板参数、编译时常量等。

```c++
constexpr double C = 299792.458; // km/s
void f(double speed) 
{
    const double local_max = 160.0/(60∗60); // 160 km/h == 160.0/(60*60) km/s 
    static_assert(speed<C,"can't go that fast"); // error: speed must be a constant
    static_assert(local_max<C,"can't go that fast"); // OK // ...
}
```
In general, static_assert(A,S) prints S as a compiler error message if A is not true.
