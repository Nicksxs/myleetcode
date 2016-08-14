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
        else ret[0] = i;
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