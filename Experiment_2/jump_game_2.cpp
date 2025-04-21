class Solution {
    public:
        int jump(vector<int> &nums){
            int n = nums.size();
            int jumps = 0, l = 0, r = 0;
            while (r < n - 1){
                int longest = 0;
                for (int i = l; i <= r; i++){
                    longest = max(i + nums[i], longest);
                }
                l = r + 1;
                r = longest;
                jumps++;
            }
            return jumps;
        }
    };