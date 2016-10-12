class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, j = 1, n;
        vector<string> res;
        n = nums.size();
        while(i < n){
            j = 1;
            while(j < n && nums[i+j] - nums[i] == j) j++;
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return res;
    }
};