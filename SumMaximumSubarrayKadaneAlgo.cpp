//===>>Method 1

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            int curr_sum = 0;
            for(int j=i; j<nums.size(); j++){
                curr_sum += nums[j];
                //cout<<curr_sum<<endl;
                max_sum = max(max_sum, curr_sum);
            }
        }
    return max_sum;
    }
};


//==>>Method 2


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MAX = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            MAX = max(sum, MAX);
            if(sum < 0) sum = 0;
        }
        return MAX;
    }
};