class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int infpt=0;
        int min = INT_MAX;
        int n = nums.size()-1;
        for(int i(n);i>0;i--){
            if(nums[i-1] <nums[i]){
                infpt =i;
                break;
            }
        }
        if(infpt ==0){
            sort(nums.begin(),nums.end());
        }
        else{
            int toswap = nums[infpt-1];
            for(int i(infpt);i<=n;i++ ){
                 if(nums[i]- toswap >0 && nums[i] -toswap<min){
                     int temp = nums[i];
                     nums[i] = nums[infpt-1];
                     nums[infpt-1] = temp;
                 }
            }        
        }
        sort(nums.begin()+infpt, nums.end());
        
    }
};