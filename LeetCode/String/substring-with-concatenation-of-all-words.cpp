#include <vector>
#include <unordered_map>
#include <string>
using std::vector;
using std::unordered_map;
using std::string;
// https://leetcode.com/discuss/10063/hash-idea-and-exception-case
// https://leetcode.com/discuss/22289/my-ac-c-code-o-n-complexity-26ms
// http://www.cnblogs.com/feature/articles/1813967.html Rabin-Karp
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) { // Runtime: 876 ms
		vector<int> ret;
		if (s.empty() || words.empty() || words[0].empty()) {
			return ret;
		}

		int sLen = s.size(), wordLen = words[0].size();
		unordered_map<string, int> wordsMap;
		for (auto word : words) {
			wordsMap[word]++;
		}

		int count = words.size(), curCount = 0;
		int curPos = 0, startPos = 0;
		string stmp;
		unordered_map<string, int> tmpMap;
		while (curPos + wordLen <= sLen) {
			stmp = s.substr(curPos, wordLen);
			if (wordsMap.find(stmp) == wordsMap.end()) {
				curPos = startPos + 1;
				startPos = curPos;
				curCount = 0;
				tmpMap.clear();
			}
			else {
				tmpMap[stmp]++;
				curCount++;
				if (tmpMap[stmp] <= wordsMap[stmp]) {
					if (curCount == count) {
						ret.push_back(startPos);
						curPos = startPos + 1;
						startPos = curPos;
						curCount = 0;
						tmpMap.clear();
					}
					else {
						curPos += wordLen;
					}
				}
				else {
					curPos = startPos + 1;
					startPos = curPos;
					curCount = 0;
					tmpMap.clear();
				}
			}
		}
		return ret;
	}

	vector<int> findSubstring2(string s, vector<string>& words) { // Runtime: 884 ms
		unordered_map<string, int> counts;
		for (string word : words)
			counts[word]++;
		int n = s.length(), num = words.size(), len = words[0].length();
		vector<int> indexes;
		for (int i = 0; i < n - num * len + 1; i++) {
			unordered_map<string, int> seen;
			int j = 0;
			for (; j < num; j++) {
				string word = s.substr(i + j * len, len);
				if (counts.find(word) != counts.end()) {
					seen[word]++;
					if (seen[word] > counts[word])
						break;
				}
				else break;
			}
			if (j == num) indexes.push_back(i);
		}
		return indexes;
	}
};