class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     int ones = 0, twos = 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         ones = (ones ^ nums[i]) & ~twos;
    //         twos = (twos ^ nums[i]) & ~ones;
    //     }
    //     return ones;
    // }
    int singleNumber(vector<int>& nums) {
         vector<int> bit(32,0);
         int n = nums.size();
 
         for(int i =0; i< n; ++i)
         {
             int k=1;
             for(int j =0; j<32; ++j)
             {
                 int rotated;
                 if((rotated = nums[i]>>j) == 0) break;
                 bit[j] += rotated & k;
             }
         }
         
         int target=0;
         for(int i =0; i<32; ++i)
         {
             target += (bit[i]%3 <<i);
         }
         return target;
     }
};