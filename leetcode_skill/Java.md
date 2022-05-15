### java数组
```java
// 数据类型
boolean bo;
long num;
String strNum;

// 一维数组
int[] nums;
int[] nums = {1,2,3,4};
int[] nums = new int[4];
int[] nums = new int[4]{1,2,3,4};
int nums [] = new int[4]{1,2,3,4};

int len = nums.length();
// 多维数组
int nums [][] = new int[2][2];

import java.util.Scanner;
Scanner input = new Scanner(System.in);
String strNum = input.next();
System.out.println(strNum);

// String转int
int  i = Integer.parseInt(strNum);
int i = Integer.valueOf(strNum).intValue();

// int转String
String s = String.valueOf(i);
String s = Integer.toString(i);
String s = "" + i;

// 判断字符是否为数字，字母等
Character.isDigit(c);
Character.isLowerCase(c) || Character.isUpperCase(c);
Character.isLetterOrDigit( char ch );

int i = (int)c;
char c = (char)i;
// String的contains(), split()方法

```