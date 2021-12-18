# 堆的实现及应用



C++中优先队列默认为大顶堆（即less<T>），这里适合用小顶堆（greater<T>），当然也可以使用大顶堆，数量限制在nums.size() - k + 1。
Python中优先队列使用heapq.heapify(min_heap)来初始化优先队列，python中只有小顶堆，如果想要换大顶堆，需在添加数据时都*-1，出队时再*-1，用这种方式来得到大顶堆。
	

```c++ (小顶堆greater) []
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
```
```c++ (大顶堆，默认less) []
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto& num : nums) {
            pq.push(num);
            if (pq.size() > nums.size() - k + 1) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
```
```python (小顶堆) []
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_heap = []
        heapq.heapify(min_heap)
        for num in nums:
            heapq.heappush(min_heap, num)
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        return min_heap[0]
```
```python (大顶堆，元素*-1) []
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        max_heap = []
        heapq.heapify(max_heap)
        for num in nums:
            heapq.heappush(max_heap, num * -1)
            if len(max_heap) > len(nums) - k + 1:
                heapq.heappop(max_heap)
        return max_heap[0] * -1
```
	
	
	
**347题：前k个高频元素**
https://leetcode-cn.com/problems/top-k-frequent-elements/
涉及自定义比较函数
	
```c++ []
class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        unordered_map<int, int> umap;
        vector<int> ans;
        for (auto num : nums) {
            umap[num]++;
        }
        for (auto it = begin(umap); it != end(umap); it++) {
            pq.push(make_pair(it->first, it->second));
            if (pq.size() > umap.size() - k) {        // 这个if判断执行了k次，就选择出了umap中的k个出现频率最高的数
                ans.emplace_back(pq.top().first);
                pq.pop();
            }
        }
        return ans;
    }
};
```
```python 堆 []
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = collections.Counter(nums)
        heap = [(val, key) for key, val in count.items()]
        return [item[1] for item in heapq.nlargest(k, heap)]
```
```python 排序 []
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        return sorted(count, key=count.get, reverse=True)[:k]
```
	
	
**451题：根据字符出现频率排序**
	https://leetcode-cn.com/problems/sort-characters-by-frequency/submissions/
	
```c++ []
class Solution {
public:
    static bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    }

    string frequencySort(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(&cmp)> pq(cmp);
        string ans;
        unordered_map<char, int> umap;
        for (auto& c : s) {
            umap[c]++;
        }
        for (auto [c, count] : umap) {
            pq.push(make_pair(c, count));
        }
        while (!pq.empty()) {
            ans += string(pq.top().second, pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
```
```python []
class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join(x * c for [x, c] in Counter(s).most_common())
```
	
	
**973题：最接近原点的k个点**
https://leetcode-cn.com/problems/k-closest-points-to-origin/submissions/
	
```c++ []
class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        vector<vector<int>> ans;
        for (auto point : points) {
            pq.push(make_pair(point[0], point[1]));
            if (pq.size() > points.size() - k) {
                ans.push_back({pq.top().first, pq.top().second});
                pq.pop();
            }
        }
        return ans;
    }
};
```
```python 大顶堆 []
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        q = [(-x ** 2 - y ** 2, i) for i, (x, y) in enumerate(points[:k])]
        heapq.heapify(q)
        
        n = len(points)
        for i in range(k, n):
            x, y = points[i]
            dist = -x ** 2 - y ** 2
            heapq.heappushpop(q, (dist, i))
        
        ans = [points[identity] for (_, identity) in q]
        return ans
```
```python 排序 []
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=lambda x: [x[0] ** 2 + x[1] ** 2])
        return points[:k]
```