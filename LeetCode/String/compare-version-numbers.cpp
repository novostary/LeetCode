#include <string>
#include <sstream>
using std::string;
using std::stringstream;

// https://leetcode.com/discuss/23934/10-line-concise-solution-c
// https://leetcode.com/discuss/19194/my-solutions-in-3-languages
// https://leetcode.com/discuss/30652/my-2ms-easy-solution-with-c-c
// https://leetcode.com/discuss/32731/java-solution-with-fewer-if-logic
// https://leetcode.com/discuss/19118/accepted-small-java-solution
class Solution {
public:
	int compareVersion(string version1, string version2) {
		for (auto& ch : version1) {
			if (ch == '.') {
				ch = ' ';
			}
		}
		for (auto& ch : version2) {
			if (ch == '.') {
				ch = ' ';
			}
		}

		stringstream ss1(version1);
		stringstream ss2(version2);
		int n1, n2;
		while (1) {
			// if (not(ss1 >> n1)) {
			if (!(ss1 >> n1)) {
				n1 = 0;
			}
			if (!(ss2 >> n2)) {
				n2 = 0;
			}
			// if (not ss1 and not ss2) {
			if (! ss1 && ! ss2) {
				return 0;
			}
			if (n1 < n2) {
				return -1;
			}
			if (n1 > n2) {
				return 1;
			}
		}
	}

	// Runtime: 0 ms
	int compareVersion2(string version1, string version2) {
		// "01", "1"
		if (version1.empty() && version2.empty()) {
			return 0;
		}
		else if (version1.empty()) {
			for (auto ch : version2) {
				if (ch != '.' && ch != '0') {
					return -1;
				}
			}
			return 0;
		}
		else if (version2.empty()) {
			for (auto ch : version1) {
				if (ch != '.' && ch != '0') {
					return 1;
				}
			}
			return 0;
		}
		size_t ipos = version1.find_first_of('.');
		if (ipos == string::npos) {
			ipos = version1.size();
		}
		size_t istart = 0;
		while (istart < ipos && version1.at(istart) == '0') {
			istart++;
		}
		size_t jpos = version2.find_first_of('.');
		if (jpos == string::npos) {
			jpos = version2.size();
		}
		size_t jstart = 0;
		while (jstart < jpos && version2.at(jstart) == '0') {
			jstart++;
		}

		if (ipos - istart > jpos - jstart) {
			return 1;
		}
		else if (ipos - istart < jpos - jstart) {
			return -1;
		}

		for (size_t i = istart, j = jstart; i < ipos && j < jpos; i++, j++) {
			if (version1.at(i) > version2.at(j)) {
				return 1;
			}
			else if (version1.at(i) < version2.at(j)) {
				return -1;
			}
		}
		ipos++;
		jpos++;
		if (ipos >= version1.size() && jpos >= version2.size()) {
			return 0;
		}
		else if (ipos >= version1.size()) {
			return compareVersion("", version2.substr(jpos));
		}
		else if (jpos >= version2.size()) {
			return compareVersion(version1.substr(ipos), "");
		}

		return compareVersion(version1.substr(ipos), version2.substr(jpos));

	}
};