class Solution {
    public:
        bool predictTheWinner(vector<int>& nums) {
            int n = nums.size();
    
            vector<int> pref(n, 0);
            pref[0] = nums[0];
            for(int i = 1; i < n; i++){
                pref[i] = pref[i - 1] + nums[i];
            }
            vector<vector<int>> dp(n, vector<int>(n, -1));
    
            int p1 = solve(nums, pref, 0, n - 1, dp);
            int p2 = pref[n - 1] - p1;
    
            return p1 >= p2;
        }
    
        int solve(vector<int> &nums, vector<int> &pref, int i, int j, vector<vector<int>> &dp){
            if(i == j) return nums[i];
            if(dp[i][j] != -1) return dp[i][j];
    
            int oppLo = min(solve(nums, pref, i + 1, j, dp), solve(nums, pref, i, j - 1, dp));
    
            int total = i == 0 ? pref[j] : pref[j] - pref[i - 1];
            int myHi = total - oppLo;
    
            return dp[i][j] = myHi;
        }
    };