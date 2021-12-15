# 二叉树的定义和四种遍历方式
## 1. 二叉树的定义

> Definition of binary tree by c++
```C++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

```
> Definition of a binary tree by python
```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```
## 2. 二叉树的遍历-迭代实现
> 前序遍历，中序遍历，后序遍历，层次遍历
### 2.1 前序遍历（两种方法）
> 方法一：C++
```C++ []
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                ans.emplace_back(node->val);
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return ans;
    }
```
> 方法一：Python
```Python []
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans, stk = [], []
        node = root
        while stk or node:
            while node:
                stk.append(node)
                ans.append(node.val)
                node = node.left
            node = stk.pop()
            node = node.right
        return ans
```

> 方法二：C++
```C++ []
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            ans.emplace_back(node->val);
            if (node->right != nullptr) {
                stk.push(node->right);
            }
            if (node->left != nullptr) {
                stk.push(node->left);
            }
            node = node->right;
        }
        return ans;
    }
};
```
> 方法二：Python
```Python []
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        ans, stk = [], [root, ]
        while stk:
            node = stk.pop()
            ans.append(node.val)
            if node.right:
                stk.append(node.right)
            if node.left:
                stk.append(node.left)
        return ans
```

### 2.2 中序遍历（一种方法）
> C++
```C++ []
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            ans.emplace_back(node->val);
            node = node->right;
        }
        return ans;
    }
```

> Python
```Python []
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans, stk, node = [], [], root
        while stk or node:
            while node:
                stk.append(node)
                node = node.left
            node = stk.pop()
            ans.append(node.val)
            node = node.right
        return ans
```

### 2.3 后序遍历（两种方法）
> 方法一（由前序遍历颠倒顺序得到）：C++
```C++ []
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            ans.emplace_back(node->val);
            if (node->left != nullptr) {
                stk.push(node->left);
            }
            if (node->right != nullptr) {
                stk.push(node->right);
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```
> 方法一：Python
```Python []
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        ans, stk = [], [root, ]
        while stk:
            node = stk.pop()
            ans.append(node.val)
            if node.left:
                stk.append(node.left)
            if node.right:
                stk.append(node.right)
        return ans[::-1]
```
> 方法二：C++
```C++ []
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode *node = root;
        TreeNode *pre = nullptr;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            if (node->right == nullptr || node->right == pre) {
                stk.pop();
                ans.emplace_back(node->val);
                pre = node;
                node = nullptr;
            } else {
                node = node->right;
            }
        }
        return ans;
    }
};
```
> 方法二：Python
```Python []
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans, stk, node, pre = [], [], root, None
        while stk or node:
            while node:
                stk.append(node)
                node = node.left
            node = stk[-1]
            if not node.right or node.right == pre:
                ans.append(node.val)
                stk.pop()
                pre = node
                node = None
            else:
                node = node.right
        return ans
```

### 2.4 层次遍历
> C++
```C++ []
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            auto size = que.size();
            vector<int> temp;
            for (auto i = 0; i < size; i++) {
                auto node = que.front();
                que.pop();
                temp.emplace_back(node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```

> Python
```Python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        que, ans = [root, ], list(list())
        while que:
            size = len(que)
            temp = []
            for _ in range(size):
                node = que[0]
                temp.append(node.val)
                del que[0]
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
            ans.append(temp)
        return ans
```