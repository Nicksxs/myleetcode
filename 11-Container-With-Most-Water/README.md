[题解，说的很明白](https://discuss.leetcode.com/topic/35117/share-my-short-java-code-with-%E4%B8%AD%E6%96%87-explanation)
```java
/*
    设置两个指针i, j, 一头一尾, 相向而行. 假设i指向的挡板较低, j指向的挡板较高(height[i] < height[j]).
    下一步移动哪个指针?
    -- 若移动j, 无论height[j-1]是何种高度, 形成的面积都小于之前的面积.
    -- 若移动i, 若height[i+1] <= height[i], 面积一定缩小; 但若height[i+1] > height[i], 面积则有可能增大.
    综上, 应该移动指向较低挡板的那个指针.
*/
public class Solution {
    public int maxArea(int[] height) {
        if (height==null || height.length==0) { return 0; }
        int max = 0;
        int i = 0, j = height.length-1;
        while (i < j) {
            max = Math.max(max, (j-i) * Math.min(height[i], height[j]));
            if (height[i] < height[j]) {  // should move i
                int k; for (k=i+1; k<j && height[k]<=height[i]; ++k) {}
                i = k;
            } else {  // should move j
                int k; for (k=j-1; k>i && height[k]<=height[j]; --k) {}
                j = k;
            }
        }
        return max;
    }
}
```