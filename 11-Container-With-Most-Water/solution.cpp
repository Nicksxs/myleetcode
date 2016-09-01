class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        int max = 0;
        int i = 0, j = height.size() - 1;
        while(i < j) {
            max = max > (j - i) * ((height[i] > height[j] ? height[j] : height[i])) ? max : (j - i) * ((height[i] > height[j] ? height[j] : height[i])) ;
            if(height[i] < height[j]){
                int k; 
                for(k = i + 1; height[k] <= height[i]; k++){}
                i = k;
            }else{
                int k;
                for(k = j - 1; height[k] <= height[j]; k--){}
                j = k;
            }
        }
        return max;
    }
};