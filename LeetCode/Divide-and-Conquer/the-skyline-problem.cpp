#include <vector>
#include <utility>
#include <algorithm>
using std::vector;
using std::pair;
using std::max;
// Runtime: 828 ms
// Not the Best!
// http://www.geeksforgeeks.org/divide-and-conquer-set-7-the-skyline-problem/
class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> ret;
		getSkyline(ret, buildings, 0, buildings.size() - 1);
		return ret;
	}
	void getSkyline(vector<pair<int, int>>& ret, vector<vector<int>>& buildings, int i, int j) {
		if (i == j) {
			ret.push_back(pair<int, int>(buildings[i][0], buildings[i][2]));
			ret.push_back(pair<int, int>(buildings[i][1], 0));
			return;
		}
		else if (i > j) {
			return;
		}
		int mid = i + ((j - i) >> 1);
		vector<pair<int, int>> ret1;
		getSkyline(ret1, buildings, i, mid);
		vector<pair<int, int>> ret2;
		getSkyline(ret2, buildings, mid + 1, j);
		merge(ret, ret1, ret2);
	}
	void merge(vector<pair<int, int>>& ret, vector<pair<int, int>>& ret1, vector<pair<int, int>>& ret2) {
		int i = 0, j = 0;
		int h1 = 0, h2 = 0;
		while (i < ret1.size() && j < ret2.size()) {
			if (ret1[i].first > ret2[j].first) {
				h2 = ret2[j].second;
				addToVector(ret, pair<int, int>(ret2[j].first, max(h1, h2)));
				j++;
			}
			else {
				h1 = ret1[i].second;
				addToVector(ret, pair<int, int>(ret1[i].first, max(h1, h2)));
				i++;
			}
		}
		if (j == ret2.size()) {
			for (; i < ret1.size(); i++) {
				ret.push_back(ret1[i]);
			}
		}
		if (i == ret1.size()) {
			for (; j < ret2.size(); j++) {
				ret.push_back(ret2[j]);
			}
		}
	}

	void addToVector(vector<pair<int, int>>& ret, pair<int, int>& p) {
	// no matching function for call to ¡®Solution::addToVector(std::vector<std::pair<int, int> >&, std::pair<int, int>)¡¯
		if (!ret.empty()) {
			if (ret.back().second == p.second) {
				return;
			}
			if (ret.back().first == p.first) {
				ret.back().second = max(ret.back().second, p.second);
				return;
			}
		}
		ret.push_back(p);
	}

	vector<pair<int, int>> getSkyline1(vector<vector<int>>& buildings) {
		return getSkyline(buildings, 0, buildings.size() - 1);
	}
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings, int i, int j) {
		vector<pair<int, int>> ret;
		if (i == j) {
			ret.push_back(pair<int, int>(buildings[i][0], buildings[i][2]));
			ret.push_back(pair<int, int>(buildings[i][1], 0));
			return ret;
		}
		else if (i > j) {
			return ret;
		}
		int mid = i + ((j - i) >> 1);
		vector<pair<int, int>> ret1 = getSkyline(buildings, i, mid);
		vector<pair<int, int>> ret2 = getSkyline(buildings, mid + 1, j);
		return merge(ret1, ret2);
	}
	vector<pair<int, int>> merge(vector<pair<int, int>>& ret1, vector<pair<int, int>>& ret2) {
		vector<pair<int, int>> ret;
		int i = 0, j = 0;
		while (i < ret1.size() && ret1[i].first < ret2[j].first) {
			ret.push_back(ret1[i]);
			i++;
		}
		while (i == 0 && j < ret2.size() && ret1[i].first > ret2[j].first) {
			ret.push_back(ret2[j]);
			j++;
		}
		if (ret1[0].first == ret2[0].first) {
			ret.push_back(pair<int, int>(ret1[0].first, max(ret1[0].second, ret2[0].second)));
			i++;
			j++;
		}
		while (i < ret1.size() && j < ret2.size()) {
			if (ret1[i].first > ret2[j].first) {
				if (ret2[j].second > ret1[i - 1].second) {
					ret.push_back(ret2[j]);
				}
				else if (j > 0 && ret2[j - 1].second > ret1[i - 1].second) {
					ret.push_back(pair<int, int>(ret2[j].first, ret1[i - 1].second));
				}
				j++;
			}
			else if (ret1[i].first == ret2[j].first) {
				if (ret1[i].second == ret2[j].second) {
					ret.push_back(ret1[i]);
				}
				else {
					int tmp = max(ret1[i].second, ret2[j].second);
					if (i > 0 && j > 0) {
						if (ret1[i - 1].first > ret2[j - 1].first) {
							if (!(tmp == ret1[i - 1].second)) {
								ret.push_back(pair<int, int>(ret1[i].first, tmp));
							}
						}
						else if (ret1[i - 1].first == ret2[j - 1].first) {
							if (!(tmp == max(ret1[i - 1].second, ret2[j - 1].second))) {
								ret.push_back(pair<int, int>(ret1[i].first, tmp));
							}
						}
						else {
							if (!(tmp == ret2[j - 1].second)) {
								ret.push_back(pair<int, int>(ret1[i].first, tmp));
							}
						}
					}
					else if (i > 0) {
						if (!(tmp == ret1[i - 1].second)) {
							ret.push_back(pair<int, int>(ret1[i].first, tmp));
						}
					}
					else {
						if (!(tmp == ret2[j - 1].second)) {
							ret.push_back(pair<int, int>(ret1[i].first, tmp));
						}
					}
				}
				i++;
				j++;
			}
			else {
				if (ret1[i].second > ret2[j - 1].second) {
					ret.push_back(ret1[i]);
				}
				else if (i > 0 && ret1[i - 1].second > ret2[j - 1].second) {
					ret.push_back(pair<int, int>(ret1[i].first, ret2[j - 1].second));
				}
				i++;
			}
		}
		if (j == ret2.size()) {
			for (; i < ret1.size(); i++) {
				ret.push_back(ret1[i]);
			}
		}
		if (i == ret1.size()) {
			for (; j < ret2.size(); j++) {
				ret.push_back(ret2[j]);
			}
		}
		return ret;
	}
};