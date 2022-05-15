### C#数组
```C#
// 数据类型
int num;
long num;
double num;
string name = Console.ReadLine();  // 无需引入包
Console.WriteLine("Name: " + name);
Console.WriteLine("Name: {0}", name);

// 一维数组
int[] nums;
int[] nums = {1,2,3,4};
int[] nums = new int[4];
int[] nums = new int[4]{1,2,3,4};

// 多维数组
int[,] nums = new int[2,2];
int[,] nums = new int[2,2]{{1,2}, {3,4}};
int[,,] nums = new int[2,2,2];
```
`int n = nums.Length;`

```C#
	// 字符串转数字，必须要严格符合，否则会转换失败（12.12不能转换为int型）
int num = Convert.ToInt32(strNum);
int num = int.Parse(strNum);
double num = Convert.ToDouble(strNum);
double num = double.Parse(strNum);
bool res = double.TryParse(strNum, out num);

string strNum = num.ToString();


char.isLetter(str)
char.IsDigit(str)
if(ch>='a'&&ch<='z')   // 小写字母
if(ch>='A'&&ch<='Z')  // 大写字母
	
	
```