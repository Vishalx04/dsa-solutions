class Solution {
   public:
    int lowerBound(vector<int> &nums, int x) {
        int ans = nums.size();
        int low = 0;
        int high = nums.size() - 1;
        int mid = low + (high - low) / 2;
        while (low <= high) {
            mid = low + (high - mid) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};