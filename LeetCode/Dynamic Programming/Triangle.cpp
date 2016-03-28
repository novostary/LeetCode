class Solution {
public:
    // Runtime: 12 ms 
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        vector<int> res(triangle.size(), 0);
        res[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            int coln = triangle[i].size();
            res[coln - 1] = res[coln - 2] + triangle[i][coln - 1];
            for (int j = coln - 2; j > 0; --j) {
                res[j] = min(res[j - 1], res[j]) + triangle[i][j];
            }
            res[0] = res[0] + triangle[i][0];
        }
        int minsum = INT_MAX;
        for (int i = 0; i < res.size(); ++i) {
            if (minsum > res[i]) {
                minsum = res[i];
            }
        }
        return minsum;
    }
};
