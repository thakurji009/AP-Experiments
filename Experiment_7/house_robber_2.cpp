class Solution {
    public:
        int helper(vector<int> & nums, int st, int end){
            int n = nums.size();
            if(end-st==1) return nums[st];
            vector<int> dp(end-st, 0);
            dp[0] = nums[st];
            dp[1] = max(nums[st], nums[st+1]);
            for(int i=2;i<end-st;i++){
                dp[i] = max(dp[i-1], dp[i-2]+nums[st+i]);
            }
            return dp[end-st-1];
        }
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n==1) return nums[0];
            if(n==2) return max(nums[0], nums[1]);
            return max(helper(nums, 0, n-1), helper(nums, 1, n));
        }
    };