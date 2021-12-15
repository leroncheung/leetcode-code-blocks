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

