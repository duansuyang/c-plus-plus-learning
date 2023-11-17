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

**Structures**
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


**Classes**

一个类定义，Vector 是类的名字
定义了两个私有成员变量
构造函数，用于创建 Vector 对象
其中，Vector(int s) : 声明构造函数；
:elem{new double[s]}, sz{s}  初始化列表，依次初始化成员变量；
{ }     构造函数的函数体；

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