class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // left half sorted
            else if (nums[low] <= nums[mid]) {
                if (target <= nums[mid] && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            } // else right half sorted
            else {
                if (target >= nums[mid+1] && target <= nums[high]) {
                    low = mid + 1;
                } else
                    high = mid - 1;
            }
        }
        return false;
    }
};