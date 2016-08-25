class Solution {
public:
    // int findKthLargest(vector<int>& nums, int k) {
        //method 1
        // std::sort(nums.begin(), nums.end());  
        // return nums[nums.size()-k]; 
        
        //method 2
        // int cur=nums[k-1];
        // vector<int> bigger;
        // vector<int> smaller;
        // for(size_t i=0; i<nums.size(); ++i){
        //     if(i==k-1) continue;
        //     if(nums[i]>=cur) bigger.push_back(nums[i]);
        //     else smaller.push_back(nums[i]);
        // }
        // if(bigger.size()==k-1) return cur;
        // if(bigger.size()>k-1) return findKthLargest(bigger,k);
        // if(bigger.size()<k-1) return findKthLargest(smaller,k-bigger.size()-1);
        
        //method 3
    int findKthLargest(vector<int>& nums, int k) {  
        quickSortVariant(nums, nums.size() - k, 0, nums.size() - 1);  
        return nums[nums.size() - k];  
    }  
      
    int getRand(int start, int end){  
        if(end < start) {  
            return 0;  
        }  
        srand((unsigned)time(0));  
        return rand()%(end-start+1) + start;  
    }  
      
    int swap(vector<int>& nums, int i, int j){  
        int temp = nums[i];  
        nums[i]=nums[j];  
        nums[j]=temp;  
    }  
      
    void quickSortVariant(vector<int>& nums, int k, int start, int end){  
        int flag = getRand(start, end); //找到一个标记元素  
        swap(nums, start, flag);  
        int flagNum = nums[start];  
        int i=start, j=end;  
        while(i<j){  
            while(j>i&&nums[j]>=flagNum){  
                j--;  
            }  
            nums[i]=nums[j];  
            while(j>i&&nums[i]<=flagNum){  
                i++;  
            }  
            nums[j]=nums[i];  
        }  
        nums[i]=flagNum;  
        if(i>k){  
            quickSortVariant(nums, k, start, i - 1);  
        }else if(i<k){  
            quickSortVariant(nums, k, i+1, end);  
        }  
    }  
};