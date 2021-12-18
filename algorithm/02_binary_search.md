# 二分查找

1. while (low <= high)
初始条件：low=0, high=len-1
终止：low>high
向左查找：high=mid-1
向右查找：low=mid+1
关键属性：不需要后处理，循环结束之后，找到就是找到，没找到就是没找到
2. while (low<high)
初始条件：low=0, high=len-1（也有high=len的用法）
终止：low=high
向左查找：high=mid
向右查找：low=mid+1 
关键属性：循环查找中至少有两个元素，循环结束之后，还剩下一个元素，需要判断是否符合条件
                一般情况下，因为mid=(high-low)/2+low更靠近low，所以一般直接修改low=mid+1（向右）。而向左时，一般采用high=mid，不采用high=mid-1，因为可能造成死循环。
            类似的，mid=(high-low+1)/2+low更靠近high，所以一般直接修改high=mid-1（向左）。这种情况下，不采用low=mid+1，因为这样可能会造成死循环。 


1. 求平方根, 第一个错误的版本，寻找比目标字母大的最小字母
``` c++
while (low <= high)
if (mid * mid <= x)        
    ans = mid
    low = mid + 1
```
2. 旋转数组
* 查找值：先判断是否全局有序（全局有序按正常的二分查找），再判断前一半有序还是后一半有序，再单独判断
* 查找最小值：先判断是否全局有序（nums[low] <= nums[high]全局有序直接return），左边有序（nums[low] <= nums[mid]）的话肯定在右边，右边有序的话（high=mid）
* 查找最小值，但是有重复值：先去重（注意low和high不应该相等），其余步骤和上面一样
3. 寻找峰值（比较相邻元素）
        建议使用while (low < high)，确保最后还剩一个元素且该元素在范围内
比较nums[mid]和nums[mid+1]，注意mid+1是否超出索引范围，超出（说明已经找到最右边的最大值了）则直接break。函数最后return low（此时无需再判断low是否超出索引，不可能超出）
4. 二叉搜索树/pow()实现
拆分两半实现，然后用递归实现
5. 排序数组中查找元素的第一个和最后一个位置
def binary_search(flag):
    low, high, ans = 0, len(nums) - 1, -1
    while low <= high:
        mid = (high - low) // 2 + low
        if nums[mid] == target:
            ans = mid
            if flag:
                high = mid - 1
            else:
                low = mid + 1
        elif nums[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return ans

        
