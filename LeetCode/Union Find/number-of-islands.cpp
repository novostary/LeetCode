#include <vector>
using std::vector;
// Runtime: 8 ms
class Solution {
public:
	// Runtime: 8 ms
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		int ROW = grid.size(), COL = grid[0].size();
		UF uf(ROW * COL + 1);
		int dummyPoint = ROW * COL; // We assume it as 0 and it connects all 0s.
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (grid[i][j] == '1') {
					if (j != COL - 1 && grid[i][j + 1] == '1') {
						uf.unionP(i * COL + j, i * COL + j + 1);
					}
					if (i != ROW - 1 && grid[i + 1][j] == '1') {
						uf.unionP(i * COL + j, (i + 1) * COL + j);
					}
				}
				else {
					uf.unionP(i * COL + j, dummyPoint);
				}
			}
		}
		return uf.getCount() - 1;
	}
	int numIslands2(vector<vector<char>>& grid) {
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

class UF {
public:
	UF(int N) {
		count = N;
		id = new int[N];
		weight = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
			weight[i] = 0;
		}
	}
	~UF() {
		delete[]id;
		delete[]weight;
	}
	void unionP(int p, int q) {
		int i = root(p);
		int j = root(q);
		if (i == j) {
			return;
		}
		if (weight[i] < weight[j]) {
			id[i] = j;
		}
		else if (weight[i] > weight[j]) {
			id[j] = i;
		}
		else {
			id[i] = j;
			weight[j]++;
		}
		count--;
	}
	bool connected(int p, int q) {
		return root(p) == root(q);
	}
	int getCount() {
		return count;
	}
private:
	int *id;
	int *weight;
	int count;
	int root(int i) {
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
};