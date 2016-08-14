title: 34_Search_for_a_Range
date: 2016-08-14 21:33:24
tags: [leetcode,c++]
categories: leetcode
---
## question
### 34. Search for a Range

[Original Page](https://leetcode.com/problems/search-for-a-range/)

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of _O_(log _n_).

If the target is not found in the array, return `[-1, -1]`.

For example,  
Given `[5, 7, 7, 8, 8, 10]` and target value 8,  
return `[3, 4]`.

## analysis
一开始就想到了二分查找，但是原来做二分查找的时候一般都是找到确定的那个数就完成了，  
这里的情况比较特殊，需要找到整个区间，所以需要两遍查找，并且一个是找到小于target  
的最大索引，一个是找到大于target的最大索引，代码参考[leetcode discuss](https://discuss.leetcode.com/topic/5891/clean-iterative-solution-with-two-binary-searches-with-explanation/2),这位仁  
兄也做了详细的分析解释。  


## code 
```C++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int i = 0, j = nums.size() - 1;
        int mid;
        while(i < j){
            mid = (i + j) / 2;
            if(nums[mid] < target) i = mid + 1;
            else j = mid;
        }
        if(nums[i] != target) return ret;
        else {
            ret[0] = i;
            if((i+1) < (nums.size() - 1) && nums[i+1] > target){
                ret[1] = i;
                return ret;
            }
        }   //一点小优化
        j = nums.size() - 1;
        while(i < j){
            mid = (i + j) / 2 + 1;
            if(nums[mid] > target) j = mid - 1;
            else i = mid;
        }
        ret[1] = j;
        return ret;
    }
};
```