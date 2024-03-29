# 程序员面试宝典总结
> For interview

## 程序基础
### 赋值

```c++
int a = 2;
int main() {
    int a = a;  // a为未定义值
}
```

`x & (x - 1)`的作用是将x的最后一个`1`改为`0`，可以以此来统计数字的二进制表示中的`1`的个数。
```c++
int cnt = 0;
while (x) {
    cnt++;
    x = x & (x - 1)
}
```

`printf("%d %d\n",  *ptr, *(ptr++));    // C从右往左`
`cout << *p << " " << *(++p);           // C++从左往右`

`cout << (int&)a;       // 将从a的起始地址开始的sizeof(int)个字节当成int型数输出，需要注意变量a在内存中的存储方式（整型和浮点型有不同）`

```c++
unsigned int a = 0x12345678;
unsigned char b = (unsigned char)a; // 类型强制转换
char *c = (char *)&a;   // 指针类型强制转换
```



```c++
int a = 10;
int *b;
*b = a;     // 错误！b指针未指向任何内存，不能直接使用*b
```

```c++
int a = 10;
int *b;
b = &a;     // 正确！
```

```C++
// 以下代码在C和C++中都允许
char ss[] = "hello world!";

// 以下代码在C语言中是允许的，在C++中不允许！！！
char *ss = "hello world!";
```


```c++
// 指针只能相减，且结果为：地址值相减后再除以sizeof(int)【指针指向的类型的大小】
int a[3] = {1,2,3};
int *p = a;
int *q = &a[2];
cout << q - p << endl;  //  结果为2！！！
```

```C++
int a[] = {1,2,3,4,5};
int *ptr = (int*)(&a + 1);      // 数组名a本身就是指针，再加个&，就变成了双指针。加1就是数组整体加1行
cout << *(ptr - 1) << endl;     // 输出5
```

```C++
char *a[] = {"hello", "the", "world"};
char **pa = a;      // 指针的指针
pa++;
cout << *pa << endl;    // 输出the
```


> 标准模板库STL是一个基于模板类的容器类库，包括链表，队列，列表和堆栈。标准模板库还提供许多常用的算法，包括排序和搜索等。
> 泛型编程是是一种基于发现高效算法的最抽象表示的编程方法。STL就是泛型编程的例子。

```c++
// stl的vector删除指定元素6
vector<int> nums{1,2,3,4,5,6,3,6,6};
nums.erase(remove(begin(nums), end(nums), 6), end(nums));
```

```C++
// 错误代码
class Test {
public:
    Test() = default;
    ~Test() = default;
    Test(int t) {}
    void func() {}
};

int main() {
    Test a;
    a.func();
    Test b();      // 此处声明了一个函数，应该使用Test b;
    b.func();   // 编译报错！！！

    return 0;
}
```


- C++构造函数和析构函数调用次数
```C++
class Test {
public:
    Test() {
        cout << "Test::Test()" << endl;
    }
    Test(int tmp) : a(tmp) {
        cout << "Test::Test(int tmp)" << endl;
    }
    Test(const Test& tmp) {
        a = tmp.a;
        cout << "Test::Test(const Test &)" << endl;
    }
    ~Test() {
        cout << "Test::~Test()" << endl;
    }
    
private:
    int a;
};

Test func(Test t) {
    return t;
}

int main()
{
    // Test tt = func(5);
    func(5);            // 这句的作用和上一句一样，两次析构

    return 0;
}

// 输出：
// Test::Test(int tmp)
// Test::Test(const Test &)
// Test::~Test()
// Test::~Test()
```


> C++找错题
```c++
#include <iostream>

class Base {
public:
    Base(int t) : a(t) {}
    ~Base() = default;

private:    // 应该改成protected
    int a;
};

class Derived : public Base {
public:
    Derived(int t) : a(t) {    // 应该改成：Derived(int t) : Base(t), a(t) {}
    }
    ~Derived() = default;

    void print() {
        std::cout << a + Base::a << std::endl;
    }

private:
    int a;
};
```