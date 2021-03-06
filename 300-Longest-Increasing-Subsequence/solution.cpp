class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
    // 不得不判斷的特例
    if (nums.size() == 0) return 0;
 
    // 先放入一個數字，免得稍後 v.back() 出錯。
    vector<int> v;
    v.push_back(nums[0]);
 
    for (int i = 1; i < nums.size(); ++i)
    {
        int n = nums[i];
 
        if (n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<endl;
    }
 
    return v.size();
    }
};