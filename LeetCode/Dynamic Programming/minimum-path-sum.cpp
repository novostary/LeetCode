#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
	// Runtime: 28 ms
	// int minPathSum(vector<vector<int>>& grid) {
	//     if (grid.empty() || grid[0].empty()) {
	//         return 0;
	//     }
	//     int ROW = grid.size(), COL = grid[0].size();
	//     vector<vector<int>> ret(ROW, vector<int>(COL, 0));
	//     ret[0][0] = grid[0][0];
	//     for (int j = 1; j < COL; j++) {
	//         ret[0][j] = ret[0][j - 1] + grid[0][j];
	//     }
	//     for (int i = 1; i < ROW; i++) {
	//         ret[i][0] = ret[i - 1][0] + grid[i][0];
	//     }
	//     for (int i = 1; i < ROW; i++) {
	//         for (int j = 1; j < COL; j++) {
	//             ret[i][j] = min(ret[i - 1][j], ret[i][j - 1]) + grid[i][j];
	//         }
	//     }
	//     return ret[ROW - 1][COL - 1];
	// }

	// Runtime: 32 ms
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		int ROW = grid.size(), COL = grid[0].size();
		vector<int> ret(COL, INT_MAX);
		ret[0] = 0;
		// for (int j = 1; j < COL; j++) {
		//     ret[j] = ret[j - 1] + grid[0][j];
		// }
		for (int i = 0; i < ROW; i++) { // Runtime: 28 ms
			ret[0] = ret[0] + grid[i][0];
			for (int j = 1; j < COL; j++) {
				ret[j] = min(ret[j - 1], ret[j]) + grid[i][j];
			}
		}
		return ret[COL - 1];
	}
};