#include <vector>
#include <unordered_set>
#include <utility>
using std::vector;
using std::unordered_set;
using std::pair;
// https://leetcode.com/discuss/34791/bfs-topological-sort-and-dfs-finding-cycle-by-c
class Solution {
public:
	// bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

	// }

	// 10, [[5,8],[3,5],[1,9],[4,5],[0,2],[1,9],[7,8],[4,9]] // duplicates... 31 / 34 test cases passed.
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> matrix(numCourses);
		vector<int> inDegree(numCourses, 0);
		// for (auto p : prerequisites) {
		//     if (matrix[p.second].find(p.first) == matrix[p.second].end()) { // Runtime: 280 ms
		//         matrix[p.second].insert(p.first);
		//         inDegree[p.first]++;
		//     }
		// }
		for (auto p : prerequisites) {
			matrix[p.second].insert(p.first);
		}
		for (int i = 0; i < numCourses; ++i) { // Runtime: 268 ms
			for (auto item : matrix[i]) {
				++inDegree[item];
			}
		}
		for (int j = 0, i; j < numCourses; ++j) {
			for (i = 0; i < numCourses && inDegree[i] != 0; ++i);
			if (i == numCourses) {
				return false;
			}
			inDegree[i] = -1;
			for (auto it = matrix[i].begin(); it != matrix[i].end(); ++it) {
				--inDegree[*it];
			}
		}
		return true;
	}
};