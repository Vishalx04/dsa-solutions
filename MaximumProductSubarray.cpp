class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int result = nums[0];

        for (int i = 0; i < nums.size(); i++) {

            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            result = max({result, suffix, prefix});

            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;
        }

        return result;
    }
};