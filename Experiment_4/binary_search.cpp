class Solution {
    public:
    int binarySearch(vector<int>& arr, int low, int high, int x){
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) return mid;
            if (arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
        int search(vector<int>& nums, int target) {
            int n= nums.size();
            return binarySearch(nums, 0, n-1, target);
        }
    };