#include <vector>
using std::vector;
// Runtime: 8 ms
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) {
			return 0;
		}
		int count = 0;
		int ROW = grid.size(), COL = grid[0].size();
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (grid[i][j] == '1') {
					count++;
					DFSIslands(grid, i, j, ROW, COL);
				}
			}
		}
		return count;
	}
	void DFSIslands(vector<vector<char>>& grid, int i, int j, int ROW, int COL) {
		if (grid[i][j] == '1') {
			grid[i][j] = '0';
			if (i > 0) {
				DFSIslands(grid, i - 1, j, ROW, COL);
			}
			if (i < ROW - 1) {
				DFSIslands(grid, i + 1, j, ROW, COL);
			}
			if (j > 0) {
				DFSIslands(grid, i, j - 1, ROW, COL);
			}
			if (j < COL - 1) {
				DFSIslands(grid, i, j + 1, ROW, COL);
			}
		}
	}

	// int numIslands(vector<vector<char>>& grid) {
	//     int count = 0;
	//     for (int i = 0; i < grid.size(); i++) {
	//         for (int j = 0; j < grid[0].size(); j++) {
	//             if (grid[i][j] == '1') {
	//                 count++;
	//                 DFSIslands(grid, i, j);
	//             }
	//         }
	//     }
	//     return count;
	// }
	// void DFSIslands(vector<vector<char>>& grid, int i, int j) {
	//     if (grid[i][j] == '1') {
	//         grid[i][j] = '0';
	//         if (i > 0) {
	//             DFSIslands(grid, i - 1, j);
	//         }
	//         if (i < grid.size() - 1) {
	//             DFSIslands(grid, i + 1, j);
	//         }
	//         if (j > 0) {
	//             DFSIslands(grid, i, j - 1);
	//         }
	//         if (j < grid[0].size() - 1) {
	//             DFSIslands(grid, i, j + 1);
	//         }
	//     }
	// }
};