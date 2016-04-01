class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.begin() == nums.end()) return 0;
        vector<int>::iterator itor;
        for (itor = nums.begin(); itor + 1 != nums.end(); )
        {
            if (*(itor + 1) == val) {
                nums.erase(itor + 1);
            }
            else {
                itor++;
            }
        }
        itor = nums.begin();
        if (*itor == val) {
            nums.erase(itor);
            return nums.size();
        }
        return nums.size();
    }
};