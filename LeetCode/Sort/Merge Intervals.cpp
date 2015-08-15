#include <vector>
#include <algorithm>
using std::vector;
using std::max;
// Runtime: 572 ms
// https://leetcode.com/discuss/43383/easy-c-solution-with-explanations-o-nlogn-time-and-o-n-space
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool compareInterval(const Interval& v1, const Interval& v2) {
		// http://www.cplusplus.com/reference/list/list/sort/
		// if (v1.start < v2.start || (v1.start == v2.start && v1.end <= v2.end)) {
		// Runtime Error
		if (v1.start < v2.start || (v1.start == v2.start && v1.end < v2.end)) {
			return true;
		}
		else {
			return false;
		}
		// return v1.start < v2.start || (v1.start == v2.start && v1.end < v2.end);
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		if (intervals.empty()) {
			return ret;
		}

		sort(intervals.begin(), intervals.end(), compareInterval);

		int start = intervals[0].start, end = intervals[0].end;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start <= end) {
				end = max(end, intervals[i].end);
			}
			else {
				ret.push_back(Interval(start, end));
				start = intervals[i].start;
				end = intervals[i].end;
			}
		}
		ret.push_back(Interval(start, end));
		return ret;
	}
	// Runtime: 592 ms
	vector<Interval> merge2(vector<Interval>& intervals) {
		vector<Interval> ret;
		if (intervals.empty()) {
			return ret;
		}

		sort(intervals.begin(), intervals.end(), compareInterval);

		for (int i = 0; i < intervals.size(); i++) {
			if (!i || ret.back().end < intervals[i].start) {
				ret.push_back(intervals[i]);
			}
			else if (ret.back().end < intervals[i].end) {
				ret.back().end = intervals[i].end;
			}
		}
		return ret;
	}
};