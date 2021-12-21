# C++
> Leetcode刷题中的C++部分的技巧总结

# 1. 输入输出
## 1.1 输入输出重定向
## 1.2 多进制输入输出
## 1.3 输出格式限定
- **setw(n)用法**：通俗地讲就是预设宽度
   >如 `cout<<setw(5)<<255<<endl;`
   结果是:
   (空格)(空格)255
- **setfill(char c)用法** : 就是在预设宽度中如果已存在没用完的宽度大小，则用设置的字符c填充
   > 如 `cout<<setfill('@')<<setw<<255<<endl;`
   结果是:
   @@255
- **setbase(int n)** : 将数字转换为 n 进制.
   >如 `cout<<setbase(8)<<setw(5)<<255<<endl;`
    `cout<<setbase(10)<<setw(5)<<255<<endl;`
    `cout<<setbase(16)<<255<<endl;`
   结果是:
   (空格)（空格)377
   (空格)(空格) 255
   (空格)(空格) ff
- **setprecision用法**
   使用`setprecision(n)`可控制输出流显示浮点数的数字个数。C++默认的流输出数值有效位是6。
   >如果`setprecision(n)`与`setiosflags(ios::fixed)`合用，可以控制小数点右边的数字个数。`setiosflags(ios::fixed)`是用定点方式表示实数。
   如果与`setiosnags(ios::scientific)`合用， 可以控制指数表示法的小数位数。`setiosflags(ios::scientific)`是用指数方式表示实数。

# 2. STL使用
## 2.1 vector
## 2.2 string
### 2.2.1 string转char *
`char *p = const_cast<char *>(str.c_str());`
### 2.2.2 string遍历
## 2.3 set
## 2.4 map
# 3. 库函数使用
## 3.1 \<string>头文件
### 3.1.1 字母数字判断
### 3.1.2 字符串转数字
### 3.1.3 数字转字符串
### 3.1.4 字符串分割
- substr()
- strtok_r()
- strsep()
## 3.2 \<algorithm>头文件
## 3.3 搜索
## 3.4 随机数
# 4. 其他
## 4.1 位运算
## 4.2 最大值最小值表示法