class Solution {
   public:
    int findKRotation(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        int index = -1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[low] <= nums[mid]) {
                if (nums[low] < ans) {
                    ans = nums[low];
                    index = low;
                }

                low = mid + 1;
            } else {
                if (nums[mid] < ans) {
                    index = mid;
                    ans = nums[mid];
                }
                high = mid - 1;
            }
        }

        return index;
    }
};