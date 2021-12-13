# Bit Operation 位运算
> 位运算在数学中经常会用到，用来计算数字转换为二进制后的`1`和`0`的个数，数字按位取反，按位与等位运算。位运算速度较快。

## LC191 - 位1的个数

1. 循环检查二进制位
    - c++
    ```c++ []
        int hammingWeight(uint32_t n) {
            int cnt = 0;
            for (int i = 0; i < 32; i++) {
                if (n & (1 << i)) {
                    cnt++;
                }
            }
            return cnt;
        }
    ```
    - python
    ```python []
        def hammingWeight(self, n: int) -> int:
            cnt = sum(1 for i in range(32) if n & (1 << i)) 
            return  cnt
    ```
2. 位运算优化
    > **Brian Kernighan算法**：`n & (n−1)`，其运算结果为把`n`的二进制位中的最低位的`1`变为`0`之后的结果
    
    - c++
    ```c++ []
        int hammingWeight(uint32_t n) {
            int cnt = 0;
            while (n) {
                n &= n - 1;
                cnt++;
            }
            return cnt;
        }
    ```
    - python
    ```python []
        def hammingWeight(self, n : int) -> int:
            cnt = 0
            while n:
                n &= n - 1
                cnt += 1
            return cnt
    ```
3. 调用库函数
    - c++
    ```c++ []
        int hammingWeight(uint32_t n) {
            return __builtin_popcount(n);
        }
    ```
    - python
    ```python []
        def hammingWeight(self, n : int) -> int:
            return format(n, '02b').count('1')
    ```

## LC190 - 颠倒二进制位
1. 逐位颠倒
    - c++
    ```c++ []
        uint32_t reverseBits(uint32_t n) {
            uint32_t ans = 0;
            for (int i = 0; i < 32; ++i) {
                ans = (ans << 1) | (n & 1);
                n >>= 1;
            }
            return ans;
        }
    ```
    - python
    ```python []
        def reverseBits(self, n : int) -> int:
            ans = 0
            for i in range(32):
                ans = (ans << 1) | (n & 1)
                n >>= 1
            return ans
    ```
2. 位运算分治
    - c++
    ```c++ []
        class Solution {
        public:
            uint32_t reverseBits(uint32_t n) {
                n = (n >> 16) | (n << 16);
                n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
                n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
                n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
                n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
                return n;
            }
        };
    ```

    - python
    ```python []
        def reverseBits(self, n):
            n = (n >> 16) | (n << 16);
            n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
            n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
            n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
            n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
            return n;
    ```

## LC260 - 丢失的数字
> 按位异或运算（`^`）：相同比特位异或结果为`0`，不同则为`1`。
1. 位运算
    - c++
    ```c++ []
        int missingNumber(vector<int>& nums) {
            int res = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                res ^= nums[i];
            }
            for (int i = 0; i <= n; i++) {
                res ^= i;
            }
            return res;
        }
    ```
    - python
    ```python []
        def missingNumber(self, nums: List[int]) -> int:
            xor = 0
            for i, num in enumerate(nums):
                xor ^= i ^ num
            return xor ^ len(nums)
    ```