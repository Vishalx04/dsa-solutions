class Solution {
public:
    long long int merge(vector<int>& nums, int st, int mid, int end) {
        int j = mid + 1;
        long long count = 0;
        vector<int> temp;
        for (int i = st; i <= mid; i++) {
            while (j <= end && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        int left = st;
        int right = mid + 1;
        while (left <= mid && right <= end) {
            if (nums[left] > nums[right]) {
                temp.push_back(nums[right]);
                right++;
            } else {
                temp.push_back(nums[left]);
                left++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= end) {
            temp.push_back(nums[right]);
            right++;
        }
        for (int k = 0; k < temp.size(); k++) {
            nums[st + k] = temp[k];
        }
        return count;
    }
    long long mergeSort(vector<int>& nums, int st, int end) {
        if (st >= end)
            return 0;
        int mid = st + (end - st) / 2;
        long long left = mergeSort(nums, st, mid);
        long long right = mergeSort(nums, mid + 1, end);
        long long current = merge(nums, st, mid, end);
        return left + current + right;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int ans = mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};

