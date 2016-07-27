class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
         return nums.size();
        int forward = nums[0];
        bool deleted = false;
        vector<int> indexs;
        for(int i = 1; i < nums.size(); i++){
            
            if(!deleted && nums[i] == forward){
                // nums.erase(nums.begin() + i);
                deleted = true;
            }else if(deleted && nums[i] == forward){
                nums.erase(nums.begin() + i);
                i--;
                // continue;
            }else if(!deleted && nums[i] != forward){
                forward = nums[i];
            }else{
                forward = nums[i];
                deleted = false;
            }
        }
        return nums.size();
    }
};