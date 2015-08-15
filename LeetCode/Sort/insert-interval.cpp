#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::max;
using std::min;
using std::back_insert_iterator;
// Runtime: 580 ms
// Best: 568 ms??
// lower_bound: Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
// upper_bound: Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	// Runtime: 580 ms
	static bool compareLowerBound(const Interval& i1, const Interval& i2) {
		return i1.end < i2.end;
	}
	static bool compareUpperBound(const Interval& i1, const Interval& i2) {
		return i1.start < i2.start;
	}
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		Interval lowInterval(0, newInterval.start);
		auto low = lower_bound(intervals.begin(), intervals.end(), lowInterval, compareLowerBound);
		if (low == intervals.end()) {
			// ret.insert(ret.end(), intervals.begin(), intervals.end()); // 580 ms
			copy(intervals.begin(), intervals.end(), back_insert_iterator<vector<Interval>>(ret)); // 584 ms
			ret.push_back(newInterval);
			return ret;
		}

		Interval highInterval(newInterval.end, 0);
		auto high = upper_bound(intervals.begin(), intervals.end(), highInterval, compareUpperBound);
		if (high == intervals.begin()) {
			ret.push_back(newInterval);
			// ret.insert(ret.end(), intervals.begin(), intervals.end()); 
			copy(intervals.begin(), intervals.end(), back_insert_iterator<vector<Interval>>(ret));
			return ret;
		}

		Interval mergeInterval(min(low->start, newInterval.start), max((high - 1)->end, newInterval.end));
		// ret.insert(ret.end(), intervals.begin(), low);
		copy(intervals.begin(), low, back_insert_iterator<vector<Interval>>(ret));
		ret.push_back(mergeInterval);
		// ret.insert(ret.end(), high, intervals.end());
		copy(high, intervals.end(), back_insert_iterator<vector<Interval>>(ret));
		return ret;
	}

	// Runtime: 580 ms
	vector<Interval> insert3(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		auto iter = intervals.begin();
		while (iter != intervals.end() && iter->end < newInterval.start) {
			ret.push_back(*iter);
			++iter;
		}

		while (iter != intervals.end() && iter->start <= newInterval.end) {
			newInterval.start = min(iter->start, newInterval.start);
			newInterval.end = max(iter->end, newInterval.end);
			++iter;
		}
		// sometimes Runtime: 576 ms
		/*auto tmp = iter;
		while (iter != intervals.end() && iter->start <= newInterval.end) {
			++iter;
		}
		if (tmp != iter) {
			newInterval.start = min(tmp->start, newInterval.start);
			newInterval.end = max((iter - 1)->end, newInterval.end);
		}*/
		ret.push_back(newInterval);
		if (iter != intervals.end()) {
			ret.insert(ret.end(), iter, intervals.end());
			// copy(iter, intervals.end(), back_insert_iterator<vector<Interval>>(ret));
		}
		return ret;

	}

	// Runtime: 580 ms
	vector<Interval> insert4(vector<Interval>& intervals, Interval newInterval) {
		// inplace
		Interval lowInterval(0, newInterval.start);
		auto low = lower_bound(intervals.begin(), intervals.end(), lowInterval, compareLowerBound);
		if (low == intervals.end()) {
			intervals.push_back(newInterval);
			return intervals;
		}

		Interval highInterval(newInterval.end, 0);
		auto high = upper_bound(intervals.begin(), intervals.end(), highInterval, compareUpperBound);
		if (high == intervals.begin()) {
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}

		// Input:        [[3,5],[12,15]], [6,6]
		// Output:        [[3,5],[6,6],[6,6]]
		// Expected:        [[3,5],[6,6],[12,15]]
		if (low == high) {
			intervals.insert(low, newInterval);
		}
		else {
			Interval mergeInterval(min(low->start, newInterval.start), max((high - 1)->end, newInterval.end));
			*low = mergeInterval;
			intervals.erase(++low, high);
		}
		return intervals;
	}

	// Runtime: 592 ms
	vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		bool inserted = false;
		for (vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); ++iter) {
			if (newInterval.start < (*iter).start) {
				intervals.insert(iter, newInterval);
				inserted = true;
				break;
			}
		}
		if (!inserted) {
			intervals.push_back(newInterval);
		}
		return merge(intervals);
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;

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
};