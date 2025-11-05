//brute --
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        int n = nums.size();
        for(int i = 0 ;i <n-2 ;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> arr = {nums[i], nums[j], nums[k]};
                        sort(arr.begin(), arr.end());
                        ans.insert(arr);
                    }
                }
            }
        }
        vector<vector<int>>result(ans.begin(), ans.end());
        return result;
    }
};

// better --

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            unordered_set<int> hash;
            for (int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);
                if (hash.find(third) != hash.end()) {
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);
                }
                hash.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


//optimal - 

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3) return ans;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            int target = -(nums[i]);
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    ans.push_back(triplet);
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++, k--;
                } else if (nums[j] + nums[k] > target)
                    k--;
                else if (nums[j] + nums[k] < target)
                    j++;
            }
        }
        return ans;
    }
};