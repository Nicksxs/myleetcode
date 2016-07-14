class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(nums[i] == nums[j]){
        //             if(j - i <= k)
        //                 return true;
        //         }
        //             // return true;
        //     }
        // }
        // return false;
        // if(nums.size() == 0)
        // return false;
        // int temp;
        // for(int i = 0; i < nums.size() - 1; i++){
        //     if(k < nums.size() && i+k+1 > nums.size())
        //         return false;
        //     temp = (i+k+1 > nums.size())? nums.size(): i+k+1;
        //     printf("temp: %d\n",temp);
        //     printf("i: %d\n",i);
        //     for(int j = i+1; j < temp; j++){
        //         printf("j: %d\n",j);
        //         if(nums[i] == nums[j]){
        //             // if(j - i <= k)
        //                 return true;
        //         }
        //     }
        // }


        // method 0  超时
        // int len = nums.size();
        // for(int i = 0; i < len - 1; i++){
        //     if(k >= len)
        //         temp = len;
        //     else
        //         temp = (i+k+1 > len)? len: i+k+1;
        //     // printf("temp: %d\n",temp);
        //     // printf("i: %d\n",i);
        //     for(int j = i+1; j < temp; j++){
        //         // printf("j: %d\n",j);
        //         if(nums[i] == nums[j]){
        //             // if(j - i <= k)
        //                 return true;
        //         }
        //     }
        // }
        // return false;
        unordered_map<int, int> m;  // value --> index
        for(int i = 0; i < nums.size(); i ++)
        {
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = i;
            else
            {
                if(i - m[nums[i]] <= k)
                    return true;
                else
                    m[nums[i]] = i; // update the index
            }
        }
        return false;
        
    }
};