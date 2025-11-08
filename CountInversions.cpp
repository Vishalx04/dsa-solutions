class Solution {
   public:
    long long int merge(vector<int> &nums, int st, int mid, int end) {
        int i = st;
        int j = mid + 1;
        vector<int> temp;
        long long int invCount = 0;
        while (i <= mid && j <= end) {
            if (nums[i] > nums[j]) {
                temp.push_back(nums[j]);
                invCount += mid - i + 1;
                j++;
            } else {
                temp.push_back(nums[i]);
                i++;
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < (int)temp.size(); ++k) {
            nums[st + k] = temp[k];
        }

        return invCount;
    }
    long long int mergeSort(vector<int> &nums, int st, int end) {
        if (st >= end) return 0;
        int mid = st + (end - st) / 2;
        long long int leftCount = mergeSort(nums, st, mid);
        long long int rightCount = mergeSort(nums, mid + 1, end);

        long long int invCount = merge(nums, st, mid, end);
        return leftCount + rightCount + invCount;
    }
    long long int numberOfInversions(vector<int> nums) {
        if (nums.empty()) return 0;
        long long int ans = mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};