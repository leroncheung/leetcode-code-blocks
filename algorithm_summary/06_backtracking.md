# 回溯法
> - 是否有重复元素？
> - 是swap还是append？
> - 是否可以重复选择元素？

## 1. 回溯题目总结：
> 回溯模板：
```python
    def backtrack(nums, temp, idx):
        if idx == len(nums):    // 终止条件，
			ans.append(temp)
			return
        for i in range():
            temp.append(nums[i])
            backtrack(nums, temp, idx + 1)
            # backtrack(nums, tmep, i + 1)
            temp.pop()
```

## 2. 回溯题目分类
- 组合和子集：append，i(i + 1)，sort，visited
    - append
    - 不可重复选择元素：i；可重复选择元素：i + 1
    - 原数组含有重复元素：先全局sort，visited：`if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])`
- 全排列：swap，idx + 1，sort
    - swap
    - idx + 1
    - 原数组含有重复元素：局部sort：`sort(begin(nums) + idx, end(nums)); if (i > idx && nums[i] == nums[i - 1])`
- 其他：append或swap

### 2.1 组合类
**77题：组合：给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。**
https://leetcode-cn.com/problems/combinations/
```c++ []
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;

public:
    void backTrack(int n, int k, int idx) {
        if (temp.size() == k) {
            ans.emplace_back(temp);
            return;
        }
        for (int i = idx; i <= n + 1 - (k - temp.size()); i++) {
            temp.emplace_back(i);
            backTrack(n, k, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backTrack(n, k, 1);
        return ans;
    }
};
```
```python []
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backTrack(idx, temp):
            if len(temp) == k:
                ans.append(temp)
                return
            for i in range(idx, n + 1):
                backTrack(i + 1, temp + [i])
   
        ans = []
        backTrack(1, [])
        return ans
```


**39题：组合求和：数组无重复元素，单个元素可以被无限次选取**
https://leetcode-cn.com/problems/combination-sum/

```c++ []
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;

public:
    void backTrack(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.emplace_back(temp);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                temp.push_back(candidates[i]);
                backTrack(candidates, target - candidates[i], i);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTrack(candidates, target, 0);
        return ans;
    }
};
```
```python []
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backTrack(target, temp, idx):
            if target == 0:
                ans.append(temp)
                return
            for i in range(idx, len(candidates)):
                if target - candidates[i] >= 0:
                    backTrack(target - candidates[i], temp + [candidates[i]], i)

        ans = []
        backTrack(target, [], 0)
        return ans
```

**40题：组合求和2:数组中可能存在重复元素，每个数字只能使用一次**
https://leetcode-cn.com/problems/combination-sum-ii/

```c++ []
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited;

public:
    void backTrack(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.emplace_back(temp);
            return;
        }
        for (int i = idx; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {
                continue;
            }
            temp.emplace_back(candidates[i]);
            visited[i] = true;
            backTrack(candidates, target - candidates[i], i + 1);   // i+1表示只能选择列表中的下一个数字了，本数字不可以重复选择
            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        visited = vector<bool>(candidates.size(), false);
        sort(begin(candidates), end(candidates));
        backTrack(candidates, target, 0);
        return ans;
    }
};
```
```python []
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def backTrack(temp, target, idx):
            if target == 0:
                ans.append(temp)
                return
            for i in range(idx, len(candidates)):
                if i > 0 and candidates[i] == candidates[i - 1] and not visited[i - 1]:
                    continue
                if target - candidates[i] >= 0:
                    visited[i] = True
                    backTrack(temp + [candidates[i]], target - candidates[i], i + 1)
                    visited[i] = False
        
        ans = []
        visited = [False] * len(candidates)
        candidates = sorted(candidates)
        backTrack([], target, 0)
        return ans
```

**216题：组合求和3:找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。**
https://leetcode-cn.com/problems/combination-sum-iii/
```
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;

public:
    void backTrack(int k, int n, int idx) {
        if (temp.size() > k) {
            return;
        }
        if (temp.size() == k && n == 0) {
            ans.emplace_back(temp);
            return;
        }
        for (int i = idx; i <= 9; i++) {
            if (n - i < 0) {
                break;
            }
            temp.emplace_back(i);
            backTrack(k, n - i, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backTrack(k, n, 1);
        return ans;
    }
};
```

### 2.2 子集类
**90题：子集2:给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。可能含有重复元素。**
https://leetcode-cn.com/problems/subsets-ii/solution/

```
class Solution {
private:
    vector<vector<int>> ans;
    vector<bool> visited;
    vector<int> temp;

public:
    void backTrack(vector<int>& nums, int idx) {
        ans.emplace_back(temp);
        for (int i = idx; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            visited[i] = true;
            temp.emplace_back(nums[i]);
            backTrack(nums, i + 1);
            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        sort(begin(nums), end(nums));
        backTrack(nums, 0);
        return ans;
    }
};
```

### 2.3 全排列类
**46题：全排列：给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。**
https://leetcode-cn.com/problems/permutations/

```
class Solution {
private:
    vector<vector<int>> ans;

public:
    void backTrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            backTrack(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(nums, 0);
        return ans;
    }
};
```

**47题：全排列2:给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。**
https://leetcode-cn.com/problems/permutations-ii/
解法一：
```
class Solution {
private:
    vector<vector<int>> ans;

public:
    void backTrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            sort(begin(nums) + idx, end(nums));
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            swap(nums[i], nums[idx]);
            backTrack(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backTrack(nums, 0);
        return ans;
    }
};
```

解法二（更常见的解法）：
```
class Solution {
private:
    vector<vector<int>> ans;
    vector<bool> visited;
    vector<int> temp;

public:
    void backTrack(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.emplace_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue;
            }
            visited[i] = true;
            temp.emplace_back(nums[i]);
            backTrack(nums);
            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        sort(begin(nums), end(nums));
        backTrack(nums);
        return ans;
    }
};
```

### 2.4 其他
**131题:分割字符串：给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。**
https://leetcode-cn.com/problems/palindrome-partitioning/

```c++ []
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> temp;

public:
    bool isParlindrom(string& s) {
        auto ss = s;
        reverse(begin(s), end(s));
        return ss == s;
    }

    void backTrack(string& s, int idx) {
        if (idx == s.size()) {
            ans.emplace_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            auto str = s.substr(idx, i - idx + 1);
            if (isParlindrom(str)) {
                temp.emplace_back(str);
                backTrack(s, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backTrack(s, 0);
        return ans;
    }
};
```
```python []
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def is_parlindrom(s):
            ss = s[::-1]
            return ss == s

        def backTrack(temp, idx):
            if idx == len(s):
                ans.append(temp)
                return
            for i in range(idx, len(s)):
                sub_str = s[idx: i + 1]
                if is_parlindrom(sub_str):
                    backTrack(temp + [sub_str], i + 1)
        ans = []
        backTrack([], 0)
        return ans
```

93题：复原IP地址：给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案
https://leetcode-cn.com/problems/restore-ip-addresses/

