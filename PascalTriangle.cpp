class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> triangle;
        triangle.push_back({1});
        for (int i = 1; i < n; i++) {
            triangle.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
};