#include <vector>
#include <unordered_set>
#include <utility>
using std::vector;
using std::unordered_set;
using std::pair;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) { // Runtime: 512 ms
		vector<unordered_set<int>> matrix(numCourses);
		vector<int> inDegree(numCourses, 0);
		for (auto p : prerequisites) {
			matrix[p.second].insert(p.first);
		}
		for (int i = 0; i < numCourses; ++i) {
			for (auto item : matrix[i]) {
				++inDegree[item];
			}
		}

		vector<int> ret(numCourses, 0);

		for (int j = 0, i; j < numCourses; ++j) {
			for (i = 0; i < numCourses && inDegree[i] != 0; ++i);
			if (i == numCourses) {
				ret.clear();
				break; // error
			}

			ret[j] = i;

			inDegree[i] = -1;
			for (auto it = matrix[i].begin(); it != matrix[i].end(); ++it) {
				--inDegree[*it];
			}
		}
		return ret;
	}
};