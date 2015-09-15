#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
	// dynamic programming
	bool isMatch(string s, string p) { // Runtime: 4 ms
		int ssize = s.size(), psize = p.size();
		// bool f[ssize + 1][psize + 1];
		bool **f;
		f = new bool*[ssize + 1];
		for (int i = 0; i <= ssize; ++i) {
			f[i] = new bool[psize + 1];
		}

		f[0][0] = true;
		for (int i = 1; i <= ssize; ++i) {
			f[i][0] = false;
		}
		f[0][1] = false;
		for (int j = 2; j <= psize; ++j) {
			f[0][j] = '*' == p.at(j - 1) ? f[0][j - 2] : false;
		}

		for (int i = 1; i <= ssize; ++i) {
			for (int j = 1; j <= psize; ++j) {
				if (p[j - 1] != '*') {
					f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
				}
				else {
					f[i][j] = f[i][j - 2] || (f[i - 1][j] && (s[i - 1] == p[j - 2] || '.' == p[j - 2]));
				}
			}
		}
		return f[ssize][psize];
	}
	bool isMatch3(string s, string p) { // Runtime: 12 ms
		int ssize = s.size(), psize = p.size();
		vector<vector<bool>> f(ssize + 1, vector<bool>(psize + 1, false));

		f[0][0] = true;
		for (int j = 2; j <= psize && '*' == p.at(j - 1); j += 2) {
			f[0][j] = true;
		}

		for (int i = 1; i <= ssize; ++i) {
			for (int j = 1; j <= psize; ++j) {
				if (p[j - 1] != '*') {
					f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
				}
				else {
					f[i][j] = f[i][j - 2] || (f[i - 1][j] && (s[i - 1] == p[j - 2] || '.' == p[j - 2]));
				}
			}
		}
		return f[ssize][psize];
	}

	// backtracking
	bool isMatch2(string s, string p) { // Runtime: 92 ms
		return isMatch(s, p, 0, 0, s.size(), p.size());
	}
private:
	bool isMatch(string &s, string &p, int i, int j, int ssize, int psize) {
		if (j == psize) {
			return i == ssize;
		}
		if (j + 1 < psize && p.at(j + 1) == '*') {
			if (isMatch(s, p, i, j + 2, ssize, psize)) {
				return true;
			}
			while (matchFirst(s, p, i, j, ssize)) {
				if (isMatch(s, p, ++i, j + 2, ssize, psize)) {
					return true;
				}
			}
			return false;
		}
		else {
			if (!matchFirst(s, p, i, j, ssize)) {
				return false;
			}
			return isMatch(s, p, i + 1, j + 1, ssize, psize);
		}
	}
	bool matchFirst(string &s, string &p, int i, int j, int ssize) {
		return i != ssize && (s.at(i) == p.at(j) || p.at(j) == '.');
	}
};